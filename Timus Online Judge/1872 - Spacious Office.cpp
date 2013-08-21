#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MAXN 1000

struct team{
    int id,l,r;
    
    team(){}
    
    bool operator < (team X)const{
        if(r != X.r) return r < X.r;
        return l > X.l;
    }
};

int N,a[MAXN];
pair<int, int> b[MAXN];
set< pair<int, int> > S;

int l[MAXN],r[MAXN];
team t[MAXN];

int ans_team[MAXN],ans_office[MAXN];

int M,T[4 * 2 * MAXN];
vector<int> X;

int query(int node, int l, int r, int x, int y){
    if(r < x || l > y) return -1;
    
    if(x <= l && r <= y) return T[node];
    
    int mi = (l + r) >> 1;
    
    return max(query(2 * node + 1,l,mi,x,y),query(2 * node + 2,mi + 1,r,x,y));
}

void update(int node, int l, int r, int x, int val){
    if(r < x || l > x) return;
    
    if(l == r) T[node] = max(T[node],val);
    else{
        int mi = (l + r) >> 1;
        
        update(2 * node + 1,l,mi,x,val);
        update(2 * node + 2,mi + 1,r,x,val);
        T[node] = max(T[2 * node + 1],T[2 * node + 2]);
    }
}

int main(){
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%d",&a[i]);
        b[i].first = a[i]; b[i].second = i;
        S.insert(make_pair(a[i],i));
        X.push_back(a[i]);
    }
    
    for(int i = 0;i < N;++i){
        scanf("%d %d",&l[i],&r[i]);
        t[i].l = l[i]; t[i].r = r[i]; t[i].id = i;
        X.push_back(t[i].l);
    }
    
    sort(b,b + N);
    sort(t,t + N);
    
    sort(X.begin(),X.end());
    M = unique(X.begin(),X.end()) - X.begin();
    
    bool ok = true,found = false;
    
    for(int i = 0;i < N;++i){
        set< pair<int, int> >::iterator it = S.lower_bound(make_pair(t[i].l,0));
        
        if(it == S.end() || it->first > t[i].r) ok = false;
        else{
            ans_office[ it->second ] = t[i].id;
            ans_team[ t[i].id ] = it->second;
            S.erase(it);
        }
    }
    
    if(!ok) puts("Let's search for another office.");
    else{
        memset(T,-1,sizeof T);
        
        for(int i = 0;i < N;++i){
            int l2 = lower_bound(X.begin(),X.begin() + M,l[ ans_office[ b[i].second ] ]) - X.begin();
            int r2 = lower_bound(X.begin(),X.begin() + M,b[i].first) - X.begin();
            
            int ret = query(0,0,M - 1,l2,r2);
            if(ret >= b[i].first) found = true;
            
            update(0,0,M - 1,r2,r[ ans_office[ b[i].second ] ]);
        }
        
        if(found) puts("Ask Shiftman for help.");
        else{
            puts("Perfect!");
            
            for(int i = 0;i < N;++i)
                printf("%d ",ans_team[i] + 1);
            printf("\n");
        }
    }
    
    return 0;
}
