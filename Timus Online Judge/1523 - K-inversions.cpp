#include <cstdio>

using namespace std;

#define MAX_VAL 20000

const int MOD = 1000000000;
int T[9][MAX_VAL+1];

void update(int A[], int idx, int val){
    for(int x = idx;x<=MAX_VAL;x += (x & -x))
        A[x] = (A[x]+val)%MOD;
}

int F(int A[], int idx){
    int ret = 0;
    
    for(int x = idx;x>0;x -= (x & -x))
        ret = (ret+A[x])%MOD;
    
    return ret;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    
    int ans = 0;
    
    for(int i = 0,a;i<n;++i){
        scanf("%d",&a);
        a = n+1-a;
        
        update(T[0],a,1);
        
        for(int j = 1;j+1<k;++j)
            update(T[j],a,F(T[j-1],a-1));
        
        ans = (ans+F(T[k-2],a-1))%MOD;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
