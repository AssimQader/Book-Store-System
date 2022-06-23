#include<iostream>
#include<string>
#include"Book.h"
#include"Customer.h"
using namespace std;

int z = 0;
void MainMenue()
{
	cout << "\t\t\t\t\t *****SIMPLE BookShop SYSTEM*****\n\n"
		<< "\t\t\t\t\t  1. Show the Books\n"
		<< "\t\t\t\t\t  2. Buy a Book\n"
		<< "\t\t\t\t\t  3. Display Purachase Information\n"
		<< "\t\t\t\t\t  4. Cancel Books\n"
		<< "\t\t\t\t\t  5. Change Copies Number\n"
		<< "\t\t\t\t\t  6. Exit..\n\n"
		<< "\t\t\t\t\t  Enter your choise -> "; cin >> z;
}

int main()
{
	Book b[] = { Book(123, 15, 7, "The Greatest Books", "In Search of Lost Time", "Marcel"),
			   Book(124, 10, 18,"Francisco de Robles", "Don Quixote","Miguel de Cervantes"),
			   Book(125, 33, 60, "Scholastic Press" , "The Hunger Games" ,"Suzanne Collins"),
			   Book(126,110, 29, "Scholastic Press" , "Harry Potter and the Order of the Phoenix", "J.K. Rowling"),
			   Book(127, 215,44, "Kazanova mce" ,  "The Fault in Our Stars" ,"John Green"),
			   Book(128, 5,12, "García Márquez" ,  "To Kill a Mockingbird" ,"Harper Lee"),
			   Book(129,290,27, "J.D.Salinger"  , "Moby Dick", "Herman Melville"),
			   Book(130,290,100, "Wikipedia"  , "Gone With the Wind", "Margaret Mitchell")
	};  
	Customer co;
	
	do
	{
		MainMenue();

		switch (z)
		{
		case 1:
			co.show_books();
			break;
		case 2:
			co.buy_book(b);
			break;
		case 3:
			co.purachase_information(b);
			break;
		case 4:
			co.cancel(b);
			break;
		case 5:
			co.chang_copies_number(b);
		}
	} while (z != 6);


	cout << "\n\t\t*** You are logged out from the Application, thanks for using \"Zamzam BookShop System\" ***\n"
		<< "\t\t*** We hope to see you soon :) ***\n" << "\t\t\t\t\t | Created By: Asem Adel Ba7r |\n\n";
}