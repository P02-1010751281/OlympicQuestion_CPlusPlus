#include<cstdio>

int A[500000],Swap[500000];

bool Comp(int x,int y){
	return x<y;
}

void MergeSort(int L,int R){
	int Mid = (L+R)/2,TmpL = L,TmpR = Mid+1,TmpS = L;
	if(L != R){
		MergeSort(L,Mid);
		MergeSort(Mid+1,R);
		while(TmpL <= Mid && TmpR <= R){
			if(Comp(A[TmpL],A[TmpR])){
				Swap[TmpS] = A[TmpL];
				TmpL++;
				TmpS++;
			} else {
				Swap[TmpS] = A[TmpR];
				TmpR++;
				TmpS++;
			}
		}
		while(TmpL <= Mid){
			Swap[TmpS] = A[TmpL];
			TmpL++;
			TmpS++;
		}
		while(TmpR <= R){
			Swap[TmpS] = A[TmpR];
			TmpR++;
			TmpS++;
		}
		for(int i = L;i <= R;i++) A[i] = Swap[i];
	}
}

int main(){
	int R;
	scanf("%d",&R);
	for(int i = 1;i <= R;i++) scanf("%d",&A[i]);
	MergeSort(1,R);
	for(int i = 1;i <= R;i++) printf("%d ",A[i]);
	return 0;
}
