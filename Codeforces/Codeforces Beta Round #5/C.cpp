#include <cstdio>
#include <cstring>

using namespace std;

char s[1000001];
int sum[1000001],rmq[20][1000001],ind[20][1000001];

// want = 0 : value
// want = 1 : index
int solve(int s, int e, int want){
	int log = 0;
	
	while((1 << log) <= e-s+1) ++log;
	--log;
	
	if(rmq[log][s] < rmq[log][e - (1 << log) + 1]) return (want == 0? rmq[log][s] : ind[log][s]);
	return (want == 0? rmq[log][e - (1 << log) + 1] : ind[log][e - (1 << log) + 1]);
}

int main(){
	fgets(s,1000002,stdin);
	
	int L = strlen(s); --L;
	s[L] = 0;
	
	for(int i = 0;i < L;++i)
		sum[i + 1] = sum[i] + (s[i] == '('? 1 : -1);
	
	for(int i = 0;i <= L;++i){
		rmq[0][i] = sum[i];
		ind[0][i] = i;
	}
	
	for(int i = 1;i <= L;++i){
		rmq[0][i] = rmq[0][i - 1] + (s[i - 1] == '('? 1 : -1);
		ind[0][i] = i;
	}
	
	for(int l = 1,l2 = 2,j = 1;l2 <= L + 1;l <<= 1,l2 <<= 1,++j){
		for(int i = 0;i <= L;++i){
			if(i+l <= L){
				if(rmq[j-1][i] < rmq[j-1][i+l]){
					rmq[j][i] = rmq[j-1][i];
					ind[j][i] = ind[j-1][i];
				}else{
					rmq[j][i] = rmq[j-1][i+l];
					ind[j][i] = ind[j-1][i+l];
				}
			}else{
				rmq[j][i] = rmq[j-1][i];
				ind[j][i] = ind[j-1][i];
			}
		}
	}
	
	int ans = 0,cont = 1;
	
	for(int i = 0;i+1 < L;++i){
		if(s[i] == '('){
			int lo = i+1,hi = L,mi;
			
			while(lo != hi){
				mi = (lo + hi + 1) / 2;
				
				if(solve(i+1,mi,0) < rmq[0][i]) hi = mi - 1;
				else lo = mi;
			}
			
			lo = solve(i+1,lo,1);
			
			if(lo > i+1 && rmq[0][lo] == rmq[0][i]){
				int l = lo - i;
				
				if(ans == l) ++cont;
				else if(ans < l){
					ans = l;
					cont = 1;
				}
			}
		}
	}
	
	printf("%d %d\n",ans,cont);
	
	return 0;
}
