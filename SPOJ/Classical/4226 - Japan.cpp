#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_SIZE 1001

int T[MAX_SIZE];

void update(int idx, int val){
    for(;idx<MAX_SIZE;idx+=(idx & -idx)) T[idx]+=val;
}

int F(int idx){
    long long sum = 0;
    for(;idx>0;idx -= (idx & -idx)) sum += T[idx];
    return sum;
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
            update(P[i].second,1);
        }
        
        printf("Test case %d: %lld\n",tc,ans);
    }
    
    return 0;
}
