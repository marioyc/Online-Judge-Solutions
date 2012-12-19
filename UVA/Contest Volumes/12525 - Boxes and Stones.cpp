#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007
#define MAXS 200
#define MAXB 100

int memo[MAXB][MAXS + 1][MAXS + 1];

int solve(int pos, int s, int have){
    if(pos == 0){
        if(s) return 0;
        return have == 0? 1 : 0;
    }
    
    int &ret = memo[pos][s][have];
    
    if(ret == -1){
        ret = solve(pos - 1,s,have / 2);
        if(s) ret += solve(pos,s - 1,have + 1);
        if(ret >= MOD) ret -= MOD;
    }
    
    return ret;
}

int main(){
    int S,B;
    memset(memo,-1,sizeof memo);
    
    while(scanf("%d %d",&S,&B) == 2)
        printf("%d\n",solve(B - 1,S,0));
    
    return 0;
}
