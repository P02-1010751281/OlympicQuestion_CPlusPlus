#include<cstdio> 

long long Sum = 0;

void Hanoi(int N,char A,char B,char C){
	if(N != 0){
		Hanoi(N-1,A,C,B);
		Sum++;
		printf("The %d Time : From ",Sum);
		printf("%c >>>>> %c\n",A,B);
		Hanoi(N-1,B,A,C);
	}
}

int main(){
	int N;
	scanf("%d",&N);
	Hanoi(N,'A','B','C');
	return 0;
}
