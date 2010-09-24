#include<cstdio>
#include<iostream>

using namespace std;

#define QSIZE 200000

int Q[QSIZE],dist[QSIZE],start,end;

int min_moves(int N, int K){
    for(int i=0;i<QSIZE;i++) dist[i]=-1;
    
    start=0;
    Q[0]=N;
    dist[N]=0;
    end=1;
    
    int aux;
    
    while(1){
        aux=Q[start];
        start++;
        if(start==QSIZE) start=0;
        
        if(aux==K) return dist[aux];
        
        if(aux>0 && dist[aux-1]==-1){
            Q[end++]=aux-1;
            dist[aux-1]=dist[aux]+1;
        }
        
        if(aux<100000 && dist[aux+1]==-1){
            Q[end++]=aux+1;
            dist[aux+1]=dist[aux]+1;
        }
        
        if(2*aux<QSIZE && dist[2*aux]==-1){
            Q[end++]=2*aux;
            dist[2*aux]=dist[aux]+1;
        }
    }
}

int main(){    
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    if(K<=N) printf("%d\n",N-K);
    else printf("%d\n",min_moves(N,K));
    
    return 0;
}
