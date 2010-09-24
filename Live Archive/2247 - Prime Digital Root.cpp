#include<iostream>
#include<iomanip>

using namespace std;

bool primo[1000000];

int root(int &N){
    if(primo[N]) return N;
    
    int sum;
    
    while(N>9){
        sum=0;
        while(N!=0){
            sum+=N%10;
            N/=10;
        }
        
        N=sum;
        
        if(primo[N]) return N;    
    }
    
    return -1;
};

int main(){    
    int N,aux;
    
    for(int i=0;i<1000000;i++) primo[i]=true;
    
    primo[0]=primo[1]=false;
    
    for(int i=2;i<1000000;i++)
        if(primo[i])
            for(int j=2;j*i<1000000;j++) primo[j*i]=false;
    
    while(1){
        cin>>N;
        if(N==0) break;
        
        cout<<setw(7)<<N<<" ";
        
        aux=root(N);
        
        if(aux==-1) cout<<setw(7)<<"none"<<endl;
        else cout<<setw(7)<<aux<<endl;
    }
    
    return 0;
}
