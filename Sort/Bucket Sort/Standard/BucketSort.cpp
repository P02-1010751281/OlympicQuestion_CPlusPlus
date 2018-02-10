#include<cstdio> 
#include<cstring>
#include<iostream>

int A[50000];

int main(){
	int Len,Tmp,TLen = 0;
	scanf("%d",&Len);
	for(int i = 0;i < Len;i++){
		scanf("%d",&Tmp);
		A[Tmp]++;
		TLen = std::max(Tmp,TLen)+1;
	}
	for(int i = 0;i < TLen;i++){
		while(A[i]){
			printf("%d ",i);
			A[i]--;
		}
	}
	return 0;
}
