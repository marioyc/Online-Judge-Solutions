#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_Q 200000
int q,ans[MAX_Q];

struct event{
    int ind,s,e;
    
    event(){};
    event(int ind, int s, int e) : ind(ind), s(s), e(e) {};
    
    bool operator < (event E)const{
        return e<E.e;
    }
}e[MAX_Q];

#define MAX_N 30000
int n,a[MAX_N],T[MAX_N+1];

void update(int idx, int val){
    for(;idx<=n;idx += (idx & -idx)) T[idx] += val;
}

int F(int idx){
    int sum = 0;
    for(;idx>0;idx -= (idx & -idx)) sum += T[idx];
    return sum;
}

#define MAX_VAL 1000000+1
int last[MAX_VAL];

void solve(){
    sort(e,e+q);
    
    int pos = 0,tot = 0;
    memset(last,-1,sizeof(last));
    memset(T,0,sizeof(T));
    
    for(int i = 0;i<n;++i){
        if(last[a[i]]!=-1) update(last[a[i]],-1);
        else ++tot;
        
        update(i+1,1);
        last[a[i]] = i+1;
        
        while(pos<q && e[pos].e==i+1){
            ans[e[pos].ind] = tot-F(e[pos].s-1);
            ++pos;
        }
    }
    
    for(int i = 0;i<q;++i) printf("%d\n",ans[i]);
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;++i) scanf("%d",&a[i]);
    
    scanf("%d",&q);
    for(int i = 0,x,y;i<q;++i){
        scanf("%d %d",&x,&y);
        e[i] = event(i,x,y);
    }
    
    solve();
    
    return 0;
}
