#include <iostream>
using namespace std;

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


int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[n];  
    cout << "Enter Array:\n";
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int last = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            while (i < last && a[last] == 0) {
                last--;
            }
            if (i < last) {
                a[i] = a[last];
                a[last] = 0;
                last--;
            }
        }
    }

    int count = 0;
    last = n - 1;
    while (last >= 0 && a[last] == 0) {
        count++;
        last--;
    }

    insertionSort(a, n - count);

    cout << "Final array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}


/*
########   Output :-

PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics> cd "c:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA\" ; 
if ($?) { g++ del_zero.cpp -o del_zero } ; if ($?) { .\del_zero }
Enter size of array: 5
Enter Array:
45
33
12
45
31
Final array: 12 31 33 45 45 
PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA> 
  */