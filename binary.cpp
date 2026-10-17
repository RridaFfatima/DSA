#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int x = 50;

    ofstream fout("data.dat", ios::binary);

    fout.write((char*)&x, sizeof(x));

    fout.close();

    return 0;
}