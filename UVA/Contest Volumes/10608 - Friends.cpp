#include <cstdio>
#include <iostream>

using namespace std;

int parent[30000],rank[30000],cont[30000],ans;

void Make_Set(int x){
    parent[x]=x;
    rank[x]=0;
    cont[x]=1;
}

int Find(int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(int &x, int &y){
    int PX=Find(x),PY=Find(y);
    if(PX==PY) return;
    
    if(rank[PX]>rank[PY]){
        parent[PY]=PX;
        cont[PX]+=cont[PY];
        ans>?=cont[PX];
    }else{
        parent[PX]=PY;
        cont[PY]+=cont[PX];
        ans>?=cont[PY];
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

int main(){
    int T,N,M,x,y;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&N,&M);
        
        for(int i=0;i<N;i++) Make_Set(i);
        
        ans=1;
        
        for(int i=0;i<M;i++){
            scanf("%d %d",&x,&y);
            x--; y--;
            Union(x,y);
        }
        
        printf("%d\n",ans);
    }
}
