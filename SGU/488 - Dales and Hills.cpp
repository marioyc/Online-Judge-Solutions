#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000000

int a[MAXN],b[MAXN];

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&a[i]);
        
        for(int i = 0;i + 1 < N;++i){
            if(a[i] < a[i + 1]) b[i] = 1;
            else if(a[i] > a[i + 1]) b[i] = -1;
            else b[i] = 0;
        }
        
        int ans1 = 0,ans2 = 0;
        --N;
        
        for(int i = 0;i < N;){
            if(b[i] == 1){
                int e = i;
                
                while(e < N && b[e] == 1) ++e;
                
                int aux = e - i;
                i = e;
                
                if(b[e] == -1){
                    e = i;
                    
                    while(e < N && b[e] == -1) ++e;
                    
                    aux = min(aux,e - i);
                    ans1 = max(ans1,aux);
                }
            }else ++i;
        }
        
        for(int i = 0;i < N;){
            if(b[i] == -1){
                int e = i;
                
                while(e < N && b[e] == -1) ++e;
                
                int aux = e - i;
                i = e;
                
                if(b[e] == 1){
                    e = i;
                    
                    while(e < N && b[e] == 1) ++e;
                    
                    aux = min(aux,e - i);
                    ans2 = max(ans2,aux);
                }
            }else ++i;
        }
        
        printf("%d %d\n",ans1,ans2);
    }
    
    return 0;
}
