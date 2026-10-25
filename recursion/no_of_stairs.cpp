#include<iostream>
#include<string>
using namespace std;
int noofways(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    return noofways(n-1)+ noofways(n-2);
    
}
int main(){
    int r=noofways(3);
    cout<<r;
    return 0;
}