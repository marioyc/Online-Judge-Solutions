#include <iostream>
#include <vector>
#include <string>
#include <map>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    string s;
    vector<string> v;
    
    while(cin>>s)
        v.push_back(s);
    
    map<string,bool> M;
    
    for(int i=0;i<v.size();i++) M[v[i]]=true;
    
    vector<string> v2;
        
    string s1,s2;
        
    for(int i=0;i<v.size();i++)
    {
        for(int j=1;j<v[i].size();j++)
        {
            s1=v[i].substr(0,j);
            s2=v[i].substr(j,v.size()-j);
            if(M[s1] && M[s2]) v2.push_back(v[i]);
        }
    }
    
    sort(all(v2));
    
    for(int i=0;i<v2.size()-1;i++)
    {
        for(int j=i+1;j<v2.size();j++)
        {
            while(v2[i]==v2[j] && j<v2.size())
            {
                v2.erase(v2.begin()+j);
            }            
        }
    }
    
    for(int i=0;i<v2.size();i++) cout<<v2[i]<<endl;

    return 0;
}
