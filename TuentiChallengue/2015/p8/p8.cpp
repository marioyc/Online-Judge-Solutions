#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>

using namespace std;

#define MAXN 100000

map<string, int> id;
int cont_id = 0;
int p[MAXN];
//vector<int> L[MAXN];
map< vector<int>, vector<int> > get;

vector<int> v[20];

int solve(int n){
	if(v[n].size() == 1)
		return p[ v[n][0] ];
	
	int ret = 0;

	for(int i = (int)v[n].size() - 1;i >= 0;--i){
		ret += p[ v[n][i] ];
	}
	
	vector<int> aux;
	int m = v[n].size();

	for(int mask = 1;mask < (1 << m);++mask){
		if(__builtin_popcount(mask) == 1)
			continue;

		aux.clear();
		v[n + 1].clear();

		for(int i = 0;i < m;++i){
			if(mask >> i & 1)
				aux.push_back(v[n][i]);
			else
				v[n + 1].push_back(v[n][i]);
		}

		if(get.find(aux) != get.end()){
			vector<int> L = get[aux],aux2 = v[n + 1];

			for(int i = (int)L.size() - 1;i >= 0;--i){
				aux2.push_back(L[i]);
				v[n + 1] = aux2;
				sort(v[n + 1].begin(),v[n + 1].end());

				ret = max(ret,solve(n + 1));

				aux2.pop_back();
			}
		}
	}

	return ret;
}

int main(){
	freopen("book.data","r",stdin);
	string line,s;

	for(int i = 0,p2;i < 100000;++i){
		//cout << i << endl;
		getline(cin,line);
		istringstream is(line);

		is >> s >> p2;

		if(id.find(s) == id.end())
			id[s] = cont_id++;

		int cur = id[s];
		p[cur] = p2;
		vector<int> L;

		while(is >> s){
			if(id.find(s) == id.end())
				id[s] = cont_id++;
			L.push_back(id[s]);
		}

		if(!L.empty()){
			sort(L.begin(),L.end());
			get[L].push_back(cur);
		}
	}

	fclose(stdin);

	freopen("submitInput8","r",stdin);

	int T;
	cin >> T;
	getline(cin,line);

	while(T--){
		getline(cin,line);
		v[0].clear();

		istringstream is(line);

		while(is >> s)
			v[0].push_back(id[s]);
		
		sort(v[0].begin(),v[0].end());

		cout << solve(0) << endl;
	}

	return 0;
}