#include<iostream>
#include<string>
using namespace std;
void func( int n){
    if(n<=0 ){
        return;
    }
     func(n-1);
     for(int i=0;i<n; i++){
     cout<<'*';
     }
     cout<<endl;
     

}
int main()
{
    func( 3);
    return 0;
}