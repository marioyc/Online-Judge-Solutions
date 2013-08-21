#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main(){
    int T,n,m;
    char M[50][51];
    bool visited[50][51];
    int dam[50][51];
    int dr[] = {-1,1,0,0},dc[] = {0,0,-1,1};
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&n,&m);
        
        for(int i = 0;i < n;++i)
            scanf("%s",M[i]);
        
        memset(dam,0,sizeof dam);
        
        int sr,sc,er,ec;
        
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(M[i][j] == 'A'){
                    int r1 = max(0,i - 2),r2 = min(n - 1,i + 2);
                    int c1 = max(0,j - 2),c2 = min(m - 1,j + 2);
                    
                    for(int x = r1;x <= r2;++x)
                        for(int y = c1;y <= c2;++y)
                            if(abs(x - i) + abs(y - j) <= 2)
                                dam[x][y] |= 1;
                }else if(M[i][j] == 'B'){
                    int r1 = max(0,i - 3),r2 = min(n - 1,i + 3);
                    int c1 = max(0,j - 3),c2 = min(m - 1,j + 3);
                    
                    for(int x = r1;x <= r2;++x)
                        for(int y = c1;y <= c2;++y)
                            if(abs(x - i) + abs(y - j) <= 3)
                                dam[x][y] |= 2;
                }else if(M[i][j] == 'C'){
                    dam[i][j] |= 4;
                }else if(M[i][j] == 'D'){
                    int r1 = max(0,i - 2),r2 = min(n - 1,i + 2);
                    int c1 = max(0,j - 2),c2 = min(m - 1,j + 2);
                    
                    for(int x = r1;x <= r2;++x)
                        for(int y = c1;y <= c2;++y)
                            if(abs(x - i) + abs(y - j) <= 2)
                                dam[x][y] |= 8;
                }else if(M[i][j] == 'E'){
                    int r1 = max(0,i - 1),r2 = min(n - 1,i + 1);
                    int c1 = max(0,j - 1),c2 = min(m - 1,j + 1);
                    
                    for(int x = r1;x <= r2;++x)
                        for(int y = c1;y <= c2;++y)
                            if(abs(x - i) + abs(y - j) <= 1)
                                dam[x][y] |= 16;
                }else if(M[i][j] == '$'){
                    sr = i;
                    sc = j;
                }else if(M[i][j] == '!'){
                    er = i;
                    ec = j;
                }
            }
        }
        
        int ans = -1;
        
        for(int mask = 0;mask < (1 << 5);++mask){
            int aux = 0;
            
            if(mask & 1) ++aux;
            if(mask & 2) aux += 2;
            if(mask & 4) aux += 3;
            if(mask & 8) aux += 4;
            if(mask & 16) aux += 5;
            
            memset(visited,false,sizeof visited);
            queue< pair<int, int> > Q;
            Q.push(make_pair(sr,sc));
            visited[sr][sc] = true;
            
            while(!Q.empty()){
                pair<int, int> cur = Q.front();
                Q.pop();
                
                if(cur.first == er && cur.second == ec){
                    if(ans == -1 || aux < ans) ans = aux;
                    break;
                }
                
                for(int k = 0;k < 4;++k){
                    int r = cur.first + dr[k];
                    int c = cur.second + dc[k];
                    
                    if(r >= 0 && r < n && c >= 0 && c < m && !visited[r][c] && (M[r][c] == '.' || M[r][c] == 'C' || M[r][c] == '!') && (dam[r][c] & mask) == dam[r][c]){
                        Q.push(make_pair(r,c));
                        visited[r][c] = true;
                    }
                }
            }
        }
        
        printf("Case %d: %d\n",tc,ans);
    }
    
    return 0;
}
