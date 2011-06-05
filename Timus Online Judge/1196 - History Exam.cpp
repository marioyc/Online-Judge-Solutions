#include <cstdio>
#include <set>

using namespace std;

set<int> S;

int main(){
    int N,M;
    
    scanf("%d",&N);
    
    for(int i = 0,a;i < N;++i){
        scanf("%d",&a);
        S.insert(a);
    }
    
    scanf("%d",&M);
    
    int ans = 0;
    
    for(int i = 0,a;i < M;++i){
        scanf("%d",&a);
        if(S.find(a) != S.end()) ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
