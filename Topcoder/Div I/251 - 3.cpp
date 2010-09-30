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

class MusicCompilation
{
public:
	vector <string> makeCompilation(vector <string> artists)
	{
		vector<string> beginning, middle,ans;
		
		for(int i=0;i<artists.size();++i){
			istringstream is(artists[i]);
			string name;
			int hits;
			
			is>>name>>hits;
			
			if(hits==1) middle.push_back(name);
			else{
				beginning.push_back(name);
				hits -= 2;
				
				for(int i=0;i<hits;++i) middle.push_back(name);
			}
		}
		
		sort(beginning.begin(),beginning.end());
		sort(middle.begin(),middle.end());
		
		for(int i=0;i<beginning.size();++i) ans.push_back(beginning[i]);
		for(int i=0;i<middle.size();++i) ans.push_back(middle[i]);
		for(int i=0;i<beginning.size();++i) ans.push_back(beginning[i]);
		
		return ans;
	}
};
