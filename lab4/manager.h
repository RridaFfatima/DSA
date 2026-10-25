#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "order.h"
#include "Queue.h"
using namespace std;

class OrderManager
{
private:
    Queue<Order> q;
    int timeQuantum;

public:
    OrderManager(Order arr[], int len, int tq)
    {
        timeQuantum = tq;

        for (int i = 0; i < len; i++)
        {
            q.enqueue(arr[i]);
        }
    }

    void processOrders()
    {
        int timer = 0;

        while (!q.isEmpty())
        {
            Order current = q.getFront();

            cout << "\nOrder ID: "
                 << current.getId();

            cout << "\nCustomer: "
                 << current.getName();

            cout << "\nRemaining preparation time: "
                 << current.getPreparationTime()
                 << endl;

            int remaining = current.getPreparationTime();
            int elapsed = 0;

            while (elapsed < timeQuantum && remaining > 0)
            {
                remaining--;
                elapsed++;
                timer++;
            }

            current.setPreparationTime(remaining);

            q.dequeue();

            if (remaining == 0)
            {
                cout << "Order ("
                     << current.getId()
                     << ", "
                     << current.getName()
                     << ") completed preparation"
                     << endl;
            }
            else
            {
                q.enqueue(current);
            }

            cout << "Simulation time: "
                 << timer << " seconds"
                 << endl;
        }
    }
};

#endif