#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int ans[101],k;
	
	ans[100]=1;
	for(int i=99;i>=67;i--) ans[i]=2;
	for(int i=66;i>=55;i--) ans[i]=3;
	for(int i=54;i>=48;i--) ans[i]=4;
	
	//Constante de Euler-Mascheroni : 0.577215664901532860606
	for(int i=47;i>=5;i--) ans[i]=round(exp(100.0/i-0.577215664901532860606));
	
	while(scanf("%d",&k)==1) printf("%d\n",ans[k]);
	
	return 0;
}
