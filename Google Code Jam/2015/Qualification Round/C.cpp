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

int f(int x, int y){
	int sign = 1;

	if(x < 0){
		sign = -sign;
		x = -x;
	}

	if(y < 0){
		sign = -sign;
		y = -y;
	}

	if(x == 1) return sign * y;
	if(y == 1) return sign * x;
	if(x == y) return -sign;

	int ret = 9 - x - y;

	if(x == 3 && y == 2) sign = -sign;
	if(x == 2 && y == 4) sign = -sign;
	if(x == 4 && y == 3) sign = -sign;

	return sign * ret;
}

int pow(int x, long long n){
	if(n == 0) return 1;

	int ans = pow(x,n / 2);
	ans = f(ans,ans);
	if(n & 1)
		ans = f(ans,x);
	return ans;
}

int main(){
	ios::sync_with_stdio(0);

	int T,L;
	long long X;

	cin >> T;

	string s;
	int a[10000];

	for(int tc = 1;tc <= T;++tc){
		cin >> L >> X >> s;

		for(int i = 0;i < L;++i){
			if(s[i] == 'i') a[i] = 2;
			if(s[i] == 'j') a[i] = 3;
			if(s[i] == 'k') a[i] = 4;
		}

		for(int i = 1;i < L;++i)
			a[i] = f(a[i - 1],a[i]);

		bool ok = true;

		if(pow(a[L - 1],X) != -1) ok = false;

		long long p1 = -1,p2 = -2;

		for(int i = 0;i < L;++i){
			int aux = a[i];
			long long pos = -1;

			for(int j = 0;j <= 4 && j < X;++j){
				if(aux == 2){
					pos = i + j * L;
					break;
				}

				aux = f(a[L - 1],aux);
			}

			if(p1 == -1 || (pos != -1 && pos < p1))
				p1 = pos;
		}

		for(int i = 0;i < L;++i){
			if(s[i] == 'i') a[i] = 2;
			if(s[i] == 'j') a[i] = 3;
			if(s[i] == 'k') a[i] = 4;
		}

		for(int i = L - 2;i >= 0;--i)
			a[i] = f(a[i],a[i + 1]);

		for(int i = 0;i < L;++i){
			int aux = a[i];
			long long pos = -1;

			for(int j = 0;j <= 4 && j < X;++j){
				if(aux == 4){
					pos = L * X - (L - i) - j * L;
					break;
				}

				aux = f(aux,a[L - 1]);
			}

			if(p2 == -1 || (pos != -1 && pos > p2))
				p2 = pos;
		}

		if(p1 == -1 || p2 == -1 || p2 - p1 < 2)
			ok = false;

		cout << "Case #" << tc << ": " << (ok? "YES" : "NO") << endl;
	}

	return 0;
}