#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct emp{
    int id,s,h;
    
    emp(){}
};

bool cmp1(emp a, emp b){
    return a.h < b.h;
}

bool cmp2(emp a, emp b){
    return a.s < b.s;
}

int bit[30001];
int last[30001];

void update(int idx, int val){
    for(int x = idx;x <= 30000;x += x & -x)
        bit[x] = min(bit[x],val);
}

int query(int idx){
    int ret = 30001;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret = min(ret,bit[x]);
    
    return ret;
}

int ans1[30001],ans2[30001];
vector<int> L[30001];

void dfs(int cur, int prev){
    ans2[cur] = 0;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(to != prev){
            dfs(to,cur);
            ans2[cur] += 1 + ans2[to];
        }
    }
}

int main(){
    int T,N,Q,x;
    emp A[30000];
    map<int, int> id;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&Q);
        
        for(int i = 0;i < N;++i)
            scanf("%d %d %d",&A[i].id,&A[i].s,&A[i].h);
        
        sort(A,A + N,cmp1);
        
        for(int i = 0,j = 1;i < N;){
            int e = i;
            
            while(e < N && A[e].h == A[i].h) ++e;
            
            while(i < e) A[i++].h = j;
            
            ++j;
        }
        
        sort(A,A + N,cmp2);
        memset(last,-1,sizeof last);
        int r;
        
        for(int i = 1;i <= N;++i) bit[i] = 30001;
        for(int i = 0;i < N;++i) id[ A[i].id ] = i;
        
        for(int i = N - 1;i >= 0;--i){
            L[i].clear();
            
            if(i == N - 1){
                r = i;
                ans1[r] = 0;
            }else{
                int p = query(N + 1 - A[i].h);
                ans1[i] = A[p].id;
                L[p].push_back(i);
            }
            
            update(N + 1 - A[i].h,i);
        }
        
        dfs(r,-1);
        
        while(Q--){
            scanf("%d",&x);
            x = id[x];
            printf("%d %d\n",ans1[x],ans2[x]);
        }
    }
    
    return 0;
}
