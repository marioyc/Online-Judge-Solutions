#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int R,C;
string M[100];
bool ok[100][100][4];

int dr[] = {-1,1,0,0},dc[] = {0,0,-1,1};
bool visited[100][100][4];

struct node{
    int r,c,dist;
    
    node(){}
    
    node(int _r, int _c, int _dist):
        r(_r), c(_c), dist(_dist){}
};

int solve(int sr, int sc, int er, int ec){
    queue<node> Q;
    memset(visited,false,sizeof visited);
    
    Q.push(node(sr,sc,0));
    visited[sr][sc][0] = true;
    
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop();
        
        if(cur.r == er && cur.c == ec) return cur.dist;
        
        for(int k = 0;k < 4;++k){
            int r2 = cur.r + dr[k],c2 = cur.c + dc[k];
            
            if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && ok[r2][c2][(cur.dist + 1) % 4] && !visited[r2][c2][(cur.dist + 1) % 4]){
                Q.push(node(r2,c2,cur.dist + 1));
                visited[r2][c2][(cur.dist + 1) % 4] = true;
            }
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    
    int T;
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> R >> C;
        
        for(int i = 0;i < R;++i)
            cin >> M[i];
        
        int sr,sc,er,ec;
        
        for(int i = 0;i < R;++i){
            for(int j = 0;j < C;++j){
                if(M[i][j] == 'S'){
                    sr = i; sc = j;
                    M[i][j] = '.';
                }else if(M[i][j] == 'G'){
                    er = i; ec = j;
                    M[i][j] = '.';
                }else if(M[i][j] == '^'){
                    M[i][j] = '0';
                }else if(M[i][j] == '>'){
                    M[i][j] = '1';
                }else if(M[i][j] == 'v'){
                    M[i][j] = '2';
                }else if(M[i][j] == '<'){
                    M[i][j] = '3';
                }
            }
        }
        
        memset(ok,true,sizeof ok);
        
        for(int i = 0;i < R;++i){
            for(int j = 0;j < C;++j){
                for(int k = 0;k < 4;++k){
                    if(M[i][j] == '#' || (M[i][j] >= '0' && M[i][j] <= '3'))
                        ok[i][j][k] = false;
                    else{
                        for(int d = 1;d <= i;++d){
                            if(M[i - d][j] == '#') break;
                            if(M[i - d][j] >= '0' && M[i - d][j] <= '3'){
                                int dir = (M[i - d][j] - '0' + k) % 4;
                                if(dir == 2) ok[i][j][k] = false;
                                break;
                            }
                        }
                        
                        for(int d = 1;i + d <= R - 1;++d){
                            if(M[i + d][j] == '#') break;
                            if(M[i + d][j] >= '0' && M[i + d][j] <= '3'){
                                int dir = (M[i + d][j] - '0' + k) % 4;
                                if(dir == 0) ok[i][j][k] = false;
                                break;
                            }
                        }
                        
                        for(int d = 1;d <= j;++d){
                            if(M[i][j - d] == '#') break;
                            if(M[i][j - d] >= '0' && M[i][j - d] <= '3'){
                                int dir = (M[i][j - d] - '0' + k) % 4;
                                if(dir == 1) ok[i][j][k] = false;
                                break;
                            }
                        }
                        
                        for(int d = 1;j + d <= C - 1;++d){
                            if(M[i][j + d] == '#') break;
                            if(M[i][j + d] >= '0' && M[i][j + d] <= '3'){
                                int dir = (M[i][j + d] - '0' + k) % 4;
                                if(dir == 3) ok[i][j][k] = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        cout << "Case #" << tc << ": ";
        
        int ans = solve(sr,sc,er,ec);
        
        if(ans == -1) cout << "impossible\n";
        else cout << ans << '\n';
    }
    
    return 0;
}
