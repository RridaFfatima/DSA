#include<iostream>
#include "Stack.h"
#include<string>
#include<cmath>
using namespace std;

int evaluate(string s){
    Stack<int> c;
    int i=0;
    
for(int i=s.length()-1; i>=0; i--){
            if(s[i] >='0'  && s[i]<='9'){
            c.push(s[i]-'0');

        }
        else if(s[i]=='+' || s[i]=='-' ||s[i]=='*' ||s[i]=='/' ||s[i]=='^'){
            int op1=c.pop();
            int op2 = c.pop();
            switch(s[i]){
                case '+' :
                op1=op1+op2;
                c.push(op1);
                break;
                case '-' :
                op1=op2-op1;
                c.push(op1);
                break;
                case '*' :
                op1=op1*op2;
                c.push(op1);
                break;
                case '/' :
                op1=op2/op1;
                c.push(op1);
                break;
                case '^' :
                op1=pow(op2,op1);
                c.push(op1);
                break;
            }

        }
    }
    int r=0;
    while(!c.isempty()){
        r= c.pop();
    }
    return r;
}
int main(){
    char a[]="+5*83";
    int result=evaluate(a);
    cout<<"evaluated prefix is: "<<result<<endl;
    return 0;
}