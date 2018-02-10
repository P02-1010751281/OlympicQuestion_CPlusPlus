#include<cstdio>

int A[25000],N,Alen,Sum;

void BubbleSort(){
	bool Do;
	int i = 0;
	do{
		Do = 0;
		for(int j = 0;j < N-1;j++){
			if(A[j] > A[j+1]){
				A[j] ^= A[j+1] ^= A[j] ^= A[j+1];
				Do = 1;
				Sum++;
			}
		}
		i++;
	}while(Do);
}


int main(){
	scanf("%d",&N);
	for(int i = 0;i < N;i++) scanf("%d",&A[i]);
	BubbleSort();s
	printf("\n%d",Sum);
	return 0;
} 
