#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,num,c=0;
	long long s,sum=0;
	cin>>n>>s;
	map <long long int,int> ss;
	ss[0]=1;
	for(int i=1;i<=n;i++){
        cin>>num;
		sum=sum+num;
		/*for(int j=0;j<i;j++){
            if(ss[j]==(sum-s)){
                c++;
            }
		}*/
		if(ss.count(sum-s)==1){
            c+=ss[(sum-s)];
		}
		ss[sum]++;
	}
	cout<<c<<endl;
	return 0;
}
