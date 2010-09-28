#include<cstdio>
#include<algorithm>
#include<set>

using namespace std;

int a[500001];
set<int> S;

int main(){    
    int t,n;    
    a[0]=0;
    S.insert(0);
    
    for(int i=1;i<500001;i++){
        t=a[i-1]-i;
        if(t>0 && S.find(t)==S.end()) a[i]=t;
        else a[i]=a[i-1]+i;
        
        S.insert(a[i]);
    }
    
    while(1){
        scanf("%d",&n);
        if(n==-1) break;
        
        printf("%d\n",a[n]);
    }
    
    return 0;
}
