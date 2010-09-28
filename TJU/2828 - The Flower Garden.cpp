#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int F,K,L,I,cont;
    bool garden[10000];
    
    scanf("%d %d",&F,&K);
    
    fill(garden,garden+F,0);
    
    for(int i=0;i<K;i++){
        scanf("%d %d",&L,&I);
        
        for(int j=L-1;j<F;j+=I) garden[j]=1;
    }
    
    cont=0;
    
    for(int i=0;i<F;i++)
        if(!garden[i]) cont++;
    
    printf("%d\n",cont);
    
    return 0;
}
