#include <cstdio>

const int Maxn = 1000;

int Number;
int A[Maxn],Swap[Maxn];

void MergeSort(int Left,int Right){
	if(Left == Right) return ;
	int Middle = (Left+Right)/2;
	int L = Left,M = Middle+1;
	MergeSort(Left,Middle);
	MergeSort(Middle+1,Right);
	while(L <= Middle && M <= Right) Swap[Si++] = A[L] <= A[M] ? A[L++] : A[M++];
	while(L <= Middle) Swap[Si++] = A[L++];
	while(M <= Right) Swap[Si++] = A[M++];
	for(int i = Left;i <= Right;i++) A[i] = Swap[i];
}

bool Check(int Middle,int Objective){
	return A[Middle] < Objective;
}

bool BirinaryChop(int Left,int Right,int Objective){
	if(Left != Right)
		if(A[Middle] == Objective) return 1;
		else return 0;
	int Middle = (Left + Right)/2;
	return A[Middle] == Objective ? 1 : Check(Middle,Objective) ? BirinaryChop(Left,Middle,Objective) : BirinaryChop(Middle+1,Right,Objective);
}

int main(){
	int Objective;
	for(int i = 1;i <= Number;i++) scanf("%d",&A[i]);
	scanf("%d",&Objective);
	MergeSort(1,Number);
	if(BirinaryChop(1,Number,Objective)) printf("Yes");
	else printf("Not Found");
	return 0;
}
