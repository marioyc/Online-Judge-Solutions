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

using namespace std;

class DominoesGame
{
public:
	int memo[(1<<10)][20][20];
	vector< pair<int, int> > P;
	
	int getValue(int s, int e){
		if(s==e) return P[s].first+P[s].second;
		
		int ans = 0;
		
		if(P[s].first==P[s].second) ans += 2*P[s].first;
		else ans += P[s].first;
		
		if(P[e].first==P[e].second) ans += 2*P[e].second;
		else ans += P[e].second;
		
		return ans;
	}
	
	int solve(int mask, int s, int e){
		int &ret = memo[mask][s][e];
		if(ret!=-1) return ret;
		
		ret = 0;
		
		for(int i=0;i<P.size();++i){
			int ind = (i>>1);
			
			if(mask & (1<<ind)) continue;
			
			if(P[e].second==P[i].first) ret = max(ret,solve(mask | (1<<ind),s,i));
			if(P[s].first==P[i].second) ret = max(ret,solve(mask | (1<<ind),i,e));
		}
		
		int cur_val = getValue(s,e);
		if(cur_val%5==0) ret += cur_val;
		
		return ret;
	}
	
	int largestTotal(vector <string> tiles)
	{
		for(int i=0;i<tiles.size();++i){
			int x,y;
			sscanf(tiles[i].c_str(),"%d:%d",&x,&y);
			P.push_back(make_pair(x,y));
			P.push_back(make_pair(y,x));
		}
		
		memset(memo,-1,sizeof(memo));
		
		int ans = 0;
		for(int i=0;i<P.size();++i) ans = max(ans,solve((1<<(i/2)),i,i));
		return ans;
	}
};
