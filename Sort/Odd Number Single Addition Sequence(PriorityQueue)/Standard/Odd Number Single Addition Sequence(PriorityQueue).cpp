#include<cstdio> 
#include<iostream>
#include<queue>

std::priority_queue <int> A;

int N,Alen = 0;
int main(){
	scanf("%d",&N);
	int Tmp;
	Alen = N;
	for(int i = 0;i < N;i++){
		scanf("%d",&Tmp);
		if(Tmp%2 != 0){
			A.push(-Tmp);
			Alen++;
		} 
		Alen--;
	}
	for(int i = 1;i < Alen;i++){
		Tmp = A.top();
		printf("%d,",-Tmp);
		A.pop();
	}
	Tmp = A.top();
	printf("%d",-Tmp);
	A.pop();
	return 0;
}
