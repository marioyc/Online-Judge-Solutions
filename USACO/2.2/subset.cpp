/*
ID:zion_ba1
LANG:C++
TASK:subset
*/

#include <iostream>

using namespace std;

int memo[391][40];

int count(int S, int n){
    if(S<0) return 0;
    
    if(n==0){
        if(S==0) return 1;
        return 0;
    }
    
    if(memo[S][n]!=-1) return memo[S][n];
    
    memo[S][n]=count(S-n,n-1)+count(S,n-1);
    
    return memo[S][n];
}

int main(){
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    
    int N;
    scanf("%d",&N);
    
    if(N%4==1 || N%4==2) printf("0\n");
    else{
        int S=N*(N+1)/4-N;
        
        for(int i=0;i<=S;i++)
            for(int j=0;j<N;j++)
                memo[i][j]=-1;
        
        printf("%d\n",count(S,N-1));
    }
    
    return 0;
}
