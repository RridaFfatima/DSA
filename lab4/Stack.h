#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
template <class T>
class Stack{
    private:
    T *data;
    int capacity;
    int top;
    public:
    Stack(int c=10){
        if(c>0){
        capacity=c;
        }
        else {
            exit(0);
        }
        top=0;
        data= new T [capacity];
    }
    ~Stack(){
        delete []data;
    }
    Stack( const Stack &ref ){
        capacity=ref.capacity;
        top=ref.top;
        data = new T[capacity];
        for(int i=0; i<top; i++){
            data[i]=ref.data[i];
        }
    }
    Stack & operator =(const Stack &ref){
        if (this !=&ref){
        delete [] data;
        capacity=ref.capacity;
        top=ref.top;
        data = new T[capacity];
        for(int i=0; i<top; i++){
            data[i]=ref.data[i];
        }

        }
        return *this;
    }
    bool isfull(){
        if (top ==capacity){
            return true;
        }
        else {
            return false;
        }
    }
    void push(T e){
        if (!isfull()){
            data[top]=e;
            top++;
        }
    }
    bool isempty(){
        if(top==0){
            return true;
        }
        else{
            return false;
        }
    }
    T pop(){
        if (!isempty()){
            top--;
            return data[top];
        }
    }
    T gettop(){
        return top;
    }
     T getStacktop(){
        if(!isempty()){
            return data[top -1];
        }
     }
};
