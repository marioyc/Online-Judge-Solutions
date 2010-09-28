#include <cstdio>
#include <vector>

using namespace std;

long long min(long long a, long long b){
    if(a<b) return a;
    return b;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    long long p1,p2,p3,n;
    scanf("%lld %lld %lld %lld",&p1,&p2,&p3,&n);
    
    int pos1=0,pos2=0,pos3=0;
    long long x;
    
    vector<long long> v;
    v.push_back(1);
    
    for(int i=0;i<n;i++){
        x=min(v[pos1]*p1,min(v[pos2]*p2,v[pos3]*p3));
        
        if(v[pos1]*p1==x) pos1++;
        if(v[pos2]*p2==x) pos2++;
        if(v[pos3]*p3==x) pos3++;
        
        v.push_back(x);
    }
    
    printf("%lld\n",x);
    
    return 0;
}
