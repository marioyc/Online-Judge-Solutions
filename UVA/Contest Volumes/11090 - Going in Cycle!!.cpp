#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAX_V 50

vector< pair<int, int> > L[MAX_V+1];
int dist[MAX_V+1][MAX_V+2];


void karp(int n){
    for(int i = 0;i<n;++i)
    	if(!L[i].empty())
        	L[n].push_back(make_pair(i,0));
    ++n;
    
    for(int i = 0;i<n;++i)
        fill(dist[i],dist[i]+(n+1),INT_MAX);
    
    dist[n-1][0] = 0;
    
    for (int k = 1;k<=n;++k) for (int u = 0;u<n;++u){
        if(dist[u][k-1]==INT_MAX) continue;
        
        for(int i = L[u].size()-1;i>=0;--i)
            dist[L[u][i].first][k] = min(dist[L[u][i].first][k],
                                            dist[u][k-1]+L[u][i].second);
    }
    
    bool flag = true;
    
    for(int i = 0;i<n && flag;++i)
        if(dist[i][n]!=INT_MAX)
            flag = false;
    
    if(flag){
        //El grafo es aciclico
        printf("No cycle found.\n");
        return;
    }
    
    double ans = 1e15;
    
    for(int u = 0;u+1<n;++u){
        if(dist[u][n]==INT_MAX) continue;
        double W = -1e15;
        
        for(int k = 0;k<n;++k)
            if(dist[u][k]!=INT_MAX)
                W = max(W,(double)(dist[u][n]-dist[u][k])/(n-k));
        
        ans = min(ans,W);
    }
    
    printf("%.2lf\n",ans);
}

int main(){
	int T,n,m,a,b,c;
	
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d %d",&n,&m);
		
		for(int i = 0;i<=n;++i) L[i].clear();
		
		for(int i = 0;i<m;++i){
			scanf("%d %d %d",&a,&b,&c);
			--a; --b;
			L[a].push_back(make_pair(b,c));
		}
		
		printf("Case #%d: ",tc);
		karp(n);
	}
	
	return 0;
}
