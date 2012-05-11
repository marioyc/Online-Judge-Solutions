#include <cstdio>

using namespace std;

#define MAXN 100000

int a[MAXN];
long long bit[MAXN + 1],bit2[MAXN + 1];

int main(){
    int N;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    
    long long ans = 0;
    
    for(int i = N - 1;i >= 0;--i){
        int cont = 0;
        
        for(int x = a[i];x > 0;x -= x & -x){
            ans += bit[x];
            cont += bit2[x];
        }
        
        for(int x = a[i];x <= MAXN;x += x & -x){
            bit[x] += a[i];
            ++bit2[x];
        }
        
        ans += (long long)cont * a[i];
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
