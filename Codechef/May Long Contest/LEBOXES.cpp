#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define INF 500000000

int T,n,m,v[30],p[30],c[30],d[30];
int memo[30][31][31];

int solve(int pos, int buy, int D){
    if(pos == -1){
        if(buy > 0) return INF;
        return 0;
    }
    
    int &ret = memo[pos][buy][D];
    
    if(ret == -1){
        ret = solve(pos - 1,buy,D);
        if(buy > 0 && D >= d[pos]) ret = min(ret,c[pos] + solve(pos - 1,buy - 1,D - d[pos]));
    }
    
    return ret;
}

vector< pair<int, double> > v1[16],v2[16];
double sump[16][(1 << 15) + 1];

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&m);
        
        for(int i = 0;i < n;++i)
            scanf("%d %d",&v[i],&p[i]);
        
        for(int i = 0;i < m;++i)
            scanf("%d %d",&c[i],&d[i]);
        
        int n1 = n / 2,n2 = (n + 1) / 2;
        
        for(int i = 0;i <= n1;++i) v1[i].clear();
        for(int i = 0;i <= n2;++i) v2[i].clear();
        
        for(int mask = 0;mask < (1 << n1);++mask){
            int V = 0,D = 0;
            double P = 1;
            
            for(int i = 0;i < n1;++i){
                if(mask & (1 << i)){
                    V += v[i];
                    P *= p[i] / 100.0;
                }else{
                    ++D;
                    P *= 1 - p[i] / 100.0;
                }
            }
            
            v1[D].push_back(make_pair(V,P));
        }
        
        for(int mask = 0;mask < (1 << n2);++mask){
            int V = 0,D = 0;
            double P = 1;
            
            for(int i = 0;i < n2;++i){
                if(mask & (1 << i)){
                    V += v[n1 + i];
                    P *= p[n1 + i] / 100.0;
                }else{
                    ++D;
                    P *= 1 - p[n1 + i] / 100.0;
                }
            }
            
            v2[D].push_back(make_pair(V,P));
        }
        
        for(int i = 0;i <= n1;++i) sort(v1[i].begin(),v1[i].end());
        for(int i = 0;i <= n2;++i) sort(v2[i].begin(),v2[i].end());
        
        for(int i = 0;i <= n2;++i){
            sump[i][0] = 0;
            
            int sz = v2[i].size();
            
            for(int j = 0;j < sz;++j)
                sump[i][j + 1] = sump[i][j] + v2[i][j].second;
        }
        
        memset(memo,-1,sizeof memo);
        double ans = 0;
        
        for(int buy = 0;buy <= m;++buy){
            for(int TD = 0;TD <= n;++TD){
                int Cmin = solve(m - 1,buy,TD);
                int Cmax = (buy == m? INF : solve(m - 1,buy + 1,TD));
                
                if(Cmin < INF){
                    for(int D1 = 0,D2 = TD;D1 <= TD && D1 <= n1;++D1,--D2){
                        if(D2 > n2) continue;
                        
                        for(int i = v1[D1].size() - 1;i >= 0;--i){
                            int lo = 0,hi = v2[D2].size() - 1,mi;
                            
                            while(lo < hi){
                                mi = (lo + hi) >> 1;
                                
                                if(v2[D2][mi].first + v1[D1][i].first < Cmin) lo = mi + 1;
                                else hi = mi;
                            }
                            
                            int a = lo;
                            
                            lo = 0; hi = v2[D2].size() - 1;
                            
                            while(lo < hi){
                                mi = (lo + hi + 1) >> 1;
                                
                                if(v2[D2][mi].first + v1[D1][i].first >= Cmax) hi = mi - 1;
                                else lo = mi;
                            }
                            
                            int b = lo;
                            
                            if(v2[D2][a].first + v1[D1][i].first >= Cmin && v2[D2][b].first + v1[D1][i].first < Cmax)
                                ans += buy * v1[D1][i].second * (sump[D2][b + 1] - sump[D2][a]);
                        }
                    }
                }
            }
        }
        
        printf("%.4f\n",ans);
    }
    
    return 0;
}
