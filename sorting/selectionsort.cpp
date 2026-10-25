#include<iostream>
#include <string>
using namespace std;
void selection_sort(int *a, int n){
    for(int i=0; i<n; i++){
        int minindex=i;
        for(int j=i+1; j<n;j++){
        if(a[j]<a[minindex]){
        minindex=j;     
       }
    }
    if(minindex!=i){
    swap(a[minindex],a[i]);
    }
}
}
int main(){
    int a[5]={3,2,7,4,5};
    selection_sort(a,5);
    for(int i=0;i<5; i++){
            cout<<a[i]<<" ";

    }
    return 0;
}