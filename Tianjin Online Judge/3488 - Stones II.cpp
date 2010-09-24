#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int T,n,a,b,ans;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        
        priority_queue<int> Q;
        
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            Q.push(-a);
        }
        
        ans = 0;
        
        for(int i=1;i<n;++i){
            a = Q.top(); Q.pop();
            b = Q.top(); Q.pop();
            Q.push(a+b);
            ans -= a+b;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
