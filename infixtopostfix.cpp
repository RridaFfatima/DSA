#include<iostream>
#include "Stack.h"
#include<string>
using namespace std;
int precedence(char c){
if(c=='+' || c=='-'){
    return 1;
}
else if(c=='*' || c=='/'){
    return 2;
}
else if(c=='^'){
    return 3;
}
else if(c=='(' ){
    return 0;
}
else {
    return -1;
}

}
string infix_to_postfix(char s[]){
    string p;
    Stack<char>c;
    int i=0;
    while(s[i] !='\0'){
        if(s[i] >='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z'){
            p=p+s[i];
        }
        else if(s[i]=='+' || s[i]=='-' ||s[i]=='*' ||s[i]=='/' ||s[i]=='^' ){
            while(!c.isempty() && precedence(c.getStacktop())>precedence(s[i])){
                char pop=c.pop();
                p=p+pop;
            }
            if(s[i]!=')'){
                c.push(s[i]);
            }
            else if(s[i] ==')'){
                while(!c.isempty() && c.getStacktop()!='('){
                    char pop=c.pop();
                    p=p+pop;
                }
                c.pop();
            }
        }
i++;
    }
    while(!c.isempty()){
        char pop=c.pop();
           p=p+pop;
    }
    return p;
}
int main(){

    char s[] = "A+B*C";

    string result = infix_to_postfix(s);

    cout << "Postfix: " << result;

    return 0;
}