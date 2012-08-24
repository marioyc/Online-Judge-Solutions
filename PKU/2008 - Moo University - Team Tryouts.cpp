#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct cow{
    int h,w,val;
    
    cow(){}
}a[1000];

bool cmp1(cow x, cow y){
    return x.val < y.val;
}

int main(){
    int N,A,B,C;
    
    scanf("%d %d %d %d",&N,&A,&B,&C);
    
    int h[N],w[N];
    
    for(int i = 0;i < N;++i){
        scanf("%d %d",&a[i].h,&a[i].w);
        a[i].val = A * a[i].h + B * a[i].w - C;
        h[i] = a[i].h;
        w[i] = a[i].w;
    }
    
    sort(a,a + N,cmp1);
    
    sort(h,h + N);
    int M1 = unique(h,h + N) - h;
    
    sort(w,w + N);
    int M2 = unique(w,w + N) - w;
    
    int ans = 0;
    
    for(int i = 0;i < M1;++i){
        int pos1 = 0,aux = 0;
        priority_queue<int, vector<int>, greater<int> > Q;
        
        for(int j = 0,pos2 = 0;j < M2;++j){
            int maxval = A * h[i] + B * w[j];
            
            while(pos1 < N && a[pos1].val <= maxval){
                if(a[pos1].h >= h[i]){
                    Q.push(a[pos1].w);
                    ++aux;
                }
                
                ++pos1;
            }
            
            while(!Q.empty() && Q.top() < w[j]){
                Q.pop();
                --aux;
            }
            
            ans = max(ans,aux);
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
