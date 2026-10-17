#include<iostream>
#include<string>
#include<fstream>

using namespace std;
class  Matrix{
        public:

    int rows;
    int cols;
    int **data;

    Matrix(int rows=0, int cols=0){
        this->rows=rows;
        this->cols=cols;
        if(rows>0 && cols>0){

        
        data= new int* [rows];
        
        for(int i=0; i<rows; i++){
            data[i]==new int [cols];
        
        for(int j=0; j<cols; j++){
            data[i][j]=0;
        }
    }
}
    else{
        data=nullptr;
    }
    }

    ~Matrix(){
        for(int i=0; i<rows; i++){
            delete [] data[i];
        }
        delete [] data;
    }
    void setvalue(int r, int c, int value){
        data[r][c]=value;
    }
    int getvalue(int r, int c)const{
        return data[r][c];
    }
    void display()const{
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int* operator [](int index){
        return data[index];
    }
    int* operator [](int index)const{
        return data[index];
    }
    void readfromfile(const char * filename){
    
    ifstream fin(filename);
    if(!fin){
        cout<<"file not open"<<endl;
        return;
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            fin>>data[i][j];
        }
    }
    fin.close();
    }
};
class sparsematrix{
    int nonzero;
    const int cols{3};
    int **s_mat;
    public:
    sparsematrix(int nonzero=0){
        this->nonzero=nonzero;
        if(this->nonzero>0){
        s_mat=new int *[this->nonzero];
        for(int i=0; i<this->nonzero; i++){
            s_mat[i]= new int [cols];
        }
        }
        else{
            s_mat=nullptr;
        }
    }
~sparsematrix(){
        for(int i=0; i<nonzero; i++){
            delete [] s_mat[i];
        }
        delete [] s_mat;
    }
void read(const Matrix &m){
    nonzero=0;
    for(int i=0; i<m.rows; i++){
        for(int j=0; j<m.cols; j++){
            if(m.data[i][j]!=0){
                nonzero++;
            }
        }
    }
    s_mat=new int *[nonzero];
    for(int i=0; i<nonzero; i++){
        s_mat[i]=new int[cols];
    }
    int k=0;
    for(int i=0; i<m.rows; i++){
        for(int j=0; j<m.cols; j++){
            if(m[i][j]!=0)
            {
                s_mat[k][0]=i;
                s_mat[k][1]=j;
                s_mat[k][2]=m[i][j];
                k++;
            }

        }    }
}
void display()const{
    cout<<"row \t"<<"column\t"<<"value\t"<<endl;
    for(int i=0; i<nonzero; i++){
        cout<<s_mat[i][0];
         cout<<s_mat[i][1];
        cout<<s_mat[i][2];
    }
    cout<<endl;
}
Matrix addSparseMatrix(const sparsematrix other, int rows,int cols){
    Matrix m(rows,cols);
    for(int i=0; i<nonzero; i++){
        int r=s_mat[i][0];
         int c=s_mat[i][1];
        int v=s_mat[i][2];
        m[r][c]=v;
    }
    for(int i=0; i<other.nonzero; i++){
        int r=other.s_mat[i][0];
         int c=other.s_mat[i][1];
        int v=other.s_mat[i][2];
        m[r][c]+=v;
    }
    
return m;
}
    
};
