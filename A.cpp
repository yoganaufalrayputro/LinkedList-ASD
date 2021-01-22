#include<iostream>
#include<string.h>
using namespace std;
#define max 20
typedef char infotype;
struct stack{
    int top;
    infotype data[max];
};

stack data;
#define Top(S) data.top
#define InfoTop(S) data.data[data.top]

bool isEmpty(stack s){
    return (Top(S)==-1);
}

bool isFull(stack s){
    return (Top(s)==max-1);
}

void CreateEmpty(stack *s){
    Top(*s)=-1;
}

void push(stack *s, infotype x){
    //if(!isFull){
        Top(*s)++;
        InfoTop(*s)=x;
 //}
    //else cout<<"Stack overflow";
}

void pop(stack *s, infotype *x){
//    if(!isEmpty){
        *x=InfoTop(*s);
        Top(*s)--;
    //}
    //else cout<<"Stack Kosong";
}

void outp(stack s){
    for(int i=0; i<=Top(s); i++){
        cout<<data.data[i]<<" ";
    }
}

int main(){
    stack data;
    int n;
    string kata;


    cin>>n;

    for(int j=0; j<n; j++){
        CreateEmpty(&data);
        cin>>kata;


        for(int i=0; i<kata.length(); i++){
            if(kata[i]=='1' || kata[i]=='2' || kata[i]=='3' || kata[i]=='4' || kata[i]=='5' || kata[i]=='6' || kata[i]=='7' || kata[i]=='8'|| kata[i]=='9' || kata[i]=='0'){
                push(&data, kata[i]);
            }
            else if(kata[i]=='_'){
                pop(&data,&kata[i]);
            }
        }

        outp(data);
        cout<<endl;
    }

}
