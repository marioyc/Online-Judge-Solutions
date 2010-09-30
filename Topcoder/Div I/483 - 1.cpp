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

class BestApproximationDiv1
{
public:
	string findFraction(int maxDen, string number)
	{
		int A = -1, B = -1, D = -1;
		
		for(int i = 1;i<=maxDen;++i) for(int j = 0;j<i;++j){
			if(__gcd(i,j)==1){
				int cont = 1,aux = j;
				
				for(int k = 0;k<6;++k){
					aux *= 10;
					int d = aux/i;
					aux %= i;
					if(number[k+2]!='0'+d) break;
					++cont;
				}
				
				if(cont>D || (cont==D && (i<B || (i==B && j<A)))){
					A = j;
					B = i;
					D = cont;
				}
			}
		}
		
		ostringstream os;
		os<<A<<"/"<<B<<" has "<<D<<" exact digits";
		return os.str();
	}
};
