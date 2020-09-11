#ifndef LIST_H
#define LIST_H

class List
{
private:
    struct node
    {
        int data;
        node *next;
    };

    typedef struct node *nodePtr;

    nodePtr head, curr, temp;

public:
    List(); // constructor
    void AddNode(int addData);
    void DeleteNode(int delData);
    void PrintList();
};

#endif /* LIST_H */