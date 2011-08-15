#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[1001],T[1001];
int memo[1000][1000],pos1[1000][26],pos2[1000][26];

int solve(int n, int m){
    if(n < 0 || m < 0) return m + n + 2;
    
    int &ret = memo[n][m];
    
    if(ret == -1){
        ret = min(1 + min(solve(n,m-1),solve(n-1,m)),(S[n] == T[m]? 0 : 1) + solve(n-1,m-1));
        
        int a = pos1[n][T[m]-'a'],b = pos2[m][S[n]-'a'];
        
        if(a != -1 && b != -1 && (n == a+1 || m == b+1))
            ret = min(ret,solve(a-1,b-1) + n-a-1 + m-b-1 + 1);
    }
    
    return ret;
}

int main(){
    while(true){
        scanf("%s %s",S,T);
        if(S[0] == '*') break;
        
        int L1 = strlen(S),L2 = strlen(T);
        
        for(int i = 0;i < 26;++i)
            pos1[0][i] = pos2[0][i] = -1;
        
        for(int i = 1;i < L1;++i){
            for(int j = 0;j < 26;++j)
                pos1[i][j] = pos1[i-1][j];
            
            pos1[i][S[i-1]-'a'] = i-1;
        }
        
        for(int i = 1;i < L2;++i){
            for(int j = 0;j < 26;++j)
                pos2[i][j] = pos2[i-1][j];
            
            pos2[i][T[i-1]-'a'] = i-1;
        }
        
        memset(memo,-1,sizeof(memo));
        
        printf("%d\n",solve(L1-1,L2-1));
    }
    
    return 0;
}
