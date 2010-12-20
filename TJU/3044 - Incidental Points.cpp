#include <cstdio>
#include <algorithm>

using namespace std;

struct point{
    int x,y;
    
    point(){}
    
    point(int _x, int _y){
        x = _x;
        y = _y;
    }
    
    void normalize(){
        if(x!=0 || y!=0){
            int g = __gcd(x,y);
            x /= g;
            y /= g;
            
            if(x<0){
                x = -x;
                y = -y;
            }
        }
    }
    
    bool operator < (point X)const{
        if(x!=X.x) return x<X.x;
        return y<X.y;
    }
}P[1000],P2[1000];

int main(){
    int T = 0,N,x,y;
    char s[100001];
    
    while(true){
        N = 0;
        
        while(scanf("%d %d",&x,&y)==2)
            P[N++] = point(x,y);
        
        if(N==0) break;
        scanf("%s",s);
        
        int ans = 1;
        
        if(N>1){
            ans = 2;
            
            for(int i = 0;i<N;++i){
                for(int j = 0,k = 0;j<N;++j){
                    if(j==i) continue;
                    P2[k] = point(P[j].x-P[i].x,P[j].y-P[i].y);
                    P2[k].normalize();
                    ++k;
                }
                
                sort(P2,P2+N);
                
                for(int j = 1,cont = 1;j+1<N;++j){
                    if(P2[j].x==P2[j-1].x && P2[j].y==P2[j-1].y){
                        ++cont;
                        if(1+cont>ans) ans = 1+cont;
                    }else cont = 1;
                }
            }
        }
        
        ++T;
        printf("%d. %d\n",T,ans);
    }
    
    return 0;
}
