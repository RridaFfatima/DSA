#include<iostream>
#include <string>
using namespace std;
void selection_sort(int *a, int n){
    for(int i=1; i<n; i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
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