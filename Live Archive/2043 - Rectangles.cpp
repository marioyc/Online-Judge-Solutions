#include <cstdio>

using namespace std;

int main(){
    int N,x1[5000],x2[5000],y1[5000],y2[5000];
    
    while(scanf("%d",&N) == 1){
        for(int i = 0;i < N;++i)
            scanf("%d %d %d %d",&x1[i],&x2[i],&y1[i],&y2[i]);
        
        int ans = 0;
        
        for(int i = 0;i < N;++i){
            bool found = false;
            
            for(int j = 0;j < N && !found;++j)
                if(j != i && x1[j] <= x1[i] && x2[j] >= x2[i] && y1[j] <= y1[i] && y2[j] >= y2[i])
                    found = true, ++ans;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
