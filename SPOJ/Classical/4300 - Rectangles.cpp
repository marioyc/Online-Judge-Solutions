#include <cstdio>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    int ans = 0;
    
    for(int i = 1;i <= N / i;++i)
        ans += N / i - i + 1;
    
    printf("%d\n",ans);
    
    return 0;
}
