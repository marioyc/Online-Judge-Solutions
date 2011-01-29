#include <cstdio>

using namespace std;

int main(){
    int T,N,cur,a;
    bool down;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&cur);
        down = true;
        
        int ans = 1;
        
        for(int i = 1;i<N;++i){
            scanf("%d",&a);
            
            if((down && cur>a) || (!down && cur<a)){
                down = !down;
                ++ans;
            }
            
            cur = a;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
