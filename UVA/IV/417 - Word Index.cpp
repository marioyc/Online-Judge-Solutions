#include<iostream>
#include<string>
#include<map>
#include<queue>

using namespace std;

map<string, int> M;

void generate_positions(){
    queue<string> Q;
    for(char c='a';c<='z';c++) Q.push(string(1,c));
    
    string s;
    
    int cont=1;    
    
    while(!Q.empty()){
        s=Q.front();
        Q.pop();
        
        M[s]=cont;
        cont++;
        
        if(s.size()==5) continue;
        
        for(char c=s[s.size()-1]+1;c<='z';c++) Q.push(s+c);
    }
}

int main(){
    generate_positions();
    
    string s;
    map<string, int> :: iterator it;
    
    while(cin>>s){
        it=M.find(s);
        if(it==M.end()) cout<<0<<endl;
        else cout<<it->second<<endl;
    }
    
    return 0;
}
