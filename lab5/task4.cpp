#include<iostream>
#include<string>
using namespace std;
int func (int cx, int cy,int x, int y,int k){
    if(k<1){
        return;
    }
    int size=k/2;
    if(k==1){
        return;
    }
    int count=0;
    if(x>=cx-k && x<=cx+k && y>=cy-k && y<=cy+k){
        count ++;
    }
    count+=func(cx+k, cy+k,x,y,size);
    count+=func(cx+k,cx-k,x,y,size);
    count+=func(cx-k, cy+k,x,y,size);
    count+=func(cx-k, cy-k,x,y,size);
    return count;
}
int main()
{
    int k, x, y;

    cin >> k;
    cin >> x >> y;

    if (k < 1 || k > 512 ||
        x < 0 || x > 2048 ||
        y < 0 || y > 2048)
    {
        cout << "Invalid input";
        return 0;
    }

    int count=func(k, 1024, 1024, x, y);

    cout<< count << endl;

    return 0;
}