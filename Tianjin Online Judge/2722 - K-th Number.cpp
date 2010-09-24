#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100000
#define LOG2_MAXN 16

int n,a[MAXN],M[LOG2_MAXN+2][MAXN];
int depth[(1<<(LOG2_MAXN+2))],L[(1<<(LOG2_MAXN+2))],first[(1<<(LOG2_MAXN+2))];

void generate(int node, int d, int s, int e){
	depth[node] = d;
	L[node] = e-s+1;
	first[node] = s;
	
	if(s==e) M[d][s] = a[s];
	else{
		int mi = (s+e)/2;
		
		generate(2*node+1,d+1,s,mi);
		generate(2*node+2,d+1,mi+1,e);
		
		int sz1 = mi-s+1,sz2 = e-mi;
		int s1 = s,s2 = mi+1;
		int cont1 = 0,cont2 = 0;
		
		while(cont1<sz1 && cont2<sz2){
			if(M[d+1][s1+cont1]<M[d+1][s2+cont2]){
				M[d][s+cont1+cont2] = M[d+1][s1+cont1];
				++cont1;
			}else{
				M[d][s+cont1+cont2] = M[d+1][s2+cont2];
				++cont2;
			}
		}
		
		if(cont1==sz1){
			while(cont2!=sz2){
				M[d][s+cont1+cont2] = M[d+1][s2+cont2];
				++cont2;
			}
		}else{
			while(cont1!=sz1){
				M[d][s+cont1+cont2] = M[d+1][s1+cont1];
				++cont1;
			}
		}
	}
}

int num,ind[LOG2_MAXN];

void get_nodes(int node, int s, int e, int a, int b){
	if(s>b || e<a) return;
	
	if(s>=a && e<=b){
		ind[num] = node;
		++num;
	}else{
		int mi = (s+e)/2;
		get_nodes(2*node+1,s,mi,a,b);
		get_nodes(2*node+2,mi+1,e,a,b);
	}
}

int count(int idx, int val){
	int d = depth[idx],s = first[idx],l = L[idx];
	
	if(M[d][s]>val) return 0;
	
	int lo = 0,hi = l-1,mi;
	
	while(lo!=hi){
		mi = (lo+hi+1)/2;
		
		if(M[d][s+mi]<=val) lo = mi;
		else hi = mi-1;
	}
	
	return lo+1;
}

int get_Kth(int s, int e, int k){
	num = 0;
	get_nodes(0,0,n-1,s,e);
	
	int lo = 0,hi = n-1,mi;
	
	while(lo!=hi){
		mi = (lo+hi)/2;
		
		int cont = 0;
		
		for(int i = 0;i<num;++i)
			cont += count(ind[i],a[mi]);
		
		if(cont<k) lo = mi+1;
		else hi = mi;
	}
	
	return a[lo];
}

int main(){
	int m;
	scanf("%d %d",&n,&m);
	
	for(int i = 0;i<n;++i) scanf("%d",&a[i]);
	
	generate(0,0,0,n-1);
	for(int i = 0;i<n;++i) a[i] = M[0][i];
	
	for(int i = 0,s,e,k;i<m;++i){
		scanf("%d %d %d",&s,&e,&k);
		printf("%d\n",get_Kth(s-1,e-1,k));
	}
	
	return 0;
}
