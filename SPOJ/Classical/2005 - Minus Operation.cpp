#include <cstdio>
#include <cstring>

using namespace std;

int a[100],op[100];
short can[100][100001];

int main(){
    int T,n,m;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&m);
        
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        
        if(n == 1) printf("\n");
        else if(n == 2) printf("1\n");
        else{
            m = m - (a[0] - a[1]) + 50000;
            
            can[1][m] = 1;
            
            for(int i = 2,l = m,r = m;i < n;++i){
                memset(can[i],0,sizeof can[i]);
                
                for(int j = l;j <= r;++j){
                    if(can[i - 1][j]){
                        can[i][ j - a[i] ] = 1;
                        can[i][ j + a[i] ] = 2;
                    }
                }
                
                l -= (a[i] >= 0? a[i] : -a[i]);
                r += (a[i] >= 0? a[i] : -a[i]);
            }
            
            for(int i = n - 1,j = 50000;i >= 2;--i){
                if(can[i][j] == 1){
                    j += a[i];
                    op[i] = 1;
                }else{
                    j -= a[i];
                    op[i] = 2;
                }
            }
            
            op[1] = 2;
            
            for(int i = n - 1,cont = 0;i >= 1;--i){
                if(op[i] == 1) ++cont;
                else{
                    for(int j = 0;j < cont;++j)
                        printf("%d\n",i + 1);
                    
                    n -= cont;
                    cont = 0;
                }
            }
            
            for(int i = 1;i < n;++i)
                printf("1\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
