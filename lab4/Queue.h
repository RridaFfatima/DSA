#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    T* data;
    int capacity;
    int noOfElements;
    int front;
    int rear;

public:

    Queue(int c = 10)
    {
        data = new T[c];
        capacity = c;
        noOfElements = 0;
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return noOfElements == 0;
    }

    bool isFull()
    {
        return noOfElements == capacity;
    }
    int getNoOfElement(){
        return noOfElements;
    }
    void enqueue(T v)
    {
        if (isFull())
            return;

        rear = (rear + 1) % capacity;
        data[rear] = v;
        noOfElements++;
    }

    T dequeue()
    {
        if (isEmpty())
            return T();

        T value = data[front];

        front = (front + 1) % capacity;
        noOfElements--;

        return value;
    }
T getFront()
{
    if (isEmpty())
        return T();

    return data[front];
}

T getRear()
{
    if (isEmpty())
        return T();

    return data[rear];
}
    void display()
    {cout<<"Elements in the circular queue are: ";
        for (int i = 0; i < noOfElements; i++)
        {
            cout << data[(front + i) % capacity] << " ";
        }

        cout << endl;
    }

    Queue<T>& operator=(const Queue<T>& q)
    {
        if (this != &q)
        {
            delete[] data;

            capacity = q.capacity;
            noOfElements = q.noOfElements;
            front = q.front;
            rear = q.rear;

            data = new T[capacity];

            for (int i = 0; i < capacity; i++)
            {
                data[i] = q.data[i];
            }
        }

        return *this;
    }

    ~Queue()
    {
        delete[] data;
    }
};

#endif