#include<iostream>
#include "Stack.h"
using namespace std;
void duplicate(int a[], int &n){
    Stack<int>s;
    Stack<int>temp;
    for(int i=0; i<n; i++){
        bool d=false;
        while(!s.isempty()){
            int x=s.pop();
        if(x==a[i]){
            d=true;
        }
        temp.push(x);
    }

    while(!temp.isempty()){
        s.push(temp.pop());
    }
    if(!duplicate){
        s.push(a[i]);
    }
}
    int i=0;
    while(!s.isempty()){
        a[i]=s.pop();
        i++;
    }
    return ;
    

}
int main(){
    int n=5;
    int a[]={3,5,5,8,3};
    duplicate(a,n);
    return 0;
}