#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#define all(v) (v).begin(), (v).end()

using namespace std;

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s;
    getline(cin,s);
    string x;
    while(getline(cin,s)){
        istringstream is(s);
        ostringstream os;
        while(is>>x){
            reverse(all(x));
            os<<x<<" ";
        }
        s=os.str();
        s.erase(s.size()-1,1);
        cout<<s<<endl;
    }
    return 0;
}
