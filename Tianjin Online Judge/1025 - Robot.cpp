#include<cstdio>
#include<queue>

using namespace std;

struct nodo{
    int x,y,dir,time;
    
    nodo(int a, int b, int c, int d){
        x=a;
        y=b;
        dir=c;
        time=d;
    }
};

int M,N;
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
bool obstacle[50][50];
bool visited[51][51][4];

bool valido(int x, int y){
    if(x<=0 || y<=0 || x>=M || y>=N) return false;
    if(obstacle[x-1][y-1]) return false;
    if(obstacle[x-1][y]) return false; 
    if(obstacle[x][y-1]) return false;
    if(obstacle[x][y]) return false;
    
    return true;
}

int shortest_time(int &startx, int &starty, int &dir, int &endx, int &endy){
    queue<nodo> Q;
    if(valido(startx,starty)){
        Q.push(nodo(startx,starty,dir,0));
        visited[startx][starty][dir]=true;
    }
    
    while(!Q.empty()){
        nodo aux=Q.front();
        Q.pop();
        
        if(aux.x==endx && aux.y==endy) return aux.time;
        
        if(!visited[aux.x][aux.y][(aux.dir+1)%4]){
            visited[aux.x][aux.y][(aux.dir+1)%4]=true;
            Q.push(nodo(aux.x,aux.y,(aux.dir+1)%4,aux.time+1));
        }
        
        if(!visited[aux.x][aux.y][(aux.dir+3)%4]){
            visited[aux.x][aux.y][(aux.dir+3)%4]=true;
            Q.push(nodo(aux.x,aux.y,(aux.dir+3)%4,aux.time+1));
        }
        
        for(int i=1;i<=3;i++){
            if(valido(aux.x+di[aux.dir]*i,aux.y+dj[aux.dir]*i)){
                if(visited[aux.x+di[aux.dir]*i][aux.y+dj[aux.dir]*i][aux.dir]) continue;
                visited[aux.x+di[aux.dir]*i][aux.y+dj[aux.dir]*i][aux.dir]=true;
                Q.push(nodo(aux.x+di[aux.dir]*i,aux.y+dj[aux.dir]*i,aux.dir,aux.time+1));
            }else break;
        }
    }
    
    return -1;
}

int main(){    
    int startx,starty,endx,endy,dir,ax;
    char s[6];    
    
    while(1){
        scanf("%d %d",&M,&N);
        if(M==0 || N==0) break;
        
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++){
                scanf("%d",&ax);
                obstacle[i][j]=ax;
            }
        
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++) fill(visited[i][j],visited[i][j]+4,false);
        
        scanf("%d %d %d %d %s",&startx,&starty,&endx,&endy,s);
        
        if(s[0]=='n') dir=0;
        else if(s[0]=='e') dir=1;
        else if(s[0]=='s') dir=2;
        else dir=3;
        
        printf("%d\n",shortest_time(startx,starty,dir,endx,endy));
    }
    
    return 0;
}
