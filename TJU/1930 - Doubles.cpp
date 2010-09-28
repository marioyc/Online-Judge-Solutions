#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int M[15];
    int n,ax;
    bool N[100];
    
    while(1){
        cin>>ax;
        n=0;
        memset(N,0,sizeof(N));        
        
        if(ax==-1) break;
        
        while(ax!=0){
            M[n++]=ax;
            N[ax]=1;
            cin>>ax;
        }
        
        ax=0;
        
        for(int i=0;i<n;i++){
            if(M[i]%2==0 && N[M[i]/2]) ax++;
        }
        
        cout<<ax<<endl;
    }
    
    return 0;
}
