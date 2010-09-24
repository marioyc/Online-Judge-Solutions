#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <set>

using namespace std;

long long memo[148][148];
int words,L[74],acum[74],m;
string abbrev,WL[74];

void toLower(string &s){
    for(int i = s.size()-1;i>=0;--i)
        s[i] = s[i]-'A'+'a';
}

long long solve(int pos1, int w, int pos2){
    if(pos1 == m){
        if(w == words) return 1;
        return 0;
    }
    if(w == words) return 0;
    
    int pos3 = acum[w]+pos2;
    
    if(memo[pos1][pos3] != -1) return memo[pos1][pos3];
    
    long long aux = 0;
    
    for(int i = L[w]-1;i>=pos2;--i){
        if(WL[w][i] == abbrev[pos1]){
            if(i != L[w]-1) aux += solve(pos1+1,w,i+1);
            aux += solve(pos1+1,w+1,0);
        }
    }
    
    memo[pos1][pos3] = aux;
    return aux;
}

set<string> I;

void add(string &s){
	if(I.find(s) != I.end()) return;
    WL[words] = s;
    L[words] = s.size();
    ++words;
}

int main(){
    int n;
    long long ans;
    string s,s2;
    
    while(true){
        cin>>n;
        if(n==0) break;
        
        I.clear();
        
        for(int i = 0;i<n;++i){
            cin>>s;
            I.insert(s);
        }
        
        getline(cin,s);
        
        while(true){
        	getline(cin,s);
            istringstream is(s);
            
            is>>abbrev>>s2;
            if(abbrev == "LAST" && s2 == "CASE") break;
            cout<<abbrev;
            toLower(abbrev);
            m = abbrev.size();
            
            words = 0; acum[0] = 0;
            add(s2);
            while(is>>s2) add(s2);
            
            for(int i=1;i<words;++i) acum[i] = acum[i-1]+L[i-1];
            
            memset(memo,-1,sizeof(memo));
            ans = solve(0,0,0);
            
            if(ans>0) cout<<" can be formed in "<<ans<<" ways"<<endl;
            else cout<<" is not a valid abbreviation"<<endl;
        }
    }
    
    return 0;
}
