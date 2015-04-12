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

	int T,N;

	cin >> T;

	int a[1000];

	for(int tc = 1;tc <= T;++tc){
		cin >> N;

		for(int i = 0;i < N;++i)
			cin >> a[i];

		sort(a,a + N);
		int ans = a[N - 1];

		for(int i = 1;i <= a[N - 1];++i){
			int aux = i;

			for(int j = 0;j < N;++j)
				aux += (a[j] + i - 1) / i - 1;

			ans = min(ans,aux);
		}

		cout << "Case #" << tc << ": " << ans << endl;
	}

	return 0;
}