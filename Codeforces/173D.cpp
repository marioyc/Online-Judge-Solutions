#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAXN 100001
#define MAXM 100000

pair<int, int> e[MAXM];
vector<int> L[MAXN];
int Q[MAXN],head,tail,color[MAXN];
vector<int> A,B,not_adj[MAXN];

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        
        e[i] = make_pair(u,v);
        
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    memset(color,-1,sizeof color);
    
    for(int i = 1;i <= n;++i){
        if(color[i] == -1){
            head = tail = 0;
            Q[tail++] = i;
            color[i] = 0;
            
            while(head < tail){
                int cur = Q[head++];
                
                if(color[cur] == 0) A.push_back(cur);
                else B.push_back(cur);
                
                for(int j = L[cur].size() - 1,to;j >= 0;--j){
                    to = L[cur][j];
                    
                    if(color[to] == -1){
                        Q[tail++] = to;
                        color[to] = color[cur] ^ 1;
                    }
                }
            }
        }
    }
    
    bool ok = false;
    
    if(A.size() % 3 == 0){
        ok = true;
        
        int cont = 1;
        
        while(!A.empty()){
            for(int it = 0;it < 3 && !A.empty();++it){
                color[A.back()] = cont;
                A.pop_back();
            }
            
            ++cont;
        }
        
        while(!B.empty()){
            for(int it = 0;it < 3 && !B.empty();++it){
                color[B.back()] = cont;
                B.pop_back();
            }
            
            ++cont;
        }
    }else{
        if(A.size() % 3 == 2) swap(A,B);
        
        int colorA = color[ A[0] ];
        
        for(int i = 0;i < m;++i)
            if(color[ e[i].first ] != colorA)
                swap(e[i].first,e[i].second);
        
        sort(e,e + m);
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        int szA = A.size(),szB = B.size();
        
        for(int i = 0,j = 0;i < szA;++i){
            int k = j;
            
            while(k < m && e[k].first == A[i]) ++k;
            
            if(k - j <= szB - 2){
                ok = true;
                
                vector<int> aux;
                int cont = 0;
                
                for(int a = 0,b = j,u;a < szB && cont < 2;++a){
                    u = B[a];
                    
                    if(b == k || u != e[b].second){
                       aux.push_back(u); 
                       ++cont;
                    }else ++b;
                }
                
                memset(color,-1,sizeof color);
                color[ A[i] ] = color[ aux[0] ] = color[ aux[1] ] = 1;
                cont = 2;
                
                while(!A.empty()){
                    for(int it = 0;it < 3 && !A.empty();){
                        if(color[ A.back() ] == -1){
                            color[ A.back() ] = cont;
                            ++it;
                        }
                        
                        A.pop_back();
                        if(it == 3) ++cont;
                    }
                }
                
                while(!B.empty()){
                    for(int it = 0;it < 3 && !B.empty();){
                        if(color[ B.back() ] == -1){
                            color[ B.back() ] = cont;
                            ++it;
                        }
                        
                        B.pop_back();
                        if(it == 3) ++cont;
                    }
                }
                
                break;
            }else if(k - j == szB - 1){
                for(int a = 0,b = j,u;a < szB;++a){
                    u = B[a];
                    
                    if(b == k || u != e[b].second){
                       not_adj[u].push_back(A[i]);
                       break;
                    }else ++b;
                }
            }
            
            j = k;
        }
        
        if(!ok){
            for(int i = 0;i < szB;++i){
                if(not_adj[ B[i] ].size() >= 2){
                    for(int j = i + 1;j < szB;++j){
                        if(not_adj[ B[j] ].size() >= 2){
                            ok = true;
                            
                            memset(color,-1,sizeof color);
                            
                            color[ B[i] ] = color[ not_adj[ B[i] ][0] ] = color[ not_adj[ B[i] ][1] ] = 1;
                            color[ B[j] ] = color[ not_adj[ B[j] ][0] ] = color[ not_adj[ B[j] ][1] ] = 2;
                            
                            int cont = 3;
                            
                            while(!A.empty()){
                                for(int it = 0;it < 3 && !A.empty();){
                                    if(color[ A.back() ] == -1){
                                        color[ A.back() ] = cont;
                                        ++it;
                                    }
                                    
                                    A.pop_back();
                                    if(it == 3) ++cont;
                                }
                            }
                            
                            while(!B.empty()){
                                for(int it = 0;it < 3 && !B.empty();){
                                    if(color[ B.back() ] == -1){
                                        color[ B.back() ] = cont;
                                        ++it;
                                    }
                                    
                                    B.pop_back();
                                    if(it == 3) ++cont;
                                }
                            }
                            
                            break;
                        }
                    }
                    
                    break;
                }
            }
        }
    }
    
    if(!ok) puts("NO");
    else{
        puts("YES");
        
        for(int i = 1;i <= n;++i)
            printf("%d ",color[i]);
        
        printf("\n");
    }
    
    return 0;
}
