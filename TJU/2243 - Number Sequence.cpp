#include<cstdio>

using namespace std;

int memo[1001];

int length(int n){
    if(n==1) return 1;
    if(n>1000){
        if(n%2==0) return 1+length(n/2);
        return 1+length(3*n+1);
    }
    
    if(memo[n]!=-1) return memo[n];
    
    int aux;
    
    if(n%2==0) aux=1+length(n/2);
    else aux=1+length(3*n+1);
    
    memo[n]=aux;
    
    return aux;
}

int main(){    
    int N;
    
    for(int i=1;i<1001;i++) memo[i]=-1;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        printf("%d\n",length(N));
    }
    
    return 0;
}
