#include <cstdio>
#include <algorithm>

using namespace std;

struct train{
	int s,e,pos;
	
	train(){}
	
	bool operator < (train T)const{
		return s<T.s;
	}
}a[200];

int main(){
	int T,t,A,B,h1,m1,h2,m2;
	int n,m,available[200],pos[200];
	int ans_A,ans_B;
	
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d %d %d",&t,&A,&B);
		n = A+B;
		
		for(int i = 0;i<n;++i){
			scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
			a[i].s = h1*60+m1;
			a[i].e = h2*60+m2;
			a[i].pos = (i<A? 0 : 1);
		}
		
		sort(a,a+n);
		
		m = ans_A = ans_B = 0;
		
		for(int i = 0;i<n;++i){
			int ind = m;
			
			for(int j = 0;j<m;++j){
				if(pos[j]==a[i].pos && available[j]<=a[i].s){
					ind = j;
					break;
				}
			}
			
			if(ind==m){
				if(a[i].pos==0) ++ans_A;
				else ++ans_B;
				++m;
			}
			
			available[ind] = a[i].e+t;
			pos[ind] = 1-a[i].pos;
		}
		
		printf("Case #%d: %d %d\n",tc,ans_A,ans_B);
	}
	
	return 0;
}
