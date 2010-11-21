#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
    while(a%b!=0){
        a %= b;
        swap(a,b);
    }
    
    return b;
}

using namespace std;

int main(){
    int N,P[1000];
    scanf("%d",&N);
    
    for(int i = 0;i<N;++i){
        scanf("%d",&P[i]);
        --P[i];
    }
    
    long long ans = 1;
    bool visited[1000];
    memset(visited,false,sizeof(visited));
    
    for(int i = 0;i<N;++i){
        if(visited[i]) continue;
        
        int pos = i,sz = 0;
        
        while(!visited[pos]){
            visited[pos] = true;
            pos = P[pos];
            ++sz;
        }
        
        ans = ans/gcd(ans,(long long)sz)*sz;
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
