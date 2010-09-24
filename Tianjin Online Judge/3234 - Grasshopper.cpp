#include <cstdio>
#include <algorithm>

using namespace std;

int N,M[100][100];
int memo[100][100];

int solve(int r, int c){
    if(memo[r][c]!=-1) return memo[r][c];
    
    int ans=0;
    
    if(r>0){
        for(int i=0;i<N;i++)
            if(abs(c-i)>1 && M[r-1][i]>M[r][c]) ans=max(ans,1+solve(r-1,i));
    }
    
    if(r<N-1){
        for(int i=0;i<N;i++)
            if(abs(c-i)>1 && M[r+1][i]>M[r][c]) ans=max(ans,1+solve(r+1,i));
    }
    
    if(c>0){
        for(int i=0;i<N;i++)
            if(abs(r-i)>1 && M[i][c-1]>M[r][c]) ans=max(ans,1+solve(i,c-1));
    }
    
    if(c<N-1){
        for(int i=0;i<N;i++)
            if(abs(r-i)>1 && M[i][c+1]>M[r][c]) ans=max(ans,1+solve(i,c+1));
    }
    
    memo[r][c]=ans;
    return ans;
}

int main(){
    int R,C;
    
    scanf("%d %d %d",&N,&R,&C);
    R--; C--;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&M[i][j]);
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            memo[i][j]=-1;
    
    printf("%d\n",1+solve(R,C));
    
    return 0;
}
