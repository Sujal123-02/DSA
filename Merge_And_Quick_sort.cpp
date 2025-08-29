#include <iostream>
using namespace std;

void quickSort(float arr[], int first, int last)
{
    if (first < last)
    {
        float pivot = arr[last];   
        int i = first - 1;

        
        for (int j = first; j < last; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
               
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

       
        float temp = arr[i + 1];
        arr[i + 1] = arr[last];
        arr[last] = temp;

        int pi = i + 1; 

 
        quickSort(arr, first, pi - 1);
        quickSort(arr, pi + 1, last);
    }
}
float b[100];
void merge(float a[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= ub)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int x = lb; x < ub; x++)
    {
        a[x] = b[x];
    }
}

void mergeSort(float arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;

        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);

        merge(arr, lb, mid, ub);
    }
}

void display(float arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void showmenu()
{
    cout << "\n=== MENU ===\n";
    cout << "1. Sort using Quick Sort\n";
    cout << "2. Sort using Merge Sort\n";
    cout << "3. Display Percentages\n";
    cout << "4. Exit\n";
}

int main()
{
    int n, choice;
    float percentages[100];
    bool entered = false;

    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter percentages:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> percentages[i];
    }
    entered = true;

    do
    {
        showmenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            quickSort(percentages, 0, n - 1);
            cout << "Sorted using Quick Sort!\n";
            display(percentages, n);
            break;

        case 2:

            mergeSort(percentages, 0, n - 1);
            cout << "Sorted using Merge Sort!\n";
            display(percentages, n);
            break;

        case 3:

            cout << "Percentages:\n";
            display(percentages, n);
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}


/*
############  Output :- 

PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics> cd "c:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA\" ; if ($?) { g++ Merge_And_Quick_sort.cpp -o Merge_And_Quick_sort } ; if ($?) { .\Merge_And_Quick_sort }
Enter number of students: 5
Enter percentages:
75
76
67
89
92

=== MENU ===
1. Sort using Quick Sort
2. Sort using Merge Sort
3. Display Percentages
4. Exit
Enter your choice: 1
Sorted using Quick Sort!
67 75 76 89 92 

=== MENU ===
1. Sort using Quick Sort
2. Sort using Merge Sort
3. Display Percentages
4. Exit
Enter your choice: 2
Sorted using Merge Sort!
67 75 76 89 92

=== MENU ===
1. Sort using Quick Sort
2. Sort using Merge Sort
3. Display Percentages
4. Exit
Enter your choice: 3
Percentages:
67 75 76 89 92

=== MENU ===
1. Sort using Quick Sort
2. Sort using Merge Sort
3. Display Percentages
4. Exit
Enter your choice: 4
Exiting program.
PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA>
*/