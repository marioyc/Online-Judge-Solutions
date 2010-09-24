#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int gcd(int a, int b){
	if(a%b==0) return b;
	return gcd(b,a%b);
}

int main(){
	int T,N,a[99],ans;
	string s;
	
	cin>>T;
	getline(cin,s);
	
	while(T--){
		getline(cin,s);
		istringstream is(s);
		N = 0;
		
		while(is>>a[N]) ++N;
		
		ans = 0;
		
		for(int i = 0;i<N;++i)
			for(int j = i+1;j<N;++j)
				ans = max(ans,gcd(a[i],a[j]));
		
		cout<<ans<<endl;
	}
	
	return 0;
}
