#include <string>
#include <iostream>

using namespace std;

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s1;
    string s2;
    
    int a[10];
    int b[10];
    
    while(true)
    {
         
        cin>>s1;
        if(s1=="THEEND") break;
                
        cin>>s2;

        for(int i=0;i<s1.size();i++) a[i]=i;
        
        for(int i=0;i<s1.size()-1;i++)
        {
            for(int j=i+1;j<s1.size();j++)
            {
                if(s1[a[i]]>s1[a[j]]) swap(a[i],a[j]);
                else if(s1[a[i]]==s1[a[j]] && a[i]>a[j]) swap(a[i],a[j]);
            }
        }        
                
        for(int i=0;i<s1.size();i++) b[a[i]]=i;
        
        for(int i=0;i<s2.size()/s1.size();i++)
        {
            for(int j=0;j<s1.size();j++) cout<<s2[s2.size()/s1.size()*b[j]+i];
        }
        
        cout<<endl;
    }   

    return 0;
}
