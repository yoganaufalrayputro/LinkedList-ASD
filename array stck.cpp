#include<iostream>
using namespace std;

#define max 5

bool isEmpty(int top){
	return ( top==-1 );
}

int* push(int arr[], int value, int *top){
	if (*top == max-1) cout<<"stack overflow \n" ;
	else {
		arr[++*top]=value;
		return arr;
	}
}

void pop(int *top){
	*top = *top-1;
}

int peek (int arr[], int top){
	return arr[top];
}

void outp(int arr[], int top){
	for(int i=top; i>=0; i--){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int top=-1;
	int arr[max], var;
	
	push(arr, 3, &top);
	push(arr, 5, &top);
	push(arr, 7, &top);
	push(arr, 1, &top);
	push(arr, 8, &top);
	cout<<"Top : "<<peek(arr, top)<<"\n";  	
	pop(&top);
	
	cout<<"Pop :   "; outp(arr, top);
	
	//cout<<peek(arr, top);
	
}
