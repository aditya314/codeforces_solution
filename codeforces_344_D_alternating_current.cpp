#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int l=s.length();
	stack <char> st;
	for(int i=0;i<l;i++){
        char ch=s[i];
		if(!st.empty()){
			char c=st.top();
			if(c==ch){
				st.pop();
				continue;
			}
		}
        st.push(ch);
	}
	if(st.empty()){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}
