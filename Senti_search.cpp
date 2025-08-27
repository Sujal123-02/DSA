#include <iostream>
using namespace std;

int sentinelSearch(string names[], int n, string key) {
    string last = names[n-1];
    names[n-1] = key;   

    int i=0;
    while(names[i] != key) {
        i++;
    }

    names[n-1] = last; 

    if(i < n-1 || last == key)
        return i;
    else
        return -1;
}


void insertFriend(string names[], string numbers[], int &n, string newName, string newNumber) {
    int i = n-1;
    while(i >= 0 && names[i] > newName) {
        names[i+1] = names[i];
        numbers[i+1] = numbers[i];
        i--;
    }
    names[i+1] = newName;
    numbers[i+1] = newNumber;
    n++;
}


void display(string names[], string numbers[], int n) {
    cout << "\nPhonebook:\n";
    for(int i=0; i<n; i++) {
        cout << names[i] << " : " << numbers[i] << endl;
    }
}

int main() {
    string names[50], numbers[50]; 
    int n = 3;

    names[0] = "Amit"; 
    numbers[0] = "9876543210";
    names[1] = "Rohit"; 
    numbers[1] = "9123456780";
    names[2] = "Sonal"; 
    numbers[2] = "9988776655";

    string name;
    cout << "Enter name to search: ";
    cin >> name;

    int pos = sentinelSearch(names, n, name);

    if(pos != -1) {
        cout << name << " found with number: " << numbers[pos] << endl;
    } else {
        cout << name << " not found. Enter mobile number to add: ";
        string mob;
        cin >> mob;
        insertFriend(names, numbers, n, name, mob);
        cout << name << " inserted successfully.\n";
    }

    display(names, numbers, n);
    return 0;
}


/*
########   Output:-

PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics> cd "c:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA\" ; if ($?) { g++ Senti_search.cpp -o Senti_search } ; if ($?) { .\Senti_search }
Enter name to search: Sujal                   
Sujal not found. Enter mobile number to add: 7385292229
Sujal inserted successfully.

Phonebook:
Amit : 9876543210
Rohit : 9123456780
Sonal : 9988776655
Sujal : 7385292229
PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA> cd "c:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA\" ; if ($?) { g++ Senti_search.cpp -o Senti_search } ; if ($?) { .\Senti_search }
Enter name to search: Rohit
Rohit found with number: 9123456780

Phonebook:
Amit : 9876543210
Rohit : 9123456780
Sonal : 9988776655
*/