#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int n;
    string l1,l2;
    string s2,s3,s4,s5;
    int pos1,pos2,pos3,pos4;
    
    cin>>n;
    getline(cin,l1);
    
    for(int caso=1;caso<=n;caso++){
        getline(cin,l1);
        getline(cin,l2);
        
        pos1=l1.find("<");
        pos2=l1.find(">");
        pos3=l1.find("<",pos1+1);
        pos4=l1.find(">",pos2+1);
        
        s2=l1.substr(pos1+1,pos2-pos1-1);
        s3=l1.substr(pos2+1,pos3-pos2-1);
        s4=l1.substr(pos3+1,pos4-pos3-1);
        s5=l1.substr(pos4+1,l1.size()-pos4-1);
        
        l1.erase(pos1,1);
        l1.erase(pos2-1,1);
        l1.erase(pos3-2,1);
        l1.erase(pos4-3,1);
        
        cout<<l1<<endl;
        
        pos1=l2.find("...");
        l2.erase(pos1,3);
        l2.insert(pos1,s4+s3+s2+s5);
        
        cout<<l2<<endl;
    }

    return 0;
}
