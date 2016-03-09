#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 1000005

int N,M,Y;
pair<int,int> x[MAXN];
int mn[MAXN],mx[MAXN];

int main(){
    while(scanf("%d %d %d",&N,&M,&Y) == 3){
        for(int i = 0;i < M;++i)
            scanf("%d %d",&x[i].first,&x[i].second);
        
        sort(x,x + M);
        
        if((x[0].second + x[M - 1].second) & 1) puts("N");
        else{
            Y -= (x[0].second + x[M - 1].second) / 2;
            for(int i = 1;i + 1 < M;++i) Y -= x[i].second;
            
            if(Y < 0) puts("N");
            else{
                int smn = 0,smx = 0;
                
                mn[M - 1] = mx[M - 1] = 0;
                
                for(int i = 0;i + 1 < M;++i){
                    int dx = x[i + 1].first - x[i].first - 1;
                    smn += (mn[i] = min(x[i].second,x[i + 1].second) * dx);
                    smx += (mx[i] = max(x[i].second,x[i + 1].second) * dx);
                }
                
                for(int i = M - 3;i >= 0;--i){
                    mn[i] += mn[i + 1];
                    mx[i] += mx[i + 1];
                }
                
                if(Y < smn || Y > smx) puts("N");
                else{
                    putchar('S');
                    
                    for(int i = 0;i + 1 < M;++i){
                        bool inc = x[i + 1].second >= x[i].second;
                        
                        int l = min(x[i].second,x[i + 1].second),r = max(x[i].second,x[i + 1].second),lo;
                        
                        for(int dx = x[i + 1].first - x[i].first - 1;dx > 0;--dx){
                            if(inc){
                                lo = max(l,Y - (dx - 1) * r - mx[i + 1]);
                                l = lo;
                            }else{
                                lo = max(l,(Y - mx[i + 1] + dx - 1) / dx);
                            }
                            
                            Y -= lo;
                            printf(" %d",lo);
                        }
                    }
                    
                    putchar('\n');
                }
            }
        }
    }
    
    return 0;
}
