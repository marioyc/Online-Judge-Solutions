#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAX_V 26*26

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
            dist[L[u][i].first][k] = min(dist[L[u][i].first][k],dist[u][k-1]+L[u][i].second);
    }
    
    bool flag = true;
    
    for(int i = 0;i<n && flag;++i)
        if(dist[i][n]!=INT_MAX)
            flag = false;
    
    if(flag){
        //graph is acyclic
        printf("No solution.\n");
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
        
    printf("%.2lf\n",-ans);
}

int main(){
	int n;
	char s[1001];
	
	while(true){
		scanf("%d",&n);
		if(n==0) break;
		
		for(int i = 0;i<=MAX_V;++i) L[i].clear();
		
		for(int i = 0;i<n;++i){
			scanf("%s",s);
			int l = strlen(s);
			
			if(l>=2){
				int v1 = (s[0]-'a')*26+(s[1]-'a');
				int v2 = (s[l-2]-'a')*26+(s[l-1]-'a');
				L[v1].push_back(make_pair(v2,-l));
			}
		}
		
		karp(MAX_V);
	}
	
	return 0;
}
