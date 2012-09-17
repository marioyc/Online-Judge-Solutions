#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int L[2][20];
long long mask[2][20];

long long get_hash(int set, int id, int l, int r){
    long long h = mask[set][id];
    h &= (1LL << (r + 1)) - 1;
    return (h >> l) & ((1LL << (r - l + 1)) - 1);
}

struct node{
    int set,id,len;
    
    node(){}
    node(int _set, int _id, int _len) :
        set(_set), id(_id), len(_len){}
};

int n1,n2;
bool visited[2][20][41];

char solve(){
    queue<node> Q;
    memset(visited,false,sizeof visited);
    
    for(int i = 0;i < n1;++i){
        Q.push(node(0,i,L[0][i]));
        visited[0][i][ L[0][i] ] = true;
    }
    
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop();
        
        if(cur.len == 0) return 'S';
        
        int N = (cur.set == 0? n2 : n1);
        
        for(int i = 0;i < N;++i){
            int len = min(L[cur.set ^ 1][i],cur.len);
            
            if(get_hash(cur.set,cur.id,L[cur.set][cur.id ] - cur.len,L[cur.set][cur.id ] - cur.len + len - 1) == get_hash(cur.set ^ 1,i,0,len - 1)){
                if(len == L[cur.set ^ 1][i]){
                    if(!visited[cur.set][cur.id][cur.len - len]){
                        Q.push(node(cur.set,cur.id,cur.len - len));
                        visited[cur.set][cur.id][cur.len - len] = true;
                    }
                }else{
                    if(!visited[cur.set ^ 1][i][ L[cur.set ^ 1][i] - len ]){
                        Q.push(node(cur.set ^ 1,i,L[cur.set ^ 1][i] - len));
                        visited[cur.set ^ 1][i][ L[cur.set ^ 1][i] - len ] = true;
                    }
                }
            }
        }
    }
    
    return 'N';
}

int main(){
    char s[41];
    
    while(scanf("%d %d",&n1,&n2) == 2){
        memset(mask,0,sizeof mask);
        
        for(int i = 0;i < n1;++i){
            scanf("%s",s);
            
            long long h = 0;
            L[0][i] = strlen(s);
            
            for(int j = 0;j < L[0][i];++j)
                if(s[j] == '1') mask[0][i] |= (1LL << j);
        }
        
        for(int i = 0;i < n2;++i){
            scanf("%s",s);
            
            long long h = 0;
            L[1][i] = strlen(s);
            
            for(int j = 0;j < L[1][i];++j)
                if(s[j] == '1') mask[1][i] |= (1LL << j);
        }
        
        printf("%c\n",solve());
    }
    
    return 0;
}
