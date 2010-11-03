#include <cstdio>
#include <cstring>
#include <algorithm>

#include <iostream>

using namespace std;

#define MAX_SIZE 10000

int n,parent[MAX_SIZE],rank[MAX_SIZE],ans[MAX_SIZE];

void Make_Set(const int x){
     parent[x]=x;
     rank[x]=0;
}

int Find(const int x){
     if(parent[x]!=x) parent[x]=Find(parent[x]);
     return parent[x];
}

void Union(const int x, const int y){
    int PX=Find(x),PY=Find(y);
    if(PX==PY) return;
    
    int sum = ans[PX]+ans[PY];
    
    if(rank[PX]>rank[PY]){
        parent[PY]=PX;
        ans[PX] = sum;
    }else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
        ans[PY] = sum;
    }
}

int main(){
    int T,M[100][100];
    scanf("%d",&T);
    
    int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1}, ret;
    
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) scanf("%d",&M[i][j]);
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) ans[i*n+j] = M[i][j];
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) Make_Set(i*n+j);
        
        ret = 0;
        
        for(int i=0;i<n;++i) for(int j=0;j<n;++j){
            if(M[i][j]==0) continue;
            for(int k=0;k<4;++k){
                int r = i+dr[k], c = j+dc[k];
                if(r>=0 && r<n && c>=0 && c<n && M[r][c]>0) Union(i*n+j,r*n+c);
            }
            ret = max(ret,ans[Find(i*n+j)]);
        }
        
        printf("%d\n",ret);
    }
    
    return 0;
}

