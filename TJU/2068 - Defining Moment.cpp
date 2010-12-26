#include <iostream>
#include <string>

using namespace std;

string solveSuffix(string s){
    int L = s.size();
    
    if(L>2 && s[L-2]=='e' && s[L-1]=='r') return "one who "+s.substr(0,L-2)+"s";
    else if(L>3 && s[L-3]=='i' && s[L-2]=='n' && s[L-1]=='g') return "to actively "+s.substr(0,L-3);
    else if(L>3 && s[L-3]=='i' && s[L-2]=='z' && s[L-1]=='e') return "change into "+s.substr(0,L-3);
    else if(L>1 && s[L-1]=='s') return "multiple instances of "+s.substr(0,L-1);
    else if(L>4 && s[L-4]=='t' && s[L-3]=='i' && s[L-2]=='o' && s[L-1]=='n') return "the process of "+s.substr(0,L-4)+"ing";
    return s;
}

string solve(string s){
    int L = s.size();
    
    if(L>4 && s[0]=='a' && s[1]=='n' && s[2]=='t' && s[3]=='i') return "against "+solveSuffix(s.substr(4,L-4));
    else if(L>4 && s[0]=='p' && s[1]=='o' && s[2]=='s' && s[3]=='t') return "after "+solveSuffix(s.substr(4,L-4));
    else if(L>3 && s[0]=='p' && s[1]=='r' && s[2]=='e') return "before "+solveSuffix(s.substr(3,L-3));
    else if(L>2 && s[0]=='r' && s[1]=='e') return solveSuffix(s.substr(2,L-2))+" again";
    else if(L>2 && s[0]=='u' && s[1]=='n') return "not "+solveSuffix(s.substr(2,L-2));
    return solveSuffix(s);
}

int main(){
    int T;
    cin>>T;
    
    string s;
    
    while(T--){
        cin>>s;
        cout<<solve(s)<<'\n';
    }
    
    return 0;
}
