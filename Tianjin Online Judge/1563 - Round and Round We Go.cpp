#include <iostream>
#include <string>
#include <set>

using namespace std;

bool isCyclic(string s){
	set <string> rotations;
	rotations.insert(s);
	
	int L = s.size();
	
	for(int i=1;i<L;++i)
		rotations.insert(s.substr(i,L-i)+s.substr(0,i));
	
	for(int i=1;i<=L;++i){
		string aux(L,'0');
		
		int c = 0;
		
		for(int j=L-1;j>=0;--j){
			c += (s[j]-'0')*i;
			aux[j] += c%10;
			c /= 10;
		}
		
		if(c!=0 || rotations.find(aux)==rotations.end()) return false;
	}
	
	return true;
}

int main(){
	string s;
	
	while(cin>>s){
		cout<<s;
		
		if(isCyclic(s)) cout<<" is cyclic"<<endl;
		else cout<<" is not cyclic"<<endl;
	}
	
	return 0;
}
