#include <cstdio>
#include <algorithm>

using namespace std;

struct cow{
	int ind,A,B;
	
	cow(){
	}
	
	cow(const int _ind, const int _A, const int _B){
		ind=_ind;
		A=_A;
		B=_B;
	}
};

bool sort1(const cow &a, const cow &b){
	return a.A>b.A;
}

bool sort2(const cow &a, const cow &b){
	return a.B>b.B;
}

int main(){
	int N,K,A,B;
	
	scanf("%d %d",&N,&K);
	
	cow a[N];
	
	for(int i=0;i<N;i++){
		scanf("%d %d",&A,&B);
		a[i]=cow(i+1,A,B);
	}
	
	sort(a,a+N,sort1);
	sort(a,a+K,sort2);
	
	printf("%d\n",a[0].ind);
	
	return 0;
}
