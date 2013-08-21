#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,a,b,h[10];
int memo[10][17][17],choose[10][17][17];

int solve(int pos, int last1, int last2){
    if(pos == n - 1){
        if(b * last2 > h[pos]) return 0;
        return 200;
    }
    
    int &ret = memo[pos][last1][last2];
    
    if(ret == -1){
        ret = 200;
        
        for(int i = 0;i <= 16;++i){
            if(b * i + a * last2 + b * last1 > h[pos - 1]){
                int aux = i + solve(pos + 1,last2,i);
                if(aux < ret){
                    ret = aux;
                    choose[pos][last1][last2] = i;
                }
            }
        }
    }
    
    return ret;
}

int main(){
    scanf("%d %d %d",&n,&a,&b);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&h[i]);
    
    memset(memo,-1,sizeof memo);
    printf("%d\n",solve(1,0,0));
    
    for(int i = 1,last1 = 0,last2 = 0;i < n - 1;++i){
        int m = choose[i][last1][last2];
        for(int j = 0;j < m;++j) printf("%d ",i + 1);
        last1 = last2; last2 = m;
    }
    
    printf("\n");
    
    return 0;
}
