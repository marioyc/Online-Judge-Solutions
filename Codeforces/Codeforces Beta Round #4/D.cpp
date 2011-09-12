#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	map<string, int> nxt;
	string s;
	
	for(int i = 0;i < N;++i){
		cin >> s;
		
		if(nxt.find(s) == nxt.end()) cout << "OK\n";
		else cout << s << nxt[s] << '\n';
		
		++nxt[s];
	}
	
	return 0;
}
