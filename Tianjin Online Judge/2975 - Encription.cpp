#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    vector<string> v;
    string s;
    
    int frequency[26];
    int max,ind,n;    
    
    while(getline(cin,s)) v.push_back(s);

    memset(frequency,0,sizeof(frequency));

    for(int i=0;i<v.size();i++)
        for(int j=0;j<v[i].size();j++)
            if(v[i][j]>='a' && v[i][j]<='z') frequency[v[i][j]-'a']++;
            else if(v[i][j]>='A' && v[i][j]<='Z') frequency[v[i][j]-'A']++;
    
    max=-1;
    
    for(int i=0;i<26;i++){
        if(frequency[i]>max){
            max=frequency[i];
            ind=i;
        }
    }
    
    n=('i'-'a'-ind+26)%26;
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]>='a' && v[i][j]<='z') cout<<(char)('a'+(v[i][j]-'a'+n)%26);
            else if(v[i][j]>='A' && v[i][j]<='Z') cout<<(char)('A'+(v[i][j]-'A'+n)%26);
            else cout<<v[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}
