#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    short L,N;
    string s1,s2;
    map<string, string> M;
    
    cin>>L>>N;
    
    for(int i=0;i<L;i++){
        cin>>s1>>s2;
        M[s1]=s2;
    }
    
    char c1,c2;
    
    for(int i=0;i<N;i++){
        cin>>s1;
        if(M[s1]!="") cout<<M[s1]<<endl;
        else{
            c1=s1[s1.size()-1];
            c2=s1[s1.size()-2];
            
            if(c1=='y'&&(c2!='a'&&c2!='e'&&c2!='i'&&c2!='o'&&c2!='u')){
                s1.erase(s1.size()-1,1);
                cout<<s1<<"ies"<<endl;
            }else if(c1=='o'||c1=='s'||c1=='x'||(c1=='h'&&(c2=='c'||c2=='s'))) cout<<s1<<"es"<<endl;
            else cout<<s1<<"s"<<endl;
        }
    }

    return 0;
}
