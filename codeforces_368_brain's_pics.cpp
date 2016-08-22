#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i,j;
    cin>>n>>m;
    char ar[n][m];
    bool color=false;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>ar[i][j];
            if(ar[i][j]=='C' || ar[i][j]=='M' || ar[i][j]=='Y'){
                color=true;
            }
        }
    }
    if(color){
        cout<<"#Color"<<endl;
    }
    else{
        cout<<"#Black&White"<<endl;
    }
    return 0;

}
