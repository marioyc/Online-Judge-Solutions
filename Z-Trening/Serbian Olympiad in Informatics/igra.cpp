#include <cstdio>
#include <algorithm>

using namespace std;

int a[128],memo[128][128];

int solve(int n, int m){
    if(n==m) return a[n];
    if(n>m) return 0;
    
    if(memo[n][m]!=-1) return memo[n][m];
    
    memo[n][m]=max(a[n]+min(solve(n+2,m),solve(n+1,m-1)),a[m]+min(solve(n,m-2),solve(n+1,m-1)));
    
    return memo[n][m];
}

int main(){    
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            memo[i][j]=-1;
    
    printf("%d\n",solve(0,n-1));
    
    return 0;
}
