#include <algorithm>
#include <cstdio>

const int Maxn = 1000000 + 5;

struct Heap{
	int *heap,Size;
	
	Heap(int Large){
		heap = new int [Large + 5];
		Size = 0;
	}
	
	void Delete(){
		heap[1] = heap[Size --];
		int Father = 1,Son;
		while((Father << 1) <= Size){
			Son = Father << 1;
			if(Son < Size && heap[Son] > heap[Son + 1]) 
				++Son;
			if(heap[Father] <= heap[Son]) 
				return;
			std::swap(heap[Father],heap[Son]);
			Father = Son;
		}
	}
	
	int Pop(){
		const int Ans = heap[1];
		heap[1] = heap[Size --];
		int Father = 1,Son;
		while((Father << 1)<= Size){
			Son = Father << 1;
			if(Son< Size && heap[Son] > heap[Son + 1]) 
				++Son;
			if(heap[Father] <= heap[Son]) 
				return Ans;
			std::swap(heap[Father],heap[Son]);
			Father = Son;
		}
	}
	
	void Push(int X){
		heap[++ Size] = X;
		int Son = Size,Father;
		while(Son > 1){
			Father = Son >> 1;
			if(heap[Father] <= heap[Son])
				return;
			std::swap(heap[Father],heap[Son]);
			Son = Father;
		}
	}
	
	int Top(){
		return heap[1];
	}
};

int main(){
	int N,Command,Number;
	Heap H(Maxn);
	scanf("%d",&N);
	while(N --){
		scanf("%d",&Command);
		switch(Command){
			case 1 :
				scanf("%d",&Number);
				H.Push(Number);
				break;
			case 2 :
				printf("%d\n",H.Top());
				break;
			case 3 :
				H.Delete();
				break;
		}
	}
	return 0;
}
