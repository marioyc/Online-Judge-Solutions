#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAXN 200005

int pos[MAXN];
vector< pair<int, int> > v;

int bit[MAXN];

void update(int idx, int val){
    for(int x = idx;x < MAXN;x += x & -x)
        bit[x] += val;
}

int query(int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

#define MAXQ 200005

pair< pair<int, int>, int > q[MAXQ];
int ans[MAXQ];

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 1,p;i <= n;++i){
        scanf("%d",&p);
        pos[p] = i;
    }
    
    for(int i = 1;i <= n;++i){
        for(int j = i;j <= n;j += i){
            int x = pos[i],y = pos[j];
            if(x > y) swap(x,y);
            v.push_back(make_pair(x,y));
            update(y,1);
        }
    }
    
    sort(v.begin(),v.end());
    int nv = v.size();
    
    for(int i = 0;i < m;++i){
        scanf("%d %d",&q[i].first.first,&q[i].first.second);
        q[i].second = i;
    }
    
    sort(q,q + m);
    
    for(int i = 1,pq = 0,pv = 0;i <= n;++i){
        while(pq < m && q[pq].first.first == i){
            ans[ q[pq].second ] = query(q[pq].first.second);
            ++pq;
        }
        
        while(pv < nv && v[pv].first == i){
            update(v[pv].second,-1);
            ++pv;
        }
    }
    
    for(int i = 0;i < m;++i)
        printf("%d\n",ans[i]);
    
    return 0;
}
