#include<iostream>
#include <string>
#include "Stack.h"
using namespace std;
void bubble_sort(Stack<int> &s){
    Stack<int>temp;
    Stack<int>sorted;
    int c;
    while(!s.isempty()){
         c=s.pop();
    
    while(!temp.isempty() && c<temp.getStacktop())
{
    sorted.push(temp.pop());
}
temp.push(c);
while(!sorted.isempty()){
    temp.push(sorted.pop());

}
    }

while(!temp.isempty()){
    sorted.push(temp.pop());

}
while(!sorted.isempty()){
    s.push(sorted.pop());

}
}
int main(){
    Stack<int> s ;
    s.push(3);
     s.push(5);
    s.push(4);
    s.push(7);

    bubble_sort(s);
    for(int i=0;i<5; i++){
            cout<<s.pop()<<" ";

    }
    return 0;
}