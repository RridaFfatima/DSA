#include<iostream>
#include<string>
#include "Stack.h"
using namespace std;
Stack<string>c;
void visitpage(string s){
        c.push(s);

}
void goback(){
    cout<<"browser history: ";
    if(c.isempty()){
        cout<<"no prev page"<<endl;
    }
string p=c.getStacktop();
c.pop();
string pp=c.getStacktop();
cout<<"going back to: "<<pp<<endl;
}
void display(){
    while(!c.isempty()){
        string p=c.getStacktop();
        c.pop();
        cout<<p<<endl;
    }
    cout<<"no histroy available"<<endl;
}
void exitt(){
    while(!c.isempty()){
        c.pop();
    }
    return;
}
int main(){
    bool flag=true;
    while(flag){
    cout<<"1. Visit Page"<<endl;
    cout<<"2. Go Back"<<endl;
    cout<<"3. Display History"<<endl;
    cout<<"4. Exit"<<endl;
    int n=0;
    cout<<"Enter choice: ";
    cin>>n;
    if(n==1){
        cout<<"Enter page: ";
        string s;
        cin>>s;
        visitpage(s);
    }
    if(n==2){
        goback();
    }if(n==3){
        display();
    }if(n==4){
        exitt();
        flag= false;
    }
    }
    return 0;
}