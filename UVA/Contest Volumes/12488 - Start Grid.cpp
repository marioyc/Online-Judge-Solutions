#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,a[24],b[24];
    
    while(scanf("%d",&N) == 1){
        for(int i = 0;i < N;++i) scanf("%d",&a[i]);
        for(int i = 0;i < N;++i) scanf("%d",&b[i]);
        
        int ans = 0;
        
        for(int i = 0;i < N;++i){
            int pos = 0;
            
            for(int j = 0;j < N;++j)
                if(a[j] == b[i]) pos = j;
            
            for(int j = pos;j > i;--j)
                swap(a[j],a[j - 1]);
            
            ans += max(0,pos - i);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
