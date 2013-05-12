#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

using namespace std;


class DancingFoxes {
public:
	int minimalDays(vector <string> f) {
		int n = f.size();
		int d[n][n];
		
		for(int i = 0;i < n;++i)
			for(int j = 0;j < n;++j)
				d[i][j] = f[i][j] == 'Y'? 1 : 100;
		
		for(int i = 0;i < n;++i) d[i][i] = 0;
		
		for(int k = 0;k < n;++k)
			for(int i = 0;i < n;++i)
				for(int j = 0;j < n;++j)
					d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
		
		if(d[0][1] >= 100) return -1;
		
		int aux = d[0][1] + 1,ans = 0;
		
		while(aux > 2){
			aux -= aux / 3;
			++ans;
		}
		
		return ans;
	}
};
