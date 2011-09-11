#include <iostream>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);	
	
	char s[50001];
	cin >> s;
	
	int L = strlen(s),diff = 0;
	set< pair<int, int> > S;
	long long ans = 0;
	
	for(int i = 0,a,b;i < L;++i){
		if(s[i] == '(') ++diff;
		if(s[i] == ')') --diff;
		
		if(s[i] == '?'){
			cin >> a >> b;
			
			S.insert(make_pair(a-b,i));
			s[i] = ')';
			ans += b;
			--diff;
		}
		
		if(diff == -1){
			if(S.empty()) break;
			else{
				pair<int,int> best = *S.begin();
				S.erase(S.begin());
				
				s[best.second] = '(';
				ans += best.first;
				diff += 2;
			}
		}
	}
	
	if(diff == 0) cout << ans << '\n' << s << endl;
	else cout << -1 << endl;
	
	return 0;
}
