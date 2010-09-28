#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t,n;
    cin>>t;
    string s;
    
    for(int i=0;i<t;i++){
        ostringstream os;
        cin>>n;
        for(int i=0;i<32;i++)
            if((n&(1<<i))!=0) os<<i<<" ";
        
        s=os.str();
        s.erase(s.size()-1,1);
        cout<<s<<endl;
    }

    return 0;
}
