#include<iostream>
#include<string>
#include<cmath>
#include<stdexcept>
using namespace std;
class term{
    public:
    int cofficient;
    int exponent;
    term(int cofficient=0,int exponent=0){
        this->cofficient=cofficient;
        this->exponent=exponent;
    }
    ~term(){}
};
class polynomials{
       public:

    term* t;
    int size;
    int capacity;
    friend ostream& operator <<(ostream &out, const polynomials &p);
    polynomials(int size=0){
       this-> capacity=size;
       this->size=0;
       this-> t =new term[this->capacity];

       
    }

    void addTerm(int cofficient, int power){
        if(power<0){
            throw runtime_error("polynomial power cant be negative");
        }
        if(cofficient==0){
            return;
        }
        for(int i=0; i<size; i++){
            if (t[i].exponent==power){
                t[i].cofficient+=cofficient;
                return;
            }

        }
        if(size>=capacity){
            return ;
        }
        t[size].cofficient=cofficient;
        t[size].exponent=power;
        size++;
    }
    
    
    int getDegree(){
        return t[0].exponent;

    }
    int getCoefficient(int power){
        int index=0;
        for(int i=0; i<size; i++){
        if (power == t[i].exponent){
            //return t[i].cofficient;
             index =i;
        }
    }
        return t[index].cofficient;

    }

    int Operater(int value){
        int result=0;
        for(int i=0; i<size; i++){
            result+=t[i].cofficient * (pow(value,t[i].exponent));
        }
        return result;
    }
    ~polynomials(){
        delete []t;

    }

    polynomials(const polynomials &ref){
        size=ref.size;
        capacity=ref.capacity;
        this->t =new term[this->size];
        for(int i=0; i<this->size; i++){
        t[i]=ref.t[i];
       }

    }

    polynomials operator +(polynomials p2){
    polynomials result(20);
       int i=0; int j=0;
        while(i<size && j<p2.size){
            int cofficient=0;
            int exponent=0;
        if(t[i].exponent==p2.t[j].exponent){

            cofficient= t[i].cofficient+p2.t[j].cofficient;
            exponent=p2.t[j].exponent;
            result.addTerm(cofficient,exponent);
            i++;
            j++;
           
        }
    else if(t[i].exponent>p2.t[j].exponent){
        
        result.addTerm(t[i].cofficient, t[i].exponent);
        i++;

        
    }
        else{
             result.addTerm(p2.t[j].cofficient, p2.t[j].exponent);
             j++;

        }
        }
        while(i<size){
            result.addTerm(t[i].cofficient,t[i].exponent);
            i++;
        }
         while(j<size){
            result.addTerm(p2.t[i].cofficient,p2.t[i].exponent);
            j++;
        }
    return result;
}
    
    void addToCoefficient(int coefficient, int power){
        for(int i=0; i<size; i++){
            if(t[i].exponent==power){
                t[i].cofficient+=coefficient;
            }
        }
    }
    void clear(){
        for(int i=0; i<size; i++){
            t[i].cofficient=0;
        }
    }
    void setCoefficient(int newCoefficient, int power){
        for(int i=0; i<size; i++){
            if(t[i].exponent==power){
                t[i].cofficient=newCoefficient;
                return;
            }
            
        }
        
                addTerm(newCoefficient,power);
            
        
    }

    polynomials operator -(polynomials p2){
       polynomials result(20);
       int i=0; int j=0;
        while(i<size && j<p2.size){
            int cofficient=0;
            int exponent=0;
        if(t[i].exponent==p2.t[j].exponent){

            cofficient= t[i].cofficient-p2.t[j].cofficient;
            exponent=p2.t[j].exponent;
            result.addTerm(cofficient,exponent);
            i++;
            j++;
           
        }
    else if(t[i].exponent>p2.t[j].exponent){
        
        result.addTerm(t[i].cofficient, t[i].exponent);
        i++;

        
    }
        else{
             result.addTerm(-p2.t[j].cofficient, p2.t[j].exponent);
             j++;

        }
        
        }
        while(i<size){
            result.addTerm(t[i].cofficient,t[i].exponent);
            i++;
        }
         while(j<size){
            result.addTerm(-p2.t[i].cofficient,p2.t[i].exponent);
            j++;
        }

    

        
    return result;
}
    
    
polynomials operator *(polynomials p2){
        polynomials result (100);
        
        for(int i=0; i<size ; i++){
            for(int j=0; j<p2.size; j++){
                int cofficient=0;
                int exponent=0;
                cofficient= t[i].cofficient*p2.t[j].cofficient;
                exponent=t[i].exponent +p2.t[j].exponent ;

                    result.addTerm(cofficient,exponent); 
                       

        }
    }
    for(int i=0; i<result.size-1; i++){
        for(int j=0; j<result.size-1-i; j++){
            if(result.t[j].exponent<result.t[j+1].exponent){
                term temp;
                temp=result.t[j+1];
                result.t[j+1]=result.t[j];
                result.t[j]=temp;


            }
        }
    }
    return result;
}
        

    



polynomials antiderivative(){
    polynomials d(20);
    for(int i=0; i<size; i++){
        int ccoficient=0;
        int eexponent=0;
        ccoficient=t[i].cofficient/((t[i].exponent )+1);
         eexponent=(t[i].exponent)+1;
         d.addTerm(ccoficient,eexponent);
    }
    return d;


}

polynomials derivative(){
     polynomials d(20);
    for(int i=0; i<size; i++){
        int ccofficient=0;
        int eexponent=0;
        if(t[i].exponent ==0){
        continue;
        }
        
        ccofficient=t[i].cofficient*t[i].exponent;
        
        eexponent=(t[i].exponent)-1;
         d.addTerm(ccofficient,eexponent);

    }
    return d;
}
};


