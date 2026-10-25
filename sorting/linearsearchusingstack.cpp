#include<iostream>
#include <string>
#include "Stack.h"

using namespace std;
bool linear_search(int *a, int size, int key){
    Stack<int>s;
    Stack<int>t;
        for (int i=0; i<size; i++){
        s.push(a[i]);
    }
    int x=s.pop();
    if(key == x){
            return true;
    }
    else{
        t.push(x);
        return false;
    }
    if(!t.isempty()){
        s.push(t.pop());
    }
}

int main(){
    int a[5]={1,2,3,4,5};
    bool r=linear_search(a,5,8);
    if(r){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    return 0;
}