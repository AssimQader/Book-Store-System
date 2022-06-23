#include "Book.h"
#include<iostream>
#include<string>
#include<fstream>
#define N 8  // N is the number of books in the list, each book have its quantity //
using namespace std;

int n = 0; //counter for each baught process//

Book::Book() :book_id(0), num_of_avi_copies(0), price(0), publisher("unkonown"), title("unknown"), author("unknown"), numOf_wantedCopies(0)
{
}
Book::Book(int bi, int nu, double p, string pu, string t, string a) : book_id(bi), num_of_avi_copies(nu),
           price(p), publisher(pu), title(t), author(a), numOf_wantedCopies(0) {}





void Book::setnumOf_wantedCopies(int i)
{
	numOf_wantedCopies = i;
}

int Book::getnumOf_wantedCopies()
{
	return numOf_wantedCopies;
}

double Book::total_cost()
{
	double totalcost = getnumOf_wantedCopies() * price;
	return totalcost;
}

void Book::show_books()
{
	fstream myFile;
	myFile.open("BookShop.txt", ios::in);
	if (myFile.is_open())
	{
		string lines;
		while (getline(myFile, lines) )
		{
			cout << lines << "\n";
		}
		myFile.close();
	}
}

void Book::buy_book(Book b[]) //array of objects from class book as a parameter.
{
	int numOf_desiredBooks;
	string bookName, bookAuthor;
	bool flag = false; //to check from the input book from user, is it avilable in the list or not

	cout << "#Choose the name and the author of the book you want to buy: \n";
	cout << " - Book Name: ";
	getline(cin >> ws, bookName);
	cout << " - Book Author: ";
	getline(cin >> ws, bookAuthor);

	for (int i = 0; i < N; i++)
	{
		if (bookName == b[i].title && bookAuthor == b[i].author) //check from the ordered name and author that user woll input
		{
			cout << "#Enter the number of copies: ";
			cin >> numOf_desiredBooks;
			b[i].setnumOf_wantedCopies(numOf_desiredBooks); 

			//check if the number of ordered copies is avilable//
			if (b[i].getnumOf_wantedCopies() > b[i].num_of_avi_copies) 
			{
				cout << "There is only " << b[i].num_of_avi_copies << " copies avilable in the store.\n";
			}
			else if (b[i].getnumOf_wantedCopies() <= b[i].num_of_avi_copies)
			{
				n++; //buy
				b[i].num_of_avi_copies = b[i].num_of_avi_copies - b[i].getnumOf_wantedCopies(); //to update the rest avilable copies after buying process//
				cout << " = Your order added successfully..\n\n";
			}

			flag = true;
			break;
		}
	}

	if (flag == false)
		cout << " - There is no such book in the store.. \n\n";;
} 

void Book::chang_copies_number(Book b[])
{
	string name;
	int newquantity;

	cout << " #which book you want to change its orderd quantity: ";
	getline(cin >> ws, name); // [ cin >> ws ] is to ignore the white spaces, geline() function will not be able to work without it//

	for (int i = 0; i < N; i++)
	{
		if (b[i].title == name)
		{
			//cancel the old copies ordered. Make the avilable copies return to its old value before buying process//
			b[i].num_of_avi_copies = b[i].num_of_avi_copies + b[i].getnumOf_wantedCopies()/*the old value*/;

		   cout << " - Number of Avilabel copies = " << b[i].num_of_avi_copies << "\n";

			cout << " - Enter the new quantity: ";
			cin >> newquantity;

			if (newquantity > b[i].num_of_avi_copies)
			{
				cout << "There is only " << b[i].num_of_avi_copies << " copies avilable in the store.\n";
			}
			else if (newquantity <= b[i].num_of_avi_copies)
			{
				b[i].setnumOf_wantedCopies(newquantity);
				b[i].num_of_avi_copies = b[i].num_of_avi_copies - b[i].getnumOf_wantedCopies()/*the new value*/;
				cout << " - Updated done successfully..\n\n";

				break;
			}
		}
	}
}

void Book::purachase_information(Book b[])
{
	try
	{
		if (n == 0) //if the user used this function before buy any books
			throw 0;

		cerr << "\t//YOUR PURCHASE INFOs//\n\t-----------------------\n\n";
		for (int i = 0; i < N; ++i)
		{
			if (b[i].getnumOf_wantedCopies() != 0) //to display the book purchased only, not the whole list
			{
				cerr << "Book Name : " << b[i].title << "\n"
					<< "Book ID: " << b[i].book_id << "\n"
					<< "Book Author: " << b[i].author << "\n"
					<< "Book Publisher: " << b[i].publisher << "\n"
					<< "Number of purchased copies: " << b[i].getnumOf_wantedCopies() << " copy\n"
					<< "Total Cost: " << b[i].total_cost() << "$\n____________________________________\n";
			}
		}
	}
	catch (int i)
	{
		cout << "There is no purachesd books yet..\n\n";
	}
}

void Book::cancel(Book b[])
{
	string name;
	cout << "Enter the name of the book you want to cancel: ";
	getline(cin >> ws, name);

	bool flag = false;//if it becomes true, the cancelation done, if not then the customer puts a wrong book name

	for (int i = 0; i < N; i++)
	{
		if (b[i].title == name)
		{
			b[i].num_of_avi_copies += b[i].getnumOf_wantedCopies(); //add the baugth copies to the avilable ones (return process)
			b[i].setnumOf_wantedCopies(0);
			n--; //cancel the purchase of the customer

			cout << "Cancelation done successfully..\n\n";
			flag = true;
			break;
		}
	}

	if (flag == false)
		cout << " - You did not buy such a Book , please enter a valid book name.. \n\n";
}





