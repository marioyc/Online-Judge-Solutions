#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

struct node{
    int r,c,rb,cb;
    int push,walk;
    
    node(){}
    
    node(int _r, int _c, int _rb, int _cb, int _push, int _walk):
        r(_r), c(_c), rb(_rb), cb(_cb), push(_push), walk(_walk){}
    
    bool operator < (node X)const{
        if(push != X.push) return push > X.push;
        return walk > X.walk;
    }
};

bool visited[20][20][20][20],first[20][20][20][20];
pair<int,int> dist[20][20][20][20];
node parent[20][20][20][20];
int dir[20][20][20][20];

int main(){
    int tc = 1,R,C;
    char M[20][21];
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};
    
    while(true){
        scanf("%d %d",&R,&C);
        if(R == 0) break;
        
        for(int i = 0;i < R;++i)
            scanf("%s",M[i]);
        
        int rs,cs,rb,cb,re,ce;
        
        for(int i = 0;i < R;++i){
            for(int j = 0;j < C;++j){
                if(M[i][j] == 'S'){
                    rs = i;
                    cs = j;
                }
                
                if(M[i][j] == 'B'){
                    rb = i;
                    cb = j;
                }
                
                if(M[i][j] == 'T'){
                    re = i;
                    ce = j;
                }
            }
        }
        
        memset(visited,false,sizeof visited);
        memset(first,true,sizeof first);
        bool possible = false;
        int R1,C1,R2,C2,L;
        
        priority_queue<node> Q;
        
        Q.push(node(rs,cs,rb,cb,0,0));
        
        while(!Q.empty()){
            node cur = Q.top();
            Q.pop();
            
            if(visited[cur.r][cur.c][cur.rb][cur.cb]) continue;
            visited[cur.r][cur.c][cur.rb][cur.cb] = true;
            
            if(cur.rb == re && cur.cb == ce){
                possible = true;
                R1 = cur.r; C1 = cur.c;
                R2 = cur.rb; C2 = cur.cb;
                L = cur.walk;
                break;
            }
            
            for(int k = 0;k < 4;++k){
                int r = cur.r + dr[k];
                int c = cur.c + dc[k];
                int r2 = cur.rb;
                int c2 = cur.cb;
                int d1 = cur.push;
                int d2 = cur.walk + 1;
                
                if(r >= 0 && r < R && c >= 0 && c < C && M[r][c] != '#'){
                    if(r == r2 && c == c2){
                        r2 += dr[k];
                        c2 += dc[k];
                        ++d1;
                    }
                    
                    if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && M[r2][c2] != '#' && !visited[r][c][r2][c2]){
                        Q.push(node(r,c,r2,c2,d1,d2));
                        
                        if(first[r][c][r2][c2] || make_pair(d1,d2) < dist[r][c][r2][c2]){
                            first[r][c][r2][c2] = false;
                            dist[r][c][r2][c2] = make_pair(d1,d2);
                            parent[r][c][r2][c2] = cur;
                            dir[r][c][r2][c2] = k;
                        }
                    }
                }
            }
        }
        
        printf("Maze #%d\n",tc++);
        
        if(!possible) puts("Impossible.\n");
        else{
            char ans[L + 1];
            ans[L--] = 0;
            
            while(R1 != rs || C1 != cs || R2 != rb || C2 != cb){
                bool push = dist[R1][C1][R2][C2].first != parent[R1][C1][R2][C2].push;
                
                if(dir[R1][C1][R2][C2] == 0) ans[L--] = push? 'N' : 'n';
                else if(dir[R1][C1][R2][C2] == 1) ans[L--] = push? 'S' : 's';
                else if(dir[R1][C1][R2][C2] == 2) ans[L--] = push? 'W' : 'w';
                else ans[L--] = push? 'E' : 'e';
                
                node p = parent[R1][C1][R2][C2];
                R1 = p.r; C1 = p.c;
                R2 = p.rb; C2 = p.cb;
            }
            
            puts(ans);
            putchar('\n');
        }
    }
    
    return 0;
}
