#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N;
    string a;
    
    ios::sync_with_stdio(false);
    
    while(true){
        cin>>N;
        if(N==0) break;
        
        int ans = 0;
        
        for(int i = 0;i<N;++i){
            cin>>a;
            sort(a.begin(),a.end());
            
            int x = 0,L = a.size();
            for(int i = 0;i<L;++i) x = x*10+a[i]-'0';
            ans = max(ans,x);
        }
        
        cout<<ans<<'\n';
    }
    
    return 0;
}
