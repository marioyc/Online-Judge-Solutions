#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int T,N,prev[99],aux,end;
    char type[100],line[601],text[99][256];
    vector<int> L[99];
    bool visited[99];
    int ans[99],sz;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d\n",&N);
        
        memset(text,'\0',sizeof(text));
        memset(visited,false,sizeof(visited));
        
        for(int i=0;i<N;++i){
            fgets(line,600,stdin);
            type[i] = line[0];
            
            int pos = 3;
            
            while(true){
                if(line[pos]=='"') break;
                text[i][pos-3] = line[pos];
                ++pos;
            }
            
            int l = strlen(line);
            
            L[i].clear();
            
            if(type[i]=='C'){
                aux = -1;
                
                for(int j=pos+1;j<l;++j){
                    if(line[j]>='0' && line[j]<='9'){
                        if(aux==-1) aux = 0;
                        aux = aux*10+(line[j]-'0');
                        if(j==l-1){
                            L[i].push_back(aux-1);
                            aux = -1;
                        }
                    }else{
                        if(aux!=-1) L[i].push_back(aux-1);
                        aux = -1;
                    }
                }
            }else if(line[pos+2]!='H') visited[i] = true;
        }
        
        queue<int> Q;
        Q.push(0);
        visited[0] = true;
        
        while(!Q.empty()){
            int aux = Q.front();
            Q.pop();
            
            if(type[aux]=='E'){
                end = aux;
                break;
            }
            
            for(int i=L[aux].size()-1;i>=0;--i){
                int v = L[aux][i];
                if(visited[v]) continue;
                
                Q.push(v);
                visited[v] = true;
                prev[v] = aux;
            }
        }
        
        sz = 0;
        
        while(end!=0){
            ans[sz++] = end;
            end = prev[end];
        }
        
        ans[sz++] = 0;
        
        printf("STORY %d\n",tc);
        for(int i=sz-1;i>=0;--i) printf("%s\n",text[ans[i]]);
    }
    
    return 0;
}
