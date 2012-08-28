#include <cstdio>
#include <cstring>

using namespace std;

int trie[100000][26],cont;

void add(char *s){
    int L = strlen(s),pos = 0;
    
    for(int i = 0;i < L;++i){
        if(trie[pos][ s[i] - 'a' ] == 0) trie[pos][ s[i] - 'a' ] = cont++;
        pos = trie[pos][ s[i] - 'a' ];
    }
}

int trie2[100000][26],cont2;
int suff[26];
bool start[26];

void add2(char *s){
    int L = strlen(s),pos = 0;
    start[ s[L - 1] - 'a' ] = true;
    
    for(int i = L - 1;i >= 0;--i){
        if(trie2[pos][ s[i] - 'a' ] == 0){
            trie2[pos][ s[i] - 'a' ] = cont2++;
            ++suff[ s[i] - 'a' ];
        }
        
        pos = trie2[pos][ s[i] - 'a' ];
    }
}

long long ans = 0;

void solve(int pos){
    for(int i = 0;i < 26;++i){
        if(trie[pos][i]){
            solve(trie[pos][i]);
            if(pos > 0 && start[i]) ++ans;
        }else if(pos > 0) ans += suff[i];
    }
}

int main(){
    int P,S;
    char s[1001];
    
    while(true){
        scanf("%d %d",&P,&S);
        if(P == 0) break;
        
        memset(trie,0,sizeof trie);
        cont = 1;
        
        for(int i = 0;i < P;++i){
            scanf("%s",s);
            add(s);
        }
        
        memset(trie2,0,sizeof trie2);
        cont2 = 1;
        
        memset(start,false,sizeof start);
        memset(suff,0,sizeof suff);
        
        for(int i = 0;i < S;++i){
            scanf("%s",s);
            add2(s);
        }
        
        ans = 0;
        solve(0);
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
