#include <iostream>
#define size 8
using namespace std;
int arr[size];
void init(){
    for (int i =0 ; i<size ;i++){
        arr[i]=-1;
    }
}

void insert(){
    int val;
    int key;
    cout<<endl;
    cout<<endl;
    cout<<"==================================="<<endl;
    cout<<"Enter the ISBN number of a Book :";
    cin>>val;
    key=(val%size);
    if(arr[key]==-1){
        arr[key]=val;
        cout<<"Book of ISBN "<<val<<" is assigned at location "<<key<<"."<<endl;
        cout<<"===================================";
    }
    else{
        cout<<"Collision Occured!";
        int i=(key + 1 ) % size;
        while(i != key && arr[i]!=-1){
            int i=(key + 1 ) % size;         
        }
        if(arr[i]==-1){
            arr[i]=val;
            cout<<"Book of ISBN "<<val<<" is assigned at location "<<i<<"."<<endl;
            cout<<"===================================";
        }
    }

}


void del() {
    int val;
    cout<<endl;
    cout<<"===================================";
    cout << "\nEnter ISBN to delete: ";
    cin >> val;

    int key = val % size;
    int i = key;

    while (arr[i] != -1) {
        if (arr[i] == val) {
            arr[i] = -2; 
            cout << "Book with ISBN " << val << " deleted from location " << i << ".\n";
            return;
        }
        i = (i + 1) % size;
        if (i == key) break;
    }

    cout << "Book with ISBN " << val << " not found.\n";
    cout<<"===================================";
    cout<<endl;
}


void search() {
    int val;
    cout<<endl;
    cout<<"===================================";
    cout << "\nEnter ISBN to search: ";
    cin >> val;

    int key = val % size;
    int i = key;

    while (arr[i] != -1) {
        if (arr[i] == val) {
            cout << "Book found at location " << i << ".\n";
            return;
        }
        i = (i + 1) % size;
        if (i == key) break; 
    }

    cout << "Book with ISBN " << val << " not found.\n";
    cout<<"===================================";
    cout<<endl;
}

void display(){
    cout<<endl;
    cout<<"===================================";
    cout << "\nCurrent Book Storage:\n";
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1)
            cout << "Slot " << i << ": ISBN " << arr[i] << "\n";
        else
            cout << "Slot " << i << ": [Empty]\n";
    }
    cout<<"===================================";
    cout<<endl;
}

void menu(){
    cout<<endl;
	cout<<endl;
	cout<<"\n ******************* Library System Store ******************"<<endl;
	cout<<"1. Insert the Book \n";
	cout<<"2. Delete a Book\n";
	cout<<"3. Search Book\n";
	cout<<"4. Display Book\n";
	cout<<"5. Exit\n";
	cout<<"Choose an option: ";
}

int main(){
    int ch;
    init();
    do{
        menu();
        
        cin>>ch;
        switch(ch){
            case 1:
                insert();
                break;

           case 2:
                del();
                break;

            case 3:
                search();
                break;

            case 4:
                display();
                break;
            case 5:
                cout<<"Thanks for Visiting";
                break;
            default:
                cout<<"Invalid choice";
        }
    }
    while(ch!=5);
}



/*
#######Output:

PS C:\Users\Sujal\OneDrive\Desktop\Programs\Academics> cd "c:\Users\Sujal\OneDrive\Desktop\Programs\Academics\DSA\" ; if ($?) { g++ hashing_Table.cpp -o hashing_Table } ; if ($?) { .\hashing_Table }



 ******************* Library System Store ******************
1. Insert the Book 
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option: 1


===================================
Enter the ISBN number of a Book :42
Book of ISBN 42 is assigned at location 2.
===================================


 ******************* Library System Store ******************
1. Insert the Book 
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option: 1


===================================
Enter the ISBN number of a Book :34
Collision Occured!Book of ISBN 34 is assigned at location 3.
===================================


 ******************* Library System Store ******************
1. Insert the Book
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option: 1


===================================
Enter the ISBN number of a Book :45
Book of ISBN 45 is assigned at location 5.
===================================


 ******************* Library System Store ******************
1. Insert the Book
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option: 1


===================================
Enter the ISBN number of a Book :65
Book of ISBN 65 is assigned at location 1.
===================================


 ******************* Library System Store ******************
1. Insert the Book
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option: 1


===================================
Enter the ISBN number of a Book :55
Book of ISBN 55 is assigned at location 7.
===================================


 ******************* Library System Store ******************
1. Insert the Book
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option: 2

===================================
Enter ISBN to delete: 55
Book with ISBN 55 deleted from location 7.



 ******************* Library System Store ******************
1. Insert the Book
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option: 4

===================================
Current Book Storage:
Slot 0: [Empty]
Slot 1: ISBN 65
Slot 2: ISBN 42
Slot 3: ISBN 34
Slot 4: [Empty]
Slot 5: ISBN 45
Slot 6: [Empty]
Slot 7: ISBN -2
===================================



 ******************* Library System Store ******************
1. Insert the Book
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option: 1


===================================
Enter the ISBN number of a Book :40
Book of ISBN 40 is assigned at location 0.
===================================


 ******************* Library System Store ******************
1. Insert the Book
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option: 3

===================================
Enter ISBN to search: 42
Book found at location 2.



 ******************* Library System Store ******************
1. Insert the Book
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option: 4

===================================
Current Book Storage:
Slot 0: ISBN 40
Slot 1: ISBN 65
Slot 2: ISBN 42
Slot 3: ISBN 34
Slot 4: [Empty]
Slot 5: ISBN 45
Slot 6: [Empty]
Slot 7: ISBN -2
===================================



 ******************* Library System Store ******************
1. Insert the Book
2. Delete a Book
3. Search Book
4. Display Book
5. Exit
Choose an option:

*/