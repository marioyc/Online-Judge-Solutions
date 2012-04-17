#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

int N,M[15][15],memo[15][15][(1 << 15)][2];

int solve(int r, int c, int mask, int diag){
    if(c == N) return solve(r + 1,0,mask,0);
    if(r == N) return 0;
    
    int &ret = memo[r][c][mask][diag];
    
    if(ret == -1){
        ret = solve(r,c + 1,mask & ~(1 << c),(mask & (1 << c))? 1 : 0);
        
        if(diag == 0 && (c == 0 || (mask & (1 << (c - 1))) == 0) && (mask & ((1 << c) | (1 << (c + 1)))) == 0)
            ret = max(ret,M[r][c] + solve(r,c + 1,mask | (1 << c),0));
    }
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    
    string line;
    
    while(getline(cin,line)){
        N = 0;
        istringstream is(line);
        
        while(is >> M[0][N]) ++N;
        
        if(N == 0) break;
        
        for(int i = 1;i < N;++i){
            getline(cin,line);
            istringstream is(line);
            int j = 0;
            
            while(is >> M[i][j]) ++j;
        }
        
        getline(cin,line);
        
        /*for(int i = 0;i < N;++i){
            for(int j = 0;j < N;++j) printf("%d ",M[i][j]);
            printf("\n");
        }*/
        
        memset(memo,-1,sizeof memo);
        cout << solve(0,0,0,0) << '\n';
    }
    
    return 0;
}
