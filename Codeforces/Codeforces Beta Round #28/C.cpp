#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

long long C[51][51];

long long comb(int n, int m){
    if(m==0 || n==m) return 1;
    
    long long &ret = C[n][m];
    if(ret==-1) ret = comb(n-1,m)+comb(n-1,m-1);
    
    return ret;
}

int a[50];
double memo[51][51][51];

double solve(int n, int m, int max_q){
    double &ret = memo[n][m][max_q];
    
    if(ret<-0.5){
        if(m==0) ret = max(max_q,(n+a[m]-1)/a[m]);
        else if(n==0) ret = max_q;
        else{
            ret = 0;
            
            for(int i = 0;i<=n;++i){
                double p = pow((double)1/(m+1),i)*pow((double)m/(m+1),(n-i));
                ret += p*comb(n,i)*solve(n-i,m-1,max(max_q,(i+a[m]-1)/a[m]));
            }
        }
    }
    
    return ret;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i<m;++i)
        scanf("%d",&a[i]);
    
    memset(C,-1,sizeof(C));
    
    for(int i = 0;i<=n;++i)
        for(int j = 0;j<=m;++j)
            for(int k = 0;k<=n;++k)
                memo[i][j][k] = -1.0;
    
    printf("%.11f\n",solve(n,m-1,0));
    
    return 0;
}
