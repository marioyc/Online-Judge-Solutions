#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int N;
    
    scanf("%d",&N);
    
    int M[100][100];
    
    for(int i=0;i<N*N;i++)
        for(int j=0;j<N*N;j++) scanf("%d",&M[i][j]);
    
    bool row[100][100];
    bool col[100][100];
    bool square[100][100];
    
    for(int i=0;i<N*N;i++){
        fill(row[i],row[i]+N*N,false);
        fill(col[i],col[i]+N*N,false);
        fill(square[i],square[i]+N*N,false);
    }
    
    bool ok=true;
    
    for(int i=0;i<N*N && ok;i++){
        for(int j=0;j<N*N && ok;j++){
            if(M[i][j]==0) continue;
            
            if(row[i][M[i][j]-1]) ok=false;
            else row[i][M[i][j]-1]=true;
            
            if(col[j][M[i][j]-1]) ok=false;
            else col[j][M[i][j]-1]=true;
            
            if(square[i/N*N+j/N][M[i][j]-1]) ok=false;
            else square[i/N*N+j/N][M[i][j]-1]=true;
        }
    }
    
    if(ok) printf("CORRECT\n");
    else printf("INCORRECT\n");
    
    return 0;
}
