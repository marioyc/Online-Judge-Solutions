#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    int x,y,dist;
    
    node(){}
    
    node(int _x, int _y, int _dist){
        x = _x; y = _y; dist = _dist;
    }
    
    bool operator < (node X)const{
        return dist>X.dist;
    }
};

int n,x1,y1,x2,y2;

int solve(){
    bool visited[n+1][n+1];
    memset(visited,false,sizeof(visited));
    
    int ans = 4*n;
    priority_queue<node> Q;
    Q.push(node(x1,y1,0));
    
    while(!Q.empty()){
        node aux = Q.top();
        Q.pop();
        
        if((aux.x==x2 && (x2==0 || x2==n)) || (aux.y==y2 && (y2==0 || y2==n))){
            ans = min(ans,aux.dist+abs(aux.x-x2)+abs(aux.y-y2));
            continue;
        }
        
        if(visited[aux.x][aux.y]) continue;
        visited[aux.x][aux.y] = true;
        
        if((aux.y==0 || aux.y==n) && !visited[0][aux.y]) Q.push(node(0,aux.y,aux.dist+aux.x));
        if((aux.y==0 || aux.y==n) && !visited[n][aux.y]) Q.push(node(n,aux.y,aux.dist+n-aux.x));
        if((aux.x==0 || aux.x==n) && !visited[aux.x][0]) Q.push(node(aux.x,0,aux.dist+aux.y));
        if((aux.x==0 || aux.x==n) && !visited[aux.x][n]) Q.push(node(aux.x,n,aux.dist+n-aux.y));
    }
    
    return ans;
}

int main(){
    scanf("%d %d %d %d %d",&n,&x1,&y1,&x2,&y2);
    
    printf("%d\n",solve());
    
    return 0;
}
