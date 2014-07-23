#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int x1[50],y1[50],x2[50],y2[50];
long long M[105][105];
vector<int> vx,vy;

int get(vector<int> v, int x){
    for(int i = v.size() - 1;i >= 0;--i)
        if(v[i] == x) return i;
    return -1;
}

int dr[] = {-1,1,0,0},dc[] = {0,0,-1,1};
int nx,ny;

void dfs(int r, int c, long long cur){
    M[r][c] = -1;
    
    for(int k = 0;k < 4;++k){
        int r2 = r + dr[k],c2 = c + dc[k];
        
        if(r2 >= 0 && r2 < nx && c2 >= 0 && c2 < ny && M[r2][c2] == cur)
            dfs(r2,c2,cur);
    }
}

int main(){
    int n;
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        vx.clear(); vy.clear();
        vx.push_back(-1);
        vy.push_back(-1);
        
        for(int i = 0;i < n;++i){
            scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
            vx.push_back(x1[i]);
            vx.push_back(x2[i]);
            vy.push_back(y1[i]);
            vy.push_back(y2[i]);
        }
        
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        vx.erase(unique(vx.begin(),vx.end()),vx.end());
        vy.erase(unique(vy.begin(),vy.end()),vy.end());
        nx = vx.size(); ny = vy.size();
        
        memset(M,0,sizeof M);
        
        for(int i = 0;i < n;++i){
            x1[i] = get(vx,x1[i]);
            x2[i] = get(vx,x2[i]);
            y1[i] = get(vy,y1[i]);
            y2[i] = get(vy,y2[i]);
            
            for(int j = x1[i];j < x2[i];++j)
                for(int k = y2[i];k < y1[i];++k)
                    M[j][k] |= (1LL << i);
        }
        
        int ans = 0;
        
        for(int i = 0;i < nx;++i)
            for(int j = 0;j < ny;++j)
                if(M[i][j] >= 0){
                    dfs(i,j,M[i][j]);
                    ++ans;
                }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
