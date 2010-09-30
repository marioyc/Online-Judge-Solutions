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

class Undo
{
public:
	string getText(vector <string> commands, vector <int> time)
	{
		int n = commands.size();
		string state[n+1];
		
		for(int i = 0;i<n;++i){
			istringstream is(commands[i]);
			
			string op;
			is>>op;
			
			if(op=="type"){
				char c;
				is>>c;
				
				state[i+1] = state[i]+c;
			}else{
				int rev;
				is>>rev;
				
				state[i+1] = state[i];
				
				for(int j = i;j>=0 && time[i]-time[j]<=rev;--j)
					state[i+1] = state[j];
			}
		}
		
		return state[n];
	}
};
