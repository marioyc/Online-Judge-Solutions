#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXL 100000

char s1[MAXL + 1],s2[MAXL + 1],aux[3];
int can[26],cont[MAXL][26],cont2[26];
vector<int> occ[26];
int pos[26];

int main(){
    int T,K;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s %s %d",s1,s2,&K);
        
        memset(can,false,sizeof can);
        
        for(int i = 0;i < K;++i){
            scanf("%s",aux);
            
            int a = aux[0] - 'a';
            int b = aux[1] - 'a';
            
            can[a] |= (1 << b);
            can[b] |= (1 << a);
        }
        
        bool ok = true;
        int L = strlen(s1),L2 = strlen(s2);
        
        memset(cont2,0,sizeof cont2);
        
        for(int i = 0;i < L;++i) ++cont2[ s1[i] - 'a' ];
        for(int i = 0;i < L2;++i) --cont2[ s2[i] - 'a' ];
        
        for(int i = 0;i < 26;++i)
            if(cont2[i] > 0)
                ok = false;
        
        if(!ok) puts("-1");
        else{
            memset(cont[0],0,sizeof cont[0]);
            
            for(int i = 0;i < 26;++i)
                occ[i].clear();
            
            for(int i = 0;i < L;++i){
                if(i > 0)
                    for(int j = 0;j < 26;++j)
                        cont[i][j] = cont[i - 1][j];
                
                ++cont[i][ s1[i] - 'a' ];
                occ[ s1[i] - 'a' ].push_back(i);
            }
            
            memset(pos,0,sizeof pos);
            unsigned int ans = 0;
            
            for(int i = 0;i < L;++i){
                int cur = occ[ s2[i] - 'a' ][ pos[ s2[i] - 'a' ] ];
                ++pos[ s2[i] - 'a' ];
                
                int mask = 0;
                
                for(int j = 0;j < 26;++j){
                    if(cur > 0 && cont[cur - 1][j] > cont2[j]){
                        ans += cont[cur - 1][j] - cont2[j];
                        mask |= (1 << j);
                    }
                }
                
                if((mask & can[ s2[i] - 'a' ]) != mask) ok = false;
                ++cont2[ s2[i] - 'a' ];
            }
            
            printf("%lld\n",ok? (long long)ans : -1);
        }
    }
    
    return 0;
}
