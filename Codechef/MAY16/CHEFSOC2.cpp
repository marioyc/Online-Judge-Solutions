#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007

int N,s,memo[1000][1000];
int A[1000];

int solve(int m, int dog){
    if(m == -1){
        if(dog == s) return 1;
        return 0;
    }

    int &ret = memo[m][dog];

    if(ret == -1){
        ret = 0;
        if(dog >= A[m])
            ret += solve(m - 1,dog - A[m]);
        if(dog + A[m] < N)
            ret += solve(m - 1,dog + A[m]);
        if(ret >= MOD)
            ret -= MOD;
    }

    return ret;
}

int main(){
    int T,M;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d %d",&N,&M,&s);
        --s;

        for(int i = 0;i < M;++i)
            scanf("%d",&A[i]);

        memset(memo,-1,sizeof memo);

        for(int i = 0;i < N;++i){
            printf("%d",solve(M - 1,i));
            if(i == N - 1) printf("\n");
            else printf(" ");
        }
    }

    return 0;
}
