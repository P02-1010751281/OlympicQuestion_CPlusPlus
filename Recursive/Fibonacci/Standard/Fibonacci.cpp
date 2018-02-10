#include<cstdio>

long long A[25000];

int main(){
//	freopen("out.txt","w",stdout);
	A[0] = 0;
	A[1] = 1;
	printf("1:1");
	for(int i = 2;;i++) {
		printf("%d:",i);
		printf("%lld\n",A[i] = A[i-1]+A[i-2]);
	}
	return 0;
}
