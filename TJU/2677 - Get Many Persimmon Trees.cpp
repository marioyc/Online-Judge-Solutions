#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N,R,C,Cmax,Rmax,M[100][100];
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        scanf("%d %d",&R,&C);
        memset(M,0,sizeof(M));
        
        for(int i = 0,r,c;i<N;++i){
            scanf("%d %d",&r,&c);
            --r; --c;
            M[r][c] = 1;
        }
        
        scanf("%d %d",&Rmax,&Cmax);
        
        for(int i = 0;i<R;++i)
            for(int j = 0;j<C;++j)
                M[i][j] += (i>0? M[i-1][j] : 0)+(j>0? M[i][j-1] : 0)-(i>0 && j>0? M[i-1][j-1] : 0);
        
        int ans = 0;
        
        for(int r = 0;r<R;++r){
            for(int c = 0;c<C;++c){
                int r2 = (r+Rmax-1<R? r+Rmax-1 : R-1), c2 = (c+Cmax-1<C? c+Cmax-1 : C-1);
                
                int aux = M[r2][c2]-(c>0? M[r2][c-1] : 0)-(r>0? M[r-1][c2] : 0)+(r>0 && c>0? M[r-1][c-1] : 0);
                
                if(aux>ans) ans = aux;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
