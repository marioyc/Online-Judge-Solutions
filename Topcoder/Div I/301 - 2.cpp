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

class EscapingJail
{
public:
	int getMaxDistance(vector <string> chain)
	{
		int n=chain.size(),M[n][n];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(chain[i][j]==' ') M[i][j]=-1;
				else if(isdigit(chain[i][j])) M[i][j]=chain[i][j]-'0';
				else if(chain[i][j]>='a' && chain[i][j]<='z') M[i][j]=chain[i][j]-'a'+10;
				else M[i][j]=chain[i][j]-'A'+36;
			}
		
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++){
					if(M[i][k]==-1 || M[k][j]==-1) continue;
					else if(M[i][j]==-1) M[i][j]=M[i][k]+M[k][j];
					else M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
				}
		
		int ans=0;
		
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(M[i][j]==-1) return -1;
				else ans=max(ans,M[i][j]);
		
		return ans;
	}
};
