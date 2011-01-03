#include <cstdio>

using namespace std;

int parent[50000],rank[50000],ans;

void Make_Set(int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(int &x, int &y){
    int PX=Find(x),PY=Find(y);
    if(PX==PY) return;
    
    ans--;
    
    if(rank[PX]>rank[PY])
        parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

int main(){
    int tc=1,n,m,x,y;
    
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0) break;
        
        for(int i=0;i<n;i++) Make_Set(i);
        
        ans=n;
        
        for(int i=0;i<m;i++){
            scanf("%d %d",&x,&y);
            Union(x,y);
        }
        
        printf("Case %d: %d\n",tc,ans);
        tc++;
    }
    
    return 0;
}
