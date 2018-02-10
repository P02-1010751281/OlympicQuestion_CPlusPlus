#include<cstdio>
#include<cstring>
#include<iostream>

bool A[2500];
int N,Alen = 0,Sum = 0;

int main(){
	memset(A,0,sizeof(A));
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		int Tmp;
		scanf("%d",&Tmp);
		if(A[Tmp]) Sum--;
		A[Tmp] = 1;
		Alen = std::max(Alen,Tmp);
		Sum++;
	}
	printf("%d\n",Sum);
	for(int i = 1;i <= Alen;i++) if(A[i]) printf("%d ",i);
	return 0;
}
