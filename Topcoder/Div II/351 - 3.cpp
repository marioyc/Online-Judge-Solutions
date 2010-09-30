#include <iostream>
#include <vector>

using namespace std;

class InsertSort{
	public :
	
	int calcMinimalCost(vector <int> A){
		int dp[50],sum = 0,mx = 0;
		
		for(int i=0;i<A.size();++i){
			dp[i] = A[i];
			
			for(int j=0;j<i;++j)
				if(A[i]>=A[j] && A[i]+dp[j]>dp[i])
					dp[i] = A[i]+dp[j];
			
			if(dp[i]>mx) mx = dp[i];
			sum += A[i];
		}
		
		return sum-mx;
	}
};
