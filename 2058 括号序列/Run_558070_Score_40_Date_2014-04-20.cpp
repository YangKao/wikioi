#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> q;
int n;
string t[20];
char td(char a){
    if(a=='}') return '{';
    else if(a==')') return '(';
    else if(a=='>') return '<';
    else if(a==']') return '[';
    else return '0';
}
int tt=1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>t[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=t[i].length()-1;j++)
        {
            if(t[i][j]=='{'||t[i][j]=='('||t[i][j]=='<'||t[i][j]=='[')
            {
                q.push(t[i][j]);
            }
            else if(td(t[i][j])!=q.top()){
                tt=0;
                break;
            }
            else{
                q.pop();
            }
        }
        if(tt&&q.empty()){
        	cout<<"TRUE"<<endl;
        }
        else{cout<<"FALSE"<<endl;}
        tt=1;
    }
	return 0;
}
