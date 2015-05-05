#include <iostream>

using namespace std;

int main(){
	int T;
	unsigned int x;

	cin >> T;

	while(T--){
		cin >> x;
		cout << (x + 1) / 2 << '\n';
	}

	return 0;
}