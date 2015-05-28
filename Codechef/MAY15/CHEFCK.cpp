#include <cstdio>
#include <queue>
#include <map>

using namespace std;

#define MAXN 10000000
#define MOD 1000000007

int minK[MAXN];
deque< pair<int, int> > DQ;

int main(){
    int N,K,Q;

    scanf("%d %d %d",&N,&K,&Q);

    long long a,b,d,e;
    int c,f,r,s,t,m,A;

    scanf("%lld %lld %d %lld %lld %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&A);

    long long powt = t;

    DQ.push_back(make_pair(A,0));
    minK[0] = A;

    for(int i = 1;i < N;++i){
        powt *= t;
        if(powt >= s) powt %= s;

        if(powt <= r)
            A = (a * A % m * A + b * A + c) % m;
        else
            A = (d * A % m * A + e * A + f) % m;

        if(DQ.front().second == i - K)
            DQ.pop_front();

        while(!DQ.empty() && DQ.back().first > A)
            DQ.pop_back();

        DQ.push_back(make_pair(A,i));
        minK[i] = DQ.front().first;
    }

    int L1,La,Lc,Lm,D1,Da,Dc,Dm,L,R;

    scanf("%d %d %d %d %d %d %d %d",&L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);

    long long S = 0,P = 1;

    for(int i = 0;i < Q;++i){
        L1 = ((long long)La * L1 + Lc) % Lm;
        D1 = ((long long)Da * D1 + Dc) % Dm; 
        L = L1 + 1;
        R = min(L + K - 1 + D1,N);

        int ans = min(minK[R - 1],minK[L + K - 2]);
        S += ans;
        P = (P * ans) % MOD;
    }

    printf("%lld %lld\n",S,P);

    return 0;
}