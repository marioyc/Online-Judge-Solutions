#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct state{
    int pos,dist;
    
    state(){}
    
    state(int _pos, int _dist){
        pos = _pos; dist = _dist;
    }
}aux;

int main(){
    int N;
    scanf("%d",&N);
    
    int type[101],arg[101];
    memset(type,-1,sizeof(type));
    
    for(int i = 0,s,t,k;i<N;++i){
        scanf("%d %d %d",&s,&t,&k);
        type[s] = t;
        arg[s] = k;
    }
    
    int next[101];
    bool visited[101];
    
    for(int i = 0;i<=100;++i){
        memset(visited,false,sizeof(visited));
        
        if(type[i]==-1) next[i] = i;
        else{
            int pos = i;
            visited[i] = true;
            
            while(type[pos]!=-1){
                if(type[pos]==2) pos = arg[pos];
                else if(type[pos]==1) pos = (pos>=arg[pos]? pos-arg[pos] : 0);
                else{
                    if(pos+arg[pos]<=100) pos += arg[pos];
                    else{
                        int x = arg[pos]-100+pos;
                        pos = (100>=x? 100-x : 0);
                    }
                }
                
                if(visited[pos]){
                    next[i] = -1;
                    break;
                }else{
                    visited[pos] = true;
                    next[i] = pos;
                }
            }
        }
    }
    
    int ans = -1;
    queue<state> Q;
    memset(visited,false,sizeof(visited));
    
    visited[0] = true;
    Q.push(state(0,0));
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        
        if(aux.pos==100){
            ans = aux.dist;
            break;
        }
        
        for(int i = 1;i<=6;++i){
            int pos = next[(aux.pos+i<=100? aux.pos+i : 200-i-aux.pos)];
            
            if(pos!=-1 && !visited[pos]){
                visited[pos] = true;
                Q.push(state(pos,aux.dist+1));
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
