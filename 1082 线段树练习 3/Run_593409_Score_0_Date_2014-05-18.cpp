#include <iostream>
using namespace std;
int n,c[1000000],m;
int t,g,l,h;
int low(int x){
	return x&(-x);
}
int sum(int x){
	int sum=0;
    while(x>0){
    	sum+=c[x];
        x-=low(x);
    }
    return sum;
}
int update(int x,int y){
    while(x<=n){
    	c[x]+=y;
        x+=low(x);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>t;
        update(i,t);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
    	cin>>t;
        if(t==1){
            cin>>g>>l>>h;
        	for(int i=g;i<=l;i++) update(i,h);
        }
        else{
        	cout<<sum(l)-sum(g-1)<<endl;
        }
    }
	return 0;
}