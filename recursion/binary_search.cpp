#include<iostream>
#include<string>
using namespace std;
int binary_search(int *arr, int left, int right, int target){
    if(left>right){
        return -1;
    }
    int mid=(right+left)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(target>arr[mid]){
        return binary_search(arr,mid+1,right, target);

    }
else{
            return binary_search(arr,left, mid-1, target);

}
}
int main(){
    int a[]={1,4,6,3,0};
int r=binary_search(a,0,5,4);
cout<<r;
    return 0;
}