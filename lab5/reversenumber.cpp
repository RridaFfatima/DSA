#include<iostream>
#include<string>
using namespace std;
int reverse_number(int n,int result =0)
{ int rev=0;
    if(n==0){
        return result;
    }
    return  reverse_number(n/10,result*10 +(n%10));
} 
int main(){
int n=56321;
cout << "Reversed number: " << reverse_number(n) << endl;
n=89641;
cout << "Reversed number: " << reverse_number(n) << endl;
return 0;
}