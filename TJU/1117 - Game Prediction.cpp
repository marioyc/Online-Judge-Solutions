#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int n,m,a[50],N,ans;
    bool used[20*50+1];
    
    for(int tc=1;;++tc){
        scanf("%d %d",&n,&m);
        if(n==0) break;
        
        for(int i=0;i<m;++i) scanf("%d",&a[i]);
        sort(a,a+m);
        
        memset(used,false,sizeof(used));
        for(int i=0;i<m;++i) used[a[i]] = true;
        
        N = n*m;
        ans = m;
        
        for(int i=0;i<m;++i){
            for(int j=a[i]+1;j<=N;++j){
                if(!used[j]){
                    used[j] = true;
                    --ans;
                    break;
                }
            }
        }
        
        printf("Case %d: %d\n",tc,ans);
    }
    
    return 0;
}
