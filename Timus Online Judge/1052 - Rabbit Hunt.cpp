#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    
    while(a%b!=0){
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    return b;
}

int main(){
    int N;
    scanf("%d",&N);
    
    int x[200],y[200];
    
    for(int i = 0;i<N;++i)
        scanf("%d %d",&x[i],&y[i]);
    
    pair<int, int> P[200];
    
    int ans = 2;
    
    for(int i = 0;i<N;++i){
        int sz = 0,orig = 0;
        
        for(int j = 0;j<N;++j){
            if(x[j]==x[i] && y[j]==y[i]) ++orig;
            else{
                int dx = x[j]-x[i],dy = y[j]-y[i];
                int g = gcd(dx,dy);
                
                dx /= g; dy /= g;
                
                if(dx<0){
                    dx = -dx;
                    dy = -dy;
                }
                
                P[sz] = make_pair(dx,dy);
                ++sz;
            }
        }
        
        sort(P,P+sz);
        
        if(sz>0){
            ans = max(ans,1+orig);
            
            for(int i = 1,aux = 1;i<sz;++i){
                if(P[i]==P[i-1]) ++aux;
                else aux = 1;
                
                ans = max(ans,aux+orig);
            }
        }else ans = max(ans,orig);
    }
    
    printf("%d\n",ans);
    
    return 0;
}
