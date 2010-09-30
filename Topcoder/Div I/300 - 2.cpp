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

class JumpyNum
{
public:
	int N[10],memo[9][10][2][2];
	
	int solve(int d, int last, int eq, int zero){
		if(d==-1) return (zero!=1);
		
		int &ret = memo[d][last][eq][zero];
		if(ret!=-1) return ret;
		
		ret = 0;
		
		if(eq==0){
			for(int i = 0;i<10;++i)
				if(zero || abs(last-i)>=2)
					ret += solve(d-1,i,0,i==0? zero : 0);
		}else{
			for(int i = 0;i<=N[d];++i)
				if(zero || abs(last-i)>=2)
					ret += solve(d-1,i,i==N[d]? 1 : 0,i==0? zero : 0);
		}
		
		return ret;
	}
	
	int howMany(int low, int high)
	{
		for(int i = 0;i<10;++i){
			N[i] = high%10;
			high /= 10;
		}
		
		memset(memo,-1,sizeof(memo));
		int ret1 = 0;
		for(int i = 0;i<=N[9];++i) ret1 += solve(8,i,N[9]==i? 1 : 0,i==0? 1 : 0);
		
		--low;
		
		for(int i = 0;i<10;++i){
			N[i] = low%10;
			low /= 10;
		}
		
		memset(memo,-1,sizeof(memo));
		int ret2 = 0;
		for(int i = 0;i<=N[9];++i) ret2 += solve(8,i,N[9]==i? 1 : 0,i==0? 1 : 0);
		
		return ret1-ret2;
	}
};
