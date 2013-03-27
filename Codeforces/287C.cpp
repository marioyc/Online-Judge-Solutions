#include <cstdio>

using namespace std;

int main(){
    int n;
    
    scanf("%d",&n);
    
    int p[n + 1];
    
    if(n % 4 <= 1){
        if(n % 2 == 1) p[(n + 1) / 2] = (n + 1) / 2;
        
        for(int s = 1,e = n;s < e;s += 2,e -= 2){
            p[s] = s + 1;
            p[s + 1] = e;
            p[e] = e - 1;
            p[e - 1] = s;
        }
        
        for(int i = 1;i <= n;++i)
            printf("%d ",p[i]);
        printf("\n");
    }else puts("-1");
    
    return 0;
}
