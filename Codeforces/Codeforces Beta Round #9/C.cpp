#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);	
	
	int n;
	cin >> n;
	
	int ans = 0;
	
	for(int d = 1;d <= 9;++d){
		for(int mask = 1;mask < (1 << d);mask += 2){
			int aux = 0;
			
			for(int i = 0;i < d;++i){
				aux *= 10;
				if(mask & (1 << i)) ++aux;
			}
			
			if(aux <= n) ++ans;
		}
	}
	
	if(n == 1000000000) ++ans;
	
	cout << ans << endl;
	
	return 0;
}
