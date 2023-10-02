#include <iostream>
#include <stdio.h>
#include <stdexcept>


class Queue
{
    private:
    typedef struct Node
    {
        Node *next;
        int value;
    }node;

    node *tail;
    node *head;
    //node *front;

    node *create(int value, node *next)
    {
        node *newNode = new node();
        newNode->value = value;
        newNode->next = next;
        return newNode;
    } 

    public:
    Queue()
    {
        this->head = this->create(-1, nullptr);
        this->tail = this->head;
    }
    void enqueue(int value)
    {
        node *newNode = this->create(value, nullptr);
        this->tail->next = newNode;
        this->tail = newNode;
    }
    int dequeue()
    {
        if(this->isEmpty())
        {
            throw std::runtime_error("The queue is empty");
        }
        node *front = this->head->next;
        this->head->next = front->next;
        int value = front->value;
        delete front;
        return value;
    }
    int peek()
    {
        if(this->isEmpty())
        {
            throw std::runtime_error("The queue is empty");
        }
        return this->head->next->value;
    }
    bool isEmpty()
    {
        return head->next == nullptr;
    }
    ~Queue()
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
        this->tail = nullptr;
        delete this->head;
    }
};

int main()
{
    Queue silly_queue = Queue();
    for(int x = 0; x<10; x++)
    {
        silly_queue.enqueue(x);
        std::cout<<x<<std::endl;
    }
    std::cout<<std::endl;
    for(int x= 0; x < 5; x++)
    {
        std::cout<<silly_queue.dequeue()<<std::endl;
    }
}