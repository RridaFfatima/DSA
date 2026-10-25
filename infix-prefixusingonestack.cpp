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
string reverse(string s) {
    string temp = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            temp += ')';
        } else if (s[i] == ')') {
            temp += '(';
        } else {
            temp += s[i];
        }
    }
    return temp;
}
string infix_to_prefix(char *s){
    Stack<char> c;
    int i=0;
    string pre="";
    string rs=reverse(string(s));
    while(rs[i]!='\0'){
        if(rs[i]>='A' && rs[i]<='Z' || rs[i]>='a' && rs[i]<='z' || rs[i]>='0' && rs[i]<='9'){
            pre+=rs[i];
        }
        else if(rs[i]=='+'|| rs[i]=='-' || rs[i]=='*' || rs[i]=='/' ||rs[i]=='^'){
            while(!c.isempty()&& precedence(c.getStacktop())>= precedence(rs[i])){
                char op =c.pop();
                pre=pre+op;
            }
            if(rs[i]!=')'){
                c.push(rs[i]);
            }
             if(rs[i]==')'){
                while(!c.isempty() && c.getStacktop()!='('){
                    char o=c.pop();
                    pre=pre+o;

                }
                c.pop();
             }
        }
        i++;
    }
    while(!c.isempty()){
        char f=c.pop();
        pre=pre+f;
    }
    string rpre=reverse(pre);
return rpre;
}
int main(){

    char s[] = "A+B*C";

    string result = infix_to_prefix(s);

    cout << "prefix: " << result;

    return 0;
}