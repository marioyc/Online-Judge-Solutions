#include <iostream>
#include <fstream>

using namespace std;

#define MAXN 5000

int N,M;
long long a[MAXN][MAXN],suma[MAXN + 1][MAXN + 1];

long long sum(int x0, int y0, int x1, int y1){
	return suma[x1 + 1][y1 + 1] - suma[x0][y1 + 1] - suma[x1 + 1][y0] + suma[x0][y0];
}

int main(){
	freopen("sheet.data","r",stdin);

	cin >> N >> M;

	for(int i = 0;i < N;++i)
		for(int j = 0;j < M;++j)
			cin >> a[i][j];

	for(int i = 0;i < N;++i)
		suma[i][0] = 0;
	for(int i = 0;i < M;++i)
		suma[0][i] = 0;

	for(int i = 0;i < N;++i){
		for(int j = 0;j < N;++j)
			suma[i + 1][j + 1] = a[i][j] + suma[i][j + 1] + suma[i + 1][j] - suma[i][j];
	}

	fclose(stdin);

	freopen("submitInput6","r",stdin);

	int T,x0,y0,x1,y1,k;

	cin >> T;

	for(int tc = 1;tc <= T;++tc){
		cin >> x0 >> y0 >> x1 >> y1 >> k;

		long long ans = 0;

		for(int i = x0 + k;i + k <= x1;++i)
			for(int j = y0 + k;j + k <= y1;++j)
				ans = max(ans,sum(i - k,j - k,i - 1,j - 1) + sum(i + 1,j + 1,i + k,j + k));
		
		cout << "Case " << tc << ": " << ans << endl;
	}

	fclose(stdin);

	return 0;
}