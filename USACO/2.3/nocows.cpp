/*
ID:zion_ba1
LANG:C++
TASK:nocows
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int memo[200][100];

int solve(int n, int h){
    if(n==1) return 1;
    if(h==1) return 0;
    
    if(memo[n][h]!=-1) return memo[n][h];
    
    memo[n][h]=0;
    for(int i=1;i<n-1;i++) memo[n][h]=(memo[n][h]+solve(i,h-1)*solve(n-1-i,h-1))%9901;
    
    return memo[n][h];
}

int main(){
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    
    int N,K;
    scanf("%d %d",&N,&K);
    
    for(int i=0;i<=N;i++) fill(memo[i],memo[i]+K+1,-1);
    
    printf("%d\n",(solve(N,K)-solve(N,K-1)+9901)%9901);
    
    return 0;
}
