#include<iostream>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,n,m,sum,j;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&n,&m);
        
        vector<int> v(m);
        
        for(j=0;j<m;j++) scanf("%d",&v[j]);
        
        sort(v.rbegin(),v.rend());
        
        j=0; sum=0;
        
        while(sum<n && j<v.size()){
            sum+=v[j];
            j++;
        }
        
        printf("Scenario #%d:\n",i+1);
        if(sum<n) printf("impossible\n\n");
        else printf("%d\n\n",j);
    }
    
    return 0;
}
