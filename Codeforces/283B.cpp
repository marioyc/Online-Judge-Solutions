#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAXN 200000

int a[MAXN + 5];
long long sum[MAXN + 5][2];
int visited[MAXN + 5][2];
bool cycle[MAXN + 5][2];
vector< pair<int, int> > path;
long long ans[MAXN + 5];

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 2;i <= n;++i)
        scanf("%d",&a[i]);
    
    memset(ans,-1,sizeof ans);
    visited[1][0] = true;
    cycle[1][0] = true;
    
    for(int i = n - 1;i >= 1;--i){
        if(!visited[1 + i][1]){
            path.clear();
            
            int pos = 1 + i,step = 1;
            
            while(!visited[pos][step] && pos > 0 && pos <= n){
                int nxt = min(max(0,(step == 0? pos + a[pos] : pos - a[pos])),n + 1);
                //printf("%d %d -> %d %d\n",pos,step,nxt,(step ^ 1));
                
                path.push_back(make_pair(pos,step));
                sum[pos][step] = a[pos];
                
                visited[pos][step] = i;
                
                pos = nxt;
                step ^= 1;
            }
            
            int m = path.size();
            
            if(cycle[pos][step] || visited[pos][step] == i){
                for(int i = m - 1;i >= 0;--i)
                    cycle[ path[i].first ][ path[i].second ] = true;
                continue;
            }
            
            if(pos != 0 && pos != n + 1)
                sum[ path[m - 1].first ][ path[m - 1].second ] += sum[pos][step];
            
            for(int i = m - 1;i >= 0;--i){
                if(i != m - 1)
                    sum[ path[i].first ][ path[i].second ] += sum[ path[i + 1].first ][ path[i + 1].second ];
                
                if(path[i].second == 1 && path[i].first >= 2)
                    ans[path[i].first - 1] = path[i].first + sum[ path[i].first ][ path[i].second ] - 1;
            }
        }
    }
    
    for(int i = 1;i <= n - 1;++i)
        printf("%I64d\n",ans[i]);
    
    return 0;
}
