#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,t,w;
    vector<int> w1,w2;
    
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i){
        scanf("%d %d",&t,&w);
        if(t == 1) w1.push_back(w);
        else w2.push_back(w);
    }
    
    sort(w1.begin(),w1.end());
    sort(w2.begin(),w2.end());
    
    int ans = 2*n;
    
    for(int i = w1.size();i >= 0;--i){
        for(int j = w2.size();j >= 0;--j){
            int aux = i + 2 * j;
            
            for(int k = 0;k < w1.size() - i;++k)
                aux -= w1[k];
            for(int k = 0;k < w2.size() - j;++k)
                aux -= w2[k];
            
            if(aux >= 0) ans = min(ans,i + 2*j);
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
