#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    vector<int> cont1(52);
    vector<int> cont2(52);
    int T;
    
    cin>>T;
    
    string s1,s2;
    
    for(int caso=1;caso<=T;caso++){
        cin>>s1>>s2;
        
        if(s1.size()!=s2.size()){
            cout<<"No"<<endl;
            continue;
        }
        
        for(int i=0;i<52;i++) cont1[i]=cont2[i]=0;
        
        for(int i=0;i<s1.size();i++){
            if(s1[i]>='a'&& s1[i]<='z') cont1[s1[i]-'a']++;
            else cont1[s1[i]-'A']++;
            
            if(s2[i]>='a'&& s2[i]<='z') cont2[s2[i]-'a']++;
            else cont2[s2[i]-'A']++;
        }
        
        if(cont1==cont2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
