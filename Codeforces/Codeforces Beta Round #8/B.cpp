#include <queue>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

struct node{
    int x,y,dist;
    
    node(){}
    
    node(int _x, int _y, int _dist){
        x = _x; y = _y; dist = _dist;
    }
};

bool M[201][201];

int bfs(int xs, int ys, int xe, int ye){
    queue<node> Q;
    
    bool visited[201][201];
    memset(visited,false,sizeof(visited));
    
    Q.push(node(xs,ys,0)); visited[xs][ys] = true;
    
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    
    while(!Q.empty()){
        node aux = Q.front();
        Q.pop();
        
        int x = aux.x,y = aux.y,dist = aux.dist;
        
        if(x==xe && y==ye) return dist;
        
        for(int i=0;i<4;++i){
            int x2 = x+dx[i],y2 = y+dy[i];
            
            if(M[x2][y2] && !visited[x2][y2]){
                Q.push(node(x2,y2,dist+1));
                visited[x2][y2] = true;
            }
        }
    }
    
    return -1;
}

int main(){
    string s;
    cin>>s;
    
    bool valid = true;
    memset(M,false,sizeof(M));
    
    int x = 100,y = 100,dx,dy;
    M[x][y] = true;
    
    for(int i=0;i<s.size();++i){
        if(s[i] == 'L'){
            dx = -1;
            dy = 0;
        }else if(s[i] == 'R'){
            dx = 1;
            dy = 0;
        }else if(s[i] == 'U'){
            dx = 0;
            dy = 1;
        }else{
            dx = 0;
            dy = -1;
        }
        
        x += dx;
        y += dy;
        
        if(M[x][y]) valid = false;
        M[x][y] = true;
    }
    
    if(!valid){
        cout<<"BUG"<<endl;
        return 0;
    }
    
    if(s.size() == bfs(100,100,x,y)) cout<<"OK"<<endl;
    else cout<<"BUG"<<endl;
    
    return 0;
}
