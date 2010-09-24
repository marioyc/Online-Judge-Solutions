#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

struct nodo{
    int x,y,dist;
    
    nodo(){
    }
    
    nodo(int a, int b, int c){
        x=a;
        y=b;
        dist=c;
    }
};

int main(){    
    int T,C,R,aux,Ax,Ay,Bx,By,X,Y;
    bool obstacle[100][100];
    bool visited[100][100];
    nodo v;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d %d",&C,&R);
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                scanf("%d",&aux);
                obstacle[i][j]=aux;
                visited[i][j]=false;
            }
        }
        
        scanf("%d %d %d %d",&Ay,&Ax,&By,&Bx);
        
        queue<nodo> Q;
        Q.push(nodo(Ax,Ay,1));
        visited[Ax][Ay]=true;
        
        while(!Q.empty()){
            v=Q.front();
            Q.pop();
            
            if(v.x==Bx && v.y==By){
                printf("%d\n",v.dist);
                break;
            }
            
            for(int i=0;i<4;i++){
                X=v.x+dx[i];
                Y=v.y+dy[i];
                
                if(X>=0 && X<R && Y>=0 && Y<C && !visited[X][Y] && !obstacle[X][Y]){
                    visited[X][Y]=true;
                    Q.push(nodo(X,Y,v.dist+1));
                }
            }
        }
    }
    
    return 0;
}
