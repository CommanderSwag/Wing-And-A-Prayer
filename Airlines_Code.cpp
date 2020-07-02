							/*William Mitchell
							WING AND A PRAYER AIRLINES*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
using namespace std;

class Flight
{
	public:
        Flight();
		void Menu();
		void FirstClass();
		void CoachClass();
		void alphaClass();
		void betaClass();
		void Reservation();
		void Enternames();
		void CancelReservation();
		void SeatingArrangement();
		void Exit();
		void findNames(int, int);
	
	private:
		char firstname [20][20];
		char lastname [20][20];
		char x;
	    int seat[5][4];
		int seatpassenger[5][4];
		int i;
		int choice;
		string Home;
};

Flight::Flight()
{
	i=1;
	for(int b=0; b<20; b++)
	{
		strcpy(firstname[b], "0");
		strcpy(lastname[b], "0");
	}
	for(int m=0; m<5; m++)
	{
		for(int n=0; n<4; n++)
		{
			seat[m][n]=0;
			seatpassenger[m][n]=0;
		}
	}
}		

void Flight::Menu()
{
	cout<<"\n\nPlease select an option below:\n\n";
	cout<<"<1>-Make a reservation\n";
	cout<<"<2>-Cancel a reservation\n";
	cout<<"<3>-Display current seating\n";
	cout<<"<4>-Quit\n\n";
	cin>>x;
	switch(x)
	{
		case '1':
			cout<<"\n\nYou have selected: Make a reservation.\n\n";
			Reservation();
			break;
		case '2':
			CancelReservation();
		case '3':
			SeatingArrangement();
			break;
		case '4':
			Exit();
			break;	
	}
}

void Flight::SeatingArrangement()
{
     alphaClass(); 
                   cout<<"\n";
                   for(int q=0; q<7; q++)
                   {
                   cout<<"=\t";
                   }
                   cout<<"\n\n"; 
     betaClass();
     cout<<"\n\nIf you would like to return to the MENU, press <1>:\n\n";
     cin>>Home;
     if(Home=="1")
     {
          Menu();
     }
     else
     {
         Exit();
     }
}

void Flight::alphaClass()
{
     cout<<"\n<0> Seat available or <name> Seat occupied.\n\n";
     for(int m=0; m<2; m++)
     {
             for(int n=0; n<4; n++)
             {
                 if(seat[m][n]==0)
                 {
                       cout<<"0"<<"\t\t";
                 }
                 else
                 {
                     findNames(m , n);
                 }
                       
             }
             cout<<"\n";
     }
}     

void Flight::betaClass()
{
     for(int o=2; o<5; o++)
     {
             for(int p=0; p<4; p++)
             {
                   if(seat[o][p]==0)
                   {
                            cout<<"0"<<"\t\t";
                   }
                   else
                   {
                       findNames(o, p);  
                   }      
             }
             cout<<"\n";
     }
}

void Flight::Exit()
{
    cout<<"\n\nThank you, have a nice day!\n";
    cout<<"I hope your experience on Wing and a Prayer Airlines was satisfactory!\n\n";
    cout<<"(PROGRAM TERMINATED)";
} 

void Flight::Reservation()
{
	cout<<"<1> First Class or <2> Coach Class:\n\n";
	cin>>choice;
	if(choice==1)
	{
          FirstClass();
    }
    else
    {
          CoachClass();
    }
}

void Flight::CancelReservation()
{
	int r, s, t, u;
	cout<<"\n<1>First Class or <2> Coach Class:\n\n";
	cin>>r;
	if(r==1)
	{
		cout<<"\nSelect a row <Enter 1 or 2>:\n\n";
		cin>>s;
		cout<<"\nWindow seat <Enter 1 or 4> Aisle seat <Enter 2 or 3>:\n\n";
		cin>>t;
		u=seatpassenger[s][t];
		strcpy(firstname[u], "0");
		strcpy(lastname[u], "0");
		seat[s-1][t-1]=0;
	}
	else
	{
		cout<<"Select a row <Enter 3, 4, or 5>:\n\n";
		cin>>s;
		cout<<"Window seat <Enter 1 or 4> Aisle seat <Enter 2 or 3>:\n\n";
		cin>>t;
		u=seatpassenger[s][t];
		strcpy(firstname[u], "0");
		strcpy(lastname[u], "0");
		seat[s-1][t-1]=0;
	}	
}


void Flight::Enternames()
{	
	cout<<"\nEnter the passenger's first name:\n\n";
	cin>>firstname[i];
	cout<<"\n\nEnter the passenger's last name:\n\n";
	cin>>lastname[i];
	i++;
    cout<<"\n";		
}

void Flight::findNames(int a, int b)
{
     int first, last;
     last=seatpassenger[a][b];
     cout<<lastname[last]<<"\t\t";
}

void Flight::FirstClass()
{
     int row, column;
     cout<<"\n\nMake a First Class reservation:\n\n";
     cout<<"Select a row <Enter 1 or 2>:\n\n";
     cin>>row;
     cout<<"\nWindow seat <Enter 1 or 4> Aisle seat <Enter 2 or 3>:\n\n";
     cin>>column;
     if(seat[row-1][column-1]!=0)
     {
     	cout<<"\nSeat unavailable.\n";
     }
     else
     {
     	seat[row-1][column-1]=1;
     	seatpassenger[row-1][column-1]=i;
    	cout<<"\n\nSeat confirmed.\n\n";
     }
     
     Enternames();
     
     cout<<"If you would like to return to the MENU, press <1>:\n\n";
     cin>>Home;
     if(Home=="1")
     {
          Menu();
     }
     else
     {
         Exit();
     }      
}

void Flight::CoachClass()
{
     int r, c;
     cout<<"\n\nMake a Coach Class resrvation:\n\n";
     cout<<"Select a row <Enter 3, 4, or 5>:\n\n";
     cin>>r;
     cout<<"\nWindow seat <Enter 1 or 4> Aisle seat <Enter 2 or 3>:\n\n";
     cin>>c;
     if(seat[r-1][c-1]!=0)
     {
     	cout<<"\nSeat unavailable.\n\n";
     }
     else
     {
     	seat[r-1][c-1]=1;
     	seatpassenger[r-1][c-1]=i;
     	cout<<"\n\nSeat confirmed.\n\n";
     }
     
     Enternames();
     
     cout<<"If you would like to return to the MENU, press <1>:\n\n";
     cin>>Home;
     if(Home=="1")
     {
          Menu();
     }
     else
     {
         Exit();
     }  
}

		
int main()
{
    cout<<"Hello Cousin Sue, you are at the MENU.\n\n";
    
	Flight code;
	code.Menu();
	getch();
    	
	return 0;
}

/*
Hello Cousin Sue, you are at the MENU.



Please select an option below:

<1>-Make a reservation
<2>-Cancel a reservation
<3>-Display current seating
<4>-Quit

1


You have selected: Make a reservation.

<1> First Class or <2> Coach Class:

1


Make a First Class reservation:

Select a row <Enter 1 or 2>:

2

Window seat <Enter 1 or 4> Aisle seat <Enter 2 or 3>:

3


Seat confirmed.


Enter the passenger's first name:

Simon


Enter the passenger's last name:

Birch

If you would like to return to the MENU, press <1>:

1


Please select an option below:

<1>-Make a reservation
<2>-Cancel a reservation
<3>-Display current seating
<4>-Quit

3

<0> Seat available or <name> Seat occupied.

0               0               0               0
0               0               Birch           0

=       =       =       =       =       =       =

0               0               0               0
0               0               0               0
0               0               0               0


If you would like to return to the MENU, press <1>:

1


Please select an option below:

<1>-Make a reservation
<2>-Cancel a reservation
<3>-Display current seating
<4>-Quit

1


You have selected: Make a reservation.

<1> First Class or <2> Coach Class:

2


Make a Coach Class resrvation:

Select a row <Enter 3, 4, or 5>:

4

Window seat <Enter 1 or 4> Aisle seat <Enter 2 or 3>:

2


Seat confirmed.


Enter the passenger's first name:

Steven


Enter the passenger's last name:

Hawking

If you would like to return to the MENU, press <1>:

1


Please select an option below:

<1>-Make a reservation
<2>-Cancel a reservation
<3>-Display current seating
<4>-Quit

3

<0> Seat available or <name> Seat occupied.

0               0               0               0
0               0               Birch           0

=       =       =       =       =       =       =

0               0               0               0
0               Hawking         0               0
0               0               0               0


If you would like to return to the MENU, press <1>:

1


Please select an option below:

<1>-Make a reservation
<2>-Cancel a reservation
<3>-Display current seating
<4>-Quit

2

<1>First Class or <2> Coach Class:

1

Select a row <Enter 1 or 2>:

2

Window seat <Enter 1 or 4> Aisle seat <Enter 2 or 3>:

3

<0> Seat available or <name> Seat occupied.

0               0               0               0
0               0               0               0

=       =       =       =       =       =       =

0               0               0               0
0               Hawking         0               0
0               0               0               0


If you would like to return to the MENU, press <1>:

1


Please select an option below:

<1>-Make a reservation
<2>-Cancel a reservation
<3>-Display current seating
<4>-Quit

4


Thank you, have a nice day!
I hope your experience on Wing and a Prayer Airlines was satisfactory!

(PROGRAM TERMINATED)
*/
