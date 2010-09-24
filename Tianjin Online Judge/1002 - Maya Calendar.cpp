#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main(){    
    
    map<string, int> M;
    
    M["pop"]=0;
    M["no"]=1;
    M["zip"]=2;
    M["zotz"]=3;
    M["tzec"]=4;
    M["xul"]=5;
    M["yoxkin"]=6;
    M["mol"]=7;
    M["chen"]=8;
    M["yax"]=9;
    M["zac"]=10;
    M["ceh"]=11;
    M["mac"]=12;
    M["kankin"]=13;
    M["muan"]=14;
    M["pax"]=15;
    M["koyab"]=16;
    M["cumhu"]=17;
    M["uayet"]=18;
    
    vector<string> v(20);
    
    v[0]="imix";
    v[1]="ik";
    v[2]="akbal";
    v[3]="kan";
    v[4]="chicchan";
    v[5]="cimi";
    v[6]="manik";
    v[7]="lamat";
    v[8]="muluk";
    v[9]="ok";
    v[10]="chuen";
    v[11]="eb";
    v[12]="ben";
    v[13]="ix";
    v[14]="mem";
    v[15]="cib";
    v[16]="caban";
    v[17]="eznab";
    v[18]="canac";
    v[19]="ahau";
    
    int n,d,a;
    string s;
    long long sum;    
    
    cin>>n;
    
    cout<<n<<endl;
    
    for(int i=0;i<n;i++){
        scanf("%d.",&d);
        cin>>s>>a;
        
        sum=d+M[s]*20+a*365;
        
        cout<<sum%13+1<<" "<<v[sum%20]<<" "<<sum/260<<endl;
    }
}
