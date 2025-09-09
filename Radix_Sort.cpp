#include<iostream>
using namespace std;

int maximum(int a[],int n){
    int maxVal=a[0];
    for(int i=0;i<n;i++){

        if(a[i]>maxVal){
            maxVal=a[i];
        }
    }
    return maxVal;
}



int k=9;
void countSort(int A[],int n ,int pos){
    int b[n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[(A[i]/pos)%10]++;
    }
    for(int i=1;i<=k;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[--count[(A[i]/pos)%10]]=A[i];
    }
    for(int i=0;i<n;i++){
        A[i]=b[i];
    }
}

void radixSort(int A[], int n) {
    int maxVal = maximum(A, n);
    for (int pos = 1; (maxVal / pos) > 0; pos *= 10) {
        countSort(A, n, pos);
    }
}


int main(){
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    int A[n];
    cout<<"Enter array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<"The sorted array : ";
    radixSort(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;

}



/*
#########   Output :-
PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics> cd "c:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA\" ; if ($?) { g++ Radix_Sort.cpp -o Radix_Sort } ; if ($?) { .\Radix_Sort }
Enter the size : 5
Enter array : 
45 5 12 70 56 
The sorted array : 5 12 45 56 70 
PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA> 
*/