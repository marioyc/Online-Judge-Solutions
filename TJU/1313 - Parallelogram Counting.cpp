#include <cstdio>
#include <map>

using namespace std;

int main(){
    int T,n,x[1000],y[1000],ans,aux;
    scanf("%d",&T);
    
    map< pair<int,int> , int>::iterator it;
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        
        map< pair<int,int> , int> M;
        
        for(int i=0;i<n;++i) scanf("%d %d",&x[i],&y[i]);
        
        for(int i=0;i<n;++i) for(int j=0;j<i;++j) ++M[make_pair(x[i]+x[j],y[i]+y[j])];
        
        ans = 0;
        
        for(it=M.begin();it!=M.end();++it){
            aux = it->second;
            ans += aux*(aux-1)/2;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
