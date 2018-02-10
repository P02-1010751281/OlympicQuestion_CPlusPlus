#include<cstdio> 

int A[500000];

void QuickSort(int L,int R){
	int TmpL = L,TmpR = R,Mid = A[(L+R)/2],Tmp;
	do{
		while(A[TmpL] < Mid) TmpL++;
		while(A[TmpR] > Mid) TmpR--;
		if(TmpL <= TmpR) {
			Tmp = A[TmpL];
			A[TmpL] = A[TmpR];
			A[TmpR] = Tmp;
			TmpL++;
			TmpR--;
		}
	}while(TmpL <= TmpR);
	if(TmpR > L) QuickSort(L,TmpR);
	if(TmpL < R) QuickSort(TmpL,R);
}

int main(){
	int R;
	scanf("%d",&R);
	for(int i = 1;i <= R;i++) scanf("%d",&A[i]);
	QuickSort(1,R);
	for(int i = 1;i <= R;i++) printf("%d ",A[i]);
	return 0;
}
