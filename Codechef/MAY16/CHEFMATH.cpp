#include <cstdio>
#include <vector>
#include <map>

using namespace std;

#define MAXK 10
#define MOD 1000000007

vector<int> f;
map<int,int> memo[MAXK + 1][43];

int solve(int k, int pos, int x){
    if(x == 0){
        if(k == 0) return 1;
        return 0;
    }
    if(k == 0) return 0;
    if(x > (long long)k * f[pos]) return 0;

    if(memo[k][pos].find(x) != memo[k][pos].end())
        return memo[k][pos][x];

    int ret = 0;

    for(int i = 0;i <= pos;++i){
        if(x >= f[i]){
            ret += solve(k - 1,i,x - f[i]);
            if(ret >= MOD) ret -= MOD;
        }
    }

    memo[k][pos][x] = ret;
    return ret;
}

int main(){
    f.push_back(1);
    f.push_back(2);

    int a = 1,b = 2;

    for(int i = 2,c;i < 43;++i){
        c = a + b;
        a = b;
        b = c;
        f.push_back(b);
    }

    int Q,X,K;

    scanf("%d",&Q);

    while(Q--){
        scanf("%d %d",&X,&K);
        printf("%d\n",solve(K,42,X));
    }

    return 0;
}
