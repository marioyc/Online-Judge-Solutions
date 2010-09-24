/*
ID:zion_ba1
LANG:C++
TASK:milkweed
*/

#include <iostream>
#include <queue>

using namespace std;

struct node{
    int x,y,cont;
    
    node(){
    }
    
    node(int _x, int _y, int _cont){
        x=_x; y=_y; cont=_cont;
    }
};

int main(){
    freopen("milkweed.in","r",stdin);
    freopen("milkweed.out","w",stdout);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int X,Y,Mx,My;
    scanf("%d %d %d %d",&X,&Y,&Mx,&My);
    
    Mx--;
    My=Y-My;
    
    char M[X][Y+1];
    
    for(int i=0;i<X;i++) scanf("%s",M[i]);
    
    int ans=0;
    
    bool visited[X][Y];
    
    for(int i=0;i<X;i++)
        for(int j=0;j<Y;j++)
            visited[i][j]=false;
    
    queue<node> Q;
    Q.push(node(Mx,My,0));
    visited[Mx][My]=true;
    
    const int dx[]={-1,-1,-1,0,0,1,1,1};
    const int dy[]={-1,0,1,-1,1,-1,0,1};
    
    while(!Q.empty()){
        node aux=Q.front();
        Q.pop();
        
        ans=aux.cont;
        
        for(int i=0;i<8;i++){
            int x=aux.x+dx[i],y=aux.y+dy[i];
            
            if(x<0 || x>=X || y<0 || y>=Y || M[x][y]=='*' || visited[x][y]) continue;
            visited[x][y]=true;
            
            Q.push(node(x,y,aux.cont+1));
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
