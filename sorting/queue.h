#include<iostream>
#include<string>
using namespace std;
template <class T>
class queue{
private:
T * data;
int capacity;
int noofelements;
int front;
int rear;
public:
queue(int c=0){
    front=-1;
    rear=-1;
    if(c<0){
        exit{0};
    }
    else{
        capacity=c;
    }
    noofelements=0;
    data= new T[capacity];
}
queue(queue &q){
capacity=q.capacity;
noofelements=q.noofelements;
front=q.front;
rear=q.rear;
data = new T[capacity];
for(int i=0; i<noofelements; i++){
    data[i]=q.data[i];
}
}
queue& operator=(const queue& q)
{
    if (this != &q)
    {
        delete[] data;

        capacity = q.capacity;
        front = q.front;
        rear = q.rear;
        noofelements=q.noofelements;

        data = new T[capacity];

        for (int i = 0; i < capacity; i++)
        {
            data[i] = q.data[i];
        }
    }

    return *this;
}

bool isempty(){
    return noofelements=0;
}
bool isfull(){
    return noofelements==capacity;
}
void enqueue(int v){
    if(!isfull()){
        if(isempty()){
            front =0;
            rear=0;
        }
        else{
        rear=(rear+1)%capacity;

        }
        data[rear]=v;
        noofelements++;

    }
}
T dequeue( ){
    if(!isempty()){
        front=(front+1)%capacity;
        T value= data[front];
        noofelements--;
        if (noofelements==0){
            front=-1;
            rear=-1;
        }
        return value;
    }
    return T();
}
void display(){
    if(isempty()){
        return;
    }
    for(int i=0; i<noofelements ; i++){
        cout<<data[front +i]%capacity<<" ";
    }
    cout<<endl;
}
void resize(int v){
    capacity=v;
    T* newdata= new T [capacity];
    for(int i=0; i<noofelements; i++){
        newdata[i]=data[(i+front)%capacity];
    }
    delete []data;
    data=newdata;
    rear=noofelements-1;
    front =0;
}
~queue(){
    delete [] data;
}
};
int main()
{
queue<int> q(5);
q.enqueue(14);
q.enqueue(22);
q.enqueue(13);
q.enqueue(-6);
q.display();
cout<<"Deleted Value = "<<q.dequeue()<<endl;
cout<<"Deleted Value = "<<q.dequeue()<<endl;
q.display();
q.enqueue(9);
q.enqueue(20);
q.enqueue(5);
q.display();
return 0;
}