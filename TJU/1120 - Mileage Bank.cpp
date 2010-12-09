#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int calc(string &line){
    string s1,s2;
    int miles;
    char c;
    
    istringstream is(line);
    is>>s1>>s2>>miles>>c;
    
    if(c=='F') return 2*miles;
    if(c=='B') return (3*miles+1)/2;
    if(miles>500) return miles;
    return 500;
}

int main(){
    string line;
    
    while(true){
        getline(cin,line);
        if(line=="#") break;
        
        int ans = calc(line);
        
        while(true){
            getline(cin,line);
            if(line=="0") break;
            ans += calc(line);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
