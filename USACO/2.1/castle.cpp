/*
ID:zion_ba1
LANG:C++
TASK:castle
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int cont;
char map[101][102];
bool visited[101][101];

int dr[]={0,-1,0,1};
int dc[]={-1,0,1,0};
int W,H;

void dfs(int r, int c){
    if(map[r][c]=='.') cont++;
    
    for(int k=0;k<4;k++)
        if((map[r+dr[k]][c+dc[k]]==' ' || map[r+dr[k]][c+dc[k]]=='.') && !visited[r+dr[k]][c+dc[k]]){
            visited[r+dr[k]][c+dc[k]]=true;
            dfs(r+dr[k],c+dc[k]);
        }
}

int main(){
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    
    int M,N,x;
    scanf("%d %d",&M,&N);
    W=2*M+1; H=2*N+1;
    
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            map[i][j]='x';
    
    for(int i=0;i<W;i++) map[0][i]=map[H-1][i]='+';
    for(int i=0;i<H;i++) map[i][0]=map[i][W-1]='+';
    
    for(int i=1;i<H;i+=2){
        for(int j=1;j<W;j+=2){
            map[i][j]='.';
            scanf("%d",&x);
            
            for(int k=0;k<4;k++)
                if(x & (1<<k)) map[i+dr[k]][j+dc[k]]='+';
                else map[i+dr[k]][j+dc[k]]=' ';
        }
    }
    
    int rooms=0;
    int mx=0;
    
    for(int i=0;i<H;i++) fill(visited[i],visited[i]+W,false);
    
    for(int i=1;i<H;i+=2){
        for(int j=1;j<W;j+=2){
            if(!visited[i][j]){
                rooms++;
                cont=0;
                visited[i][j]=true;
                dfs(i,j);
                mx=max(mx,cont);
            }
        }
    }
    
    printf("%d\n%d\n",rooms,mx);
    
    mx=0;
    int r,c;
    
    for(int i=1;i<W-1;i++){
        for(int j=H-2;j>=1;j--){
            if(map[j][i]=='+'){
                map[j][i]=' ';
                cont=0;
                for(int k=0;k<H;k++) fill(visited[k],visited[k]+W,false);
                
                dfs(j,i);
                
                if(cont>mx){
                    mx=cont;
                    c=i;
                    r=j;
                }
                
                map[j][i]='+';
            }
        }
    }
    
    char dir;
    
    if(r%2==1){
        dir='E';
        r=(r+1)/2;
        c=c/2;
    }else{
        dir='N';
        r=r/2+1;
        c=(c+1)/2;
    }
    
    printf("%d\n%d %d %c\n",mx,r,c,dir);
    
    
    return 0;
}
