#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define B 31

int trie[150001][26],cont;
bool end[150001];
vector< pair<int,unsigned long long> > suff[150001];

void add(char *s){
    int L = strlen(s);
    int pos = 0;
    
    for(int i = 0;i < L;++i){
        if(trie[pos][ s[i] - 'a' ] == 0) trie[pos][ s[i] - 'a' ] = cont++;
        pos = trie[pos][ s[i] - 'a' ];
    }
    
    end[pos] = true;
}

void build(int pos){
    suff[pos].clear();
    if(end[pos]) suff[pos].push_back(make_pair(0,0));
    
    for(int i = 0;i < 26;++i){
        if(trie[pos][i]){
            int to = trie[pos][i];
            
            build(to);
            
            int sz = suff[to].size();
            
            for(int j = 0;j < sz;++j)
                suff[pos].push_back(make_pair(suff[to][j].first + 1,i + suff[to][j].second * B));
        }
    }
}

int main(){
    int n;
    char s[31];
    
    while(scanf("%d",&n) == 1){
        memset(trie,0,sizeof trie);
        memset(end,false,sizeof end);
        cont = 1;
        
        for(int i = 0;i < n;++i){
            scanf("%s",s);
            add(s);
        }
        
        build(0);
        
        sort(suff,suff + cont);
        
        printf("%d\n",unique(suff,suff + cont) - suff);
    }
    
    return 0;
}
