#include<iostream>
#include<cstring>
#include "Stack.h"
using namespace std;
void AddingLargeNUmbers(char *s1, char *s2){
    Stack<char>number1;
    Stack<char>number2;
    Stack<int>result;
    int carry=0;
    int i=0; int j=0;
while(s1[i]!='\0'){
number1.push(s1[i]);
i++;
}
while(s2[j]!='\0'){
number2.push(s2[j]);
j++;
}
int unit=0;
char a; char b;
while(!number1.isempty() || !number2.isempty() || carry>0){
    int aa=0;
    int bb=0;
    if(!number1.isempty()){
     a=number1.getStacktop();
     aa=a-'0';
    number1.pop();
    }
        if(!number2.isempty()){
     b=number2.getStacktop();
     bb=b-'0';
    number2.pop();
        }
     
    
    carry=carry+bb+aa;
    if(carry<10){
     result.push(carry);
     carry=0;
    }
    else{
        unit =carry%10;
         result.push(unit);
        carry=carry/10;
    }   
    


    
}
while(!result.isempty()){
    int p=result.getStacktop();
    result.pop();

    cout<<p;
}
}
int main(){
    char a [25];
    char b[25];
    cout<<"enter first number: "<<endl;
    cin>>a;
    cout<<"enter second number: "<<endl;
    cin>>b;
    AddingLargeNUmbers(a,b);
    return 0;

}