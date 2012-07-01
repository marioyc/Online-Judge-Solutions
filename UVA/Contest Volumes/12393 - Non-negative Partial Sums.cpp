#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define MAXN 1000000

int a[MAXN],sum,sum2,head,tail;
pair<int, int> Q[2 * MAXN];

int main(){
    int n,m;
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        
        head = tail = 0;
        sum = 0;
        
        for(int i = 1;i <= n;++i){
            sum += a[i - 1];
            while(head < tail && Q[tail - 1].first >= sum) --tail;
            Q[tail++] = make_pair(sum,i);
        }
        
        int ans = 0;
        sum2 = 0;
        
        for(int i = 0;i < n;++i){
            while(Q[head].second <= i) ++head;
            
            if(Q[head].first - sum2 >= 0) ++ans;
            
            sum += a[i]; sum2 += a[i];
            while(head < tail && Q[tail - 1].first >= sum) --tail;
            Q[tail++] = make_pair(sum,i + n + 1);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
