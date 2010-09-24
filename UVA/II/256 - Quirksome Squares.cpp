#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<string> v1,v2,v3,v4;
    
    string s1(2,' ');
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if((i+j)*(i+j)==i*10+j){
                s1[0]='0'+i;
                s1[1]='0'+j;
                v1.push_back(s1);
            }
        }
    }
    
    string s2(4,' ');
    
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if((i+j)*(i+j)==i*100+j){
                s2[0]='0'+i/10;
                s2[1]='0'+i%10;
                s2[2]='0'+j/10;
                s2[3]='0'+j%10;
                v2.push_back(s2);
            }
        }
    }

    string s3(6,' ');
    
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if((i+j)*(i+j)==i*1000+j){
                s3[0]='0'+i/100;
                s3[1]='0'+i%100/10;
                s3[2]='0'+i%10;
                s3[3]='0'+j/100;
                s3[4]='0'+j%100/10;
                s3[5]='0'+j%10;
                v3.push_back(s3);
            }
        }
    }
    
    string s4(8,' ');
    
    for(int i=0;i<10000;i++){
        for(int j=0;j<10000;j++){
            if((i+j)*(i+j)==i*10000+j){
                s4[0]='0'+i/1000;
                s4[1]='0'+i/100%10;
                s4[2]='0'+i/10%10;
                s4[3]='0'+i%10;
                s4[4]='0'+j/1000;
                s4[5]='0'+j/100%10;
                s4[6]='0'+j/10%10;
                s4[7]='0'+j%10;
                v4.push_back(s4);
            }
        }
    }
    
    int n;
    
    while(cin>>n){
        if(n==2) for(int i=0;i<v1.size();i++) cout<<v1[i]<<endl;
        else if(n==4) for(int i=0;i<v2.size();i++) cout<<v2[i]<<endl;
        else if(n==6) for(int i=0;i<v3.size();i++) cout<<v3[i]<<endl;
        else for(int i=0;i<v4.size();i++) cout<<v4[i]<<endl;
    }
    
    return 0;
}
