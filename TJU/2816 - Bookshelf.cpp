#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int H[100],memo[100][100];

int solve(int n, int k){
    int &ret = memo[n][k];
    if(ret!=-1) return ret;    
    
    if(k==0){
        ret = 0;
        
        for(int i = 0;i<=n;++i)
            ret = max(ret,H[i]);
    }else{
        for(int i = n,h = 0;i>=k;--i){
            h = max(h,H[i]);
            
            int aux = h+solve(i-1,k-1);
            if(ret==-1 || aux<ret) ret = aux;
        }
    }
    
    return ret;
}

int main(){
    int N,K;
    
    while(true){
        scanf("%d %d",&N,&K);
        if(N==0) break;
        
        for(int i = 0;i<N;++i) scanf("%d",&H[i]);
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(N-1,K-1));
    }
    
    return 0;
}
