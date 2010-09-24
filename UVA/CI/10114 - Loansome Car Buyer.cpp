#include<iostream>

using namespace std;

int main(){
    int meses;
    int num;
    int cont;
    int n;
    double pago;
    double prestamo;
    double value;
    double debe;
    double porc;
    double mensual;
    double L[150];

    while(1){
        cin>>meses>>pago>>prestamo>>num;
        
        if(meses<0) break;
        
        fill(L,L+150,-1.0);
        
        for(int i=0;i<num;i++){
            cin>>n>>porc;
            L[n]=porc;
        }
        
        for(int i=1;i<150;i++)
            if(L[i]==-1.0) L[i]=L[i-1];
        
        mensual=prestamo/meses;
        value=prestamo+pago;
        debe=prestamo;
        cont=0;
        
        while(1){
            value*=(1-L[cont]);
            
            if(debe<value){
                cout<<cont;
                if(cont==1) cout<<" month"<<endl;
                else cout<<" months"<<endl;
                break;
            }
            
            debe-=mensual;
            cont++;
        }
    }

    return 0;
}
