#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int n,ax;
    string s1,s2;
    
    vector<string> v1;
    vector<string> v2;
    
    while(1){
        cin>>n;
        if(n==0) break;
        
        v1.clear();
        v2.clear();
        
        getline(cin,s1);
        
        for(int i=0;i<n;i++){
            getline(cin,s1);
            getline(cin,s2);
            v1.push_back(s1);
            v2.push_back(s2);
        }
        
        getline(cin,s1);
        
        ax=0;
        
        while(ax!=v1.size()){
            n=s1.find(v1[ax]);
            
            if(n!=-1){
                s1.erase(n,v1[ax].size());
                s1.insert(n,v2[ax]);
            }else ax++;
        }
        
        cout<<s1<<endl;
    }

    return 0;
}
