#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int bit[50001];
long long ans[50001];

void update(int idx, int val){
    for(int x = idx;x <= 50000;x += x & -x)
        bit[x] += val;
}

int query(int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    pair<int, int> P[N];
    
    for(int i = 0;i < N;++i){
        scanf("%d",&P[i].first);
        P[i].second = i + 1;
    }
    
    sort(P,P + N);
    
    for(int i = 1;i <= N;++i)
        update(i,1);
    
    long long pos = 0;
    
    for(int i = 0,t = 0,m = N;i < N;){
        int e = i;
        
        while(e < N && P[e].first == P[i].first) ++e;
        
        pos += (long long)(P[i].first - t - 1) * m;
        
        for(int j = i;j < e;++j)
            ans[ P[j].second ] = pos + query(P[j].second);
        
        for(int j = i;j < e;++j)
            update(P[j].second,-1);
        
        pos += m;
        m -= e - i;
        t = P[i].first;
        i = e;
    }
    
    for(int i = 1;i <= N;++i)
        printf("%lld\n",ans[i]);
    
    return 0;
}
