#include<iostream>
#include <string>
using namespace std;
bool linear_search(int *a, int size, int key){
    for (int i=0; i<size; i++){
        if(a[i]==key){
            return true;
        }
    }
            return false;
    }

int main(){
    int a[5]={1,2,3,4,5};
    bool r=linear_search(a,5,8);
    if(r){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    return 0;
}