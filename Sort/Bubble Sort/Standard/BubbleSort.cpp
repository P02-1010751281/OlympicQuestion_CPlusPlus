#include<cstdio>

int A[25000],Len;

bool Comp(int x,int y){
	return x<y;
}

void BubbleSort(){
	bool Rem;
	int i = 0;
	do{
		Rem = 1;
		for(int j = 0;j < Len-i-1;j++){
			if(Comp(A[j+1],A[j])){
				A[j] ^= A[j+1] ^= A[j] ^= A[j+1];
				Rem = 0;
			}
		}
		i++;
	}while(!Rem);
}

int main(){
	scanf("%d",&Len);
	for(int i = 0;i < Len;i++) scanf("%d",&A[i]);
	BubbleSort();
	for(int i = 0;i < Len;i++) printf("%d ",A[i]);
	return 0;
}
