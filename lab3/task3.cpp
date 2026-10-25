#include<iostream>
#include<cstring>
#include "Stack.h"
using namespace std;
void brackets(char * s){
    Stack<char> c;
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            c.push(s[i]);
        }
         else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(c.isempty()){
                cout<<"bad"<<endl;
                return ;
            }
                char p=c.getStacktop();
                c.pop();
                if(p!='(' && s[i]==')' || p!='{' && s[i]=='}' || p!='[' && s[i]==']'){
                    cout<<"bad"<<endl;
                    return;
                }
                
            
        }
        i++;
    }
    if(c.isempty()){
        cout<<"good"<<endl;
    }
    else{
        cout<<"bad"<<endl;
    }
    return ;

}
int main(){
    char s [] ="(5+}";
    brackets(s);
    char r [] ="(5+6)";
    brackets(r);
    return 0;
}