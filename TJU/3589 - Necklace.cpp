#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAXL1 10001
#define MAXL2 1001

char s1[MAXL1],s2[MAXL2];
int L1,L2;

int f[MAXL2];
int to[MAXL2][26];

struct node{
    int pos1,match2,dist;
    
    node(){}
    node(int _pos1, int _match2, int _dist):
        pos1(_pos1), match2(_match2), dist(_dist){}
};

int dist[MAXL1][MAXL2];

int solve(){
    memset(dist,-1,sizeof dist);
    deque<node> Q;
    
    Q.push_back(node(0,0,0));
    dist[0][0] = 0;
    
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop_front();
        
        if(cur.dist != dist[cur.pos1][cur.match2]) continue;
        if(cur.pos1 == L1) return cur.dist;
        
        int pos1 = cur.pos1;
        int match2 = to[cur.match2][ s1[pos1] - 'a' ];
        
        if(match2 != L2 && (dist[pos1 + 1][match2] == -1 || cur.dist < dist[pos1 + 1][match2])){
            dist[pos1 + 1][match2] = cur.dist;
            Q.push_front(node(pos1 + 1,match2,cur.dist));
        }
        
        if(dist[pos1 + 1][cur.match2] == -1 || cur.dist + 1 < dist[pos1 + 1][cur.match2]){
            dist[pos1 + 1][cur.match2] = cur.dist + 1;
            Q.push_back(node(pos1 + 1,cur.match2,cur.dist + 1));
        }
    }
    
    return L1;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s %s",s1,s2);
        L1 = strlen(s1);
        L2 = strlen(s2);
        
        f[0] = 0;
        
        for(int i = 1,k = 0;i < L2;++i){
            while(k > 0 && s2[k] != s2[i]) k = f[k - 1];
            if(s2[k] == s2[i]) ++k;
            f[i] = k;
        }
        
        for(int i = 0;i < L2;++i){
            for(int j = 0;j < 26;++j){
                char c = 'a' + j;
                int k = i;
                
                while(k > 0 && s2[k] != c) k = f[k - 1];
                if(s2[k] == c) ++k;
                to[i][j] = k;
            }
        }
        
        printf("%d\n",solve());
    }
    
    return 0;
}
