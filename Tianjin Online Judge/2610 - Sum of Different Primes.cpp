#include<cstdio>
#include<vector>

using namespace std;

int memo[1121][15][187];
int p[187];

int f(int n, int k, int m){
    if(n==0 && k==0) return 1;
    if(k==0) return 0;
    if(n<p[m]) return 0;
    if(m>=187) return 0;
    
    if(memo[n][k][m]!=-1) return memo[n][k][m];
    
    int cont=f(n-p[m],k-1,m+1)+f(n,k,m+1);
    
    memo[n][k][m]=cont;
    
    return cont;
}

int main(){
    int n,k,cont=0;
    bool primo;
    
    memset(memo,-1,sizeof(memo));
    
    for(int i=2;i<1121;i++){
        primo=false;
        
        for(int j=0;j<cont;j++){
            if(i%p[j]==0){
                primo=true;
                break;
            }
        }
        
        if(!primo) p[cont++]=i;
    }
    
    while(1){
        scanf("%d %d",&n,&k);
        if(n==0 && k==0) break;
        
        printf("%d\n",f(n,k,0));
    }
    
    return 0;
}
