#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int val[N];
    vector<int> L[N];
    
    scanf("%d",&val[0]);
    
    for(int i = 1,p;i<N;++i){
        scanf("%d %d",&p,&val[i]);
        L[p].push_back(i);
    }
    
    int Q[N],head = 0,tail = 0;
    
    Q[0] = 0;
    ++tail;
    
    for(int i = 0;i<N;++i){
        int aux = Q[head];
        ++head;
        
        for(int i = L[aux].size()-1;i>=0;--i){
            Q[tail] = L[aux][i];
            ++tail;
        }
    }
    
    long long dp1[N],dp2[N];
    
    for(int i = N-1;i>=0;--i){
        dp1[Q[i]] = val[Q[i]];
        dp2[Q[i]] = 0;
        
        for(int j = L[Q[i]].size()-1;j>=0;--j){
            int son = L[Q[i]][j];
            dp1[Q[i]] += dp2[son];
            dp2[Q[i]] += max(dp1[son],dp2[son]);
        }
    }
    
    printf("%lld\n",max(dp1[0],dp2[0]));
    
    return 0;
}
