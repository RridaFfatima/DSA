#include<iostream>
#include<string>
#include "Queue.h"
using namespace std;


int print(int *a, int n,int k) {
    Queue<int>index;
    int time=0;
    for(int i=0; i<n; i++){
        index.enqueue(i);
    }
    while(!index.isEmpty()){
        int i=index.getFront();
        index.dequeue();
        a[i]--;
        time++;
        if(a[i]>0){
            index.enqueue(i);
        }
        else if(i==k){
            return time;
        }
    }
    return time;
    
}
int main(){
    int a[]={3,3,1,2};
    int k=0;
    int i=print(a,4,k);
    cout<<i<<endl;
    return 0;
}