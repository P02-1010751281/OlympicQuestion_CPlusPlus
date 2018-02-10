#include<cstdio>

int A[25000],Len;

bool Comp(int x,int y){
	return x<y;
}

void SelectSort(){
	for(int i = 0;i < Len;i++){
		int Tmp = A[i],Bit;
		for(int j = i;j < Len;j++){
			if(Comp(A[j],Tmp)){
				Tmp = A[j];
				Bit = j;
			}
		}
		A[Bit] = A[i];
		A[i] = Tmp;
	}
}

int main(){
	scanf("%d",&Len);
	for(int i = 0;i < Len;i++) scanf("%d",&A[i]);
	SelectSort();
	for(int i = 0;i < Len;i++) printf("%d ",A[i]);
	return 0;
}
