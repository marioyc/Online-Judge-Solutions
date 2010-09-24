#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

struct nodo{
    int r,c;
    
    nodo(){
    }
    
    nodo(int R, int C){
        r=R;
        c=C;
    }
};

int main(){    
    char M[20][21];
    bool visited[20][20];
    
    int R,C,r,c,cont;
    bool found;
    
    queue<nodo> Q;    
    nodo aux;    
    int di[]={1,-1,0,0};
    int dj[]={0,0,1,-1};
    
    while(1){
        scanf("%d %d",&C,&R);
        if(R==0 && C==0) break;
        
        for(int i=0;i<R;i++) scanf("%s",M[i]);
        
        found=false;
        
        for(int i=0;i<R && !found;i++)
            for(int j=0;j<C && !found;j++)
                if(M[i][j]=='@'){
                    found=true;
                    r=i;
                    c=j;
                }        
        
        for(int i=0;i<R;i++) fill(visited[i],visited[i]+C,false);
        
        Q.push(nodo(r,c));
        cont=0;
        
        while(!Q.empty()){
            aux=Q.front();
            Q.pop();
            
            cont++;
            
            for(int i=0;i<4;i++){
                r=aux.r+di[i];
                c=aux.c+dj[i];
                
                if(r>=0 && r<R && c>=0 && c<C && !visited[r][c] && M[r][c]=='.'){
                    visited[r][c]=true;
                    Q.push(nodo(r,c));
                }
            }
        }
        
        printf("%d\n",cont);
    }
    
    
    return 0;
}
