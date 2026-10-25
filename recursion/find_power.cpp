#include<iostream>
#include<string>
using namespace std;
int pow(int number,int power){
    if(power==0){
        return 1;
    }
    return number* pow(number,power-1);
}
int main(){
    int a=pow(2,3);
    cout<<a;
    return 0;
}