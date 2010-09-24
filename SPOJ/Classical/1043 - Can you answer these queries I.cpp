#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX_N 50000
#define LOG2_MAXN 15
const long long INF = INT_MAX;

int N,a[MAX_N];
int c[MAX_N+1],int_min[1<<(LOG2_MAXN+2)],int_max[1<<(LOG2_MAXN+2)];
int int_best[1<<(LOG2_MAXN+2)];

void build_tree(int node, int lo, int hi){
    if(lo==hi){
        if(lo!=0){
             int_min[node] = c[lo-1];
             int_max[node] = c[lo];
             int_best[node] = c[lo]-c[lo-1];
        }else{
             int_min[node] = 0;
             int_max[node] = 0;
             int_best[node] = 0;
        }
    }else{
        int mi = (lo+hi)>>1;
        build_tree(2*node+1,lo,mi);
        build_tree(2*node+2,mi+1,hi);
        int_min[node] = min(int_min[2*node+1],int_min[2*node+2]);
        int_max[node] = max(int_max[2*node+1],int_max[2*node+2]);
        int_best[node] = max(int_max[2*node+2]-int_min[2*node+1],
                         max(int_best[2*node+1],int_best[2*node+2]));
    }
}

void init(){
    c[0] = 0;
    for(int i = 0;i<N;++i) c[i+1] = c[i]+a[i];
    build_tree(0,0,N);
}

int minPrefix;
int s,e;

int tree_query(int node, int lo, int hi) {
    if (s<=lo && hi<=e) {
         int ret = int_best[node];
         if (minPrefix!=INF) ret = max(ret,int_max[node]-minPrefix);
         minPrefix = min(minPrefix,int_min[node]);
         return ret;
    }else{
         int mi = (lo+hi)>>1;
         if(mi<s) return tree_query(2*node+2,mi+1,hi);
         else if(mi>=e) return tree_query(2*node+1,lo,mi);
         else{
             int val1 = tree_query(2*node+1,lo,mi);
             int val2 = tree_query(2*node+2,mi+1,hi);
             return max(val1,val2);
         }
    }
}

// Los índices van de 1 a N
int solve_msq(int x, int y){
    minPrefix = INF;
    s = x; e = y;
    return tree_query(0,0,N);
}


int main(){
	scanf("%d",&N);
	for(int i = 0;i<N;++i) scanf("%d",&a[i]);
	
	init();
	
	int M,x,y;
	scanf("%d",&M);
	
	for(int i = 0;i<M;++i){
		scanf("%d %d",&x,&y);
		printf("%d\n",solve_msq(x,y));
	}
	
	return 0;
}
