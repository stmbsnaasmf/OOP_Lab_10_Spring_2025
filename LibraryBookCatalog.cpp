#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Book
{
public:
	string ISBN, title, author;
	bool isAvailable;
	
	Book(string ISBN, string title, string author) : ISBN(ISBN), title(title), author(author){}
};

int search(unordered_map<string, Book>& library, string author, multimap<string, Book>& searchResult)
{
	int noOfBooks = 0;
	for (std::pair<string, Book> i : library)
	{
		if (i.second.author == author)
		{
			noOfBooks++;
			searchResult.insert({author, i.second});
		}
	}
	
	return noOfBooks;
}

int main(void)
{
	Book b0("9635280258938", "Mercury", "Asad");
	Book b1("4702599831795", "Venus", "Asad");
	Book b2("8417392305289", "Earth", "Asad");
	Book b3("4323267170016", "Mars", "Taimoor");
	Book b4("8951093252041", "Saturn", "Unknown");
	Book b5("5580166798252", "Jupiter", "Taimoor");

	unordered_map<string, Book> library;
	library.insert({b0.ISBN, b0});
	library.insert({b1.ISBN, b1});
	library.insert({b2.ISBN, b2});
	library.insert({b3.ISBN, b3});
	library.insert({b4.ISBN, b4});
	library.insert({b5.ISBN, b5});

	string author = "Taimoor";
//	string author = "Asad";
	multimap<string, Book> searchResult;
//	searchResult.insert({"Asad", b0});

	cout << author << " has " << search(library, author, searchResult) << " books in the library. They are:\n";
	for (std::pair<string, Book> i : searchResult)
	{
		cout << i.second.title << "\n";
	}

	return 0;
}
