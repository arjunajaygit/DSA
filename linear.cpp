#include<iostream>
using namespace std;
void linear(int a[], int n, int s){
int flag=0;
int i;
for(int i=0;i<n;i++){
if(a[i]==s)
{
flag=1;
break;
}
}
if(flag==1){
cout<<"The element found ";
}
else
{
cout<<"The element not found";
}}
void binary(int a[], int n, int s){
int l=0,h=n-1,m,flag=0;
for(int i=0;i<n;i++){
if(a[i]>a[i+1]){
int temp =a[i];
a[i]=a[i+1];
a[i+1]=temp;}}
while(l<=h){
m=(l+h)/2;
if(s>a[m]){
l=m+1;}
else if(s<a[m]){
h=m-1;}
else{
flag=1;
break;}}
if(flag==1)
{cout<<"The element found";}
else
{cout<<"Element not found";}}
int main()
{
int n,i,s,ch;
cout<<"Enter the array size";
cin>>n;
int a[n];
cout<<"Enter array elements";
for(int i=0;i<n;i++){
cin>>a[i];
}
cout<<"ARJUN A (26)";
cout<<"Enter the element to be searched";
cin>>s;
cout<<"Select the searching algorithm\n 1)Linear Search\n 2)Binary Search";
cin>>ch;
switch(ch)
{
case 1: linear(a,n,s);break;
case 2: binary(a,n,s);break;
default: cout<<"Invalid choice";break;
}
}
