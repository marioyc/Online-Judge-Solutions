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

class TVWatching
{
public:
	vector< pair<int, int> > P;
	int memo[50][50];
	
	int solve(int next, int last){
		int &ret = memo[next][last];
		if(ret!=-1) return ret;
		
		ret = 0;
		
		for(int i=next-1;i>=0;--i)
			if(P[i].second<=P[next].first &&
				(P[last].second<1440 || (P[i].first >= P[last].second%1440)))
					ret = max(ret,P[i].second-P[i].first+solve(i,last));
		
		return ret;
	}
	
	int mostMinutes(vector <string> programs)
	{
		for(int i=0;i<programs.size();++i){
			int h1,m1,h2,m2;
			char c1,c2;
			
			sscanf(programs[i].c_str(),"%d:%d%cM",&h1,&m1,&c1);
			sscanf(programs[i].c_str()+10,"%d:%d%cM",&h2,&m2,&c2);
			
			h1 %= 12; h2 %= 12;
			
			if(c1=='P') h1 += 12;
			if(c2=='P') h2 += 12;
			
			int s = 60*h1+m1, e = 60*h2+m2;
			if(e<=s) e += 1440;
			
			P.push_back(make_pair(s,e));
		}
		
		sort(P.begin(),P.end());
		memset(memo,-1,sizeof(memo));
		
		int ans = 0;
		for(int i=0;i<P.size();++i) ans = max(ans,P[i].second-P[i].first+solve(i,i));
		
		return ans;
	}
};
