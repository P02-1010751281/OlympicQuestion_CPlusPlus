#include<cstdio>

#define Size 250000

int Queue[Size],Head = 0,Tail = 0,Num = 0;

int EnQueue(int x){
	if(Tail == Size && Head > 0) Tail = 0;
	if(Num == Size){
		printf("OverFLow\n");
		return 0;
	}
	Queue[Tail++] = x;
	Num++;
	return 1;
}

int DeQueue(){
	if(Num == 0){
		printf("UnderFlow\n");
		return 'a';
	}
	if(Head == Size && Num > 0) Head = 1;
	Num--;
	return Queue[Head++];
}


int main(){
	freopen("Test.txt","r",stdin);
	freopen("Ans.txt","w",stdout);
	int Tmp;
	while(scanf("%d",&Tmp) != EOF)	if(!EnQueue(Tmp)) break; 
	while((Tmp = DeQueue()) != 'a' || Num != 0) printf("%d ",Tmp);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
