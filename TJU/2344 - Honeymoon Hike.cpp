#include <cstdio>
#include <queue>

using namespace std;

#define max(x,y) (x)>(y)? (x):(y)
#define min(x,y) (x)<(y)? (x):(y)

struct node{
    int x,y;
    
    node(){}
    
    node(int _x, int _y){
        x = _x; y = _y;
    }
}aux;

int n,H[100][100],min_h,max_h;
bool visited[100][100];

const int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

bool possible(int diff){
    int x2,y2;
    
    for(int lo=min_h;lo<=max_h;++lo){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                visited[i][j] = (H[i][j]<lo || H[i][j]>lo+diff);
        
        if(visited[0][0]) continue;
        
        queue<node> Q;
        Q.push(node(0,0));
        visited[0][0] = true;
        
        while(!Q.empty()){
            aux = Q.front();
            Q.pop();
            
            if(aux.x==n-1 && aux.y==n-1) return true;
            
            for(int i=0;i<4;++i){
                x2 = aux.x+dx[i];
                y2 = aux.y+dy[i];
                
                if(x2>=0 && x2<n && y2>=0 && y2<n && !visited[x2][y2]){
                    Q.push(node(x2,y2));
                    visited[x2][y2] = true;
                }
            }
        }
    }
    
    return false;
}

int MinDiff(){
    min_h = max_h = H[0][0];
    
    for(int i=0;i<n;++i) for(int j=0;j<n;++j){
        min_h = min(min_h,H[i][j]);
        max_h = max(max_h,H[i][j]);
    }
    
    int lo = 0,hi = max_h-min_h,mi;
    
    while(lo<hi){
        mi = (lo+hi)/2;
        
        if(possible(mi)) hi = mi;
        else lo = mi+1;
    }
    
    return lo;
}

int main(){
    int T;
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&H[i][j]);
        
        printf("Scenario #%d:\n%d\n\n",tc,MinDiff());
    }
    
    return 0;
}
