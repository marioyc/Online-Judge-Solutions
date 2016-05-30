#include <message.h>
#include <cstdio>
#include <algorithm>
#include "winning_move.h"

using namespace std;

#define MASTER_NODE 0

long long a[1000];

int main(){
    int N = GetNumPlayers();
    int my_id = MyNodeId();

    if(my_id == MASTER_NODE){
        for(int i = 0;i < N;++i){
            a[i] = GetSubmission(i);
        }
        sort(a,a + N);
        long long ans = 0;
        for(int i = 0;i < N;){
            int e = i;
            while(e < N && a[e] == a[i]) ++e;
            if(e == i + 1){
                ans = a[i];
                break;
            }
            i = e;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
