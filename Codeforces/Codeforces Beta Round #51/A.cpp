#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);    
    
    int N;
    cin>>N;
    
    string s[N][2],aux;
    
    for(int i = 0;i<N;++i){
        if(i>0) cin>>aux;
        cin>>s[i][0]>>s[i][1];
    }
    
    bool used[N];
    memset(used,false,sizeof(used));
    
    int ans = 0;
    
    for(int i = 0;i<N;++i){
        if(used[i]) continue;
        used[i] = true;
        ++ans;
        
        for(int j = i+1;j<N;++j){
            if(used[j]) continue;
            for(int it1 = 0;it1<4;++it1){
                for(int it2 = 0;it2<4;++it2){
                    if(s[i][0]==s[j][0] && s[i][1]==s[j][1]) used[j] = true;
                    char x = s[j][0][0],y = s[j][0][1],z = s[j][1][0],w = s[j][1][1];
                    s[j][0][0] = y; s[j][0][1] = w;
                    s[j][1][0] = x; s[j][1][1] = z;
                }
                
                char x = s[i][0][0],y = s[i][0][1],z = s[i][1][0],w = s[i][1][1];
                s[i][0][0] = y; s[i][0][1] = w;
                s[i][1][0] = x; s[i][1][1] = z;
            }
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
