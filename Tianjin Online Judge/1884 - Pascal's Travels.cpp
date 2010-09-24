#include<cstdio>
#include<algorithm>

using namespace std;

char board[34][34];
long long memo[34][34];
int n;

long long paths(int I, int J){
    if(I>=n || J>=n) return 0;
    if(I==n-1 && J==n-1) return 1;
    if(board[I][J]=='0') return 0;
    
    if(memo[I][J]!=-1) return memo[I][J];
    
    memo[I][J]=paths(I+board[I][J]-'0',J)+paths(I,J+board[I][J]-'0');
    
    return memo[I][J];
}

int main(){
    while(1){
        scanf("%d\n",&n);
        if(n==-1) break;
        
        for(int i=0;i<n;i++) scanf("%s",board[i]);
        
        for(int i=0;i<n;i++) fill(memo[i],memo[i]+n,-1);
        
        printf("%lld\n",paths(0,0));
    }
    
    return 0;
}
