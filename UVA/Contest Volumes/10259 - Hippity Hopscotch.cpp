#include <cstdio>
#include <algorithm>

using namespace std;

int n,k;
int M[100][100];
int memo[100][100];

int solve(int r, int c){
    if(memo[r][c]!=-1) return memo[r][c];
    
    int r1=max(0,r-k),r2=min(r+k,n-1),c1=max(c-k,0),c2=min(c+k,n-1);
    
    int ans=0;
    
    for(int i=r1;i<=r2;i++)
        if(M[i][c]>M[r][c]) ans=max(ans,solve(i,c));
    
    for(int i=c1;i<=c2;i++)
        if(M[r][i]>M[r][c]) ans=max(ans,solve(r,i));
    
    ans+=M[r][c];
    memo[r][c]=ans;
    
    return ans;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&n,&k);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&M[i][j]);
        
        for(int i=0;i<n;i++)
            fill(memo[i],memo[i]+n,-1);
        
        if(tc!=1) printf("\n");
        printf("%d\n",solve(0,0));
    }
    
    return 0;
}
