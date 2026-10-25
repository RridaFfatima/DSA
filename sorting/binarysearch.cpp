#include<iostream>
#include <string>
using namespace std;
bool binary_search(int *a, int size, int key){
    int start=0;
    int end=size-1;
    while(start<=end){
         int mid=(start+end)/2;
        if(a[mid]==key){
            return true;
        }
        else if(a[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return false;
}
int main(){
    int a[5]={1,2,3,4,5};
    bool r=binary_search(a,5,8);
    if(r){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    return 0;
}