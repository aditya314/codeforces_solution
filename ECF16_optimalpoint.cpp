#include <bits/stdc++.h>
using namespace std;
int main(){
    long n;
    cin>>n;
    long ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    sort(ar,ar+n);
    long x;
    if(n%2==0){
        x=(n/2)-1;
    }
    else{
        x=(n/2);
    }
    cout<<ar[x]<<endl;
return 0;
}
