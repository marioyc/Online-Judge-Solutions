#include <cstdio>

using namespace std;

int main(){
    int a,b,c,d;
    
    scanf("%d %d %d %d",&a,&b,&c,&d);
    
    int n,ans = 0;
    
    scanf("%d",&n);
    
    for(int i = 1;i <= n;++i)
        if(i % a == 0 || i % b == 0 || i % c == 0 || i % d == 0)
            ++ans;
    
    printf("%d\n",ans);
    
    return 0;
}
