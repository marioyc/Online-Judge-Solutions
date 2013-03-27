#include <cstdio>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define MAXN 100000

set< pair<int, int> > valid,visited;
int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

struct node{
    int r,c,dist;
    
    node(){}
    node(int _r, int _c, int _dist):
        r(_r), c(_c), dist(_dist){}
};

int main(){
    int r0,c0,r1,c1,n;
    
    scanf("%d %d %d %d %d",&r0,&c0,&r1,&c1,&n);
    
    for(int i = 0,r,le,ri;i < n;++i){
        scanf("%d %d %d",&r,&le,&ri);
        
        for(int j = le;j <= ri;++j)
            valid.insert(make_pair(r,j));
    }
    
    int ans = -1;
    queue<node> Q;
    
    Q.push(node(r0,c0,0));
    visited.insert(make_pair(r0,c0));
    
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop();
        
        if(cur.r == r1 && cur.c == c1){
            ans = cur.dist;
            break;
        }
        
        for(int k = 0;k < 8;++k){
            int r2 = cur.r + dr[k];
            int c2 = cur.c + dc[k];
            
            if(valid.find(make_pair(r2,c2)) != valid.end() && visited.find(make_pair(r2,c2)) == visited.end()){
                visited.insert(make_pair(r2,c2));
                Q.push(node(r2,c2,cur.dist + 1));
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
