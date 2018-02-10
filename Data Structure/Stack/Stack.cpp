#include<cstdio> 

#define Size 25000

int Stack[Size],Top = 0;

int Push(int x){
	if(Top == Size) {
		printf("OverFlow\n");
		return 0;
	} else {
		Stack[++Top] = x;
		return 1; 
	}
}

int Pop(){
	if(Top == 0) {
		printf("UnderFlow\n");
		return 0;
	} else return Stack[Top--];
}

int main(){
	freopen("Test.txt","r",stdin);
	freopen("Ans.txt","w",stdout);
	int Tmp;
	while(scanf("%d",&Tmp) != EOF)	if(!Push(Tmp)) break; 
	while(Top) printf("%d ",Pop());
	fclose(stdin);
	fclose(stdout);
	return 0;
}
