#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int color[100],sum[100][100],memo[100][100];

int solve(int a, int b){
    if(b == a) return 0;
    if(b == a+1) return color[a] * color[b];
    
    int &ret = memo[a][b],aux;
    
    if(ret == -1){
        for(int i = a;i+1 <= b;++i){
            aux = sum[a][i] * sum[i+1][b] + solve(a,i) + solve(i+1,b);
            if(ret == -1 || aux < ret) ret = aux;
        }
    }
    
    return ret;
}

int main(){
    int n;
    
    while(scanf("%d",&n) == 1){
        for(int i = 0;i < n;++i) scanf("%d",&color[i]);
        for(int i = 0;i < n;++i) sum[i][i] = color[i];
        
        for(int i = 0;i < n;++i){
            for(int j = i+1;j < n;++j){
                sum[i][j] = sum[i][j-1] + color[j];
                if(sum[i][j] >= 100) sum[i][j] -= 100;
            }
        }
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(0,n-1));
    }
    
    return 0;
}
