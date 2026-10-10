#include<iostream>
#include<string>
using namespace std;
string reverse(string s , int len){
    if(len <=0){
        return "";
    }
    return s[len-1] + reverse(s,len-1);
}
int main(){
    string s ="abc";
    string ss=reverse(s,3);
    cout<<ss;
    return 0;
}