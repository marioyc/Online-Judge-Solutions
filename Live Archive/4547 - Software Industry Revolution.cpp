#include <cstdio>
#include <cstring>

using namespace std;

char p[1001],s[10001];
char p2[1000][1001];

int L[500],match[500][10000],sz[500],pos[500];
int sum[10001];

int main(){
    while(scanf("%s %s",p,s) == 2){
        int Lp = strlen(p),Ls = strlen(s),n = 0;
        
        sum[0] = 0;
        
        for(int i = 0;i < Ls;++i)
            sum[i + 1] = sum[i] + s[i] - 'a' + 1;
        
        for(int i = 0,j;i < Lp;i = j + 1){
            j = i;
            
            if(p[i] != '*'){
                while(j < Lp && p[j] != '*') ++j;
                
                L[n] = j - i;
                sz[n] = 0;
                
                for(int k = 0;k + j - i <= Ls;++k){
                    bool ok = true;
                    
                    for(int x = i;x < j;++x){
                        if(p[x] != '?' && s[k + x - i] != p[x])
                            ok = false;
                    }
                    
                    if(ok){
                        match[n][sz[n]] = k;
                        ++sz[n];
                    }
                }
                
                ++n;
            }
        }
        
        if(n == 0) printf("0\n");
        else{
            memset(pos,0,sizeof pos);
            
            int ans = -1,aux;
            
            for(int i = 0;i < sz[0];++i){
                int e = match[0][i] + L[0];
                bool done = true;
                
                for(int j = 1;j < n;++j){
                    while(pos[j] < sz[j] && match[j][pos[j]] < e) ++pos[j];
                    
                    if(pos[j] == sz[j]){
                        done = false;
                        break;
                    }else e = match[j][pos[j]] + L[j];
                }
                
                if(!done) break;
                
                aux = sum[e] - sum[match[0][i]];
                if(ans == -1 || aux < ans) ans = aux;
            }
            
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
