/*
ID:zion_ba1
LANG:C++
TASK:zerosum
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int N;

void solve(int n, int sign, int m, int sum, string s){
	if(n==N){
		if((sign==0 && sum+m==0) || (sign==1 && sum-m==0))
			cout<<s<<endl;
		return;
	}
	
	int aux = (sign==0? m : -m);
	
	solve(n+1,sign,m*10+n+1,sum,s+" "+string(1,'1'+n));
	solve(n+1,0,n+1,sum+aux,s+"+"+string(1,'1'+n));
	solve(n+1,1,n+1,sum+aux,s+"-"+string(1,'1'+n));
}

int main(){
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	
	cin>>N;	
	solve(1,0,1,0,"1");
	
	return 0;
}
