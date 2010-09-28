#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int s;
    string n;
    
    bool horizontal[10][3];
    
    horizontal[0][0]=horizontal[0][2]=1;horizontal[0][1]=0;
    horizontal[1][0]=horizontal[1][1]=horizontal[1][2]=0;
    horizontal[2][0]=horizontal[2][1]=horizontal[2][2]=1;
    horizontal[3][0]=horizontal[3][1]=horizontal[3][2]=1;
    horizontal[4][0]=horizontal[4][2]=0;horizontal[4][1]=1;
    horizontal[5][0]=horizontal[5][1]=horizontal[5][2]=1;
    horizontal[6][0]=horizontal[6][1]=horizontal[6][2]=1;
    horizontal[7][0]=1;horizontal[7][1]=horizontal[7][2]=0;
    horizontal[8][0]=horizontal[8][1]=horizontal[8][2]=1;
    horizontal[9][0]=horizontal[9][1]=horizontal[9][2]=1;
    
    bool vertical[10][4];
    
    vertical[0][0]=vertical[0][1]=vertical[0][2]=vertical[0][3]=1;
    vertical[1][0]=0;vertical[1][1]=1;vertical[1][2]=0;vertical[1][3]=1;
    vertical[2][0]=0;vertical[2][1]=1;vertical[2][2]=1;vertical[2][3]=0;
    vertical[3][0]=0;vertical[3][1]=1;vertical[3][2]=0;vertical[3][3]=1;
    vertical[4][0]=vertical[4][1]=1;vertical[4][2]=0;vertical[4][3]=1;
    vertical[5][0]=1;vertical[5][1]=0;vertical[5][2]=0;vertical[5][3]=1;
    vertical[6][0]=1;vertical[6][1]=0;vertical[6][2]=vertical[6][3]=1;
    vertical[7][0]=0;vertical[7][1]=1;vertical[7][2]=0;vertical[7][3]=1;
    vertical[8][0]=vertical[8][1]=vertical[8][2]=vertical[8][3]=1;
    vertical[9][0]=vertical[9][1]=1;vertical[9][2]=0;vertical[9][3]=1;
    
    while(1){
        cin>>s>>n;
        if(s==0)  break;
        
        for(int i=0;i<n.size();i++){
            if(i!=0) cout<<' ';
            cout<<' ';
            
            if(horizontal[n[i]-'0'][0])
                for(int j=0;j<s;j++)
                    cout<<'-';
            else
                for(int j=0;j<s;j++)
                    cout<<' ';
            
            cout<<' ';
        }
        cout<<endl;
        for(int j=0;j<s;j++){
            for(int i=0;i<n.size();i++){
                if(i!=0) cout<<' ';
            
                if(vertical[n[i]-'0'][0]) cout<<'|';
                else cout<<' ';
            
                for(int i=0;i<s;i++) cout<<' ';
            
                if(vertical[n[i]-'0'][1]) cout<<'|';
                else cout<<' ';
            }
            cout<<endl;
        }
        for(int i=0;i<n.size();i++){
            if(i!=0) cout<<' ';
            cout<<' ';
            
            if(horizontal[n[i]-'0'][1])
                for(int j=0;j<s;j++)
                    cout<<'-';
            else
                for(int j=0;j<s;j++)
                    cout<<' ';
                    
            cout<<' ';
        }
        cout<<endl;
        for(int j=0;j<s;j++){
            for(int i=0;i<n.size();i++){
                if(i!=0) cout<<' ';
            
                if(vertical[n[i]-'0'][2]) cout<<'|';
                else cout<<' ';
            
                for(int i=0;i<s;i++) cout<<' ';
            
                if(vertical[n[i]-'0'][3]) cout<<'|';
                else cout<<' ';
            }
            cout<<endl;
        }
        
        for(int i=0;i<n.size();i++){
            if(i!=0) cout<<' ';
            cout<<' ';
            
            if(horizontal[n[i]-'0'][2])
                for(int j=0;j<s;j++)
                    cout<<'-';
            else
                for(int j=0;j<s;j++)
                    cout<<' ';
                    
            cout<<' ';
        }
        cout<<endl<<endl;
    }

    return 0;
}
