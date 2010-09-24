#include <cstdio>

using namespace std;

int R,C,K,ways,k,r2,c2;
char M[5][6];
bool visited[5][5];

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

void search(int r, int c){
    if(k>K) return;
    if(r==0 && c==C-1){
        ways++;
        return;
    }
    
    k++;
    
    for(int i=0;i<4;i++){
        r2=r+dr[i];
        c2=c+dc[i];
        
        if(r2<0 || r2>=R || c2<0 || c2>=C || visited[r2][c2]) continue;
        
        visited[r2][c2]=true;
        search(r2,c2);
        visited[r+dr[i]][c+dc[i]]=false;
    }
    
    k--;
}

int main(){
    scanf("%d %d %d",&R,&C,&K);
    
    for(int i=0;i<R;i++)
        scanf("%s",M[i]);
    
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(M[i][j]=='T') visited[i][j]=true;
            else visited[i][j]=false;
    
    ways=0;
    k=1;
    visited[R-1][0]=true;
    search(R-1,0);
    
    printf("%d\n",ways);
    
    return 0;
}
