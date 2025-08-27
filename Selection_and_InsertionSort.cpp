#include <iostream>
using namespace std;


void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        float temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}


void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


void displayTopFive(int arr[], int n) {
    cout << "\nTop Five Salaries:\n";
    int count = 0;
    for(int i=n-1; i>=0 && count<5; i--) {
        cout << arr[i] << endl;
        count++;
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    int salaries[100];  
    cout << "Enter salaries:\n";
    for(int i=0; i<n; i++) {
        cin >> salaries[i];
    }

   
    int arr1[100], arr2[100];
    for(int i=0; i<n; i++) {
        arr1[i] = salaries[i];
        arr2[i] = salaries[i];
    }

    
    selectionSort(arr1, n);
    cout << "\nAfter Selection Sort (Ascending Order):\n";
    for(int i=0; i<n; i++) cout << arr1[i] << " ";
    cout << endl;
    displayTopFive(arr1, n);

   
    insertionSort(arr2, n);
    cout << "\nAfter Insertion Sort (Ascending Order):\n";
    for(int i=0; i<n; i++) cout << arr2[i] << " ";
    cout << endl;
    displayTopFive(arr2, n);

    return 0;
}



/*
###### Output :-

PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics> cd "c:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA\" ; if ($?) { g++ Selection_and_InsertionSort.cpp -o Selection_and_InsertionSort } ; if ($?) { .\Selection_and_InsertionSort }
Enter number of employees: 5
Enter salaries:
85000
75000
78000
92000
95000

After Selection Sort (Ascending Order):
75000 78000 85000 92000 95000 

Top Five Salaries:
95000
92000
85000
78000
75000

After Insertion Sort (Ascending Order):
75000 78000 85000 92000 95000

Top Five Salaries:
95000
92000
85000
78000
75000
PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA>
*/