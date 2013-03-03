#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

pair<long long, long long> choco[100000];

int main(){
    int N;
    long long B;
    
    scanf("%d %lld",&N,&B);
    
    for(int i = 0;i < N;++i)
        scanf("%lld %lld",&choco[i].first,&choco[i].second);
    
    sort(choco,choco + N);
    
    long long ans = 0;
    
    for(int i = 0;i < N && choco[i].first <= B;++i){
        long long c = min(choco[i].second,B / choco[i].first);
        B -= choco[i].first * c;
        ans += c;
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
