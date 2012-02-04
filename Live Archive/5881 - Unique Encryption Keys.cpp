#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> P[1000000];
int a[1000000],b[1000000],last[1000000];
int ans[1000000];

bool cmp1(pair<int, int> p1, pair<int, int> p2){
    if(a[p1.first] < a[p2.first]) return true;
    return false;
}

int main(){
    int M,Q;
    
    while(true){
        scanf("%d %d",&M,&Q);
        
        if(M == 0 && Q == 0) break;
        
        for(int i = 0;i < M;++i)
            scanf("%d",&a[i]);
        
        for(int i = 0;i < M;++i)
            P[i].first = i;
        
        sort(P,P + M,cmp1);
        
        int n = 0;
        P[0].second = 0;
        
        for(int i = 1;i < M;++i){
            if(a[ P[i].first ] != a[ P[i - 1].first ]) n++;
            P[i].second = n;
        }
        
        sort(P,P + M);
        
        for(int i = 0;i < M;++i) last[i] = M;
        
        for(int i = M - 1;i >= 0;--i){
            if(last[ P[i].second ] != M)
                b[i] = last[ P[i].second ];
            else
                b[i] = M;
            
            last[ P[i].second ] = i;
        }
        
        ans[M - 1] = b[M - 1];
        
        for(int i = M - 2;i >= 0;--i)
            ans[i] = min(b[i],ans[i + 1]);
        
        for(int q = 0,s,e;q < Q;++q){
            scanf("%d %d",&s,&e);
            --s; --e;
            
            if(ans[s] > e) puts("OK");
            else printf("%d\n",a[ ans[s] ]);
        }
        
        puts("");
    }
    
    return 0;
}
