#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100000

struct edge{
    int u,v;
    double w;
    
    edge(){}
    
    edge(int _u, int _v, double _w){
        u = _u; v = _v; w = _w;
    }
    
    bool operator < (edge X) const{
        return w<X.w;
    }
};

int parent[MAX_SIZE],rank[MAX_SIZE];

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
    
    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}


int main(){
    double L,w;
    cin>>L;
    
    map<string, int> ind;
    
    int N,M;
    string s1,s2;
    
    cin>>N;
    
    for(int i=0;i<N;++i){
        cin>>s1;
        ind[s1] = i;
    }
    
    cin>>M;
    vector<edge> v;
    
    for(int i=0;i<M;++i){
        cin>>s1>>s2>>w;
        v.push_back(edge(ind[s1],ind[s2],w));
    }
    
    sort(v.begin(),v.end());
    
    double ans = 0;
    
    for(int i=0;i<N;++i) Make_Set(i);
    
    for(int i=0;i<M;++i){
        if(Find(v[i].u)==Find(v[i].v)) continue;
        Union(v[i].u,v[i].v);
        ans += v[i].w;
    }
    
    if(ans<=L+1e-9) printf("Need %.1lf miles of cable\n",ans);
    else printf("Not enough cable\n");
    
    return 0;
}
