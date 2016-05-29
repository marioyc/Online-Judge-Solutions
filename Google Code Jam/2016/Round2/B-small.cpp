#include <cassert>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 200

double p[MAXN];
int N,K;
vector<int> chosen,mask_v;

double solve(int pos, int have){
    if(have == 0){
        double ret = 0;
        for(int m : mask_v){
            double aux = 1;
            for(int i = 0;i < K;++i){
                if(m >> i & 1) aux *= p[ chosen[i] ];
                else aux *= (1 - p[ chosen[i] ]) ;
            }
            ret += aux;
        }
        return ret;
    }
    if(pos == -1) return 0;

    chosen.push_back(pos);
    double ret = solve(pos - 1,have - 1);
    chosen.pop_back();
    ret = max(ret,solve(pos - 1,have));
    return ret;
}

int main(){
    //ios::sync_with_stdio(0);

    int T;

    cin >> T;

    for(int tc = 1;tc <= T;++tc){
        cin >> N >> K;

        for(int i = 0;i < N;++i)
            cin >> p[i];

        if(N <= 16){
            mask_v.clear();

            for(int i = 0;i < (1 << K);++i){
                if(__builtin_popcount(i) == K / 2)
                    mask_v.push_back(i);
            }

            chosen.clear();
            cout << "Case #" << tc << ": ";
            printf("%.10f\n",solve(N - 1,K));
        }
    }

    return 0;
}
