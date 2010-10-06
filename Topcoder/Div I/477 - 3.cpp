#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;

class KingdomTour
{
public:
	int V,adj[200][200],parent[200],leftMost[200],right[200];
	bool visited[200];
	
	void dfs(int v){
		visited[v] = true;
		
		for(int i = 0,prev = -1;i<V;++i){
			if(adj[v][i]!=-1 && !visited[i]){
				if(prev!=-1) right[prev] = i;
				else leftMost[v] = i;
				
				prev = i;
				parent[i] = v;
				dfs(i);
			}
		}
	}
	
	int memoRight[200][201],memoSubTree[200][201];
	
	int dpRight(int v, int ends){
		int &ret = memoRight[v][ends];
		if(ret!=-1) return ret;
		
		ret = INT_MAX/2;
		
		if(right[v]==-1){
			ret = dpSubTree(v,ends);
		}else{
			for(int i = 0;i<=ends;++i)
				ret = min(ret,dpSubTree(v,i)+dpRight(right[v],ends-i));
		}
		
		return ret;
	}
	
	int dpSubTree(int v, int ends){
		int &ret = memoSubTree[v][ends];
		if(ret!=-1) return ret;
		
		ret = INT_MAX/2;
		
		if(leftMost[v]==-1){ // leaf node
			if(ends<=1) ret = (v==0? 0:adj[parent[v]][v])*(2-ends%2);
		}else{
			for(int i = 0;i<=min(ends,1);++i)
				ret = min(ret,(v==0? 0:adj[parent[v]][v])*(2-ends%2)+dpRight(leftMost[v],ends-i));
		}
		
		return ret;
	}
	
	int minTime(int N, vector <string> roads, int K, int L)
	{
		V = N;
		
		string aux;
		for(int i = 0;i<roads.size();++i) aux += roads[i];
		aux += ',';
		
		istringstream is(aux);
		memset(adj,-1,sizeof(adj));
		
		for(int i = 0;i+1<N;++i){
			int a,b,c;
			char ch;
			
			is>>a>>b>>c>>ch;
			adj[a][b] = adj[b][a] = c;
		}
		
		memset(visited,false,sizeof(visited));
		memset(parent,-1,sizeof(parent));
		memset(leftMost,-1,sizeof(leftMost));
		memset(right,-1,sizeof(right));
		
		dfs(0);
		
		for(int i = 0;i<V;++i){
			cout<<parent[i]<<" "<<right[i]<<" "<<leftMost[i]<<endl;
		}
		
		memset(memoRight,-1,sizeof(memoRight));
		memset(memoSubTree,-1,sizeof(memoSubTree));
		int ans = INT_MAX;
		
		for(int i = 0;i<=K;++i){
			int aux = dpSubTree(0,2*i);
			if(aux!=-2) ans = min(ans,aux+i*L);
		}
		
		return ans;
	}
};
