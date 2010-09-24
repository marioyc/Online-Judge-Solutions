#include<iostream>
#include<string>

using namespace std;

bool ok(string s1, string s2){
    int M[26];
    memset(M,-1,sizeof(M));
    
    if(s1.size()!=s2.size()) return false;
    
    int n=s1.size();
    
    for(int i=0;i<n;i++)
        if(M[s1[i]-'a']!=-1 && M[s1[i]-'a']!=s2[i]-'a') return false;
        else M[s1[i]-'a']=s2[i]-'a';
    
    return true;
}

int main(){    
    int n;
    string s1,s2;
    
    cin>>n;
    cin>>s1>>s2;
    
    if(ok(s1,s2)) cout<<"DA"<<endl;
    else cout<<"NE"<<endl;
    
    return 0;
}
