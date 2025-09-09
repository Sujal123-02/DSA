#include <iostream>
using namespace std;
int a[20],b[20],count[20],i,k,n,maxVal;


int maximum(int a[],int n){
    maxVal=a[0];
    for(i=0;i<n;i++){

        if(a[i]>maxVal){
            maxVal=a[i];
        }
    }
    return maxVal;
}


void countSort(int a[],int n,int k){
    for(i=0;i<20;i++){
        count[i]=0;
    }
    for(i=0;i<n;i++){
        count[a[i]]++;
    }
    for(i=1;i<=k;i++){
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--){
        b[--count[a[i]]]=a[i];
    }
    for(i=0;i<n;i++){
        a[i]=b[i];
    }
    
}


int main(){
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter Elements : ";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    k=maximum(a,n);
    countSort(a,n,k);
    cout<<"The Sorted array is : "<<endl;
    for (i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}


/*
#########  Output :-

PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics> cd "c:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA\" ; if ($?) { g++ Count_Sort.cpp -o Count_Sort } ; if ($?) { .\Count_Sort }
Enter the size of array : 10
Enter Elements : 5 6 4 5 8 2 4 9 5 4   
The Sorted array is : 
2 4 4 4 5 5 5 6 8 9 
PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA> 
*/