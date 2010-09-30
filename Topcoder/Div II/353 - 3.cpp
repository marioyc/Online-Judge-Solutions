#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

class PlatformJumper{
	public :
	
	int maxCoins(vector <string> platforms, int v, int g){
		int N = platforms.size();
		int x[N],y[N],c[N];
		
		for(int i=0;i<N;++i) sscanf(platforms[i].c_str(),"%d %d %d",&x[i],&y[i],&c[i]);
		
		for(int i=0;i<N;++i) for(int j=i+1;j<N;++j){
			if(y[i]<y[j]){
				swap(x[i],x[j]);
				swap(y[i],y[j]);
				swap(c[i],c[j]);
			}
		}
		
		int ans = 0,dp[N];
		
		for(int i=0;i<N;++i){
			dp[i] = c[i];
			
			for(int j=0;j<i;++j){
				if(y[j]>y[i] && dp[j]+c[i]>dp[i]){
					long long aux1 = (long long)g*(x[j]-x[i])*(x[j]-x[i]);
					long long aux2 = (long long)2*v*v*(y[j]-y[i]);
					
					if(aux1<=aux2) dp[i] = c[i]+dp[j];
				}
			}
			
			if(dp[i]>ans) ans = dp[i];
		}
		
		return ans;
	}
};
