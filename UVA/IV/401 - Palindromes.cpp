#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s1="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    string s2="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    
    map<char,char> M;
    
    for(int i=0;i<s1.size();i++) M[s1[i]]=s2[i];
    
    int n;
    char cad[21];  
    bool palindrome,mirrored;
    
    while(cin>>cad){
        palindrome=mirrored=1;
        
        n=strlen(cad);
        
        for(int i=0;i<=n/2;i++){
            if(cad[i]!=cad[n-1-i]) palindrome=0;
            if(cad[n-1-i]!=M[cad[i]]) mirrored=0;
        }
        
        if(palindrome && mirrored) cout<<cad<<" -- is a mirrored palindrome.\n\n";
        else if(palindrome && !mirrored) cout<<cad<<" -- is a regular palindrome.\n\n";
        else if(!palindrome && mirrored) cout<<cad<<" -- is a mirrored string.\n\n";
        else cout<<cad<<" -- is not a palindrome.\n\n";
        
        
    }
    
    return 0;
}
