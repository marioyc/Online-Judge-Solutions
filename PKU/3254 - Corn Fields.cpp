#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 100000000

int R,C,M[12][12];
int memo[12][12][(1 << 12)];

int solve(int r, int c, int mask){
    if(r == R) return 1;
    
    int &ret = memo[r][c][mask];
    
    if(ret == -1){
        bool up = (mask & (1 << c))? 1 : 0;
        bool left = (c > 0 && (mask & (1 << (c - 1))))? 1 : 0;
        
        if(up) mask ^= (1 << c);
        
        ret = solve(r + (c == C - 1? 1 : 0),c == C - 1? 0 : c + 1,mask);
        
        if(!up && !left && M[r][c]) ret += solve(r + (c == C - 1? 1 : 0),c == C - 1? 0 : c + 1,mask | (1 << c));
        
        if(ret >= MOD) ret -= MOD;
    }
    
    return ret;
}

int main(){
    scanf("%d %d",&R,&C);
    
    for(int i = 0;i < R;++i)
        for(int j = 0;j < C;++j)
            scanf("%d",&M[i][j]);
    
    memset(memo,-1,sizeof memo);
    printf("%d\n",solve(0,0,0));
    
    return 0;
}
