#include<iostream>
#include "Stack.h"
#include<string>
using namespace std;
struct Pair{
    int i;
    int j;
};
void findpath( int r, int c, int a[][5], Pair s, Pair d){
    Stack<Pair> st (r*c);
    st.push(s);
    while(!st.isempty()){
        Pair curr= st.getStacktop();
        if(curr.i==d.i && curr.j==d.j){
            cout<<"path found"<<endl;
            return;
        }
        
    else if(curr.j-1>=0 && a[curr.i][curr.j-1]==0){
        a[curr.i][curr.j]=3;
        curr.j=curr.j-1;
        st.push(curr);

    }
    else if( curr.j+1<c && a[curr.i][curr.j+1]==0){
        a[curr.i][curr.j]=3;
        curr.j=curr.j+1;
        st.push(curr);
    }
    else if(curr.i-1>=0 && a[curr.i-1][curr.j]==0){
        a[curr.i][curr.j]=3;
        curr.i=curr.i-1;
        st.push(curr);
    }
    else if(curr.i+1<r && a[curr.i+1][curr.j]==0){
        a[curr.i][curr.j]=3;
        curr.i=curr.i+1;
        st.push(curr);
    }
    else if(curr.i-1>=0 && curr.j+1<c &&  a[curr.i-1][curr.j+1]==0){
        a[curr.i][curr.j]=3;
        curr.i=curr.i-1;
        curr.j=curr.j+1;
        st.push(curr);
    }
    else if(curr.i+1<r && curr.j-1>=0 &&  a[curr.i+1][curr.j-1]==0){
        a[curr.i][curr.j]=3;
        curr.i=curr.i+1;
        curr.j=curr.j-1;
        st.push(curr);
    }

    else{
        a[curr.i][curr.j]=3;
        st.pop();
    }
    }
}
int main(){
    int r=5;
    int c=5;
    Pair s;
    s.i=0;
    s.j=0;
    Pair d;
    d.i=3;
    d.j=4;
    int arr[5][5]={{0,0,0,0,0},{1,0,1,1,1},{0,0,0,0,0},{0,0,1,0,0},{0,1,1,0,0}};
    cout<<"starting maze search"<<endl;
    findpath(r,c,arr,s,d);
    return 0;
        }
   