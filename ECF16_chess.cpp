#include <bits/stdc++.h>
using namespace std;
int main(){
    int x; char ch;
    int mv;
    cin>>ch>>x;
    if((ch=='a' && (x==1 || x==8)) || (ch=='h' && (x==1 || x==8))){
        mv=3;
    }
    else if(ch=='a' || ch=='h' || x==8 ||x==1){
        mv=5;
    }
    else{
        mv=8;
    }
    cout<<mv<<endl;
return 0;
}
