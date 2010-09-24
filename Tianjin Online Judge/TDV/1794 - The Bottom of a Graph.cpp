#include <cstdio>
#include <vector>

using namespace std;

int main(){    
    int V,E,v1,v2,cont,n;
    
    int Q[5000],head,tail,aux;
    bool visited[5000];
    
    bool space;
    
    while(1){
        scanf("%d",&V);
        if(V==0) break;
        
        scanf("%d",&E);
        
        vector< vector<int> > L(V);
        
        for(int i=0;i<E;i++){
            scanf("%d %d",&v1,&v2);
            L[v2-1].push_back(v1-1);
        }
        
        space=false;
        
        for(int i=0;i<V;i++){
            Q[0]=i;
            head=0;
            tail=1;
            
            fill(visited,visited+V,false);
            visited[i]=true;
            
            cont=0;
            
            while(head!=tail){
                aux=Q[head];
                head++;
                if(head==5000) head=0;
                
                cont++;
                
                n=L[aux].size();
                
                for(int j=0;j<n;j++)
                    if(!visited[L[aux][j]]){
                        visited[L[aux][j]]=true;
                        
                        Q[tail]=L[aux][j];
                        tail++;
                        if(tail==5000) tail=0;
                    }
            }
            
            if(cont==V){
                if(space) printf(" ");
                space=true;
                
                printf("%d",i+1);
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
