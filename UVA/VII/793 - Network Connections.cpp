#include <iostream>
#include <string>

using namespace std;

int parent[800],rank[800];

void Make_Set(int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(int x){
    if(x!=parent[x]) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(int &x, int &y){
    int PX=Find(x),PY=Find(y);
    if(PX==PY) return;
    
    if(rank[PX]>rank[PY])
        parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY])
            rank[PY]++;
    }
}

int main(){
    int T,n,x,y,cont1,cont2;
    char c;
    string s;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("\n%d\n",&n);
        
        for(int i=1;i<=n;i++) Make_Set(i);
        
        cont1=cont2=0;
        
        while(1){
            if(!getline(cin,s) || s.empty()) break;
            sscanf(s.c_str(),"%c %d %d",&c,&x,&y);
            
            if(c=='c') Union(x,y);
            else Find(x)==Find(y)? cont1++:cont2++;
        }
        
        if(tc!=1) printf("\n");
        printf("%d,%d\n",cont1,cont2);
    }
    
    return 0;
}
