#include <cstdio>

using namespace std;

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    int ans = 0;
    
    for(int i = 0;i <= 40;++i)
        for(int j = 0;j <= 40;++j)
            if(i * i + j == n && i + j * j == m)
                ++ans;
    
    printf("%d\n",ans);
    
    return 0;
}
