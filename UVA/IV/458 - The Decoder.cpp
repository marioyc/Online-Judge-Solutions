#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s;
    
    while(getline(cin,s)){
        for(int i=0;i<s.size();i++) s[i]-=7;
        cout<<s<<endl;
    }

    return 0;
}
