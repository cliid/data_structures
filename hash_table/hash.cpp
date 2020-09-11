#include <iostream>
#include <string>

#include "hash.h"

hash::hash()
{
    for (int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = nullptr;
    }
}

void hash::AddItem(std::string name, std::string drink)
{
    int index = Hash(name);

    if (HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
        item *Ptr = HashTable[index];
        item *n = new item;
        n->name = name;
        n->drink = drink;
        n->next = nullptr;
        while (Ptr->next != nullptr)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

int hash::NumberOfItemsInIndex(int index)
{
    int count = 0;

    if (HashTable[index]->name == "empty")
    {
        return count;
    }
    else
    {
        count++;
        item *Ptr = HashTable[index];
        while (Ptr->next != nullptr)
        {
            count++;
            Ptr = Ptr->next;
        }
        return count;
    }
}

void hash::PrintTable()
{
    int number;
    for (int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        std::cout << "-----------------" << std::endl;
        std::cout << "index = " << i << std::endl;
        std::cout << HashTable[i]->name << std::endl;
        std::cout << HashTable[i]->drink << std::endl;
        std::cout << "# of items = " << number << std::endl;
        std::cout << "-----------------" << std::endl;
    }
}

void hash::PrintItemsInIndex(int index)
{
    item *Ptr = HashTable[index];

    if (Ptr->name == "empty")
    {
        std::cout << "index = " << index << " is empty" << std::endl;
    }
    else
    {
        std::cout << "index " << index << " contains the following item" << std::endl;
        while (Ptr != nullptr)
        {
            std::cout << "------------" << std::endl;
            std::cout << Ptr->name << std::endl;
            std::cout << Ptr->drink << std::endl;
            std::cout << "------------" << std::endl;
            Ptr = Ptr->next;
        }
    }
}
int hash::Hash(std::string key)
{
    int hash = 0;
    int index;

    index = key.length();

    for (int i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i] * 17;
    }
    hash = hash % tableSize;

    return index;
}

void hash::FindDrink(std::string name)
{
    int index = Hash(name);
    bool foundName = false;
    std::string drink;

    item *Ptr = HashTable[index];
    while (Ptr != nullptr)
    {
        if (Ptr->name == name)
        {
            foundName = true;
            drink = Ptr->drink;
        }
        Ptr = Ptr->next;
    }
    if (foundName == true)
    {
        std::cout << "Favorite Drink: " << drink << std::endl;
    }
    else
    {
        std::cout << name << "'s info was not found in the Hash Table." << std::endl;
    }
}