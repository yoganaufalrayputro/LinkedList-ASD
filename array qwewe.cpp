#include<iostream>
using namespace std;
#define max 6

struct que{
	int data[max];
	int head;
	int tail;
};
que antri;

void create(){
	antri.head=antri.tail=-1;
}

bool isEmpty(){
	return (antri.tail== -1);
}

bool isFull(){
	return (antri.tail==max-1);
}

void enqueue(int x){
	if(isEmpty()) antri.head=antri.tail=0;
	
	else if((antri.tail+1)%max==antri.head) return;
	
	else{
		antri.tail = (antri.tail+1)%max;
	}
		antri.data[antri.tail]=x;
}

int dequeue(){
	int e = antri.data[antri.head];
	if(antri.head==antri.tail) antri.tail=antri.head=-1;
	else antri.head++;
	return e;
}

int tampil(){
	cout<<"Data : ";
	if(!isEmpty()){
			for(int i=antri.head; i<=antri.tail; i++){
			cout<<antri.data[i]<<", ";
		}
	}
	
	else cout<<"Data Kosong";
}

int main(){
	create();
	
	enqueue(3);
	enqueue(5);
	enqueue(10);
	enqueue(8);
	
	cout<<"First data: "<<dequeue()<<endl;
	
	tampil();
}
