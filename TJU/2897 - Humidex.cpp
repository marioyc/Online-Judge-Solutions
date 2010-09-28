#include<iostream>
#include<cmath>

using namespace std;

double h,e;

double calcularH(double T, double D){
    e=6.11*exp(5417.753*(1/273.16 - 1/(D+273.16)));
    h=0.5555*(e-10.0);
    
    return T+h;
}

double calcularT(double H, double D){
    e=6.11*exp(5417.753*(1/273.16 - 1/(D+273.16)));
    h=0.5555*(e-10.0);
    
    return H-h;
}

double calcularD(double H, double T){
    h=H-T;
    e=h/0.5555+10.0;
    
    double D=1/(1/273.16 - 1/5417.753*log(e/6.11))-273.16;
    
    return D;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    char c1,c2;
    double n1,n2;
    double T,H,D;
    
    while(1){
        cin>>c1;
        if(c1=='E') break;
        
        cin>>n1>>c2>>n2;
        
        if(c1=='T' && c2=='H'){
            T=n1;
            H=n2;
            D=calcularD(n2,n1);
        }else if(c1=='H' && c2=='T'){
            H=n1;
            T=n2;
            D=calcularD(n1,n2);
        }else if(c1=='T' && c2=='D'){
            T=n1;
            D=n2;
            H=calcularH(n1,n2);
        }else if(c1=='D' && c2=='T'){
            D=n1;
            T=n2;
            H=calcularH(n2,n1);
        }else if(c1=='H' && c2=='D'){
            H=n1;
            D=n2;
            T=calcularT(n1,n2);
        }else{
            D=n1;
            H=n2;
            T=calcularT(n2,n1);
        }
        
        printf("T %.1f D %.1f H %.1f\n",T,D,H);      
    }
    
    return 0;
}
