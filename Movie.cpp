#include<iostream>
using namespace std;
const int row=6;
const int col=5;

void showMenu(){
	cout<<endl;
	cout<<endl;
	cout<<"\n ******************* Movie Ticket Booking System ******************"<<endl;
	cout<<"1. Book a Seat\n";
	cout<<"2. Cancel a Seat\n";
	cout<<"3. Display Seats\n";
	cout<<"4. Show TotalBooked Seats\n";
	cout<<"5. Show Ticket Pricing\n";
	cout<<"6. Exit\n";
	cout<<"Choose an option: ";
}

void showTicket(){
	cout<<"=================================="<<endl;
	cout<<"Select the type of Ticket you wanted:"<<endl;
	cout<<"1.Gold seat[200/-].\n";
	cout<<"2.Silver seat[150/-].\n";
	cout<<"3.Platinium seat[250/-].\n";
	cout<<"4.Exit\n";
	cout<<"Choose an option: ";
}

void BookGoldSeat(int seats[row][col] ){
	int r,c;
	cout<<"Enter the Seat no. You want to book."<<endl;
	cout<<"Gold type contains row no. 3 and 4."<<endl;
	cin>>r>>c;
	if (r<5 && r>=3){
		if (seats[r-1][c-1]==0){
			seats[r-1][c-1]=1;
			cout<<"Your seat is succesfully Booked.\nEnjoy the Movie.\n\n\n";
		}
		else{
			cout<<"Seat is Already Booked.\n";

		}
	}
	else{
		cout<<"Can't Book this Seat."<<endl;
	}
	
}


void BookSilverSeat(int seats[row][col] ){
	int r,c;
	cout<<"Enter the Seat no. You want to book."<<endl;
	cout<<"Silver type contains row no. 1 and 2."<<endl;
	cin>>r>>c;
	if (r<3 && r>=1){
		if (seats[r-1][c-1]==0){
			seats[r-1][c-1]=1;
			cout<<"Your seat is succesfully Booked.\nEnjoy the Movie.\n\n\n";
		}
		else{
			cout<<"Seat is Already Booked.\n";

		}
	}
	else{
		cout<<"Can't Book this Seat."<<endl;
	}
	
}

void BookPlatiniumSeat(int seats[row][col] ){
	int r,c;
	cout<<"Enter the Seat no. You want to book."<<endl;
	cout<<"Platinium type contains row no. 5 and 6."<<endl;
	cin>>r>>c;
	if (r<7 && r>=5){
		if (seats[r-1][c-1]==0){
			seats[r-1][c-1]=1;
			cout<<"Your seat is succesfully Booked.\nEnjoy the Movie.\n\n\n";
		}
		else{
			cout<<"Seat is Already Booked.\n";

		}
	}
	else{
		cout<<"Can't Book this Seat."<<endl;
	}
	
}


void BookSeat(int seats [row][col] )
{
	int ch;
	do{
		showTicket();
		cin>>ch;
		switch(ch){
			case 1:
				BookGoldSeat(seats);
				break;
			case 2:
				BookSilverSeat(seats);
				break;
			case 3:
				BookPlatiniumSeat(seats);
				break;             
			case 4:
				cout<<"Exit";
				break;
			default:
				cout<<"Invalid Input";
				break;
		} 
	} while(ch!=4);
}


void CancelSeat(int seats[row][col]){
	cout<<"=================================="<<endl;
	int i, j;
	cout<<"Enter the seat you want to Cancel:"<<endl;
	cin>>i>>j;
	if (i >= 1 && i <= row && j >= 1 && j <= col) {
		if(seats[i-1][j-1]==1){
			seats[i-1][j-1]=0;
			cout<<"Seat Cancel Successfully"<<endl;
		}
		else{
			cout<<"Seat is not Booked."<<endl;
		}
		cout<<"=================================="<<endl;
	}
	else{
		cout << "Invalid seat number!" << endl;
	}
}

void DisplaySeat(int seats[row][col]){
	cout<<"=================================="<<endl;
	cout<<"The availability of seats are : \n";
	cout<<endl;
	int i,j;
	for (i=0;i<row;i++){
		for(j=0;j<col;j++){
			cout<<seats[i][j];
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Available seats are denoted by 0."<<endl;
	cout<<"Booked seats are denoted by 1."<<endl;
	cout<<"=================================="<<endl;

}


void ShowTotalBookedSeat(int seats[row][col]){
	cout<<endl;
	cout<<"=================================="<<endl;
	int i,j,c1=0,c2=0,c3=0,c4=0;
	for (i=0;i<row;i++){
		for(j=0;j<col;j++){
			if (seats[i][j]==1){
				if(i>=0 && i<2){
					c1++;
				}
				else if (i>=2 && i<4){
					c2++;
				}
				else if (i>=4 && i<6){
					c3++;
				}
			}
			else {
				c4++;
			}
		}
		
	}
	cout<<"Total no. of Silver Seats boooked are : "<<c1<<endl;
	cout<<"Total no. of Gold Seats boooked are : "<<c2<<endl;
	cout<<"Total no. of Platinium Seats boooked are : "<<c3<<endl;
	cout<<"Available Seats are :"<<c4<<endl;
	cout<<endl;
	cout<<"=================================="<<endl;
}


void ShowTicketPrize(int seats[row][col]){
	cout<<endl;
	cout<<"=================================="<<endl;
	int tot_prize;
	int i,j,c1=0,c2=0,c3=0,c4=0;
	for (i=0;i<row;i++){
		for(j=0;j<col;j++){
			if (seats[i][j]==1){
				if(i>=0 && i<2){
					c1++;
				}
				else if (i>=2 && i<4){
					c2++;
				}
				else if (i>=4 && i<6){
					c3++;
				}
			}
			else {
				c4++;
			}
		}
		
	}

	tot_prize = c1*150 + c2*200 + c3*250 ;
	cout<<"Total price of your booking is :"<<tot_prize<<endl;
	cout<<endl;
	cout<<"=================================="<<endl;

}




int main(){
	int seats[row][col]= {0};
	int choice;
	do{
		showMenu();
		cin>>choice;
		cout<<endl;
		cout<<endl;
		switch(choice){
			case 1:
				BookSeat(seats);
				break;
			case 2:
				CancelSeat(seats);
				break;
			case 3:
				DisplaySeat(seats);
				break;
			case 4:
				ShowTotalBookedSeat(seats);
				break;
			case 5:
				ShowTicketPrize(seats);
				break;
				
			case 6:
				cout<<"Thanks for visiting!!"<<endl;
				break;
			
			default:
				cout<<"Invalid Choice."<<endl;
				
		}
	}while(choice != 6) ;
	return 0;
}


