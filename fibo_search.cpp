#include<iostream>
using namespace std;
int i;
int fib_search(int arr[],int n,int key){
    int a=0,b=1,c=1;
    while(c<n){
        a=b;
        b=c;
        c=a+b;
    }
    int offset=-1;
    while(c>1){
        int i = min(offset+a,n-1);
    
        if (arr[i]<key){
            c=b;
            b=a;
            a=c-b;
            offset=i;
        }
        else if(arr[i]>key){
            c=a;
            b=b-a;
            a=c-b;
        }
        else{
            return i;
        }
    }
    if(b && arr[offset+1]==key){
        return i;
    }
    return -1;
}

int main(){
    int i,n,key;
    cout<<"Enter the no. of students : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the roll no. of students : ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the roll no. of student to search : ";
    cin>>key;
    int pos = fib_search(arr,n,key);

     if (pos != -1)
        cout << "Student of roll no. " << key << " found at position " << pos+1  << " ." << endl;
    else
        cout << "Student of roll no. " << key << " not found in the array." << endl;

    return 0;
}

/*
############ Output :-

PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics> cd "c:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA\" ; if ($?) { g++ fibo_search.cpp -o fibo_search } ; if ($?) { .\fibo_search }
Enter the no. of students : 5
Enter the roll no. of students : 43
39
37
50
17
Enter the roll no. of student to search : 39 
Student of roll no. 39 found at position 2 .
PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA> 
*/