#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n,m,cont[20000];
	string a[20000];
	
	while(true){
		cin>>n>>m;
		if(n==0) break;
		
		for(int i = 0;i<n;++i) cin>>a[i];
		sort(a,a+n);
		
		int pos = 0;
		fill(cont,cont+n,0);
		
		while(pos<n){
			int s = pos;
			while(pos<n && a[pos]==a[s]) ++pos;
			++cont[pos-s-1];
		}
		
		for(int i = 0;i<n;++i) cout<<cont[i]<<endl;
	}
	
	return 0;
}
