#include <stdio.h>
#include <iostream>
#include <stdexcept>


class LinkedList
{
    private:
    typedef struct ListNode
    {
        int value;
        struct ListNode *next;
        struct ListNode *previous;
    }Node;

    Node *head;
    int size = 0;

    public:
    LinkedList()
    {
        this->head = createNode(-1, nullptr, nullptr);
    }
    Node *createNode(int val, Node *next, Node *previous)
    {
        Node *newNode = new Node();
        newNode->next = next;
        newNode->value = val;
        newNode->previous = previous;
        return newNode;
    }
    void append(int val)
    {
        Node *selected = this->head;
        while(selected->next != nullptr)
        {
            selected = selected->next;
        }
        selected->next = this->createNode(val, nullptr, selected);
        size++;
    }
    void deleteIndex(int desired_index)
    {
        Node *toDelete = findNode(desired_index);
        if(toDelete->previous != nullptr)
        {
            toDelete->previous->next = toDelete->next;
        }
        if(toDelete->next != nullptr)
        {
            toDelete->next->previous = toDelete->previous;
        }
        delete toDelete;
    }
    void insert(int desired_index, int val)
    {
        Node *next = findNode(desired_index);
        Node *newNode = createNode(val, next, next->previous);
        next->previous->next = newNode;
        next->previous = newNode;
    }
    Node *findNode(int desired_index)
    {
        Node *selected = this->head;
        int index = -1;
        while(selected != nullptr)
        {
            if(index == desired_index)
            {
                return selected;
            }
            selected = selected->next;
            index++;
        }
        throw std::invalid_argument("Index out of range");
    }
    int find(int index)
    {
        Node *found = findNode(index);
        return found->value;
    }
    void reverse() // iterative
    {
        Node *selected, *previous, *next;
        selected = this->head->next;
        previous = nullptr;

        while(selected != nullptr)
        {
            next = selected->next;
            selected->previous = next;
            selected->next = previous;
            previous = selected;
            selected = next;
        }
        this->head->next = previous;
        previous->previous = this->head;
    }
    ~LinkedList()
    {
        Node *selected = this->head;
        Node *next;
        int index = -1;
        while(selected != nullptr)
        {
            next = selected->next;
            if(next != nullptr)
            {
                next->previous = nullptr;
            }
            delete selected;
            selected = next;
        }
    }
};

int main()
{
    LinkedList *silly = new LinkedList();
    for(int x=0; x < 10; x++)
    {
        silly->append(x);
    }
    std::cout << silly->find(5) << std::endl;
    silly->insert(5, 999);
    std::cout << silly->find(5) << std::endl;
    silly->deleteIndex(5);
    std::cout << silly->find(5) << std::endl;
    silly->reverse();
    std::cout << silly->find(5) << std::endl;
    delete silly;
    return 0;
}