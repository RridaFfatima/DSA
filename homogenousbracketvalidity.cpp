#include<iostream>
#include "Stack.h"
#include<string>
using namespace std;
 int homogenous_string(char s[]){
    int i=0;
    Stack <char> sc;
    while(s[i]!='\0'){
        if(s[i]=='('){
            sc.push(s[i]);
        }
        if(s[i]==')'){
            if(sc.isempty()){
                return 0;
            }
            char stackpop=sc.pop();
            if(stackpop !='('){
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

    char s[] = "(A+B)*(C-D)";

    int result = homogenous_string(s);

    cout << result;

    return 0;

}
