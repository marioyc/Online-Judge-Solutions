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

class Conditional
{
public:
	double probability(int nDice, int maxSide, int v, int theSum)
	{
		double dp1[51][2501],dp2[51][2501];
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		
		dp1[0][0] = 1;
		
		for(int i = 1;i<=nDice;++i){
			for(int j = nDice*maxSide;j>=0;--j){
				if(j>=v) dp2[i][j] = dp1[i-1][j-v];
				
				for(int k = 1;k<=maxSide;++k){
					if(k>j) continue;
					
					if(k!=v) dp1[i][j] += dp1[i-1][j-k];
					dp2[i][j] += dp2[i-1][j-k];
				}
			}
		}
		
		double s = 0,t = 0;
		
		for(int i = 1;i<=nDice*maxSide;++i){
			if(i>=theSum) s += dp2[nDice][i];
			t += dp2[nDice][i];
		}
		
		return s/t;
	}
};
