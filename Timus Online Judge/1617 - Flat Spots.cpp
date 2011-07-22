#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N,cont[101];
    
    scanf("%d",&N);
    
    memset(cont,0,sizeof(cont));
    
    for(int i = 0,diam;i < N;++i){
        scanf("%d",&diam);
        ++cont[diam - 600];
    }
    
    int ans = 0;
    
    for(int i = 0;i <= 100;++i)
        ans += cont[i] / 4;
    
    printf("%d\n",ans);
    
    return 0;
}
