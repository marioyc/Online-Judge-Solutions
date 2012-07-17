#include <cstdio>
#include <algorithm>

using namespace std;

int N,a[250001];
int bit[50001];
int bit2[501][50001];

void update(int idx, int idy, int val){
    for(int x = idx;x <= 500;x += x & -x)
        for(int y = idy;y <= 50000;y += y & -y)
            bit2[x][y] += val;
}

int query(int idx, int idy){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        for(int y = idy;y > 0;y -= y & -y)
            ret += bit2[x][y];
    
    return ret;
}

int countInv(int pos){
    int x = (pos + 499) / 500;
    int ret = query(x - 1,50000) - query(x - 1,a[pos]) + query(500,a[pos] - 1) - query(x,a[pos] - 1);
    
    int r = min(x * 500,N),l = x * 500 - 499;
    
    for(int i = l;i < pos;++i)
        if(a[i] > a[pos]) ++ret;
    
    for(int i = pos + 1;i <= r;++i)
        if(a[i] < a[pos]) ++ret;
    
    return ret;
}

int main(){
    int Q;
    
    scanf("%d",&N);
    
    for(int i = 1;i <= N;++i)
        scanf("%d",&a[i]);
    
    long long inv = 0;
    
    for(int i = 1;i <= N;++i){
        inv += i - 1;
        
        for(int x = a[i];x > 0;x -= x & -x)
            inv -= bit[x];
        
        for(int x = a[i];x <= 250000;x += x & -x)
            ++bit[x];
    }
    
    for(int i = 1;i <= N;++i)
        update((i + 499) / 500,a[i],1);
    
    scanf("%d",&Q);
    
    int x,y;
    
    while(Q--){
        scanf("%d %d",&x,&y);
        
        inv -= countInv(x);
        
        int idx = (x + 499) / 500;
        
        update(idx,a[x],-1);
        update(idx,y,1);
        a[x] = y;
        
        inv += countInv(x);
        
        printf("%lld\n",inv);
    }
    
    return 0;
}
