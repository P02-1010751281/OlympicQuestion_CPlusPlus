#include<cstdio> 

int Len,A[50000];

void InsertSort(){
	for(int i = 2;i < Len;i++){
		int Tmp = A[i],j;
		for(j = i-1;Tmp < A[j];j--) A[j+1] = A[j];
		A[j+1] = Tmp;
	} 
}

int main(){
	scanf("%d",&Len);
	for(int i = 0;i < Len;i++) scanf("%d",&A[i]);
	InsertSort();
	for(int i = 0;i < Len;i++) printf("%d ",A[i]);
	return 0;
}
