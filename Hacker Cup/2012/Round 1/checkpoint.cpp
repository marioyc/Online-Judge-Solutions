#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int INF = 10000001;

int ans[10000001];
int C[4501][4501];

int main(){
    for(int i = 1;i <= 10000000;++i)
        ans[i] = i;
    
    C[0][0] = 1;
    
    for(int i = 1;i <= 4500;++i){
        C[i][0] = 1;
        
        for(int j = 1;j < i;++j){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            
            if(C[i][j] >= INF) C[i][j] = INF;
            else{
                ans[C[i][j]] = min(ans[C[i][j]],i);
            }
        }
        
        C[i][i] = 1;
    }
    
    int T;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        int S;
        
        scanf("%d",&S);
        
        int best = S + 1;
        
        for(int i = 1;i <= S/i;++i){
            if(S % i == 0){
                int a = i,b = S / i;
                best = min(best,ans[a] + ans[b]);
            }
        }
        
        printf("Case #%d: ",tc);
        printf("%d",best);
        printf("\n");
    }
    
    return 0;
}
