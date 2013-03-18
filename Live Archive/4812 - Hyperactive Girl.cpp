#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 100
#define MOD 100000000

int N,M;
pair<int, int> t[MAXN];
int memo[MAXN][MAXN];

int solve(int prev, int pos){
    if(t[pos].second == M) return 1;
    
    int &ret = memo[prev][pos];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = pos + 1;i < N;++i){
            if(t[i].first > t[pos].first && t[i].first <= t[pos].second && t[i].second > t[pos].second && (prev == pos || t[i].first > t[prev].second)){
                ret += solve(pos, i);
                if(ret >= MOD) ret -= MOD;
            }
        }
    }
    
    return ret;
}

int main(){
    while(true){
        scanf("%d %d",&M,&N);
        if(M == 0) break;
        
        for(int i = 0;i < N;++i)
            scanf("%d %d",&t[i].first,&t[i].second);
        
        sort(t,t + N);
        
        memset(memo,-1,sizeof memo);
        int ret = 0;
        
        for(int i = 0;i < N;++i){
            if(t[i].first == 0){
                ret += solve(i,i);
                if(ret >= MOD) ret -= MOD;
            }
        }
        
        printf("%d\n",ret);
    }
    
    return 0;
}
