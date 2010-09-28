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
    int R,C,r,c;
    int dr[]={1,-1,0,0,1,1,-1,-1};
    int dc[]={0,0,1,-1,1,-1,1,-1};
    queue<nodo> Q;
    nodo aux;
    
    char M[8][9];
    bool visited[8][8];
    
    int p,A;
    double S;
    
    while(1){
        scanf("%d %d",&R,&C);
        if(R==0) break;
        
        for(int i=0;i<R;i++) scanf("%s",M[i]);
        
        for(int i=0;i<R;i++) fill(visited[i],visited[i]+C,false);
        
        S=0;
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                if(!visited[i][j] && M[i][j]=='X'){
                    p=A=0;
                    
                    Q.push(nodo(i,j));
                    visited[i][j]=true;
                    
                    while(!Q.empty()){
                        aux=Q.front();
                        Q.pop();
                        
                        A++;
                        
                        if(aux.r==0) p++;
                        if(aux.r==R-1) p++;
                        if(aux.c==0) p++;
                        if(aux.c==C-1) p++;
                        if(aux.r>0 && M[aux.r-1][aux.c]=='.') p++;
                        if(aux.r<R-1 && M[aux.r+1][aux.c]=='.') p++;
                        if(aux.c>0 && M[aux.r][aux.c-1]=='.') p++;
                        if(aux.c<C-1 && M[aux.r][aux.c+1]=='.') p++;
                        
                        for(int k=0;k<8;k++){
                            r=aux.r+dr[k];
                            c=aux.c+dc[k];
                            
                            if(r>=0 && r<R && c>=0 && c<C && !visited[r][c] && M[r][c]=='X'){
                                visited[r][c]=true;
                                Q.push(nodo(r,c));
                            }
                        }
                    }
                    
                    S+=p*1.0/A;
                }
        
        if(S<R*C/4.0) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
