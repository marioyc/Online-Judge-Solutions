#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int black[501],memo[500][501];
 
int solve(int k, int n){
    if(k==0) return black[n]*(n-black[n]);
    
    int &ret = memo[k][n];
    
    if(ret==-1){
        for(int i = 1;n-i>=k-1 && i<=n;++i){
            int aux = (black[n]-black[n-i])*(i-black[n]+black[n-i])+solve(k-1,n-i);
            if(ret==-1 || aux<ret) ret = aux;
        }
    }
    
    return ret;
}
 
int main(){
    int N,K;
    scanf("%d %d",&N,&K);
    
    black[0] = 0;
    
    for(int i = 0,x;i<N;++i){
        scanf("%d",&x);
        black[i+1] = black[i];
        if(x==1) ++black[i+1];
    }
    
    memset(memo,-1,sizeof(memo));
    printf("%d\n",solve(K-1,N));
    
    return 0;
}
