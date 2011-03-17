#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int N,x[200],y[200];
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i = 0;i<N;++i)
            scanf("%d %d",&x[i],&y[i]);
        
        map< pair<int, int> , int > M;
        
        for(int i = 0;i<N;++i){
            for(int j = i+1;j<N;++j){
                int dx = x[i]-x[j],dy = y[i]-y[j];
                int g = __gcd(dx,dy);
                
                dx /= g; dy /= g;
                
                if(dx<0){
                    dx = -dx;
                    dy = -dy;
                }
                
                M[make_pair(dx,dy)]++;
            }
        }
        
        printf("%d\n",(int)M.size());
    }
    
    return 0;
}
