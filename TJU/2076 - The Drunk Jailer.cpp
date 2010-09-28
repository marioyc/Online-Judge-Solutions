#include<iostream>

using namespace std;

int aux;

int num_div(int a){
    aux=0;
    
    for(int i=1;i<=a;i++)
        if(a%i==0) aux++;
    
    return aux;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int div[101];
    int t,n,cont;
    
    for(int i=1;i<=100;i++)
        div[i]=num_div(i);
    
    cin>>t;
    
    for(int caso=0;caso<t;caso++){
        cin>>n;
        
        cont=0;
        for(int i=1;i<=n;i++)
            if(div[i]%2==1) cont++;
        
        cout<<cont<<endl;
    }
    
    return 0;
}
