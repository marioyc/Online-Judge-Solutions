#include <cstdio>
#include <algorithm>

using namespace std;

struct Part{
    int a,b,res;
    
    Part(){}
    
    Part(int _a, int _b, int _res){
        a = _a; b = _b; res = _res;
    }
    
    bool operator < (Part X)const{
        return res<X.res;
    }
}sum[499500],diff[2*499500];

int main(){
    int n,S[1000],sum_sz,diff_sz;
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i = 0;i<n;++i) scanf("%d",&S[i]);
        
        sum_sz = diff_sz = 0;
        
        for(int i = 0;i<n;++i) for(int j = i+1;j<n;++j){
            sum[sum_sz].a = S[i];
            sum[sum_sz].b = S[j];
            sum[sum_sz].res = S[i]+S[j];
            ++sum_sz;
            
            diff[diff_sz].a = S[i];
            diff[diff_sz].b = S[j];
            diff[diff_sz].res = S[i]-S[j];
            ++diff_sz;
        }
        
        sort(sum,sum+sum_sz);
        sort(diff,diff+diff_sz);
        
        int pos_front = 0,pos_back = diff_sz-1,ans = -536870913;
        
        for(int i = sum_sz-1;i>=0;--i){
            while(pos_back>=0 && diff[pos_back].res>sum[i].res) --pos_back;
            
            for(int j = pos_back;j>=0 && diff[j].res==sum[i].res;--j)
                if(sum[i].a!=diff[j].a && sum[i].a!=diff[j].b && sum[i].b!=diff[j].a && sum[i].b!=diff[j].b)
                    if(diff[j].a>ans) ans = diff[j].a;
            
            while(pos_front<diff_sz && -diff[pos_front].res>sum[i].res) ++pos_front;
            
            for(int j = pos_front;j<diff_sz && -diff[j].res==sum[i].res;++j)
                if(sum[i].a!=diff[j].a && sum[i].a!=diff[j].b && sum[i].b!=diff[j].a && sum[i].b!=diff[j].b)
                    if(diff[j].b>ans) ans = diff[j].b;
        }
        
        if(ans==-536870913) puts("no solution");
        else printf("%d\n",ans);
    }
    
    return 0;
}
