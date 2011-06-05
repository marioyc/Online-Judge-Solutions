#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

struct node{
    int r,c,t;
    
    node(){}
    
    node(int _r, int _c, int _t){
        r = _r; c = _c; t = _t;
    }
}aux,Q[10000];

int R,C;
char M[100][101];
int dist[100][100];
vector<int> tele_r[26],tele_c[26];
int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};
int head,tail;

void add(int r, int c, int t){
    if(M[r][c] >= 'A' && M[r][c] <= 'Z'){
        int type = M[r][c] - 'A';
        
        for(int i = tele_r[type].size() - 1,r2,c2;i >= 0;--i){
            r2 = tele_r[type][i]; c2 = tele_c[type][i];
            Q[tail] = node(r2,c2,t); ++tail;
            dist[r2][c2] = t;
        }
    }else{
        Q[tail] = node(r,c,t); ++tail;
        dist[r][c] = t;
    }
}

void bfs(int rs, int cs){
    head = tail = 0;
    memset(dist,-1,sizeof(dist));
    
    add(rs,cs,0);
    dist[rs][cs] = 0;
    
    while(head < tail){
        aux = Q[head]; ++head;
        int r = aux.r, c = aux.c, t = aux.t;
        
        for(int i = 0,r2,c2;i < 8;++i){
            r2 = r + dr[i]; c2 = c + dc[i];
            
            if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && M[r2][c2] != '#' && M[r2][c2] != '*' && dist[r2][c2] == -1)
                add(r2,c2,t + 1);
        }
    }
}

int main(){
    scanf("%d %d",&R,&C);
    
    int rs1,cs1,rs2,cs2,re,ce;
    
    for(int i = 0;i < R;++i){
        scanf("%s",M[i]);
        
        for(int j = 0;j < C;++j){
            if(M[i][j] == '!'){
                rs1 = i;
                cs1 = j;
            }else if(M[i][j] == '$'){
                rs2 = i;
                cs2 = j;
            }else if(M[i][j] == '*'){
                re = i;
                ce = j;
            }else if(M[i][j] >= 'A' && M[i][j] <= 'Z'){
                tele_r[M[i][j] - 'A'].push_back(i);
                tele_c[M[i][j] - 'A'].push_back(j);
            }
        }
    }
    
    int ans = -1;
    
    for(int i = 0,r2,c2;i < 8;++i){
        r2 = re + dr[i]; c2 = ce + dc[i];
        
        if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && M[r2][c2] != '#'){
            bfs(r2,c2);
            int d1 = dist[rs1][cs1], d2 = dist[rs2][cs2];
            int aux = max(d1,d2);
            
            if(d1 != -1 && d2 != -1 && (ans == -1 || aux < ans)) ans = aux;
        }
    }
    
    if(ans == -1) puts("Impossible");
    else printf("%d\n",ans + 1);
    
    return 0;
}
