#include<iostream>
#include<string>
using namespace std;
int number_of_digits(int number){
    int c=0;
    if(number>=0 && number <=9){
        return 1;
    }
    return 1 + number_of_digits(number/10);
}
int main(){
    int a=number_of_digits(245);
    cout<<a;
    return 0;
}