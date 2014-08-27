#include <cstdio>

using namespace std;

int main(){
    int T,x[4],y[4],z[4];
    
    scanf("%d",&T);
    
    while(T--){
        for(int i = 0;i < 4;++i)
            scanf("%d %d %d",&x[i],&y[i],&z[i]);
        
        for(int i = 1;i < 4;++i){
            x[i] -= x[0];
            y[i] -= y[0];
            z[i] -= z[0];
        }
        
        int det = x[1] * y[2] * z[3] + x[2] * y[3] * z[1] + x[3] * y[1] * z[2] - z[1] * y[2] * x[3] - z[2] * y[3] * x[1] - z[3] * y[1] * x[2];
        printf("%s\n",det == 0? "YES" : "NO");
    }
    
    return 0;
}
