#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct AhoCorasick{
    static const int UNDEF = 0;
    static const int MAXN = 150;
    static const int CHARSET = 10;
    
    int end,have;
    int tag[MAXN];
    int fail[MAXN];
    int trie[MAXN][CHARSET];
    
    void init(){
        tag[0] = UNDEF;
        fill(trie[0],trie[0] + CHARSET,-1);
        end = 1;
        have = 0;
    }
    
    void add(int len, const int* s){
        int p = 0;
        
        for(int i = 0; i < len; ++i){
            if(trie[p][*s] == -1) {
                tag[end] = UNDEF;
                fill(trie[end],trie[end] + CHARSET,-1);
                trie[p][*s] = end++;
            }
            
            p = trie[p][*s];
            ++s;
        }
        
        tag[p] = (1 << have);
        ++have;
    }
    
    void build(){
        queue<int> bfs;
        fail[0] = 0;
        
        for(int i = 0;i < CHARSET;++i){
            if(trie[0][i] != -1){
                fail[trie[0][i]] = 0;
                bfs.push(trie[0][i]);
            }else{
                trie[0][i] = 0;
            }
        }
        
        while(!bfs.empty()){
            int p = bfs.front();
            tag[p] |= tag[fail[p]];
            bfs.pop();
            
            for(int i = 0;i < CHARSET;++i){
                if(trie[p][i] != -1){
                    fail[trie[p][i]] = trie[fail[p]][i];
                    bfs.push(trie[p][i]);
                }else{
                  trie[p][i] = trie[fail[p]][i];
                }
            }
        }
    }
}AC;

int memo[30][150];

int solve(int d, int pos){
    if(AC.tag[pos]) return 0;
    if(d == 0) return 1;
    
    int &ret = memo[d][pos];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = 0;i <= 9;++i)
            ret += solve(d - 1,AC.trie[pos][i]);
    }
    
    return ret;
}

int main(){
    int T,K,Q,X;
    char s[11];
    int a[11];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&K);
        
        AC.init();
        
        for(int i = 0,L;i < K;++i){
            scanf("%s",s);
            
            L = strlen(s);
            
            for(int i = 0;i < L;++i)
                a[i] = s[i] - '0';
            
            AC.add(strlen(s),a);
        }
        
        AC.build();
        
        scanf("%d",&Q);
        
        memset(memo,-1,sizeof memo);
        
        while(Q--){
            scanf("%d",&X);
            
            bool done = false;
            
            for(int d = 1;d < 30 && !done;++d){
                for(int i = 1;i <= 9 && !done;++i){
                    int aux = solve(d - 1,AC.trie[0][i]);
                    
                    if(X <= aux){
                        done = true;
                        putchar('0' + i);
                        
                        for(int j = 1,st = AC.trie[0][i];j < d;++j){
                            for(int k = 0;k <= 9;++k){
                                aux = solve(d - 1 - j,AC.trie[st][k]);
                                
                                if(X <= aux){
                                    putchar('0' + k);
                                    st = AC.trie[st][k];
                                    break;
                                }else X -= aux;
                            }
                        }
                    }else X -= aux;
                }
            }
            
            if(Q == 0) putchar('\n');
            else putchar(' ');
        }
    }
    
    return 0;
}
