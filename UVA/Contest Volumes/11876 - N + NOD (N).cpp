#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int nod(int x){
    int ret = 1;
    
    for(int i = 2;i <= x / i;++i){
        if(x % i == 0){
            int cont = 1;
            
            while(x % i == 0){
                x /= i;
                ++cont;
            }
            
            ret *= cont;
        }
    }
    
    if(x > 1) ret *= 2;
    
    return ret;
}

int ans[1000001];

int main(){
    int x = 1;
    
    while(x <= 1000000){
        ++ans[x];
        x += nod(x);
    }
    
    for(int i = 1;i <= 1000000;++i)
        ans[i] += ans[i - 1];
    
    int T,A,B;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&A,&B);
        printf("Case %d: %d\n",tc,ans[B] - ans[A - 1]);
    }
    
    return 0;
}
