#include<iostream>
#include<string>
using namespace std;
void hanoi(int n, char s, char a, char d){
    if(n==1){
        cout<<" moved disk 1 from "<<s<<" to "<<d<<endl;
        return ;
    }
    hanoi(n-1,s,d,a);
    cout<<"moved disk "<<n<<" from " <<s<<" to "<<d<<endl;
 hanoi(n-1,a,s,d);

}
int main(){
    hanoi(3,'A','B','C');
    return 0;
}