#include <iostream>
#include <stdio.h>
#include <stdexcept>


class Stack
{
    private:
    typedef struct Node
    {
        Node *next;
        char value;
    }node;

    node *head;

    node *create(char value, node *next)
    {
        node *newNode = new node();
        newNode->value = value;
        newNode->next = next;
        return newNode;
    } 

    public:
    Stack()
    {
        this->head = this->create('\r', nullptr);
    }
    void push(char value)
    {
        node *newNode = this->create(value, this->head->next);
        this->head->next = newNode;
    }
    char pop()
    {
        if(this->head->next == nullptr)
        {
            throw std::runtime_error("The stack is empty");
        }
        node *popNode = this->head->next;
        char value = popNode->value;
        this->head->next = popNode->next;
        delete popNode;
        return value;
    }
    char top()
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
    Stack parentheses_check = Stack();
    char charList[10] = {'[','(',')','{','}',']','(',')','[',']'};
    for(int x = 0; x < 10; x++)
    {
        if(charList[x] == '[' || charList[x] == '{' || charList[x] == '(')
        {
            parentheses_check.push(charList[x]);
        }
        else if(charList[x] == ']' || charList[x] == '}' || charList[x] == ')')
        {
            if(parentheses_check.isEmpty())
            {
                throw std::invalid_argument("invalid close");
            }
            std::cout<<parentheses_check.top()<<" "<<charList[x]<<std::endl;
            parentheses_check.pop();
        }
    }
    if(!parentheses_check.isEmpty())
    {
        throw std::invalid_argument("invalid start");
    }
    
    return 0;
}