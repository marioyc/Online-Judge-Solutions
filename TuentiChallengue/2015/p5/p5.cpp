#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define MAXN 100

int N,R,S;
int cost[MAXN],id[MAXN],g[MAXN],start[MAXN];
int cost_mov[MAXN + 5][MAXN];
map<string, int> to_id,ship_id;
vector< pair<int, int> > L[MAXN];

long long dist[MAXN][MAXN];

int main(){
	string name,name2;

	cin >> N;

	for(int i = 0;i < N;++i){
		cin >> name >> cost[i];
		to_id[name] = i;
	}

	cin >> R;

	for(int i = 0,rc;i < R;++i){
		cin >> name >> name2 >> rc;
		L[ to_id[name] ].push_back(make_pair(rc,to_id[name2]));
	}

	for(int i = 0;i < N;++i)
		sort(L[i].begin(),L[i].end());

	cin >> S;

	for(int i = 0,x;i < S;++i){
		cin >> id[i] >> name >> g[i] >> name2;
		ship_id[name] = i;
		start[i] = to_id[name2];
	}

	int E = to_id["Raftel"];
	int MAXT = N;

	// fixed paths
	for(int i = 1;i < S;++i){
		int pos = start[i],cont = 0;

		while(pos != E){
			++cont;
			pos = (id[i] % 2 == 0? L[pos].back().second : L[pos][0].second);
			cost_mov[cont][pos] += g[i];
		}

		MAXT = min(MAXT,cont);
	}

	memset(dist,-1,sizeof dist);

	dist[0][ start[0] ] = g[0];
	bool go = true;

	// maximum amount of gold
	for(int t = 0; t < MAXT;++t){
		for(int i = 0;i < N;++i){
			if(dist[t][i] != -1){
				if(dist[t + 1][i] == -1 || dist[t][i] + 10 > dist[t + 1][i])
					dist[t + 1][i] = dist[t][i] + 10;

				if(dist[t][i] > 0){
					for(int j = (int)L[i].size() - 1;j >= 0;--j){
						int to = L[i][j].second;
						long long d = dist[t][i] - L[i][j].first - cost[to];

						if(to != E)
							d -= cost_mov[t + 1][to];
						
						d = max(d,0LL);

						if(dist[t + 1][to] == -1 || d > dist[t + 1][to])
							dist[t + 1][to] = d;
					}
				}
			}
		}
	}

	long long ans = 0;

	for(int i = 0;i <= MAXT;++i)
		if(dist[i][E] != -1)
			ans = max(ans,dist[i][E]);

	cout << ans << endl;

	return 0;
}