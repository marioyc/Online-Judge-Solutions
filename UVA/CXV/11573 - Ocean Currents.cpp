#include <cstdio>
#include <deque>
#include <map>

using namespace std;

int dr[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};

char M[1000][1001];
int dist[1000][1000];

int bfs(int rs, int cs, int rd, int cd, int &R, int &C){
    for(int i=0;i<R;i++) fill(dist[i],dist[i]+C,-1);
    
    deque< pair<int, int> > Q;
    
    Q.push_back(make_pair(rs,cs));
    dist[rs][cs]=0;
        
    pair<int, int> P;
    int r,c;
    
    while(true){
        P=*(Q.begin());
        Q.pop_front();
        
        if(P.first==rd && P.second==cd) return dist[rd][cd];
        
        r=P.first+dr[M[P.first][P.second]-'0'];
        c=P.second+dc[M[P.first][P.second]-'0'];
        
        if(r>=0 && r<R && c>=0 && c<C && (dist[r][c]==-1 || dist[r][c]>dist[P.first][P.second])){
            dist[r][c]=dist[P.first][P.second];            
            Q.push_front(make_pair(r,c));
        }
        
        for(int i=0;i<8;i++){        
            r=P.first+dr[i];
            c=P.second+dc[i];
            
            if(r>=0 && r<R && c>=0 && c<C && (dist[r][c]==-1 || dist[r][c]>dist[P.first][P.second]+1)){
                dist[r][c]=dist[P.first][P.second]+1;                
                Q.push_back(make_pair(r,c));
            }
        }
    }
}

int main(){    
    int R,C,m,rs,cs,rd,cd;
    
    while(scanf("%d %d",&R,&C)==2){
        for(int i=0;i<R;i++) scanf("%s",M[i]);
        
        scanf("%d",&m);
        
        for(int i=0;i<m;i++){
            scanf("%d %d %d %d",&rs,&cs,&rd,&cd);            
            printf("%d\n",bfs(rs-1,cs-1,rd-1,cd-1,R,C));
        }
    }
    
    return 0;
}
