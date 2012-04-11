#include <cstdio>
#include <cstring>

using namespace std;

int B,d[31];
int memo[31][21][2];

int solve(int pos, int have, int eq){
    if(have < 0) return 0;
    if(pos == -1) return have == 0;
    
    int &ret = memo[pos][have][eq];
    
    if(ret == -1){
        ret = solve(pos - 1,have,0 < d[pos]? 0 : eq);
        if(!eq || d[pos] >= 1) ret += solve(pos - 1,have - 1,1 < d[pos]? 0 : eq);
    }
    
    return ret;
}

int main(){
    int X,Y,K;
    
    scanf("%d %d %d %d",&X,&Y,&K,&B);
    
    for(int i = 0;i <= 30;++i){
        d[i] = Y % B;
        Y /= B;
    }
    
    memset(memo,-1,sizeof memo);
    int ans = solve(30,K,1);
    
    --X;
    
    for(int i = 0;i <= 30;++i){
        d[i] = X % B;
        X /= B;
    }
    
    memset(memo,-1,sizeof memo);
    ans -= solve(30,K,1);
    
    printf("%d\n",ans);
    
    return 0;
}
