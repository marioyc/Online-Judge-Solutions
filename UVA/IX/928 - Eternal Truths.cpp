#include <cstdio>
#include <queue>

using namespace std;

struct node{
    int r,c,cont;
    
    node(){
    }
    
    node(int _r, int _c, int _cont){
        r=_r;
        c=_c;
        cont=_cont;
    }
};

int main(){
    int T,R,C;
    char M[300][301];
    
    int dr[]={1,0,-1,0};
    int dc[]={0,1,0,-1};
    
    int r_start,c_start,r,c;
    bool visited[300][300][3],solved,valid;
    node aux;
    
    scanf("%d",&T);
    
    for(int tc=0;tc<T;tc++){
        scanf("%d %d",&R,&C);
        
        for(int i=0;i<R;i++) scanf("%s",M[i]);
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                if(M[i][j]=='S'){
                    r_start=i;
                    c_start=j;
                }
        
        memset(visited,false,sizeof(visited));
        
        queue<node> Q;
        Q.push(node(r_start,c_start,0));
        visited[r_start][c_start][0]=true;
        
        solved=false;
        
        while(!Q.empty()){
            aux=Q.front();
            Q.pop();
            
            if(M[aux.r][aux.c]=='E'){
                printf("%d\n",aux.cont);
                solved=true;
                break;
            }
            
            for(int i=0;i<4;i++){
                r=aux.r;
                c=aux.c;
                valid=true;
                
                for(int j=(aux.cont)%3;j>=0;j--){
                    r+=dr[i];
                    c+=dc[i];
                    
                    if(r==-1 || r==R || c==-1 || c==C || M[r][c]=='#'){
                        valid=false;
                        break;
                    }
                }
                
                if(valid && !visited[r][c][(aux.cont+1)%3]){
                    Q.push(node(r,c,aux.cont+1));
                    visited[r][c][(aux.cont+1)%3]=true;
                }
            }
        }
        
        if(!solved) printf("NO\n");        
    }
    
    return 0;
}
