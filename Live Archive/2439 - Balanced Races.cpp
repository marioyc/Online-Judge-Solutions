#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int tc = 1,N,M,Q;
    int a[10000];
    
    while(true){
        scanf("%d %d %d",&N,&M,&Q);
        
        if(N == -1) break;
        
        for(int i = 0;i < Q;++i)
            scanf("%d",&a[i]);
        
        sort(a,a + Q);
        
        printf("Race %d: ",tc++);
        
        if(N * M < Q) printf("Organization Fault!\n");
        else{
            int lo = 0,hi = a[Q - 1] - a[0],mi;
            
            while(lo < hi){
                mi = (lo + hi) >> 1;
                int s = 0;
                
                for(int i = 0;i < M;++i){
                    int e = s;
                    
                    for(int j = 0;j < N && e < Q && a[e] - a[s] <= mi;++j)
                        ++e;
                    
                    s = e;
                }
                
                if(s == Q) hi = mi;
                else lo = mi + 1;
            }
            
            printf("%d\n",lo);
        }
    }
    
    return 0;
}
