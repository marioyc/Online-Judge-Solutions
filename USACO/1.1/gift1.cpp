/*
ID: zion_ba1
LANG: C++
TASK: gift1
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){

    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);

    int n;
    string s;
    vector<string> v1;

    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>s;
        v1.push_back(s);
    }
    vector<int> v2(n,0);
    
    int a,b;
    int k;
    
    for(int i=0;i<n;i++)
    {
        cin>>s;
        cin>>a>>b;
        for(k=0;k<n;k++)
        {
            if(v1[k]==s) break;
        }
        v2[k]-=a;
        if(b!=0)
        {
            v2[k]+=a-b*(a/b);
            for(int j=0;j<b;j++)
            {
                cin>>s;
                for(k=0;k<n;k++)
                {
                    if(v1[k]==s) break;
                }
                v2[k]+=a/b;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<v1[i]<<" "<<v2[i]<<endl;
    }    

    return 0;
}
