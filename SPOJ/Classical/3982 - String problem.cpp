#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s1[1001],s2[1001];
int L1,L2,nxt2[1001][26];
int memo[1000][1000];

int solve(int pos1, int pos2){
    if(pos1 == L1) return 1005;
    
    int &ret = memo[pos1][pos2];
    
    if(ret == -1){
        ret = solve(pos1 + 1,pos2);
        
        int y = nxt2[pos2][ s1[pos1] - 'a' ];
        
        if(y == -1) ret = 1;
        else ret = min(ret,1 + solve(pos1 + 1,y + 1));
    }
    
    return ret;
}

int main(){
    scanf("%s %s",s1,s2);
    
    L1 = strlen(s1);
    L2 = strlen(s2);
    
    memset(nxt2[L2],-1,sizeof nxt2[L2]);
    
    for(int i = L2 - 1;i >= 0;--i){
        for(int j = 0;j < 26;++j) nxt2[i][j] = nxt2[i + 1][j];
        nxt2[i][ s2[i] - 'a' ] = i;
    }
    
    memset(memo,-1,sizeof memo);
    
    printf("%d\n",solve(0,0));
    
    return 0;
}
