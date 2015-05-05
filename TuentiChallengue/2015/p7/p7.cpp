#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

#define MAXN 700

int N,E;
map<string, int> id;
int dist[MAXN][MAXN];
int q[MAXN][5];
vector<int> L[MAXN];

int main(){
	string name,name2;
	char s[2];

	cin >> N >> E;

	for(int i = 0;i < N;++i){
		cin >> name;
		id[name] = i;

		for(int j = 0;j < 5;++j){
			cin >> s;

			if(s[0] == 'Y') q[i][j] = 1;
			else q[i][j] = 0;
		}
	}

	string line;
	getline(cin,line);

	for(int i = 0;i < E;++i){
		vector<int> ids;
		getline(cin,line);
		istringstream is(line);

		while(is >> name){
			ids.push_back(id[name]);
		}

		int m = ids.size();

		for(int j = 0;j < m;++j)
			for(int k = j + 1;k < m;++k){
				L[ ids[j] ].push_back(ids[k]);
				L[ ids[k] ].push_back(ids[j]);
			}
	}

	memset(dist,-1,sizeof dist);

	for(int i = 0;i < N;++i){
		queue<int> Q;
		Q.push(i);
		dist[i][i] = 0;

		while(!Q.empty()){
			int cur = Q.front();
			Q.pop();

			for(int j = (int)L[cur].size() - 1;j >= 0;--j){
				int to = L[cur][j];

				if(dist[i][to] == -1){
					dist[i][to] = dist[i][cur] + 1;
					Q.push(to);
				}
			}
		}
	}

	int score[N];
	memset(score,0,sizeof score);

	for(int i = 0;i < N;++i)
		if(q[i][0] == 1)
			score[i] += 7;

	for(int i = 0;i < N;++i){
		for(int j = 0;j < N;++j){
			if(dist[i][j] == 1 && q[j][1] == 1)
				score[i] += 3;
			else if(dist[i][j] == 2 && q[j][2] == 1)
				score[i] += 6;
		}

		bool cat = false;

		for(int j = 0;j < N && !cat;++j)
			if(dist[i][j] == 1 && q[j][3] == 1){
				cat = true;

				for(int k = (int)L[j].size() - 1;k >= 0;--k){
					int to = L[j][k];

					if(to != i && q[to][3] == 1)
						cat = false;
				}
			}

		if(cat) score[i] += 4;

		for(int j = 0;j < N;++j)
			if(dist[i][j] == -1 && q[j][4] == 1)
				score[i] += 5;
	}

	int ans = 0;

	for(int i = 0;i < N;++i)
		ans = max(ans,score[i]);

	cout << ans << '\n';

	return 0;
}