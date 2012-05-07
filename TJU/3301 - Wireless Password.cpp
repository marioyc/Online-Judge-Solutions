#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MOD 20090717

struct AhoCorasick{
    static const int UNDEF = 0;
    static const int MAXN = 101;
    static const int CHARSET = 26;
    
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

int L,n,k;
int memo[25][101][(1 << 10)];

int solve(int pos, int ac, int mask){
    if(pos == L) return __builtin_popcount(mask) >= k? 1 : 0;
    
    int &ret = memo[pos][ac][mask];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = 0,to;i < 26;++i){
            to = AC.trie[ac][i];
            ret += solve(pos + 1,to,mask | AC.tag[to]);
            if(ret >= MOD) ret -= MOD;
        }
    }
    
    return ret;
}

int main(){
    char s[11];
    int a[10];
    
    while(true){
        scanf("%d %d %d",&L,&n,&k);
        
        if(L == 0) break;
        
        AC.init();
        
        for(int i = 0;i < n;++i){
            scanf("%s",s);
            
            int ls = strlen(s);
            
            for(int j = 0;j < ls;++j)
                a[j] = s[j] - 'a';
            
            AC.add(ls,a);
        }
        
        AC.build();
        memset(memo,-1,sizeof memo);
        
        printf("%d\n",solve(0,0,0));
    }
    
    return 0;
}
