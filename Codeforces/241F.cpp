#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct node{
    int r,c,dist,pr,pc;
    
    node(){}
    node(int _r, int _c, int _dist, int _pr, int _pc):
        r(_r), c(_c), dist(_dist), pr(_pr), pc(_pc){}
    
    bool operator < (node X)const{
        return dist > X.dist;
    }
};

#define MAXR 100
#define MAXC 100

int R,C;
char M[MAXR][MAXC + 1];
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

bool visited[MAXR][MAXC];
pair<int, int> parent[MAXR][MAXC];

int cost(int r, int c){
    if(M[r][c] >= 'a' && M[r][c] <= 'z') return 1;
    return M[r][c] - '0';
}

vector< pair<int, int> > solve(pair<int, int> s, pair<int, int> e){
    priority_queue<node> Q;
    memset(visited,false,sizeof visited);
    
    Q.push(node(s.first,s.second,0,-1,-1));
    
    while(!Q.empty()){
        node cur = Q.top();
        Q.pop();
        
        if(visited[cur.r][cur.c]) continue;
        visited[cur.r][cur.c] = true;
        parent[cur.r][cur.c] = make_pair(cur.pr,cur.pc);
        
        for(int k = 0;k < 4;++k){
            int r2 = cur.r + dr[k];
            int c2 = cur.c + dc[k];
            
            if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && !visited[r2][c2] && M[r2][c2] != '#' && ((r2 == e.first && c2 == e.second)
             || (M[r2][c2] >= '0' && M[r2][c2] <= '9')))
                Q.push(node(r2,c2,cur.dist + cost(cur.r,cur.c),cur.r,cur.c));
        }
    }
    
    vector< pair<int, int> > ret;
    ret.push_back(e);
    
    int re = e.first,ce = e.second;
    
    while(true){
        pair<int, int> p = parent[re][ce];
        if(p.first == -1) break;
        re = p.first;
        ce = p.second;
        ret.push_back(make_pair(re,ce));
    }
    
    reverse(ret.begin(),ret.end());
    
    return ret;
}

int main(){
    int K;
    
    scanf("%d %d %d",&R,&C,&K);
    
    int posr[26],posc[26];
    
    for(int i = 0;i < R;++i){
        scanf("%s",M[i]);
        
        for(int j = 0;j < C;++j){
            if(M[i][j] >= 'a' && M[i][j] <= 'z'){
                posr[ M[i][j] - 'a' ] = i;
                posc[ M[i][j] - 'a' ] = j;
            }
        }
    }
    
    int rs,cs,re,ce;
    char s[1001];
    
    scanf("%d %d %s %d %d",&rs,&cs,s,&re,&ce);
    --rs; --cs; --re; --ce;
    
    int L = strlen(s);
    vector< pair<int, int> > v;
    
    v.push_back(make_pair(rs,cs));
    
    for(int i = 0;i < L;++i)
        v.push_back(make_pair(posr[ s[i] - 'a' ],posc[ s[i] - 'a' ]));
    
    v.push_back(make_pair(re,ce));
    
    L += 2;
    
    vector< vector< pair<int, int> > > sol;
    vector< pair<int, int> > sol2;
    
    for(int i = 0;i + 1 < L;++i)
        sol.push_back(solve(v[i],v[i + 1]));
    
    sol2 = sol[0];
    
    for(int i = 1;i + 1 < L;++i){
        sol2.pop_back();
        
        for(int j = 0;j < sol[i].size();++j)
            sol2.push_back(sol[i][j]);
    }
    
    pair<int,int> ans;
    int curt = 0;
    
    for(int i = 0;i < sol2.size();++i){
        if(curt <= K) ans = sol2[i];
        curt += cost(sol2[i].first,sol2[i].second);
    }
    
    printf("%d %d\n",ans.first + 1,ans.second + 1);
    
    return 0;
}
