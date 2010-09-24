#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s,ax="";
    
    while(getline(cin,s)){
        for(int i=0;i<s.size();i++){;
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) ax+=s[i];
            else{
                if(!ax.empty() && (ax[0]=='a'||ax[0]=='A'||ax[0]=='e'||ax[0]=='E'||ax[0]=='i'||ax[0]=='I'||ax[0]=='o'||ax[0]=='O'||ax[0]=='u'||ax[0]=='U')) cout<<ax<<"ay";
                else{
                    for(int j=1;j<ax.size();j++) cout<<ax[j];
                    if(!ax.empty()) cout<<ax[0]<<"ay";
                }
                ax.clear();
                cout<<s[i];
            }
        }
        
        if(!ax.empty() && (ax[0]=='a'||ax[0]=='A'||ax[0]=='e'||ax[0]=='E'||ax[0]=='i'||ax[0]=='I'||ax[0]=='o'||ax[0]=='O'||ax[0]=='u'||ax[0]=='U')) cout<<ax<<"ay";
        else{
            for(int j=1;j<ax.size();j++) cout<<ax[j];
            if(!ax.empty()) cout<<ax[0]<<"ay";
        }
        ax.clear();
        cout<<endl;
    }

    return 0;
}
