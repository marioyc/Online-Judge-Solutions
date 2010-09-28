#include<cstdio>
#include<queue>

using namespace std;

struct nodo{
    int r,c;
    
    nodo(){
    }
    
    nodo(int _r, int _c){
        r=_r;
        c=_c;
    }
};

int main(){    
    int R,C,r0,c0,r,c;
    int dr[]={1,-1,0,0,1,1,-1,-1};
    int dc[]={0,0,1,-1,1,-1,1,-1};
    queue<nodo> Q;
    nodo aux;
    
    char M[20][21];
    bool visited[20][20];
    
    int p;
    
    while(1){
        scanf("%d %d %d %d",&R,&C,&r0,&c0);
        if(R==0) break;
        
        for(int i=0;i<R;i++) scanf("%s",M[i]);
        
        for(int i=0;i<R;i++) fill(visited[i],visited[i]+C,false);
        
        p=0;
        
        Q.push(nodo(r0-1,c0-1));
        visited[r0-1][c0-1]=true;
        
        while(!Q.empty()){
            aux=Q.front();
            Q.pop();            
            
            if(aux.r==0) p++;
            if(aux.r==R-1) p++;
            if(aux.c==0) p++;
            if(aux.c==C-1) p++;
            if(aux.r>0 && M[aux.r-1][aux.c]=='.') p++;
            if(aux.r<R-1 && M[aux.r+1][aux.c]=='.') p++;
            if(aux.c>0 && M[aux.r][aux.c-1]=='.') p++;
            if(aux.c<C-1 && M[aux.r][aux.c+1]=='.') p++;
            
            for(int i=0;i<8;i++){
                r=aux.r+dr[i];
                c=aux.c+dc[i];
                
                if(r>=0 && r<R && c>=0 && c<C && !visited[r][c] && M[r][c]=='X'){
                    visited[r][c]=true;
                    Q.push(nodo(r,c));
                }
            }
        }
        
        printf("%d\n",p);
    }
    
    return 0;
}
