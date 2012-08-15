#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

pair<unsigned long long, int> a[100001];

int main(){
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    vector<int> aux(K,0);
    
    a[0] = make_pair(0,0);
    
    for(int i = 0,x;i < N;++i){
        scanf("%d",&x);
        
        for(int j = 0;j < K;++j)
            if(x & (1 << j))
                ++aux[j];
        
        int mn = aux[0];
        
        for(int j = 1;j < K;++j)
            mn = min(mn,aux[j]);
        
        for(int j = 0;j < K;++j)
            aux[j] -= mn;
        
        unsigned long long H = 0;
        
        for(int j = 0;j < K;++j)
            H = H * 100005 + aux[j];
        
        a[i + 1] = make_pair(H,i + 1);
    }
    
    sort(a,a + (N + 1));
    
    int ans = 0;
    
    for(int i = 0;i < N + 1;){
        int e = i;
        
        while(e < N + 1 && a[e].first == a[i].first) ++e;
        
        ans = max(ans,a[e - 1].second - a[i].second);
        i = e;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
