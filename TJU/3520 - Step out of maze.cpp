#include <cstdio>
#include <cstring>

using namespace std;

int R,C,curR,curC,nxtR,nxtC,Qr[10000],Qc[10000],head,tail,prev[100][100];
bool valid[100][100],visited[100][100];
char ans[10000];

int dr[] = {-1,0,1,0},dc[] = {0,1,0,-1};
char dir[] = {'U', 'R', 'D', 'L'};

void printPath(int rs, int cs, int re, int ce, char last_dir){
    int L = 0,d;
    
    while(re!=rs || ce!=cs){
        d = prev[re][ce];
        ans[L] = dir[d];
        re -= dr[d]; ce -= dc[d];
        ++L;
    }
    
    for(int i = L-1;i>=0;--i){
        putchar(ans[i]);
        putchar(' ');
    }
    
    putchar(last_dir);
    putchar('\n');
}

void bfs(int rs, int cs){
    memset(visited,false,sizeof(visited));
    head = tail = 0;
    
    Qr[tail] = rs; Qc[tail] = cs; ++tail;
    visited[rs][cs] = true;
    
    while(head<tail){
        curR = Qr[head]; curC = Qc[head];
        ++head;
        
        for(int i = 0;i<4;++i){
            nxtR = curR+dr[i]; nxtC = curC+dc[i];
            
            if(nxtR==-1 || nxtR==R || nxtC==-1 || nxtC==C){
                printPath(rs,cs,curR,curC,dir[i]);
                return;
            }else if(valid[nxtR][nxtC] && !visited[nxtR][nxtC]){
                Qr[tail] = nxtR; Qc[tail] = nxtC; ++tail;
                visited[nxtR][nxtC] = true;
                prev[nxtR][nxtC] = i;
            }
        }
    }
    
    return;
}

int main(){
    int T,rs,cs;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&R,&C);
        
        for(int i = 0,x;i<R;++i) for(int j = 0;j<C;++j){
            scanf("%d",&x);
            valid[i][j] = (x==0? true : false);
        }
        
        scanf("%d %d",&rs,&cs);
        --rs; --cs;
        
        bfs(rs,cs);
    }
    
    return 0;
}
