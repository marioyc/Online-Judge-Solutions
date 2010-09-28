#include<iostream>
#include<string>

using namespace std;

bool palindrome(string &s){
    int n=s.size();
    for(int i=0;i<n/2;i++) if(s[i]!=s[n-1-i]) return false;
    return true;
}

int main(){
    int n;
    string line;
    string s;
    
    while(1){
        getline(cin,line);
        if(line=="THE END.") break;
        
        n=line.size();
        s.clear();
        for(int i=0;i<n;i++) if(isupper(line[i]) || islower(line[i])) s+=isupper(line[i])? line[i]-'A'+'a':line[i];
        
        if(palindrome(s)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}
