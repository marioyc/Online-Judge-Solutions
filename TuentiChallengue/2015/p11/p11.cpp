#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

#define MAXS 4005
#define MAXR 1005
#define MOD 1000000007

int S,R,cont,end;
map<string, int> id;
vector<int> L[MAXR],K[MAXR],ST[MAXR];

int C[MAXR + 1][MAXR + 1];
int memo[MAXR][MAXS + 1];

int solve(int pos, int st){
	if(pos == end) return 1;

	int &ret = memo[pos][st];

	if(ret == -1){
		ret = 0;

		int deg = L[pos].size();
		st = min(S,st + 1);

		for(int i = deg - 1;i >= 0;--i){
			int to = L[pos][i];

			int need = max(0,max(K[pos][i] - 1,ST[pos][i] - st));

			if(need > deg - 1 || min(S,st + need) < ST[pos][i]) continue;

			ret = (ret + (long long)C[deg - 1][need] * solve(to,min(S,min(S,st + need) - ST[pos][i]))) % MOD;

			/*if(tc == 21){
				cout << pos << " " << st << " " << to << " " << need << " " << " " << C[deg - 1][need] << " " << (long long)C[deg - 1][need] * solve(to,min(S,min(S,st + need) - ST[pos][i])) << endl;
			}*/
		}
	}

	return ret;
}

int main(){
	for(int i = 0;i <= MAXR;++i){
		C[i][0] = 1;

		for(int j = 1;j <= i;++j){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if(C[i][j] >= MOD) C[i][j] -= MOD;
		}
	}

	freopen("scenarios.txt","r",stdin);

	int T;
	string s,s2;

	cin >> T;

	int ans[T];

	for(int tc = 0;tc < T;++tc){
		cin >> S >> R;
		//if(tc == 21)
		//	cout << S << " " << R << endl;

		id.clear();
		cont = 0;

		for(int i = 0;i <= R;++i){
			L[i].clear();
			K[i].clear();
			ST[i].clear();
		}

		for(int i = 0;i < R;++i){
			int d,k,st;
	
			cin >> s >> d;
	
			if(id.find(s) == id.end())
				id[s] = cont++;
	
			int u = id[s];
	
			while(d--){
				cin >> s2 >> k >> st;
	
				if(id.find(s2) == id.end())
					id[s2] = cont++;
	
				int v = id[s2];
	
				L[u].push_back(v);
				K[u].push_back(k);
				ST[u].push_back(st);

				/*if(tc == 21){
					cout << u << " " << v << " " << k << " " << st << endl;
				}*/
			}
		}

		end = id["exit"];
		//if(tc == 21)
		//	cout << "end = " << end << endl;
		memset(memo,-1,sizeof memo);
		ans[tc] = solve(id["start"],S);
	}

	fclose(stdin);

	freopen("submitInput","r",stdin);

	int N;

	while(cin >> N){
		cout << "Scenario " << N << ": " << ans[N] << endl;
	}

	fclose(stdin);

	return 0;
}