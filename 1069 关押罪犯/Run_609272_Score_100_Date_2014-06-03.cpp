#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int t,g;
int father[300000];
int f[500020];
int getfather(int a){
	if(father[a]==a) return a;
	else father[a]=getfather(father[a]);
	return father[a];
}
void bin(int t,int g){
	int ft=getfather(t);
	int fg=getfather(g);
	if(ft!=fg) father[ft]=fg;
}
struct zuis{
	int a;
	int b;
	int q;
};
int cmp(zuis x,zuis y){
	return x.q>y.q;
}
zuis zui[500020];
int main(){
	cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=0;
	for(int i=1;i<=m;i++){
		cin>>zui[i].a>>zui[i].b>>zui[i].q;
	}
    for(int i=1;i<=n;i++) father[i]=i;
	sort(zui,zui+m+1,cmp);
    for(int i=0;i<=m-1;i++){
        t=zui[i].a;
        g=zui[i].b;
        if(getfather(t)==getfather(g)) {
        	cout<<zui[i].q;
            return 0;
        }
        if(f[t]==0&&f[g]==0){
        	f[t]=g;
            f[g]=t;
            continue;
        }
        else if(f[t]==0){
            f[t]=g;
        }
        else if(f[g]==0){
            f[g]=t;
        }
        bin(f[t],g);
        bin(f[g],t);
    }
    cout<<0;
	return 0;
}
