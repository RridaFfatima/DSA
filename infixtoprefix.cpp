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
string infix_to_prefix(char *s){
    Stack<string>operand;
    Stack<char>operators;

    int i=0;
    while(s[i] !='\0'){
        if(s[i] >='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z'){
            string temp="";
            temp =temp +s[i];
            operand.push(temp);
        }
         else if(s[i]=='('){
                operators.push(s[i]);
            }
            else if(s[i] ==')'){
                while(!operators.isempty() && operators.getStacktop()!='('){
                    string op2=operand.pop();
                string op1=operand.pop();
                char o=operators.pop();
                string p="";
                p=o+op1+op2;
                operand.push(p);
                }
                if(!operators.isempty()){
                operators.pop();
                }
            }
        else if(s[i]=='+' || s[i]=='-' ||s[i]=='*' ||s[i]=='/' ||s[i]=='^' ){
            while(!operators.isempty() && precedence(operators.getStacktop())>=precedence(s[i])){
                string op1=operand.pop();
                string op2=operand.pop();
                char o=operators.pop();
                string p="";
                p=o+op2+op1;
                operand.push(p);
            }
            operators.push(s[i]);

           
        }
i++;
    }
    string p="";
    while(!operators.isempty()){
       string op2=operand.pop();
        string op1=operand.pop();
        char o=operators.pop();
         p="";
        p=o+op1+op2;
        operand.push(p);
}
    return operand.pop();

}
int main(){

    char s[] = "A+B*C";

    string result = infix_to_prefix(s);

    cout << "prefix: " << result;

    return 0;
}