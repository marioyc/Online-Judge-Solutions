#include <cstdio>
#include <string>
#include <map>

using namespace std;

int dp[1000][1000],bridges[1000][1000];
int id1[1000],id2[1000],val1[1000],val2[1000];
map<string, int> id;

int main(){
    int T,N1,N2;
    char name[11],os[11];
    
    scanf("%d",&T);
    
    while(T--){
        int cont = 0;
        id.clear();
        
        scanf("%d",&N1);
        
        for(int i = 0;i < N1;++i){
            scanf("%s %s %d",name,os,&val1[i]);
            if(id.find(os) == id.end()) id[os] = cont++;
            id1[i] = id[os];
        }
        
        scanf("%d",&N2);
        
        for(int i = 0;i < N2;++i){
            scanf("%s %s %d",name,os,&val2[i]);
            if(id.find(os) == id.end()) id[os] = cont++;
            id2[i] = id[os];
        }
        
        int ans = 0,best = 0;
        
        for(int i = 0;i < N1;++i){
            for(int j = 0;j < N2;++j){
                dp[i][j] = 0;
                bridges[i][j] = 0;
                
                if(i > 0 && (dp[i-1][j] > dp[i][j] || (dp[i-1][j] == dp[i][j] && bridges[i-1][j] < bridges[i][j]))){
                    dp[i][j] = dp[i-1][j];
                    bridges[i][j] = bridges[i-1][j];
                }
                
                if(j > 0 && (dp[i][j-1] > dp[i][j] || (dp[i][j-1] == dp[i][j] && bridges[i][j-1] < bridges[i][j]))){
                    dp[i][j] = dp[i][j-1];
                    bridges[i][j] = bridges[i][j-1];
                }
                
                if(id1[i] == id2[j]){
                    int total = val1[i] + val2[j],cont = 1;
                    
                    if(i > 0 && j > 0){
                        total += dp[i-1][j-1];
                        cont += bridges[i-1][j-1];
                    }
                    
                    if(total > dp[i][j] || (total == dp[i][j] && cont < bridges[i][j])){
                        dp[i][j] = total;
                        bridges[i][j] = cont;
                    }
                }
                
                if(dp[i][j] > ans || (dp[i][j] == ans && bridges[i][j] < best)){
                    ans = dp[i][j];
                    best = bridges[i][j];
                }
            }
        }
        
        printf("%d %d\n",ans,best);
    }
    
    return 0;
}
