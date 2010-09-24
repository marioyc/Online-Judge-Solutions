#include <iostream>
#include <queue>

using namespace std;

struct nodo{
    int y,x;
    
    nodo(int _y, int _x){
        y=_y;
        x=_x;
    }
};

int main(){    
    int X_size,Y_size,N;
    
    scanf("%d %d %d",&X_size,&Y_size,&N);
    
    char M[Y_size][X_size+1];
    
    for(int i=0;i<Y_size;i++)
        for(int j=0;j<X_size;j++)
            M[i][j]='0';
    
    int x,y,R,R2,c;
    bool visited[Y_size][X_size];
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    
    int x2,y2,d1,d2;
    
    for(int i=0;i<N;i++){
        scanf("%d %d %d %d",&x,&y,&R,&c);
        R2=R*R;
        
        memset(visited,false,sizeof(visited));
        
        queue<nodo> Q;
        Q.push(nodo(y,x));
        visited[y][x]=true;
        
        while(!Q.empty()){
            nodo aux=Q.front();
            Q.pop();
            
            M[aux.y][aux.x]='0'+c;
            
            for(int i=0;i<4;i++){
                y2=aux.y+dy[i];
                x2=aux.x+dx[i];
                d1=y2-y;
                d2=x2-x;
                
                if(x2>=0 && x2<X_size && y2>=0 && y2<Y_size && d1*d1+d2*d2<=R2 && !visited[y2][x2]){
                    visited[y2][x2]=true;
                    Q.push(nodo(y2,x2));
                }
            }
        }
    }
    
    for(int i=0;i<Y_size;i++){
        for(int j=0;j<X_size;j++) printf("%c",M[i][j]);
        printf("\n");
    }
    
    return 0;
}
