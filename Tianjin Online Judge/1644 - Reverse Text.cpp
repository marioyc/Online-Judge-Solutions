#include <string>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    string s;
    cin>>n;
    getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        for(int i=s.size()-1;i>=0;i--) cout<<s[i];
        cout<<endl;
    }

    return 0;
}
