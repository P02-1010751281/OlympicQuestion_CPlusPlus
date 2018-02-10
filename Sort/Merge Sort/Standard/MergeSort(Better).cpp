#include <cstdio>

const int Maxn = 1000;

int Number;
int A[Maxn],Swap[Maxn];

void Print(){
	for(int i = 1;i <= Number;i++) printf("%d ",A[i]);
}

bool Comp(int x,int y){
	return x <= y;
}

void MergeSort(int Left,int Right){
	if(Left == Right) return ;
	int Middle = (Left+Right)/2;
	int L = Left,Si = Left,M = Middle+1;
	MergeSort(Left,Middle);
	MergeSort(Middle+1,Right);
	while(L <= Middle && M <= Right) Swap[Si++] = Comp(A[L],A[M]) ? A[L++] : A[M++];
	while(L <= Middle) Swap[Si++] = A[L++];
	while(M <= Right) Swap[Si++] = A[M++];
	for(int i = Left;i <= Right;i++) A[i] = Swap[i];
}

int main(){
	scanf("%d",&Number);
	for(int i = 1;i <= Number;i++) scanf("%d",&A[i]);
	MergeSort(1,Number);
	Print();
	return 0;
}
