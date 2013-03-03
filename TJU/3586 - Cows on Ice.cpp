#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define MAXN 20000

struct node{
    int id,x,y;
    bool rock;
    
    node(){}
    node(int _id, int _x, int _y, bool _rock):
        id(_id), x(_x), y(_y), rock(_rock){}
};

bool cmp1(node a, node b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool cmp2(node a, node b){
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

vector<node> v;
set< pair<int,int> > S;
int dr[] = {-1,0,0,1};
int dc[] = {0,-1,1,0};
int x[MAXN],y[MAXN];

vector<int> L[5 * MAXN + 2];
int dist[5 * MAXN + 2];

int solve(){
    memset(dist,-1,sizeof dist);
    queue<int> Q;
    
    dist[0] = 0;
    Q.push(0);
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        if(cur == 1) return dist[cur];
        
        for(int i = L[cur].size() - 1,to;i >= 0;--i){
            to = L[cur][i];
            
            if(dist[to] == -1){
                dist[to] = 1 + dist[cur];
                Q.push(to);
            }
        }
    }
    
    return -1;
}

int main(){
    int N,sx,sy,ex,ey;
    
    scanf("%d %d %d %d %d",&N,&sx,&sy,&ex,&ey);
    
    if(sx == ex && sy == ey){
        puts("0");
        return 0;
    }
    
    int M = 0;
    v.push_back(node(M++,sx,sy,false));
    v.push_back(node(M++,ex,ey,false));
    S.insert(make_pair(sx,sy));
    S.insert(make_pair(ex,ey));
    
    for(int i = 0;i < N;++i){
        scanf("%d %d",&x[i],&y[i]);
        v.push_back(node(M++,x[i],y[i],true));
        S.insert(make_pair(x[i],y[i]));
    }
    
    for(int i = 0;i < N;++i){
        for(int k = 0;k < 4;++k){
            int x2 = x[i] + dr[k],y2 = y[i] + dc[k];
            
            if(S.find(make_pair(x2,y2)) == S.end()){
                v.push_back(node(M++,x2,y2,false));
                S.insert(make_pair(x2,y2));
            }
        }
    }
    
    int nv = v.size();
    
    sort(v.begin(),v.end(),cmp1);
    
    for(int i = 0;i < nv;){
        int e = i;
        
        while(e < nv && v[e].x == v[i].x) ++e;
        
        for(int j = i,rock1 = -1,rock2 = -1;j <= e;++j){
            if(v[j].rock || j == e){
                rock1 = rock2;
                rock2 = j;
                
                for(int k = max(i,rock1 + 1);k < rock2;++k){
                    if(rock1 != -1) L[ v[k].id ].push_back(v[rock1 + 1].id);
                    if(rock2 != e) L[ v[k].id ].push_back(v[rock2 - 1].id);
                }
            }
        }
        
        i = e;
    }
    
    sort(v.begin(),v.end(),cmp2);
    
    for(int i = 0;i < nv;){
        int e = i;
        
        while(e < nv && v[e].y == v[i].y) ++e;
        
        for(int j = i,rock1 = -1,rock2 = -1;j <= e;++j){
            if(v[j].rock || j == e){
                rock1 = rock2;
                rock2 = j;
                
                for(int k = max(i,rock1 + 1);k < rock2;++k){
                    if(rock1 != -1) L[ v[k].id ].push_back(v[rock1 + 1].id);
                    if(rock2 != e) L[ v[k].id ].push_back(v[rock2 - 1].id);
                }
            }
        }
        
        i = e;
    }
    
    printf("%d\n",solve());
    
    return 0;
}
