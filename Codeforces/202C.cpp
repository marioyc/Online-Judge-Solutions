#include <cstdio>
#include <cstring>

using namespace std;

int m;
bool visited[10][10][(1 << 10)][101];

int f(int r, int c){
    if(r == 0 && c == 0) return 1;
    if(r == 0 || c == 0) return 2;
    return 4;
}

bool dfs(int r, int c, int mask, int have){
    if(have == 0) return true;
    if(c == m) return dfs(r + 1,0,mask,have);
    
    if(r == m || have < 0 || visited[r][c][mask][have]) return false;
    visited[r][c][mask][have] = true;
    
    if(mask & (1 << c)) return dfs(r,c + 1,(mask ^ (1 << c)),have);
    else{
        if(dfs(r,c + 1,mask,have)) return true;
        if((c == 0 || (mask & (1 << (c - 1))) == 0) && dfs(r,c + 1,(mask | (1 << c)),have - f(r,c))) return true;
    }
    
    return false;
}

bool solve(int n, int x){
    if(n == 1) return x == 1;
    if(n == 2) return false;
    
    if(n % 2 == 1){
        memset(visited,false,sizeof visited);
        m = (n + 1) / 2;
        return dfs(0,0,0,x);
    }else{
        if(x % 4 != 0) return false;
        x /= 4;
        n = n / 2 - 1;
        return (n * n + 1) / 2 >= x;
    }
}

int main(){
    int x;
    
    scanf("%d",&x);
    
    for(int i = 1;;++i){
        if(solve(i,x)){
            printf("%d\n",i);
            return 0;
        }
    }
    
    return 0;
}
