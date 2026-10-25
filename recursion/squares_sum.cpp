#include<iostream>
#include<string>
using namespace std;
int squares_sum(int n){
    if(n==0){
        return 0;
    }
    return n*n + squares_sum(n-1);
}
int main(){
    int a=3;
int r=squares_sum(a);
cout<<r;
    return 0;
}