#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);	
	
	int N,K;
	cin >> N >> K;
	
	int h[N];
	for(int i = 0;i < N;++i) cin >> h[i];
	
	bool done[N];
	memset(done,false,sizeof(done));
	
	priority_queue< pair<int,int> > Qmin,Qmax;
	
	int L = 0;
	vector<int> ans;
	
	for(int s = 0,e = -1;s < N;++s){
		int mx = -1,mn = 1000001;
		
		while(!Qmin.empty()){
			pair<int,int> p = Qmin.top();
			
			if(p.second < s) Qmin.pop();
			else{
				mn = min(mn,-p.first);
				break;
			}
		}
		
		while(!Qmax.empty()){
			pair<int,int> p = Qmax.top();
			
			if(p.second < s) Qmax.pop();
			else{
				mx = max(mx,p.first);
				break;
			}
		}
		
		done[s] = true;
		
		while(e + 1 < N && max(mx,h[e + 1]) - min(mn,h[e + 1]) <= K){
			Qmin.push(make_pair(-h[e + 1],e + 1));
			Qmax.push(make_pair(h[e + 1],e + 1));
			mn = min(mn,h[e + 1]);
			mx = max(mx,h[e + 1]);
			++e;
		}
		
		if(e - s + 1 >= L){
			if(e - s + 1 > L) ans.clear();
			L = e - s + 1;
			ans.push_back(s + 1);
		}
	}
	
	int n = ans.size();
	
	cout << L << ' ' << n << '\n';
	
	for(int i = 0;i < n;++i)
		cout << ans[i] << ' ' << ans[i] + L - 1 << '\n';
	
	return 0;
}
