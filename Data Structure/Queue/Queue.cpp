#include<cstdio>

#define Size 25000

int Queue[Size],Head = 0,Tail = 0;

int EnQueue(int x){
	Tail++;
	if(Tail == Size && Head > 0) Tail = 1;
	if(Head == Tail || Tail == Size){
		printf("OverFLow\n");
		return 0;
	}
	Queue[Tail] = x;
	return 1;
}

int DeQueue(){
	Head++;
	if(Head > Tail){
		if(Head == Size) Head = 1;
		else return Queue[Head];
	} 
	if(Head < Tail) return Queue[Head];
	printf("UnderFlow\n");
	return 'a';
}


int main(){
	freopen("Test.txt","r",stdin);
	freopen("Ans.txt","w",stdout);
	int Tmp;
	while(scanf("%d",&Tmp) != EOF)	if(!EnQueue(Tmp)) break; 
	while((Tmp = DeQueue()) != 'a') printf("%d ",Tmp);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
