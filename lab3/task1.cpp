#include<iostream>
#include<cstring>
#include "Stack.h"
using namespace std;
void palindrome(string s){
Stack <char> c;
int i=0;
string b;
for(int i=0; i<s.length(); i++){
    if(s[i]!=' ' || s[i]>='A' || s[i]<='Z' || s[i]>='a' || s[i]=='z' || s[i]>='0' || s[i]<='9'){
        if(s[i]>='A' && s[i]<='Z'){
        s[i]=s[i]-'A' + 'a';
    }
    b+=s[i];
    }
}
bool p=true;
for(int i=0; i<b.length(); i++){
c.push(b[i]);
}
for(int i=0; i<b.length(); i++){

    char p=c.pop();
if(!c.isempty()){
    if(b[i]==p){
         p=true;
    }
}
else{
p=false;
}
}
if(p){
    cout<<"is palindrme"<<endl;
}
else{
    cout<<"not"<<endl;
}
}

int main(){
    string s="1221";
    palindrome(s);
    string r="Dad";
    palindrome(r);
    string ss=  "Do geese see God?";
    palindrome(ss);


    return 0;
}