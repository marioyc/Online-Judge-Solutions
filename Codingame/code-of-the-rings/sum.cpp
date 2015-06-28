#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

string toString(int n){
	string ret = "";

	while(n){
		ret += '0' + n % 10;
		n /= 10;
	}

	reverse(ret.begin(),ret.end());
	return ret;
}

int main(){
	int sum = 0;
	string sol;

	for(int i = 1;i <= 24;++i){
		string file = "out/" + toString(i) + ".txt";
		freopen(file.c_str(),"r",stdin);
		cin >> sol;
		cout << i << ":" << setw(3) << sol.size() << " ";
		sum += sol.size();
		fclose(stdin);
	}

	cout << endl << sum << endl;

	return 0;
}