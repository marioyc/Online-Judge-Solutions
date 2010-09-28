#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 100000
#define LOG2_MAXN 16

int N,A[MAX_N],ind[(1<<(LOG2_MAXN+2))];

void initialize(int node, int s, int e){
    if(s==e) ind[node] = s;
    else{
        initialize(2*node+1,s,((s+e)>>1));
        initialize(2*node+2,((s+e)>>1)+1,e);
        if (A[ind[2*node+1]]>=A[ind[2*node+2]]) ind[node] = ind[2*node+1];
        else ind[node] = ind[2*node+2];
    }
}

int query(int node, int s, int e, int a, int b){
    if(b<s || a>e) return -1;
    if(a<=s && e<=b) return ind[node];
    int ind1 = query(2*node+1,s,((s+e)>>1),a,b);
    int ind2 = query(2*node+2,((s+e)>>1)+1,e,a,b);
    if(ind1==-1) return ind2;
    if(ind2==-1) return ind1;
    if(A[ind1]>=A[ind2]) return ind1;
    return ind2;
}

int F[MAX_N+1];

int solve(int s, int e){
    int ans = 1,lo = 1,hi = N,mi,ind1,ind2;
    
    while(lo<hi){
        mi = (lo+hi+1)>>1;
        if(s>F[mi-1]) lo = mi;
        else hi = mi-1;
    }
    
    ind1 = lo; lo = 1; hi = N;
    
    while(lo<hi){
        mi = (lo+hi+1)>>1;
        if(e>F[mi-1]) lo = mi;
        else hi = mi-1;
    }
    
    ind2 = lo;
    
    if(ind1==ind2) return e-s+1;
    
    ans = max(ans,F[ind1]-s+1);
    ans = max(ans,e-F[ind2-1]);
    
    if(ind2==ind1+1) return ans;
    
    ind2 -= 2;
    ans = max(ans,A[query(0,0,N-1,ind1,ind2)]);
    
    return ans;
}

int main(){
    int n,Q,a,b;
    
    while(scanf("%d %d",&n,&Q)==2){
        scanf("%d",&a);
        A[0] = 1; N = 1;
        
        for(int i=1;i<n;++i){
            scanf("%d",&b);
            
            if(b!=a){
                A[N] = 0;
                ++N;
            }
            
            ++A[N-1];
            a = b;
        }
        
        F[0] = 0;
        for(int i=0;i<N;++i) F[i+1] = F[i]+A[i];
        
        initialize(0,0,N-1);
        
        for(int i=0;i<Q;++i){
            scanf("%d %d",&a,&b);
            printf("%d\n",solve(a,b));
        }
    }
    
    return 0;
}
