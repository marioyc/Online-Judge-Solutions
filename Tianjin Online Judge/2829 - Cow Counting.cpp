#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,L,aux;
    bool ok;
    
    scanf("%d %d",&N,&L);
    
    for(int i=1,cont=0;;i++){
        aux=i;
        
        ok=true;
        
        while(aux!=0 && ok){
            if(aux%10==L) ok=false;
            aux/=10;
        }
        
        if(ok) cont++;
        
        if(cont==N){
            printf("%d\n",i);
            break;
        }
    }
    
    return 0;
}
