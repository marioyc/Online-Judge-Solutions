#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n;
vector< vector<int> > L;
bool visited[100];

void unreachable(int v){
    fill(visited,visited+n,false);
    
    queue<int> Q;
    Q.push(v);
    
    int aux;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        for(int i=0;i<L[aux].size();i++){
            if(visited[L[aux][i]]) continue;
            visited[L[aux][i]]=true;
            Q.push(L[aux][i]);
        }
    }
    
    int cont=0;
    
    for(int i=0;i<n;i++) if(!visited[i]) cont++;
    
    printf("%d",cont);
    
    for(int i=0;i<n;i++) if(!visited[i]) printf(" %d",i+1);
    printf("\n");
}

int main(){
    int a,b,m;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        L.clear();
        L.resize(n);
        
        while(1){
            scanf("%d",&a);
            if(a==0) break;
            
            while(1){
                scanf("%d",&b);
                if(b==0) break;
                
                L[a-1].push_back(b-1);
            }            
        }
        
        scanf("%d",&m);
            
        for(int i=0;i<m;i++){
            scanf("%d",&a);
            unreachable(a-1);
        }
    }
    
    return 0;
}
