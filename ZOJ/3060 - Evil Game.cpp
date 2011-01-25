#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int R,C,M[100][100],sum[100][101];
int left[100][100],right[100][100],memo[100][100];
bool done[100][100];

int solve(int r, int c){
    int &ret = memo[r][c];
    
    if(!done[r][c]){
        if(r==R-1) ret = sum[r][C]-sum[r][c]+left[r][c];
        else{
            for(int i = 0;i<C;++i){
                int c1 = min(c,i),c2 = max(c,i);
                int aux = sum[r][c2+1]-sum[r][c1]+left[r][c1]+right[r][c2]+solve(r+1,i);
                
                if(i==0 || aux>ret) ret = aux;
            }
        }
        
        done[r][c] = true;
    }
    
    return ret;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&R,&C);
        
        for(int i = 0;i<R;++i)
            for(int j = 0;j<C;++j)
                scanf("%d",&M[i][j]);
        
        for(int i = 0;i<R;++i){
            sum[i][0] = 0;
            
            for(int j = 1;j<=C;++j)
                sum[i][j] = sum[i][j-1]+M[i][j-1];
            
            left[i][0] = 0;
            
            for(int j = 1;j<C;++j)
                left[i][j] = max(0,left[i][j-1]+M[i][j-1]-abs(M[i][j]));
            
            right[i][C-1] = 0;
            
            for(int j = C-2;j>=0;--j)
                right[i][j] = max(0,right[i][j+1]+M[i][j+1]-abs(M[i][j]));
        }
        
        memset(done,false,sizeof(done));
        printf("%d\n",solve(0,0));
    }
    
    return 0;
}
