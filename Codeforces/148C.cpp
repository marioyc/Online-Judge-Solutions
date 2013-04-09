#include <cstdio>

using namespace std;

int main(){
    int n,a,b;
    
    scanf("%d %d %d",&n,&a,&b);
    
    if((1 << b) + a > 50000 || (n > 1 && a == n - 1)) printf("-1\n");
    else{
        int t[n],sz = 0;
        t[sz++] = 1;
        
        for(int i = 0,sum = 1;i < b;++i){
            t[sz++] = sum + 1;
            sum += sum + 1;
        }
        
        for(int i = 0;i < n - a - b - 1;++i){
            t[sz] = 1;
            ++sz;
        }
        
        for(int i = 0;i < a;++i){
            t[sz] = (1 << b) + i + 1;
            ++sz;
        }
        
        for(int i = 0;i < n;++i) printf("%d ",t[i]);
        printf("\n");
    }
    
    return 0;
}
