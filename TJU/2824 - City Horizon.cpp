#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int N,A[40000],B[40000],H[40000];
pair<int, int> in[40000];
int x[80000];

int main(){
    scanf("%d",&N);
    
    for(int i = 0,sz = 0;i < N;++i){
        scanf("%d %d %d",&A[i],&B[i],&H[i]);
        
        in[i] = make_pair(A[i],i);
        x[sz++] = A[i];
        x[sz++] = B[i];
    }
    
    int m = 2 * N,m2 = 1;
    
    sort(x,x + m);
    sort(in,in + N);
    
    for(int i = 1;i < m;++i){
        if(x[i] != x[m2 - 1])
            x[m2++] = x[i];
    }
    
    priority_queue< pair<int, int> > Q;
    pair<int, int> P;
    int pos = 0;
    
    while(pos < N && in[pos].first == x[0]){
        int ind = in[pos].second;
        Q.push(make_pair(H[ind],ind));
        ++pos;
    }
    
    long long ans = 0;
    
    for(int i = 1;i < m2;++i){
        int h = 0;
        
        while(!Q.empty()){
            P = Q.top();
            
            if(B[P.second] < x[i]) Q.pop();
            else{
                h = P.first;
                break;
            }
        }
        
        ans += (long long)(x[i] - x[i - 1]) * h;
        
        while(pos < N && in[pos].first == x[i]){
            int ind = in[pos].second;
            Q.push(make_pair(H[ind],ind));
            ++pos;
        }
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
