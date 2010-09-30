#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CellRemoval{
	public :
	
	vector<int> L[50];
	int deleted, son[50];
	
	int dfs(int v){
		if(v==deleted) return 0;
		if(son[v]==0) return 1;
		int ans = 0;
		
		for(int i=L[v].size()-1;i>=0;--i){
			int next = L[v][i];
			ans += dfs(next);
		}
		
		return ans;
	}
	
	int cellsLeft(vector <int> parent, int deletedCell){
		memset(son,0,sizeof(son));
		int root = -1;
		
		for(int i=0;i<parent.size();++i){
			if(parent[i]==-1){
				root = i;
			}else{
				L[parent[i]].push_back(i);
				++son[parent[i]];
			}
		}
		
		deleted = deletedCell;
		return dfs(root);
	}
};
