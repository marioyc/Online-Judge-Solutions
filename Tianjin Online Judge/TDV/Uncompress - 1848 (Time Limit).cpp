#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s1,s2;
    vector<string> v;
    int ind;

    while(getline(cin,s1)){
        if(s1=="0") break;
        for(int i=0;i<s1.size();){
            if(s1[i]>='0' && s1[i]<='9'){
                ind=0;
                while(i<s1.size() && isdigit(s1[i])){
                    ind=ind*10+s1[i]-'0';
                    i++;
                }
                cout<<v[v.size()-ind];                
                v.push_back(v[v.size()-ind]);
                v.erase(v.begin()+v.size()-1-ind);
            }else if(islower(s1[i])||isupper(s1[i])){
                s2.clear();
                while(i<s1.size() && (islower(s1[i])||isupper(s1[i]))){
                    s2+=s1[i];
                    i++;
                }
                v.push_back(s2);
                cout<<s2;
            }else{
                cout<<s1[i];
                i++;
            }            
        }
        cout<<endl;
    }

    return 0;
}
