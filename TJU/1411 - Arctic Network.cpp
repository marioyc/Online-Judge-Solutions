#include <cstdio>

using namespace std;

int parent[500],rank[500];

void Make_set(int x){
    parent[x] = x;
    rank[x] = 0;
}

int Find(int x){
    if(parent[x]==x) return x;
    parent[x] = Find(parent[x]);
    return parent[x];
}

int num_comp;

void Union(int x, int y){
    int PX = Find(x),PY = Find(y);
    if(PX==PY) return;
    --num_comp;
    
    if(rank[PX]>rank[PY]) parent[PX] = PY;
    else{
        parent[PY] = PX;
        if(rank[PX]==rank[PY]) ++rank[PX];
    }
}

int main(){
    int T,S,P,x[500],y[500];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&S,&P);
        
        for(int i = 0;i<P;++i)
            scanf("%d %d",&x[i],&y[i]);
        
        double lo = 0,hi = 20000,mi;
        
        for(int it = 0;it<30;++it){
            mi = (lo+hi)/2;
            
            num_comp = P;
            for(int i = 0;i<P;++i) Make_set(i);
            
            for(int i = 0;i<P;++i)
                for(int j = i+1;j<P;++j)
                    if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=mi*mi)
                        Union(i,j);
            
            if(num_comp<=S) hi = mi;
            else lo = mi;
        }
        
        printf("%.2f\n",lo);
    }
    
    return 0;
}
