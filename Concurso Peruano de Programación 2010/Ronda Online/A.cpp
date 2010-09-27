#include <iostream>

using namespace std;

int main(){
	int T,N,result,num[100];
	char c[100];
	
	cin>>T;
	
	for(int tc = 1;tc<=T;++tc){
		cin>>N;
		
		for(int i = 0;i<N;++i)
			cin>>c[i]>>num[i];
		
		cin>>result;
		
		long long ans = result;
		
		for(int i = N-1;i>=0;--i){
			if(c[i]=='+') ans -= num[i];
			if(c[i]=='-') ans += num[i];
			if(c[i]=='*') ans /= num[i];
			if(c[i]=='/') ans *= num[i];
		}
		
		cout<<"Caso #"<<tc<<": "<<ans<<endl;
	}
	
	return 0;
}
