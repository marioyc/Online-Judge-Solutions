#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct point{
    int x,y,t,v;
    
    point(){}
    point(int _x, int _y, int _t, int _v):
        x(_x), y(_y), t(_t), v(_v){}
    
    point operator - (point P){
        return point(x - P.x,y - P.y,t,v);
    }
};

point v[2000],v2[4000];

bool cmp(point a, point b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

long long cross(point a, point b){
    return (long long)a.x * b.y - (long long)a.y * b.x;
}

bool polar_cmp(point a, point b){
    if(a.x >= 0 && b.x < 0) return true;
    if(a.x < 0 && b.x >= 0) return false;
    if(a.x == 0 && b.x == 0){
        if(a.y > 0 && b.y < 0) return false;
        if(a.y < 0 && b.y > 0) return true;
    }
    return cross(a,b) > 0;
}

int main(){
    int P,L,N;
    int sum[4000][2];
    
    while(true){
        scanf("%d %d",&P,&L);
        if(P == 0 && L == 0) break;
        
        int total = 0,totalp = 0,totall = 0;
        N = 0;
        
        for(int i = 0;i < P;++i,++N){
            scanf("%d %d %d",&v[N].x,&v[N].y,&v[N].v);
            totalp += v[N].v;
            v[N].t = 0;
        }
        
        for(int i = 0;i < L;++i,++N){
            scanf("%d %d %d",&v[N].x,&v[N].y,&v[N].v);
            totall += v[N].v;
            v[N].t = 1;
        }
        
        total = totalp + totall;
        int ans = 0;
        bool line = false;
        
        for(int i = 0;i < N;++i){
            int M = 0;
            
            for(int j = 0;j < N;++j)
                if(j != i) v2[M++] = v[j] - v[i];
            
            sort(v2,v2 + M,polar_cmp);
            
            for(int j = 0;j < M;++j)
                v2[M + j] = v2[j];
            
            M <<= 1;
            sum[0][0] = sum[0][1] = 0;
            
            for(int j = 0;j < M;++j){
                sum[j + 1][0] = sum[j][0] + (v2[j].t == 0? v2[j].v : 0);
                sum[j + 1][1] = sum[j][1] + (v2[j].t == 1? v2[j].v : 0);
            }
            
            for(int s = 0,e = 0;s < N - 1;){
                while(e < s + N - 1 && cross(v2[s],v2[e]) >= 0) ++e;
                --e;
                
                int cont1 = 0,cont2 = 0;
                
                for(int j = s;j <= e;++j){
                    if(cross(v2[j],v2[s]) == 0) ++cont1;
                    else break;
                }
                
                for(int j = e;j >= s;--j){
                    if(cross(v2[j],v2[s]) == 0) ++cont2;
                    else break;
                }
                
                if(s == 0 && cont1 == N - 1){
                    line = true;
                    break;
                }else{
                    int P0 = sum[s + cont1][0] - sum[s][0],L0 = sum[s + cont1][1] - sum[s][1];
                    
                    if(v[i].t == 0) P0 += v[i].v;
                    else L0 += v[i].v;
                    
                    if(e - s + 1 != cont2){
                        P0 += sum[e + 1][0] - sum[e + 1 - cont2][0];
                        L0 += sum[e + 1][1] - sum[e + 1 - cont2][1];
                    }
                    
                    int P1 = 0,P2 = sum[s + N - 1][0] - sum[e + 1][0];
                    int L1 = 0,L2 = sum[s + N - 1][1] - sum[e + 1][1];
                    
                    if(e - s + 1 != cont1) P1 = sum[e - cont2 + 1][0] - sum[s + cont1][0];
                    if(e - s + 1 != cont1) L1 = sum[e - cont2 + 1][1] - sum[s + cont1][1];
                    
                    ans = max(ans,P1 + L2 + P0);
                    ans = max(ans,P1 + L2 + L0);
                    ans = max(ans,L1 + P2 + P0);
                    ans = max(ans,L1 + P2 + L0);
                    
                    s = s + cont1;
                    e = max(e,s);
                }
            }
            
            if(line) break;
        }
        
        if(line){
            sort(v,v + N,cmp);
            ans = max(totalp,totall);
            
            for(int i = 0,sp = 0,sl = 0;i < N;++i){
                if(v[i].t == 0) sp += v[i].v;
                else sl += v[i].v;
                
                ans = max(ans,sp + totall - sl);
                ans = max(ans,sl + totalp - sp);
            }
        }
        
        printf("%d\n",total - ans);
    }
    
    return 0;
}
