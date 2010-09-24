#include<iostream>
#include<string>

using namespace std;

bool menor(string &a, string &b){
    if(a.size()<b.size()) return true;
    if(a.size()>b.size()) return false;
    
    for(int i=0;i<a.size();i++){
        if(a[i]<b[i]) return true;
        else if(a[i]>b[i]) return false;
    }
    
    return false;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s1,s2;
    int n;
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        if(menor(s1,s2)) cout<<"NO BRAINS"<<endl;
        else cout<<"MMM BRAINS"<<endl;
    }
}
