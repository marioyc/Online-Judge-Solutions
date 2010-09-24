#include <iostream>
#include <string>

using namespace std;

int L;
string s2;

long long solve(string s){
	int cont = 0;
	for(int i=0;i<L;++i) if(s[i]=='?') ++cont;
	
	long long ans = 0;
	
	for(int i=0;i<L;++i){
		if(s[i]!='?' && s[i]>s2[i]){
			ans = 1;
			for(int j=0;j<cont;++j) ans *= 10;
			
			break;
		}else if(s[i]!='?' && s[i]<s2[i]) break;
		else if(s[i]=='?'){
			int aux = 9-s2[i]+'0';
			ans = aux;
			for(int j=1;j<cont;++j) ans *= 10;
			
			s[i] = s2[i];
			ans += solve(s);
			
			break;
		}
	}
	
	return ans;
}

int main(){
	string s1;
	
	while(true){
		cin>>s1;
		if(s1=="#") break;
		cin>>s2;
		
		L = s1.size();
		cout<<solve(s1)<<endl;
	}
	
	return 0;
}
