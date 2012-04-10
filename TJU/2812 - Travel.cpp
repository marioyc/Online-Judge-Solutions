#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,cost[100][100],inc[100][100];
int memo[100][100];
bool done[100][100];

int solve(int pos, int day){
    if(day == m) return 0;
    
    int &ret = memo[pos][day];
    
    if(!done[pos][day]){
        done[pos][day] = true;
        
        for(int i = 0;i < n;++i){
            int aux = -cost[pos][i] + inc[day][i] + solve(i,day + 1);
            
            if(i == 0) ret = aux;
            else ret = max(ret,aux);
        }
    }
    
    return ret;
}

int main(){
    while(true){
        scanf("%d %d",&n,&m);
        if(n == 0 && m == 0) break;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                scanf("%d",&cost[i][j]);
        
        for(int i = 0;i < m;++i)
            for(int j = 0;j < n;++j)
                scanf("%d",&inc[i][j]);
        
        memset(done,false,sizeof done);
        printf("%d\n",solve(0,0));
    }
    
    return 0;
}
