#include<iostream>
#include<string>

using namespace std;

string s,N;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N;
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>s;
        
        if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u') cout<<s<<"cow"<<endl;
        else{
            for(int i=1;i<s.size();i++) cout<<s[i];
            cout<<s[0]<<"ow"<<endl;
        }
    }
}
