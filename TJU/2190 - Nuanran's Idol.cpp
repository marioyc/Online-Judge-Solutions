#include  <cstdio>

using namespace std;

int parent[100000],rank[100000];

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
    
    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

int main(){
    int N,M,K,x,y;
    
    scanf("%d %d %d",&N,&M,&K);
    
    for(int i=0;i<N;i++) Make_Set(i);
    
    for(int i=0;i<M;i++){
        scanf("%d %d",&x,&y);
        x--; y--;
        Union(x,y);
    }
    
    for(int i=0;i<K;i++){
        scanf("%d",&x);
        x--;
        if(Find(x)==Find(0)) printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}
