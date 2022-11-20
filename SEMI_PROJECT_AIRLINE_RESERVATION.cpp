# include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;
#define ROWS 20
#define	SEATS 4
void int_seats(char array[] [SEATS], int elements);
void seat_map(char seats[ROWS][SEATS]);
unsigned int count_seats(char seats[ROWS][SEATS]);


int main(void)
{
	char section [ROWS][SEATS] = {0};
	unsigned int i = 0, j = 0, row = 0, seats = 0, seats_available = 0;
	string answer;
	
	// initialize seats with values x and 0
	int_seats(section, ROWS);
	
	// print a map
	seat_map(section);
	
	// determine the number seats available
	seats_available = count_seats(section);
	
	// sell to a customer
	
	cout << endl << "Do you want to buy a ticket? yes/no" << endl;
	getline(cin, answer);
	
	if (seats_available == 0)
	{
		cout << "Sorry. This flight is full." << endl;
		system("pause");
		return 0;
	}
	
	while (answer == "Yes" || answer == "yes")
	{
		cout << "There are" << seats_available << "seats available." << endl;
		cout << "Select Your Seats" << endl << endl;
		seat_map(section);
		
		cout << "Enter the row and seat number: " << endl;
		cin >> row >> seats;
		cin.ignore (100,'\n');
		
		if (section[row - 1][seats - 1] == 'O')
		{
			section[row - 1][seats - 1] = 'X'; // MARK AS SOLD
			seats_available--;
			cout << "You just purchased seat " << seats << " in a row " << row << endl
				<< " Thank you for your order. " << endl << endl;
		}
		else
		{
			cout << "Sorry that seat is taken. Pick another seat. " << endl;
		}
		
		cout << "Do You Want another ticket? yes/ no" << endl;
		getline(cin, answer);
	}
	
	// accept returned ticket. mark seat as available
	cout << endl << "Do you want Cancel your Ticket? Yes/No" << endl;
	getline(cin,answer);
	
	while (answer == "Yes" || answer == "yes")
	{
		
		cout << "Enter the row and seats number for the Cancelled ticket" << endl;
		cin >> row >> seats;
		cin.ignore(10,'\n');
		cout << "you cancelled your ticket in row " << row << " seat " << seats << endl;
		cout << "seat as available" << endl;
		section[row - 1][seats - 1] = 'O';
		seats_available;
		
		cout << endl << "Do you want to Cancell another ticket? Yes/No" << endl;
		getline(cin, answer);
	}
	
	
	
	cout << endl << endl << endl;
	system("pause");


}


void int_seats(char array[] [SEATS], int elements)
{
	int i, j;
	for(i = 0; i < elements; i++)
	{
		for(j = 0; j < SEATS; j++)
		{
			if (rand() % 2 == 0)
				array[i][j] = 'O'; // vacant seats
			else
				array[i][j] = 'X'; // seats is not available 
			
		}
	}
	return;
}


// funtion of seat map

void seat_map(char seats[ROWS][SEATS])
{
	unsigned int i, j;
	cout << "Reservation Seat" << endl << endl;
	
	cout << "SEAT";
	for(j = 0; j < SEATS; j++)
	{
		if (j == 2)
		cout << " "; // print 2 spaces for the aisle
		cout << setw(2) << j + 1;
	}
	
	cout << endl << endl;
	for (i =0; i < ROWS; i++)
	{
		cout << "Row";
		cout << setw(2) << i + 1;
		for (j = 0; j < SEATS; j++)
		{
			if (j == 2)
			cout << " "; // print 2 spaces for the aisle
			cout << setw(2) << seats[i][j];
		}
		cout << endl;
	}
	return;
}


// function count the seats

unsigned int count_seats(char seats[ROWS][SEATS])
{
	unsigned int seat_count = 0, i, j;
	
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < SEATS; j++)
		{
			if (seats[i][j] == 'O')
			{
				// cout << "seat" << j + 1 << "in a row" << i + 1 << "is available." << endl;
				seat_count++;
			}
		}
	}
	return seat_count;
}















