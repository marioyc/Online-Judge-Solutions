#include <cstdio>

using namespace std;

int n,N,M[9][9];
bool R[9][10],C[9][10],sq[9][10],solved;

void solve(int r, int c){
    if(solved) return;
    if(r==N && c==0){
        solved=true;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j!=0) printf(" ");
                printf("%d",M[i][j]);
            }
            printf("\n");
        }
    }else{
        if(M[r][c]!=0) solve(c==N-1? r+1:r,c==N-1? 0:c+1);
        else{
            for(int i=1;i<=N;i++){
                if(R[r][i] || C[c][i] || sq[r/n*n+c/n][i]) continue;
                
                M[r][c]=i;
                R[r][i]=true;
                C[c][i]=true;
                sq[r/n*n+c/n][i]=true;
                
                solve(c==N-1? r+1:r,c==N-1? 0:c+1);
                
                if(solved) return;
                
                R[r][i]=false;
                C[c][i]=false;
                sq[r/n*n+c/n][i]=false;
            }
            M[r][c]=0;
        }
        
    }
}

int main(){
    bool line=false;
    
    while(scanf("%d",&n)==1){
        N=n*n;
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&M[i][j]);
        
        for(int i=0;i<N;i++)
            for(int j=1;j<=N;j++)
                R[i][j]=C[i][j]=sq[i][j]=false;
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                if(M[i][j]==0) continue;
                R[i][M[i][j]]=C[j][M[i][j]]=sq[i/n*n+j/n][M[i][j]]=true;
            }
        
        if(line) printf("\n");
        else line=true;
        
        solved=false;
        
        solve(0,0);
        
        if(!solved) printf("NO SOLUTION\n");
    }
    
    return 0;
}
