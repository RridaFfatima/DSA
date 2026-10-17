#include <iostream>
#include <string>
using namespace std;
class dimensions{
    private:
int rows;
int columns;
int *data;

public:
 dimensions(int x, int y){
rows=x;
columns=y;
data = new int[rows* columns];
}
int index(int x, int y){
    int i = x * columns + y;
    return i;
}
};

int main(){
    dimensions D(2,3);
    int i=D.index(1,2);
    cout<<"indx is "<<i<<endl;
    return 0;

}

