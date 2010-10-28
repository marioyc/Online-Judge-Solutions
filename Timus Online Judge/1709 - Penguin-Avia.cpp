#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define MAX_N 100

int main(){
	int n;
	long long d,a;
	cin>>n>>d>>a;
	
	vector<string> M1(n);
	for(int i=0;i<n;++i) cin>>M1[i];
	
	int num_comp = 0, comp[MAX_N];
	memset(comp,-1,sizeof(comp));
	
	bool used[MAX_N][MAX_N];
	memset(used,false,sizeof(used));
	
	for(int i=0;i<n;++i){
		if(comp[i]==-1){
			
			queue<int> Q;
			Q.push(i);
			comp[i] = num_comp;
			
			while(!Q.empty()){
				int aux = Q.front();
				Q.pop();
				
				for(int j=0;j<n;++j){
					if(M1[aux][j]=='1' && comp[j]==-1){
						Q.push(j);
						comp[j] = num_comp;
						used[aux][j] = used[j][aux] = true;
					}
				}
			}
			
			++num_comp;
		}
	}
	
	long long total_cost = a*(num_comp-1);
	
	for(int i=0;i<num_comp;++i){
		int E = 0, V = 0;
		
		for(int j=0;j<n;++j)
			if(comp[j]==i) ++V;
		
		for(int j=0;j<n;++j){
			if(comp[j]!=i) continue;
			for(int k=j+1;k<n;++k)
				if(M1[j][k]=='1') ++E;
		}
		
		total_cost += d*(E-V+1);
	}
	
	cout<<total_cost<<endl;
	
	vector<string> M2(n,string(n,'0'));
	bool connected[MAX_N];
	memset(connected,false,sizeof(connected));
	connected[0] = true;
	
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(M1[i][j]=='1' && !used[i][j])
				M2[i][j] = M2[j][i] = 'd';
	
	for(int j=0;j<n;++j){
		if(!connected[comp[j]]){
			M2[0][j] = M2[j][0] = 'a';
			connected[comp[j]] = true;
		}
	}
	
	for(int i=0;i<n;++i) cout<<M2[i]<<endl;
	
	return 0;
}
