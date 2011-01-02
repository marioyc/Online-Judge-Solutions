#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool checkBoth(string x, string a, string b){
    int pos,n = x.size(),l1 = a.size(),l2 = b.size();
    bool found = false;
    
    for(pos = 0;pos+l1-1<n && !found;){
        if(x.substr(pos,l1) == a){
            found = true;
            pos += l1-1;
        }
        ++pos;
    }
    
    if(!found) return false;
    found = false;
    
    for(;pos+l2-1<n && !found;){
        if(x.substr(pos,l2) == b) found = true;
        ++pos;
    }
    
    if(!found) return false;
    return true;
}

int main(){
    string x,a,b;
    
    cin>>x>>a>>b;
    
    bool b1 = checkBoth(x,a,b);
    reverse(x.begin(),x.end());
    bool b2 = checkBoth(x,a,b);
    
    if(b1){
        if(b2) cout<<"both"<<endl;
        else cout<<"forward"<<endl;
    }else{
        if(b2) cout<<"backward"<<endl;
        else cout<<"fantasy"<<endl;
    }
    
    return 0;
}
