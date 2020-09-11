#include <iostream>

#include "list.h"

List::List()
{
    head = nullptr;
    curr = nullptr;
    temp = nullptr;
}

void List::AddNode(int addData)
{
    nodePtr n;
    n->next = nullptr;
    n->data = addData;

    if (head != nullptr)
    {
        curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = n;
    }
    else
    {
        head = n;
    }
}

void List::DeleteNode(int delData)
{
    nodePtr delPtr = nullptr;
    temp = head;
    curr = head;
    while (curr != nullptr && curr->data != delData)
    {
        temp = curr;
        curr = curr->next;
    }
    if (curr == nullptr)
    {
        std::cout << delData << "was not in the list." << std::endl;
        delete delPtr;
    }
    else
    {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if (delPtr == head)
        {
            head = head->next;
            temp = nullptr;
        }
        delete delPtr;
        std::cout << "The value " << delData << " was deleted." << std::endl;
    }
}

void List::PrintList()
{
    curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->data << std::endl;
        curr = curr->next;
    }
}
