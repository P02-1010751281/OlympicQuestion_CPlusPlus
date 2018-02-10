#include<iostream>
#include<cstdio>
#include<cctype>

	using namespace std;
	#define in = read()
	typedef long long ll;
	typedef unsigned int ui;
	const ll size = 100000 + 1000;
	
		int n , v;
		ll w[size] , m[size];
		ll f[size];
	
inline ll read(){
		ll num = 0 , f = 1;     char ch = getchar();
		
		while(!isdigit(ch)){
				if(ch == '-')   f = -1;
				ch = getchar();
		}
		while(isdigit(ch)){
				num = num*10 + ch - '0';
				ch = getchar();
		}
		
		return num*f;
}

int main(){
		v in;   n in;
		for(register int i=1;i<=n;i++){
				w[i] in;    m[i] in;
		}
		
		for(register int i=1;i<=n;i++)
				for(register int j=v;j>=w[i];j--)
						f[j] = max(f[j] , f[j - w[i]] + m[i]);

		printf("%d" , f[v]);
}
// 01

/*
for( j 1~v j++)x*/
