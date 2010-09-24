#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,n,a,ans;
    scanf("%d",&T);
    
    int freq[10001];
    
    while(T--){
        memset(freq,0,sizeof(freq));
        
        scanf("%d",&n);
        ans = 0;
        
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            ++freq[a];
            if(freq[a]>ans) ans = freq[a];
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}

