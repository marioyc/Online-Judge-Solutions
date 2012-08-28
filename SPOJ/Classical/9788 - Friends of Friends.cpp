#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    vector<int> f,ff;
    
    for(int i = 0,x,y,sz;i < N;++i){
        scanf("%d %d",&x,&sz);
        
        f.push_back(x);
        
        for(int j = 0;j < sz;++j){
            scanf("%d",&y);
            ff.push_back(y);
        }
    }
    
    sort(f.begin(),f.end());
    sort(ff.begin(),ff.end());
    
    
    int n1 = f.size(),n2 = unique(ff.begin(),ff.end()) - ff.begin();
    int ans = 0;
    
    for(int i = 0,j = 0;i < n2;++i){
        while(j < n1 && f[j] < ff[i]) ++j;
        
        if(j == n1 || ff[i] != f[j]) ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
