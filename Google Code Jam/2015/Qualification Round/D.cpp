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

	int T,X,R,C;

	cin >> T;

	for(int tc = 1;tc <= T;++tc){
		cin >> X >> R >> C;

		bool ok = true;

		if(R * C % X != 0)
			ok = false;

		if(!(R >= X || C >= X))
			ok = false;

		if(!((R >= 1 + (X - 1) / 2 && C >= 1 + X / 2) || (R >= 1 + X / 2 && C >= 1 + (X - 1) / 2)))
			ok = false;

		if(X >= 7)
			ok = false;

		if(X == 4 && min(R,C) == 2)
			ok = false;

		if(X == 5 && min(R,C) == 3 && max(R,C) == 5)
			ok = false;

		if(X == 6 && min(R,C) == 3)
			ok = false;

		cout << "Case #" << tc << ": " << (ok? "GABRIEL" : "RICHARD") << endl;
	}

	return 0;
}