#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main(){
    map <string, string> party;
    map <string, int> votes;
    map <string, int> :: iterator it;
    
    int n,m;
    string s1,s2;
    
    scanf("%d\n",&n);
    
    for(int i=0;i<n;i++){
        getline(cin,s1);
        getline(cin,s2);
        
        party[s1]=s2;
    }
    
    scanf("%d\n",&m);
    
    for(int i=0;i<m;i++){
        getline(cin,s1);
        votes[s1]++;
    }
    
    int max=-1;
    bool tie;
    
    for(it=votes.begin();it!=votes.end();it++){
        if(it->second > max){
            max=it->second;
            tie=false;
            s1=it->first;
        }else if(it->second == max) tie=true;
    }
    
    if(tie) cout<<"tie"<<endl;
    else cout<<party[s1]<<endl;
    
    return 0;
}
