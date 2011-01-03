#include<iostream>
#include<sstream>
#include<iomanip>
#include<vector>
#include<string>

using namespace std;

int main(){    
    string s1,s2,s;
    vector<string> v1;
    vector<string> v2;
    int caso=1,ans,m,n;
    int lcs[501][501];
    bool equal[500][500];
    
    while(getline(cin,s1)){
        getline(cin,s2);
        
        cout<<setw(2)<<setiosflags(ios::right)<<caso<<". ";
        caso++;
        
        for(int i=0;i<s1.size();i++) if(!isupper(s1[i]) && !islower(s1[i]) && !isdigit(s1[i])) s1[i]=' ';
        for(int i=0;i<s2.size();i++) if(!isupper(s2[i]) && !islower(s2[i]) && !isdigit(s2[i])) s2[i]=' ';
        
        v1.clear();
        v2.clear();
        
        istringstream is1(s1);
        istringstream is2(s2);
        
        while(is1>>s) v1.push_back(s);
        while(is2>>s) v2.push_back(s);
        
        m=v1.size();
        n=v2.size();
        
        if(m==0 || n==0){
            cout<< "Blank!"<<endl;
            continue;
        }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(v1[i]==v2[j]) equal[i][j]=true;
                else equal[i][j]=false;
        
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==m || j==n){
                    lcs[i][j]=0;
                    continue;
                }
                
                if(equal[i][j]) lcs[i][j]=1+lcs[i+1][j+1];
                else lcs[i][j]=max(lcs[i][j+1],lcs[i+1][j]);
            }
        }
        
        cout<<"Length of longest match: "<<lcs[0][0]<<endl;
    }
    
    return 0;
}
