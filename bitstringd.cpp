#include<iostream>
#include<string>
using namespace std;
void func(string s, int len){
    if(s.length()==len ){
        cout<<s<<endl;;
        return;
    }
     func(s+"0",len);
     func(s+"1",len);

}
int main()
{
    func("", 3);
    return 0;
}