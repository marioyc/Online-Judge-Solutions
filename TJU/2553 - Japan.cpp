#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define MAX_SIZE 1001
int T[MAX_SIZE];

void update(int idx){
    for(;idx<MAX_SIZE;idx += (idx&-idx)) ++T[idx];
}

long long F(int idx){
    long long ret = 0;
    for(;idx>0;idx -= (idx&-idx)) ret += T[idx];
    return ret;
}

pair<int, int> P[1000000];

int main(){
    int TC,N,M,K;
    
    scanf("%d",&TC);
    
    for(int tc = 1;tc<=TC;++tc){
        scanf("%d %d %d",&N,&M,&K);
        
        for(int i = 0;i<K;++i)
            scanf("%d %d",&P[i].first,&P[i].second);
        
        sort(P,P+K);
        memset(T,0,sizeof(T));
        
        long long ans = 0;
        
        for(int i = 0;i<K;++i){
            ans += i-F(P[i].second);
            update(P[i].second);
        }
        
        printf("Test case %d: %lld\n",tc,ans);
    }
    
    return 0;
}
