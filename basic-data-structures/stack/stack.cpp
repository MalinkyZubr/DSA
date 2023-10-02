#include <iostream>
#include <stdio.h>
#include <stdexcept>


class Stack
{
    private:
    typedef struct Node
    {
        Node *next;
        int value;
    }node;

    node *head;

    node *create(int value, node *next)
    {
        node *newNode = new node();
        newNode->value = value;
        newNode->next = next;
        return newNode;
    } 

    public:
    Stack()
    {
        this->head = this->create(-1, nullptr);
    }
    void push(int value)
    {
        node *newNode = this->create(value, this->head->next);
        this->head->next = newNode;
    }
    int pop()
    {
        if(this->isEmpty())
        {
            throw std::runtime_error("The stack is empty");
        }
        node *popNode = this->head->next;
        int value = popNode->value;
        this->head->next = popNode->next;
        delete popNode;
        return value;
    }
    int top()
    {
        if(this->isEmpty())
        {
            throw std::runtime_error("The stack is empty");
        }
        node *topNode = this->head->next;
        return topNode->value;
    }
    bool isEmpty()
    {
        return this->head->next == nullptr;
    }
    ~Stack()
    {
        node *selected = this->head->next;
        node *next;
        while(selected != nullptr)
        {
            next = selected->next;
            delete selected;
            this->head->next = next;
            selected = next;
        }
        delete this->head;
    }
};

int main()
{
    Stack sillyStack = Stack();
    for(int x = 0; x < 10; x++)
    {
        sillyStack.push(x);
        std::cout << sillyStack.top() << std::endl;
    }
    int silliness = sillyStack.pop();
    std::cout << silliness << std::endl;
    int silliness2 = sillyStack.top();
    std::cout << silliness2 << std::endl;
    
    // reversing an array
    int intArray[10];
    Stack reverser = Stack();
    for(int x = 0; x < 10; x++)
    {
        intArray[x] = x;
        reverser.push(x);
        std::cout << x << " ";
    }
    std::cout << "\n" << std::endl;
    for(int x = 0; x < 10; x++)
    {
        intArray[x] = reverser.pop();
        std::cout << intArray[x] << " ";
    }
    //std::cout << "\n" << std::endl;

    return 0;
}