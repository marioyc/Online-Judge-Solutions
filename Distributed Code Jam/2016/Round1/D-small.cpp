#include <message.h>
#include <cassert>
#include <cstdio>
#include <vector>
#include "crates.h"

using namespace std;

#define MAXN 1000000
#define MOD 1000000007
#define MASTER_NODE 0

long long a[MAXN];
vector<int> pos,neg;

int main(){
    int N = GetNumStacks();
    long long nodes = NumberOfNodes();
    long long my_id = MyNodeId();

    if(my_id == MASTER_NODE){
        long long total = 0;

        for(int i = 0;i < N;++i){
            a[i] = GetStackHeight(i + 1);
            total += a[i];
        }

        int n = total % N;

        for(int i = 0;i < n;++i){
            a[i] -= (total + N - 1) / N;
        }

        for(int i = n;i < N;++i){
            a[i] -= total / N;
        }

        pos.clear();
        long long ans = 0;

        for(int i = N - 1;i >= 0;--i){
            if(a[i] > 0){
                while(!neg.empty() && a[i] > 0){
                    int cur = neg.back();
                    long long take = min(a[i],-a[cur]);
                    ans = (ans + take * (cur - i)) % MOD;
                    a[cur] += take;
                    a[i] -= take;
                    if(a[cur] == 0) neg.pop_back();
                }
                if(a[i] > 0){
                    pos.push_back(i);
                }
            }else if(a[i] < 0){
                while(!pos.empty() && a[i] < 0){
                    int cur = pos.back();
                    long long take = min(-a[i],a[cur]);
                    ans = (ans + take * (cur - i)) % MOD;
                    a[cur] -= take;
                    a[i] += take;
                    if(a[cur] == 0) pos.pop_back();
                }
                if(a[i] < 0){
                    neg.push_back(i);
                }
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}
