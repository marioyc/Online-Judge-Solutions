#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string line;
    int N,p,e,ans[32768];
    
    while(true){
        getline(cin,line);
        if(line=="0") break;
        
        istringstream is(line);
        N = 1;
        
        while(is>>p>>e){
            for(int i=0;i<e;++i)
                N *= p;
        }
        
        --N;
        
        for(int i=2;i<=32767;++i){
            ans[i] = 0;
            
            while(N%i==0){
                N /= i;
                ++ans[i];
            }
        }
        
        bool first = true;
        
        for(int i=32767;i>=2;--i){
            if(ans[i]>0){
                if(!first) cout<<" ";
                first = false;
                cout<<i<<" "<<ans[i];
            }
        }
        
        cout<<endl;
    }
    
    return 0;
}
