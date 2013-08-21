#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 100001
#define LG 16

vector<int> L[MAXN];
int id[MAXN],lvl[MAXN],par[MAXN];
int first[MAXN],last[MAXN];

int p[LG + 1][MAXN];
int s[LG + 1][MAXN][LG + 1],e[LG + 1][MAXN][LG + 1];

int go_up(int x, int n){
    for(int i = 0;i <= 16 && x != -1;++i)
        if(n & (1 << i))
            x = p[i][x];
    return x;
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    vector<int> r;
    
    for(int i = 1,x;i <= N;++i){
        scanf("%d",&x);
        if(x == 0) r.push_back(i);
        else L[x].push_back(i);
    }
    
    queue<int> Q;
    int cont = 1;
    memset(first,-1,sizeof first);
    memset(last,-1,sizeof last);
    memset(par,-1,sizeof par);
    
    for(int i = r.size() - 1;i >= 0;--i){
        id[ r[i] ] = cont++;
        Q.push(r[i]);
        lvl[ id[ r[i] ] ] = 0;
    }
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        for(int j = L[cur].size() - 1,to;j >= 0;--j){
            to = L[cur][j];
            id[to] = cont++;
            
            if(first[ id[cur] ] == -1) first[ id[cur] ] = id[to];
            last[ id[cur] ] = id[to];
            
            Q.push(to);
            lvl[ id[to] ] = lvl[ id[cur] ] + 1;
            par[ id[to] ] = id[cur];
        }
    }
    
    memset(p,-1,sizeof p);
    
    for(int i = 1;i <= N;++i)
        p[0][i] = par[i];
    
    int lg = 0;
    while((1 << lg) <= N) ++lg;
    --lg;
    
    for(int i = 1;i <= lg;++i){
        for(int j = 1;j <= N;++j){
            if(p[i - 1][j] != -1) p[i][j] = p[i - 1][ p[i - 1][j] ];
            else p[i][j] = -1;
        }
    }
    
    memset(s,-1,sizeof s);
    memset(e,-1,sizeof e);
    
    for(int i = 1;i <= N;++i){
        s[0][i][0] = first[i];
        e[0][i][0] = last[i];
    }
    
    for(int i = 1,sz = 1;i <= lg;++i,sz <<= 1){
        for(int j = 1;j + (1 << i) - 1 <= N;++j){
            if(lvl[j] == lvl[j + (1 << i) - 1]){
                int s1 = s[0][j][i - 1],e1 = e[0][j][i - 1];
                int s2 = s[0][j + sz][i - 1],e2 = e[0][j + sz][i - 1];
                
                if(s1 != -1 && s2 != -1){
                    s[0][j][i] = s1;
                    e[0][j][i] = e2;
                }else if(s1 != -1){
                    s[0][j][i] = s1;
                    e[0][j][i] = e1;
                }else{
                    s[0][j][i] = s2;
                    e[0][j][i] = e2;
                }
            }
        }
    }
    
    for(int k = 1,sz = 1;k <= lg;++k,sz <<= 1){
        for(int i = 1;i <= N;++i){
            for(int j = 0;j <= lg && i + (1 << j) - 1 <= N;++j){
                if(lvl[i] == lvl[i + (1 << j) - 1]){
                    int s1 = s[k - 1][i][j],e1 = e[k - 1][i][j];
                    
                    if(s1 != -1){
                        int lg2 = 0;
                        while((1 << lg2) <= e1 - s1 + 1) ++lg2;
                        --lg2;
                        
                        int s2 = s[k - 1][s1][lg2],e2 = e[k - 1][s1][lg2];
                        int s3 = s[k - 1][e1 + 1 - (1 << lg2)][lg2],e3 = e[k - 1][e1 + 1 - (1 << lg2)][lg2];
                        
                        if(s2 != -1 && s3 != -1){
                            s[k][i][j] = s2;
                            e[k][i][j] = e3;
                        }else if(s2 != -1){
                            s[k][i][j] = s2;
                            e[k][i][j] = e2;
                        }else{
                            s[k][i][j] = s3;
                            e[k][i][j] = e3;
                        }
                    }else{
                        s[k][i][j] = -1;
                        e[k][i][j] = -1;
                    }
                }else break;
            }
        }
    }
    
    int M;
    
    scanf("%d",&M);
    
    while(M--){
        int x,h;
        scanf("%d %d",&x,&h);
        
        x = go_up(id[x],h);
        
        if(x == -1) printf("0 ");
        else{
            int s1 = x,e1 = x;
            
            for(int i = 0;i <= 16;++i){
                if(h & (1 << i)){
                    lg = 0;
                    while((1 << lg) <= e1 - s1 + 1) ++lg;
                    --lg;
                    
                    int s2 = s[i][s1][lg],e2 = e[i][s1][lg];
                    int s3 = s[i][e1 - (1 << lg) + 1][lg],e3 = e[i][e1 - (1 << lg) + 1][lg];
                    
                    if(s2 != -1 && s3 != -1){
                        s1 = s2;
                        e1 = e3;
                    }else if(s2 != -1){
                        s1 = s2;
                        e1 = e2;
                    }else{
                        s1 = s3;
                        e1 = e3;
                    }
                }
            }
            
            printf("%d ",e1 - s1);
        }
    }
    
    printf("\n");
    
    return 0;
}
