#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    priority_queue<int> Q;
    int x,y;
    
    for(int i = 0;i < N;++i){
        scanf("%d",&x);
        Q.push(-x);
    }
    
    long long ans = 0;
    
    for(int i = 1;i < N;++i){
        x = Q.top(); Q.pop();
        y = Q.top(); Q.pop();
        
        Q.push(x + y);
        ans -= x + y;
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
