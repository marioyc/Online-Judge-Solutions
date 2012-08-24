#include <cstdio>
#include <set>
#include <map>

using namespace std;

int main(){
    int n;
    int x[1000],y[1000];
    set< pair<int, int> > S;
    
    while(true){
        scanf("%d",&n);
        
        if(n == 0) break;
        
        S.clear();
        
        for(int i = 0;i < n;++i){
            scanf("%d %d",&x[i],&y[i]);
            S.insert(make_pair(x[i],y[i]));
        }
        
        int ans = 0;
        
        for(int i = 0;i < n;++i){
            for(int j = i + 1;j < n;++j){
                int vx = x[j] - x[i];
                int vy = y[j] - y[i];
                
                int x1 = 2 * x[i] + vx - vy,y1 = 2 * y[i] + vy + vx;
                int x2 = 2 * x[i] + vx + vy,y2 = 2 * y[i] + vy - vx;
                
                if(x1 % 2 == 0 && y1 % 2 == 0 && y1 % 2 == 0 && y2 % 2 == 0){
                    x1 /= 2; y1 /= 2;
                    x2 /= 2; y2 /= 2;
                    
                    if(S.find(make_pair(x1,y1)) != S.end() && S.find(make_pair(x2,y2)) != S.end()) ++ans;
                }
            }
        }
        
        printf("%d\n",ans / 2);
    }
    
    return 0;
}
