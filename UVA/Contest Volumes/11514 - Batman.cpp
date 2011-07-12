#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> id;
int power[1001],cost[1001],defense[1001];
bool can[1001][1001];
int dp[1001][1001];

int main(){
    int P,V,E;
    char name[101],list[100001];
    
    while(true){
        scanf("%d %d %d",&P,&V,&E);
        if(P == 0 && V == 0 && E == 0) break;
        
        id.clear();
        
        for(int i = 1;i <= P;++i){
            scanf("%s %d %d",name,&power[i],&cost[i]);
            id[name] = i;
        }
        
        memset(can,false,sizeof(can));
        
        for(int i = 1;i <= V;++i){
            scanf("%s %d %s",name,&defense[i],list);
            
            int L = strlen(list);
            
            for(int j = 0;j < L;++j)
                if(list[j] == ',') list[j] = ' ';
            
            istringstream is(list);
            while(is >> name) can[i][id[name]] = true;
        }
        
        for(int i = 0;i <= P;++i) dp[0][i] = 0;
        for(int i = 1;i <= V;++i) dp[i][0] = E+1;
        
        for(int i = 1;i <= V;++i){
            for(int j = 1;j <= P;++j){
                dp[i][j] = dp[i][j-1];
                
                if(can[i][j] && power[j] >= defense[i])
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1] + cost[j]);
            }
        }
        
        if(dp[V][P] <= E) puts("Yes");
        else puts("No");
    }
    
    return 0;
}
