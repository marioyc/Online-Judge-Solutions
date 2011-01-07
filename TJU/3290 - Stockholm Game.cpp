#include <cstdio>

using namespace std;

int main(){
    int T,N,x[10001];
    x[0] = 0;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 1;i<=N;++i)
            scanf("%d",&x[i]);
        
        int nim = 0;
        
        for(int i = N;i>0;i -= 2)
            nim ^= (x[i]-x[i-1]-1);
        
        if(nim) puts("windy will win");
        else puts("wqb will win");
    }
    
    return 0;
}
