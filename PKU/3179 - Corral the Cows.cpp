#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vx,vy;
int nx,ny,M[501][501];

int search(int &n, vector<int> &v, int x){
    int lo = 0,hi = n - 1,mi;
    
    while(lo < hi){
        mi = (lo + hi + 1) >> 1;
        
        if(v[mi] > x) hi = mi - 1;
        else lo = mi;
    }
    
    return lo;
}

int sum(int x, int y){
    x = search(nx,vx,x);
    y = search(ny,vy,y);
    return M[x][y];
}

int main(){
    int C,N;
    
    scanf("%d %d",&C,&N);
    
    int x[N],y[N];
    vx.push_back(0);
    vy.push_back(0);
    
    for(int i = 0;i < N;++i){
        scanf("%d %d",&x[i],&y[i]);
        vx.push_back(x[i]);
        vy.push_back(y[i]);
    }
    
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    nx = unique(vx.begin(),vx.end()) - vx.begin();
    ny = unique(vy.begin(),vy.end()) - vy.begin();
    
    for(int i = 0;i < N;++i)
        ++M[lower_bound(vx.begin(),vx.begin() + nx,x[i]) - vx.begin()][lower_bound(vy.begin(),vy.begin() + ny,y[i]) - vy.begin()];
    
    for(int i = 0;i < nx;++i){
        for(int j = 0;j < ny;++j){
            if(i > 0) M[i][j] += M[i - 1][j];
            if(j > 0) M[i][j] += M[i][j - 1];
            if(i > 0 && j > 0) M[i][j] -= M[i - 1][j - 1];
        }
    }
    
    int ans = 100000;
    
    for(int i = 0;i < nx;++i){
        for(int j = 0;j < ny;++j){
            int X = vx[i],Y = vy[j];
            
            if(N - sum(X - 1,10000) - sum(10000,Y - 1) + sum(X - 1,Y - 1) >= C){
                int lo = 1,hi = 10001 - min(X,Y),mi;
                
                while(lo < hi){
                    mi = (lo + hi) >> 1;
                    
                    if(sum(X + mi - 1,Y + mi - 1) - sum(X - 1,Y + mi - 1) - sum(X + mi - 1,Y - 1) + sum(X - 1,Y - 1) < C) lo = mi + 1;
                    else hi = mi;
                }
                
                ans = min(ans,lo);
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
