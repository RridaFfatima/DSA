#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    ofstream fout("numbers.txt");
    ifstream fin("numbers.txt");
    if(!fout){
        cout<<"failed";
        return 0;
    }
    if(!fin){
        cout<<"failed";
        return 0;
    }
    for(int i=10; i< 60; i=i+10){
        fout<<i<<endl;
    }
    string n;
    int count=0;
    while(getline(fin,n)){
        cout<<n<<endl;
        count++;
    }
    cout<<" the count of lines read is: "<<count<<endl;
    fout.close();
    fin.close();
    return 0;
}