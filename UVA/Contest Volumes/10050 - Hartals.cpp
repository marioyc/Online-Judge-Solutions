#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,N,P,a[100];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&P);
        
        for(int i = 0;i<P;++i) scanf("%d",&a[i]);
        
        int ans = 0;
        
        for(int i = 1;i<=N;++i){
            if(i%7==6 || i%7==0) continue;
            
            bool found = false;
            
            for(int j = 0;j<P;++j)
                if(i%a[j]==0)
                    found = true;
            
            if(found) ++ans;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
