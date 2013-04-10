#include <cstdio>
#include <cstring>

using namespace std;

#define MAXL 100005
#define ALPH 26

struct state{
    int len,link,pos;
    int next[ALPH];
};

struct SuffixAutomata{
    state sa[2 * MAXL];
    int last,sz,len;

    SuffixAutomata(){
        sa[0].len = 0;
        sa[0].link = -1;
        memset(sa[0].next,0,sizeof sa[0].next);
        last = len = 0;
        sz = 1;
    }

    void sa_add(int c){
        int cur = sz++;
        sa[cur].len = sa[last].len + 1;
        sa[cur].pos = len;
        memset(sa[cur].next,0,sizeof sa[cur].next);
        
        int p = last;
        
        while(p != -1 && !sa[p].next[c]){
            sa[p].next[c] = cur;
            p = sa[p].link;
        }
        
        if(p == -1) sa[cur].link = 0;
        else{
            int q = sa[p].next[c];
            
            if(sa[q].len == sa[p].len + 1)
                sa[cur].link = q;
            else{
                int clone = sz++;
                sa[clone].len = sa[p].len + 1;
                sa[clone].link = sa[q].link;
                sa[clone].pos = sa[q].pos;
                memcpy(sa[clone].next,sa[q].next,sizeof(int) * ALPH);
                
                while(p != -1 && sa[p].next[c] == q){
                    sa[p].next[c] = clone;
                    p = sa[p].link;
                }
                
                sa[q].link = sa[cur].link = clone;
            }
        }
        
        last = cur;
        ++len;
    }
}S,Srev;

int L;
char s[MAXL];

int main(){
    scanf("%s",s);
    L = strlen(s);
    
    for(int i = 0;i < L;++i) S.sa_add(s[i] - 'A');
    for(int i = L - 1;i >= 0;--i) Srev.sa_add(s[i] - 'A');
    
    char s2[1001];
    int m,L2,auxl[1001],auxr[1001],ans = 0;
    
    scanf("%d",&m);
    
    while(m--){
        scanf("%s",s2);
        L2 = strlen(s2);
        memset(auxl,-1,sizeof(int) * L2);
        memset(auxr,-1,sizeof(int) * L2);
        
        for(int i = 0,cur = 0;i < L2;++i){
            cur = S.sa[cur].next[ s2[i] - 'A' ];
            if(cur == 0) break;
            auxl[i] = S.sa[cur].pos;
        }
        
        for(int i = L2 - 1,cur = 0;i >= 0;--i){
            cur = Srev.sa[cur].next[ s2[i] - 'A' ];
            if(cur == 0) break;
            auxr[i] = L - 1 - Srev.sa[cur].pos;
        }
        
        for(int i = 0;i < L2 - 1 && auxl[i] != -1;++i){
            if(auxl[i] < auxr[i + 1]){
                ++ans;
                break;
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
