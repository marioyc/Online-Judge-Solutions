#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);	
	
	int N;
	cin >> N;
	
	int t[N];
	for(int i = 0;i < N;++i) cin >> t[i];
	
	int a = 0,b = 0,sum_a = 0,sum_b = 0;
	
	for(int i = 0;i < N;++i){
		if(sum_a <= sum_b){
			sum_a += t[a];
			++a;
		}else{
			sum_b += t[N - 1 - b];
			++b;
		}
	}
	
	cout << a << ' ' << b << endl;
	
	return 0;
}
