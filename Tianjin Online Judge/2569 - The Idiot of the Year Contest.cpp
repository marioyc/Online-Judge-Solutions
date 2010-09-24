#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> num[366];
int cont[366][10];

int main(){
	memset(cont,0,sizeof(cont));
	num[0].push_back(1);
	
	for(int i=1;i<=365;++i){
		int L = num[i-1].size();
		
		for(int j=0;j<L;++j) num[i].push_back(num[i-1][j]*i);
		
		for(int j=0;j+1<L;++j){
			num[i][j+1] += num[i][j]/10;
			num[i][j] %= 10;
		}
		
		while(num[i][L-1]>9){
			num[i].push_back(num[i][L-1]/10);
			num[i][L-1] %= 10;
			++L;
		}
		
		for(int j=0;j<L;++j) ++cont[i][num[i][j]];
	}
	
	int T,n,d;
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;++tc){
		scanf("%d %d",&n,&d);
		printf("%d\n",cont[n][d]);
	}
	
	return 0;
}
