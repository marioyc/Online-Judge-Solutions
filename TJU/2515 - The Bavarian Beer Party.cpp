#include <cstdio>
#include <algorithm>

using namespace std;

int brand[1000],memo[1000][1000];

int solve(int s, int e){
    if(s>e) return 0;
    if(memo[s][e]!=-1) return memo[s][e];
    
    int aux = 0;
    
    for(int i=s+1;i<=e;i+=2)
        aux = max(aux,((brand[s]==brand[i])? 1 : 0)+solve(s+1,i-1)+solve(i+1,e));
    
    memo[s][e] = aux;
    return aux;
}

int main(){
    int T,n;
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        for(int i=0;i<n;++i) scanf("%d",&brand[i]);
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(0,n-1));
    }
    
    return 0;
}

