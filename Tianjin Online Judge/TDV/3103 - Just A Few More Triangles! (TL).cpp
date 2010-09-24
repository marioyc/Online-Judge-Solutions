#include<cstdio>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    
    scanf("%d",&n);
        
    vector<int> cont(n,0);    
    
    for(long long i=1;i<n;i++) cont[(i*i)%n]++;
    
    long long total=0;
    
    for(int i=0;i<n;i++){
        if(cont[2*i%n]!=0) total+=(long long)cont[i]*(cont[i]+1)/2*cont[2*i%n];
        for(int j=i+1;j<n;j++) total+=(long long)cont[i%n]*cont[j%n]*cont[(i+j)%n];
    }
    
    printf("%lld\n",total);
    
    return 0;
}
