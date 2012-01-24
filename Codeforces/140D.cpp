#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int n,a[100],T;
bool done[100][361];
pair<int, int> memo[100][361];

pair<int, int> solve(int pos, int t1, int t2){
    if(pos == n) return make_pair(0,0);
    
    pair<int, int> &ret = memo[pos][t1];
    
    if(!done[pos][t1]){
        ret = make_pair(0,0);
        
        if(t1 + a[pos] <= T){
            pair<int, int> aux = solve(pos + 1,t1 + a[pos],t2);
            ++aux.first;
            
            ret = aux;
        }
        
        if(t2 + a[pos] <= 720){
            pair<int, int> aux = solve(pos + 1,t1,t2 + a[pos]);
            ++aux.first;
            aux.second += abs(360 - (t2 + a[pos]));
            
            if(aux.first > ret.first || (aux.first == ret.first && aux.second < ret.second))
                ret = aux;
        }
        
        done[pos][t1] = true;
    }
    
    return ret;
}

int main(){
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    sort(a,a + n);
    
    int ans = 0,t = 0;
    
    for(int x = 10;x <= 360;++x){
        T = x;
        memset(done,false,sizeof done);
        
        pair<int, int> ret = solve(0,10,x);
        
        if(ret.first > ans || (ret.first == ans && ret.second < t)){
            ans = ret.first;
            t = ret.second;    
        }
    }
    
    printf("%d %d\n",ans,t);
    
    return 0;
}
