#include <cstdio>
#include <queue>

using namespace std;

const int dr[]={0,1,0,-1};
const int dc[]={1,0,-1,0};

struct node{
    int r,c,dir,cont;
    
    node(){
    }
    
    node(const int _r, const int _c, const int _dir, const int _cont){
        r=_r; c=_c; dir=_dir; cont=_cont;
    }
}aux;

int R,C;
char M[1000][1000];
bool visited[1000][1000][4];

void Solve(const int &r_end, const int &c_end){
    if(M[0][0]=='1'){
        printf("NOOO!\n");
        return;
    }
    
    memset(visited,false,sizeof(visited));
    
    queue<node> Q;
    Q.push(node(0,0,0,0));
    Q.push(node(0,0,1,0));
    visited[0][0][0]=true;
    visited[0][0][1]=true;
    
    int r,c;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        if(aux.r==r_end && aux.c==c_end){
            printf("%d\n",aux.cont);
            return;
        }
        
        r=aux.r+dr[aux.dir]; c=aux.c+dc[aux.dir];
        if(r>=0 && r<R && c>=0 && c<C && M[r][c]=='0' && !visited[r][c][aux.dir]){
            Q.push(node(r,c,aux.dir,aux.cont+1));
            visited[r][c][aux.dir]=true;
        }
        
        r=aux.r+dr[(aux.dir+1)&3]; c=aux.c+dc[(aux.dir+1)&3];
        if(r>=0 && r<R && c>=0 && c<C && M[r][c]=='0' && !visited[r][c][(aux.dir+1)&3]){
            Q.push(node(r,c,(aux.dir+1)&3,aux.cont+1));
            visited[r][c][(aux.dir+1)&3]=true;
        }
    }
    
    printf("NOOO!\n");
}

int main(){
    int r_end,c_end;
    
    while(1){
        scanf("%d %d",&R,&C);
        if(R==0) break;
        scanf("%d %d",&c_end,&r_end);
        
        for(int i=0;i<R;i++) scanf("%s",M[i]);
        
        r_end--; c_end--;
        Solve(r_end,c_end);
    }
    
    return 0;
}
