/*
ID:zion_ba1
LANG:C++
TASK:holstein
*/

#include <cstdio>
#include <vector>

using namespace std;

int main(){
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    
    int V; scanf("%d",&V);
    
    int req[V];
    
    for(int i=0;i<V;i++) scanf("%d",&req[i]);
    
    int G; scanf("%d",&G);
    
    int get[G][V];
    
    for(int i=0;i<G;i++)
        for(int j=0;j<V;j++)
            scanf("%d",&get[i][j]);
    
    int mn=G+1;
    vector<int> v;
    
    int aux[V]; bool valid;
    
    for(int mask=1;mask<(1<<G);mask++){
        for(int i=0;i<V;i++) aux[i]=0;
        
        for(int i=0;i<G;i++)
            if(mask & (1<<i))
                for(int j=0;j<V;j++) aux[j]+=get[i][j];
        
        valid=true;
        for(int i=0;i<V;i++) if(aux[i]<req[i]) valid=false;
        
        if(valid){
            int n=__builtin_popcount(mask);
            
            if(n<mn){
                mn=n;
                v.clear();
                for(int i=0;i<G;i++) if(mask & (1<<i)) v.push_back(i+1);
            }else if(n==mn){
                vector<int> a;
                for(int i=0;i<G;i++) if(mask & (1<<i)) a.push_back(i+1);
                
                v=min(v,a);
            }
        }
    }
    
    printf("%d",mn);
    for(int i=0;i<mn;i++) printf(" %d",v[i]);
    printf("\n");
    
    return 0;
}
