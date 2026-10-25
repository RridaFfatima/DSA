#include<iostream>
#include<cstring>
#include "Stack.h"
using namespace std;
void check_string(char * s){
    Stack<char>c;
    int i=0;
    int j=0;
    int k=0;
    bool found_b=false;
    while(s[i]!='\0'){

        if(s[i]=='a'){
            if(found_b){
                cout<<"not of the form a^nb^n"<<endl;
                return;
            }
            c.push(s[i]);
            j++;
        }
        else if(s[i]=='b'){
            found_b=true;
            if(c.isempty()){
            cout<<"not of the form a^nb^n"<<endl;
                return;
            }
                c.pop();
                k++;
        }
        else{
                cout<<"not of the form a^nb^n"<<endl;
                return;
        }
        i++;
    }
    if(j==k){
        cout<<"is of the form a^nb^n"<<endl;
    }
    else{
         cout<<"not of the form a^nb^n"<<endl;

    }

}
int main(){
    char s []="aaabbb";
    check_string(s);
    char ss []="ababab";
    check_string(ss);
     char sss []="bbbaaa";
    check_string(sss);
    return 0;

}