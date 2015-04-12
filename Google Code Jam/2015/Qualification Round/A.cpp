#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int T,Smax;
	string s;

	cin >> T;

	for(int tc = 1;tc <= T;++tc){
		cin >> Smax >> s;

		int ans = 0,have = 0;

		for(int i = 0;i <= Smax;++i){
			int cur = s[i] - '0';

			if(cur > 0){
				if(have < i){
					ans += i - have;
					have += i - have;
				}

				have += cur;
			}
		}

		cout << "Case #" << tc << ": " << ans << endl;
	}

	return 0;
}