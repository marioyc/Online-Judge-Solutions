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


class TheMountain {
public:
	int M0[200][200],M1[200][200],M2[200][200],M3[200][200],M4[200][200];
	bool ok1[200][200],ok2[200][200],ok3[200][200],ok4[200][200];
	int sum1[200][200],sum2[200][200],sum3[200][200],sum4[200][200];
	
	int minSum(int n, int m, vector <int> ri, vector <int> ci, vector <int> el) {
		memset(M0,-1,sizeof M0);
		
		for(int i = 0;i < ri.size();++i)
			M0[ ri[i] ][ ci[i] ] = el[i] - 1;
		
		memset(ok1,true,sizeof ok1);
		memset(sum1,0,sizeof sum1);
		
		memset(ok2,true,sizeof ok2);
		memset(sum2,0,sizeof sum2);
		
		memset(ok3,true,sizeof ok3);
		memset(sum3,0,sizeof sum3);
		
		memset(ok4,true,sizeof ok4);
		memset(sum4,0,sizeof sum4);
		
		for(int i = 0;i < n;++i){
			for(int j = 0;j < m;++j){
				int &mx = M1[i][j];
				mx = max(0,M0[i][j]);
				if(i > 0) mx = max(mx,M1[i - 1][j]), ok1[i][j] &= ok1[i - 1][j], sum1[i][j] += sum1[i - 1][j];
				if(j > 0) mx = max(mx,M1[i][j - 1]), ok1[i][j] &= ok1[i][j - 1], sum1[i][j] += sum1[i][j - 1];
				if(i > 0 && j > 0) sum1[i][j] -= sum1[i - 1][j - 1];
				if(M0[i][j] != -1 && mx != M0[i][j]) ok1[i][j] = false;
				++mx;
				sum1[i][j] += mx;
			}
		}
		
		for(int i = 0;i < n;++i){
			for(int j = m - 1;j >= 0;--j){
				int &mx = M2[i][j];
				mx = max(0,M0[i][j]);
				if(i > 0) mx = max(mx,M2[i - 1][j]), ok2[i][j] &= ok2[i - 1][j], sum2[i][j] += sum2[i - 1][j];
				if(j + 1 < m) mx = max(mx,M2[i][j + 1]), ok2[i][j] &= ok2[i][j + 1], sum2[i][j] += sum2[i][j + 1];
				if(i > 0 && j + 1 < m) sum2[i][j] -= sum2[i - 1][j + 1];
				if(M0[i][j] != -1 && mx != M0[i][j]) ok2[i][j] = false;
				++mx;
				sum2[i][j] += mx;
			}
		}
		
		for(int i = n - 1;i >= 0;--i){
			for(int j = 0;j < m;++j){
				int &mx = M3[i][j];
				mx = max(0,M0[i][j]);
				if(i + 1 < n) mx = max(mx,M3[i + 1][j]), ok3[i][j] &= ok3[i + 1][j], sum3[i][j] += sum3[i + 1][j];
				if(j > 0) mx = max(mx,M3[i][j - 1]), ok3[i][j] &= ok3[i][j - 1], sum3[i][j] += sum3[i][j - 1];
				if(i + 1 < n && j > 0) sum3[i][j] -= sum3[i + 1][j - 1];
				if(M0[i][j] != -1 && mx != M0[i][j]) ok3[i][j] = false;
				++mx;
				sum3[i][j] += mx;
			}
		}
		
		for(int i = n - 1;i >= 0;--i){
			for(int j = m - 1;j >= 0;--j){
				int &mx = M4[i][j];
				mx = max(0,M0[i][j]);
				if(i + 1 < n) mx = max(mx,M4[i + 1][j]), ok4[i][j] &= ok4[i + 1][j], sum4[i][j] += sum4[i + 1][j];
				if(j + 1 < m) mx = max(mx,M4[i][j + 1]), ok4[i][j] &= ok4[i][j + 1], sum4[i][j] += sum4[i][j + 1];
				if(i + 1 < n && j + 1 < m) sum4[i][j] -= sum4[i + 1][j + 1];
				if(M0[i][j] != -1 && mx != M0[i][j]) ok4[i][j] = false;
				++mx;
				sum4[i][j] += mx;
			}
		}
		
		int ans = -1;
		int r1[200],r2[200],c1[200],c2[200];
		
		for(int i = 0;i < n;++i){
			for(int j = 0;j < m;++j){
				if(ok1[i][j] && ok2[i][j] && ok3[i][j] && ok4[i][j]){
					int aux = 0;
					
					if(i > 0 && j > 0) aux += sum1[i - 1][j - 1];
					if(i > 0 && j + 1 < m) aux += sum2[i - 1][j + 1];
					if(i + 1 < n && j > 0) aux += sum3[i + 1][j - 1];
					if(i + 1 < n && j + 1 < m) aux += sum4[i + 1][j + 1];
					
					for(int k = 0;k < j;++k)
						r1[k] = max(M1[i][k],M3[i][k]), aux += r1[k];
					for(int k = m - 1;k > j;--k)
						r2[k] = max(M2[i][k],M4[i][k]), aux += r2[k];
					for(int k = 0;k < i ;++k)
						c1[k] = max(M1[k][j],M2[k][j]), aux += c1[k];
					for(int k = n - 1;k > i;--k)
						c2[k] = max(M3[k][j],M4[k][j]), aux += c2[k];
					
					aux += max(max(M1[i][j],M2[i][j]),max(M3[i][j],M4[i][j]));
					if(ans == -1 || aux < ans) ans = aux;
				}
			}
		}
		
		return ans;
	}
};
