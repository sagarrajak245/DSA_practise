#include <iostream>
using namespace std;
 int sagar (int *a,int *b);

int main(){
int a,b;

cout<<"enter first number \n";
cin>> a; 
cout<<"enter second  number \n";
cin>> b;
int t= sagar(&a,&b);

 cout<<"the value of sum is:\n"<<t;

    return 0;
}
    int sagar (int *a,int *b) {

        int c=*a+*b; 

return c;
}