ostream& operator <<(ostream &out, const polynomials &p){
    if(p.size==0){
        out<<"0"<<endl;
        return out;
    }
    for(int i=0; i<p.size; i++){
        if(p.t[i].cofficient==0){
            continue;
        }
       
        if(i==0){
            if(p.t[i].cofficient<0){
                if(p.t[i].exponent==0){
                out<<p.t[i].cofficient;
                }
                    else if(p.t[i].exponent==1){
                        out<<p.t[i].cofficient<<"x";
                        }
                        else if (p.t[i].cofficient==1){
                            out<<"x^"<<p.t[i].exponent;
                        }
                        else{
                        out<<p.t[i].cofficient<<"x^"<<p.t[i].exponent;
            }
        }
            else{
                 if(p.t[i].exponent==0){
                out<<p.t[i].cofficient;
                }
                    else if(p.t[i].exponent==1){
                        out<<p.t[i].cofficient<<"x";
                        }
                        else if (p.t[i].cofficient==1){
                            out<<"x^"<<p.t[i].exponent;
                        }
                        else{
                        out<<p.t[i].cofficient<<"x^"<<p.t[i].exponent;
            }

            }
        }
        else{
            if(p.t[i].cofficient>0){
                if(p.t[i].exponent==0){
                out<<"+"<<p.t[i].cofficient;
                }
                        else if(p.t[i].exponent==1){
                        out<<"+"<<p.t[i].cofficient<<"x";
                        }
                        else if (p.t[i].cofficient==1){
                            out<<"+x^"<<p.t[i].exponent;
                        }
                        else{
                         out<<"+"<<p.t[i].cofficient<<"x^"<<p.t[i].exponent;
                        }
            }
            else{
                if(p.t[i].exponent==0){
                 out<<p.t[i].cofficient;
                }
                        else if(p.t[i].exponent==1){
                        out<<p.t[i].cofficient<<"x";
                        }
                        else if (p.t[i].cofficient==1){
                            out<<"x^"<<p.t[i].exponent;
                        }
                        else{
                         out<<p.t[i].cofficient<<"x^"<<p.t[i].exponent;
                        }
            }
        }
     
    }
    return out;
}
int main(){
    polynomials p1(4);
    polynomials p2(4);

    try{
    p1.addTerm(2,3);
    p1.addTerm(5,2);
    p1.addTerm(-1,1);
    p1.addTerm(-7,0);



    p2.addTerm(3,4);
    p2.addTerm(-2,2);
    p2.addTerm(3,1);
     p2.addTerm(-5,0);

    }
    catch(runtime_error &r){
        cout<<"caught an error: "<<r.what()<<endl;
    }
    cout<<"p1: "<<p1<<endl;
    cout<<"p2: "<<p2<<endl;
    polynomials p8=p1;
    cout<<"copying p1 in p8: "<<p8<<endl;
    polynomials p3=p1+p2;
    polynomials p4=p2-p1;
    polynomials p5=p1*p2;
    cout<<"sum of p1+p2: "<<endl;;
    cout<<p3<<endl;
    cout<<"subtraction of p2-p1: "<<endl;
    cout<<p4<<endl;
    cout<<"multiplication of p1 *p2: "<<endl;
    cout<<p5<<endl;
    p1.addToCoefficient(3,2);
    cout<<"after adding cofficient 3 to x^2 in p1: "<<endl;
    cout<<p1<<endl;
    
    polynomials p6 =p1.derivative();
    cout<<"derivative of p1: "<<endl;;
    cout<<p6<<endl;

    polynomials p7 =p2.antiderivative();
    cout<<"antiderivative of p2: "<<endl;
    cout<<p7<<endl;

    cout<<"cofficient of x^2 in p3: ";
    cout<<p3.getCoefficient(2);
    cout<<endl;
    
    cout<<"degree of p3: "<<p3.getDegree();
    cout<<endl;

    p3.setCoefficient(4,2);
    cout<<"p3 after setting cofficient of x^2 as 4  : " <<p3<<endl;
    cout<<"p1: "<<p1<<endl;
    cout<<"evaluating p1 with x=2: "<<p1.Operater(2)<<endl;
    p2.clear();
    cout<<"cofficient of x^2 in p2 after clearing sl, cofficients to 0: "<<p2.getCoefficient(2);
    
    


    return 0;


}