#include <iostream>
#include <string>

using namespace std;

int main(){
    string comm;
    int users = 0,ans = 0;
    
    while(getline(cin,comm)){
        if(comm[0]=='+') ++users;
        else if(comm[0]=='-') --users;
        else{
            int L = comm.size();
            ans += users*L;
            
            int pos = 0;
            
            while(pos<L){
                ans -= users;
                if(comm[pos]==':') break;
                ++pos;
            }
        }
    }
    
    cout<<ans<<'\n';
    
    return 0;
}
