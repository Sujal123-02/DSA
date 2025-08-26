#include <iostream>
using namespace std;
int fact(int n){
    if (n==1){
        return 1;
    }else{
        return n*fact(n-1);
    }

}

int main(){
    cout<<"Enter the num : ";
    int n;
    cin>>n;
    cout<<"Factorial of "<<n<<" is "<<fact(n)<<endl;
    return 0;
}