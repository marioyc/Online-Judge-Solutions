#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int cont,n,u,d,tot;
    
    while(1){
        scanf("%d %d %d",&n,&u,&d);
        
        if(n==0) break;
        
        cont=0;
        tot=0;
        
        while(1){
            cont+=u;
            tot++;
            if(cont>=n) break;
            tot++;
            cont-=d;
        }
        
        cout<<tot<<endl;
    }
}
