#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int main(){
    int tc = 1,P,R,dist[50][50];
    char name1[201],name2[201];
    
    while(true){
        scanf("%d %d",&P,&R);
        if(P==0) break;
        
        map<string, int> id;
        memset(dist,-1,sizeof(dist));
        
        for(int i = 0,u,v,cont = 0;i<R;++i){
            scanf("%s %s",name1,name2);
            
            if(id.find(name1)==id.end()) id[name1] = cont++;
            if(id.find(name2)==id.end()) id[name2] = cont++;
            
            u = id[name1]; v = id[name2];
            dist[u][v] = dist[v][u] = 1; 
        }
        
        for(int k = 0;k<P;++k) for(int i = 0;i<P;++i) for(int j = 0;j<P;++j){
            if(dist[i][k]!=-1 && dist[k][j]!=-1 && (dist[i][j]==-1 || dist[i][k]+dist[k][j]<dist[i][j]))
                dist[i][j] = dist[i][k]+dist[k][j];
        }
        
        int ans = 0;
        bool conn = true;
        
        for(int i = 0;i<P;++i) for(int j = i+1;j<P;++j){
            if(dist[i][j]==-1) conn = false;
            else if(dist[i][j]>ans) ans = dist[i][j];
        }
        
        printf("Network %d: ",tc++);
        
        if(!conn) puts("DISCONNECTED");
        else printf("%d\n",ans);
        
        puts("");
    }
    
    return 0;
}
