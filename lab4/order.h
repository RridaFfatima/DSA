#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
using namespace std;

class Order
{
private:
    int orderId;
    string customerName;
    int preparationTime;

public:
    Order()
    {
        orderId = 0;
        customerName = "";
        preparationTime = 0;
    }

    Order(int id, string name, int time)
    {
        orderId = id;
        customerName = name;
        preparationTime = time;
    }

    int getId()
    {
        return orderId;
    }

    string getName()
    {
        return customerName;
    }

    int getPreparationTime()
    {
        return preparationTime;
    }

    void setPreparationTime(int t)
    {
        preparationTime = t;
    }
};

#endif