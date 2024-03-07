#include<iostream>
using namespace std;
int linsearch(int array[],int size,int value){
for(int i=0;size<5;i++){
if(array[i]==value){
cout<<"Value is found on index "<<endl;
return i;
}
}
return -1;
}
int main(){
int value,size;
cout<<"enter the size of array"<<endl;
cin>>size;
int array[size];
cout<<"enter the value of array"<<endl;
for(int i=0;i<size;i++){
cin>>array[i];
}
cout<<"enter value to search"<<endl;
cin>>value;
cout<<linsearch(array,size,value);
return 0;
}
