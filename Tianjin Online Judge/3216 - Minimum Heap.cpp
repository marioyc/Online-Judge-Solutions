#include <cstdio>
#include <algorithm>

using namespace std;

int left[1001],right[1001],C[1001][1001],M;
long long memo[1001];

long long f(int N){
    if(N<=2) return 1;
    
    if(memo[N]!=-1) return memo[N];
    
    //we can put the second lowest element at the left or right of the lowest element(father)
    memo[N]=(((1LL*C[N-2][right[N]-1]*C[right[N]-1][left[right[N]]])%M*(((f(left[N])*f(left[right[N]]))%M*f(right[right[N]]))%M))%M+((1LL*C[N-2][left[N]-1]*C[left[N]-1][left[left[N]]])%M*(((f(left[left[N]])*f(right[left[N]]))%M*f(right[N]))%M))%M)%M;
    
    return memo[N];
}

int main(){
    left[0]=right[0]=left[1]=right[1]=0;
    int aux,pot,sum=1;
    
    for(int i=1;i<=10;i++){
        aux=0;
        pot=(1<<i);
        for(int j=(1<<i);j<(1<<(i+1)) && j<=1000;j++){
            left[j]=(sum-1)/2;
            aux++;
            if(aux<=pot/2) left[j]+=aux;
            else left[j]+=pot/2;
            
            right[j]=j-1-left[j];
        }
        sum+=pot;
    }
    
    int T,N;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&N,&M);
        
        C[0][0]=1;
        
        for(int j=1;j<=N;j++){
            C[j][0]=1;
            for(int k=1;k<=N;k++) C[j][k]=(C[j-1][k]+C[j-1][k-1])%M;
        }
        
        memset(memo,-1,sizeof(memo));
        
        printf("%d\n",f(N));
    }
    
    return 0;
}
