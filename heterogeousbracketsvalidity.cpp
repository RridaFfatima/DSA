#include<iostream>
#include "Stack.h"
#include<string>
using namespace std;
 int hetrogenous_string(char s[]){
    int i=0;
    Stack <char> sc;
    while(s[i]!='\0'){
        if(s[i]=='('|| s[i]=='{'||s[i]=='['){
            sc.push(s[i]);
        }
        if(s[i]==')'|| s[i]=='}'||s[i]==']'){
            if(sc.isempty()){
                return 0;
            }
            char stackpop=sc.pop();
            if(stackpop!='(' && s[i]==')' || stackpop!='{' && s[i]=='}' || stackpop!='[' && s[i]==']' ) {
                return 0;
            }
    }
    i++;
 }
 if (sc.isempty()){
    return 1;
 }
 else{
    return 0;
 }
}
int main(){

     char s[] =  "{[()]}";

    int result = hetrogenous_string(s);

    cout << result;

    return 0;

}
