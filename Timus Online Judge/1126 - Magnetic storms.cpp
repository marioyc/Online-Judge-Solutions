#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    int M,x;
    scanf("%d",&M);
    
    int a[25001],N = 0;
    
    while(true){
        scanf("%d",&a[N]);
        if(a[N]==-1) break;
        ++N;
    }
    
    priority_queue<int> Q;
    for(int i = 0;i<M;++i) Q.push(a[i]);
    printf("%d\n",Q.top());
    N -= M;
    
    int done[100001];
    memset(done,0,sizeof(done));
    
    for(int i = 0;i<N;++i){
        Q.push(a[M+i]);
        ++done[a[i]];
        
        while(done[Q.top()]){
            --done[Q.top()];
            Q.pop();
        }
        
        printf("%d\n",Q.top());
    }
    
    return 0;
}
