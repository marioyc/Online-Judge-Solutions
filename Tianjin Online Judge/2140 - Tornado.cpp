#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int N,adelante,atras,cont,aux;
    bool todos_cero;
    int posts[5000];
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        todos_cero=true;
        
        for(int i=0;i<N;i++){
            scanf("%d",&posts[i]);
            todos_cero&=!posts[i];
        }
        
        if(todos_cero){
            printf("%d\n",(N+1)/2);
            continue;
        }
        
        cont=adelante=atras=0;
        
        for(int i=0;!posts[i];i++) adelante++;
        for(int i=N-1;!posts[i];i--) atras++;
        
        cont+=(adelante+atras)/2;
        
        aux=0;
        
        for(int i=adelante;i<N-atras;i++){
            if(posts[i]){
                cont+=aux/2;
                aux=0;
            }else aux++;
        }
        
        printf("%d\n",cont);
    }
    
    return 0;
}
