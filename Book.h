#pragma once
#include<iostream>
#include<string>
using namespace std;

class Book
{
private:
	int book_id, num_of_avi_copies, numOf_wantedCopies;
	double price;
	string publisher, title, author;
public:

	Book(); //default cont

	Book(int bi, int nc, double p, string pu, string t, string a); //parametrize cont


	void show_books();

	void buy_book(Book b[]);

	void chang_copies_number(Book b[]);

	void setnumOf_wantedCopies(int i);

	int getnumOf_wantedCopies();

	void purachase_information(Book b[]);

	double total_cost();

	void cancel(Book b[]);
};


