#include <cstdio>

using namespace std;

int main(){
    int N,M[100][100],up0[100][100],up1[100][100];
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i = 0;i<N;++i)
            for(int j = 0;j<N;++j)
                scanf("%d",&M[i][j]);
        
        for(int i = 0;i<N;++i){
            for(int j = 0;j<N;++j){
                up0[i][j] = (M[i][j]==0? 1 + (i>0? up0[i-1][j] : 0) : 0);
                up1[i][j] = (M[i][j]==1? 1 + (i>0? up1[i-1][j] : 0) : 0);
            }
        }
        
        int ans = 1;
        
        for(int i = 1;i+1<N;++i){
            for(int j = 0,cur = -1,prev = -1;j<N;++j){
                if(M[i][j]==0 && M[i-1][j]==1 && M[i+1][j]==1){
                    prev = cur; cur = j;
                    int L = cur-prev+1;
                    
                    if(prev==-1 || (L&1)==0 || L<=ans) continue;
                    
                    bool valid = true;
                    int m = (L>>1);
                    
                    if(i-m<0 || i+m>=N) continue;
                    
                    for(int k = 0;k<=m && valid;++k)
                        if(up0[i+k][prev+k]!=2*k+1 || up0[i+k][cur-k]!=2*k+1)
                            valid = false;
                    
                    for(int k = 0;k<m && valid;++k){
                        if(up1[i+m][prev+k]!=m-k || up1[i+m][cur-k]!=m-k)
                            valid = false;
                        if(up1[i-1-k][prev+k]<m-k || up1[i-1-k][cur-k]<m-k)
                            valid = false;
                    }
                    
                    if(valid) ans = L;
                }
            }
        }
        
        if(ans==1) printf("No solution\n");
        else printf("%d\n",ans);
    }
    
    return 0;
}
