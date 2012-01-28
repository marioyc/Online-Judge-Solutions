#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N;
    int x[100],y[100],x2[101],y2[101];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        
        x2[0] = 0; y2[0] = 0;
        
        for(int i = 0;i < N;++i){
            scanf("%d %d",&x[i],&y[i]);
            x2[i + 1] = x2[i] + x[i];
            y2[i + 1] = y2[i] + y[i];
        }
        
        int area = 0;
        
        for(int i = 0;i < N;++i)
            area += x2[i] * y2[i + 1] - x2[i + 1] * y2[i];
        
        area = abs(area);
        
        int B = 0;
        
        for(int i = 0;i < N;++i){
            int dx = abs(x[i]);
            int dy = abs(y[i]);
            
            B += __gcd(dx,dy);
        }
        
        int I = (area - B) / 2 + 1;
        
        printf("Scenario #%d:\n%d %d %.1f\n\n",tc,I,B,area / 2.0);
    }
    
    return 0;
}
