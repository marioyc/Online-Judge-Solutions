#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char em[100][16],len[100],s[81];
int end[80],memo[80][80];

int solve(int s, int e){
    if(s > e) return 0;
    
    int &ret = memo[s][e];
    
    if(ret == -1){
        ret = 80;
        
        if(end[s] > e) ret = solve(s + 1,e);
        else{
            for(int i = s;i <= end[s];++i)
                ret = min(ret,1 + solve(s,i - 1) + solve(i + 1,e));
        }
    }
    
    return ret;
}

int main(){
    int N,M;
    
    while(true){
        scanf("%d %d",&N,&M);
        if(N == 0 && M == 0) break;
        
        for(int i = 0;i < N;++i){
            scanf("%s",em[i]);
            len[i] = strlen(em[i]);
        }
        
        while(true){
            char c = getchar();
            if(c == '\n') break;
        }
        
        int ans = 0;
        
        for(int i = 0;i < M;++i){
            int L = 0;
            
            while(true){
                s[L] = getchar();
                if(s[L] == '\n') break;
                ++L;
            }
            
            for(int j = 0;j < L;++j){
                end[j] = 80;
                
                for(int k = 0;k < N;++k){
                    if(j + len[k] <= L){
                        bool match = true;
                        
                        for(int p = len[k] - 1;p >= 0;--p)
                            if(s[j + p] != em[k][p]) match = false;
                        
                        if(match) end[j] = min(end[j],j + len[k] - 1);
                    }
                }
            }
            
            memset(memo,-1,sizeof memo);
            ans += solve(0,L - 1);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
