#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node{
    int has[3];
    
    node(){}
    
    node(int _a, int _b, int _c){
        has[0] = _a;
        has[1] = _b;
        has[2] = _c;
    }
}aux,aux2;

int cap[3];
bool visited[256][256][256],found[766];

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    scanf("%d %d %d",&cap[0],&cap[1],&cap[2]);
    
    queue<node> Q;
    memset(visited,false,sizeof(visited));
    memset(found,false,sizeof(found));
    Q.push(node(0,0,0));
    visited[0][0][0] = true;
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        
        for(int i = 0;i < 3;++i){
            aux2 = aux;
            aux2.has[i] = cap[i];
            
            if(!visited[aux2.has[0]][aux2.has[1]][aux2.has[2]]){
                visited[aux2.has[0]][aux2.has[1]][aux2.has[2]] = true;
                
                found[aux2.has[0]] = found[aux2.has[1]] = found[aux2.has[2]] = true;
                
                for(int j = 0;j < 3;++j)
                    for(int k = j+1;k < 3;++k)
                        found[aux2.has[j] + aux2.has[k]] = true;
                
                found[aux2.has[0] + aux2.has[1] + aux2.has[2]] = true;
                
                Q.push(aux2);
            }
        }
        
        for(int i = 0;i < 3;++i) for(int j = 0;j < 3;++j){
            int change = min(aux.has[i],cap[j] - aux.has[j]);
            aux2 = aux;
            aux2.has[i] -= change;
            aux2.has[j] += change;
            
            if(!visited[aux2.has[0]][aux2.has[1]][aux2.has[2]]){
                visited[aux2.has[0]][aux2.has[1]][aux2.has[2]] = true;
                
                found[aux2.has[0]] = found[aux2.has[1]] = found[aux2.has[2]] = true;
                
                for(int j = 0;j < 3;++j)
                    for(int k = j+1;k < 3;++k)
                        found[aux2.has[j] + aux2.has[k]] = true;
                
                found[aux2.has[0] + aux2.has[1] + aux2.has[2]] = true;
                
                Q.push(aux2);
            }
        }
    }
    
    int ans = 0;
    
    for(int i = cap[0]+cap[1]+cap[2];i > 0;--i)
        if(found[i]) ++ans;
    
    printf("%d\n",ans);
    
    return 0;
}
