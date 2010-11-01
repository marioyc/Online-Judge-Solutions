#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    --N;
    
    int Q[100],D[100],T[100];
    int depart[100][10];
    
    for(int i = 0,hh,mm;i<N;++i){
        scanf("%d %d %d",&Q[i],&D[i],&T[i]);
        
        for(int j = 0;j<Q[i];++j){
            scanf("%d:%d",&hh,&mm);
            depart[i][j] = 60*hh+mm;
        }
        
        sort(depart[i],depart[i]+Q[i]);
    }
    
    int t = 0;
    
    for(int i = 0;i<N;++i){
        int t2 = -1;
        
        for(int j = 0;j<Q[i];++j){
            int aux = (t-depart[i][j]-D[i]+1439)/1440*1440+depart[i][j]+D[i];
            if(t2==-1 || aux<t2) t2 = aux;
        }
        
        t = t2+T[i];
    }
    
    printf("%d\n",t);
    
    return 0;
}
