#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 500000

int N;
pair<int, int> a[MAXN];
int mn1[MAXN],mn2[MAXN];
long long sum[MAXN];

int main(){
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d %d",&a[i].second,&a[i].first);
    
    sort(a,a + N);
    
    mn1[0] = a[0].second - a[0].first;
    sum[0] = a[0].first;
    
    for(int i = 1;i < N;++i){
        mn1[i] = min(mn1[i - 1],a[i].second - a[i].first);
        sum[i] = sum[i - 1] + a[i].first;
    }
    
    mn2[N - 1] = a[N - 1].second;
    
    for(int i = N - 2;i >= 0;--i)
        mn2[i] = min(mn2[i + 1],a[i].second);
    
    for(int i = 0;i < N;++i){
        long long aux1 = sum[i] + mn1[i];
        long long aux2 = mn2[i];
        if(i) aux2 += sum[i - 1];
        printf("%lld\n",min(aux1,aux2));
    }
    
    return 0;
}
