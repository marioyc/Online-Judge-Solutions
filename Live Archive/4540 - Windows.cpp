#include <cstdio>

using namespace std;

int main(){
    int tc = 1,N,Q;
    int r1[100],c1[100],r2[100],c2[100];
    int r,c,ans;
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        for(int i = 0;i < N;++i){
            scanf("%d %d %d %d",&r1[i],&c1[i],&c2[i],&r2[i]);
            r2[i] = r1[i] + r2[i] - 1;
            c2[i] = c1[i] + c2[i] - 1;
        }
        
        printf("Desktop %d:\n",tc++);
        
        scanf("%d",&Q);
        
        while(Q--){
            scanf("%d %d",&r,&c);
            ans = 0;
            
            for(int i = N - 1;i >= 0;--i){
                if(r >= r1[i] && r <= r2[i] && c >= c1[i] && c <= c2[i]){
                    ans = i + 1;
                    break;
                }
            }
            
            if(ans == 0) printf("background\n");
            else printf("window %d\n",ans);
        }
    }
    
    return 0;
}
