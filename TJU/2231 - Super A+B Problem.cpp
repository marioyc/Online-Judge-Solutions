#include <vector>
#include <iostream>

using namespace std;

int main(){
    int N,S,ax;
    
    vector<int> v;
    
    bool ok;
    
    while(cin>>N>>S){
        if(N==0 && S==0) break;
        
        v.clear();
        v.resize(N);
        
        for(int i=0;i<N;i++) cin>>v[i];
        
        ok=false;
        
        for(int mask=0;mask<(1<<N);mask++){
            ax=0;
            
            for(int j=0;j<N;j++){
                if((mask & (1<<j))!=0) ax+=v[j];
            }
            
            if(ax==S) ok=true;
            
            if(ok) break;
        }
        
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
