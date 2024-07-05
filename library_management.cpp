#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int year;

    Book(int id, string title, string author, int year) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->year = year;
    }

    void display() const {
        cout << "ID: " << id << ;
        cout<< "Title: " << title ;
        cout<<"Author: " << author;
        cout<< "Year: " << year << endl;
    }
};

class Library {
private:
    vector<Book> books;
    int nextId;

public:
    Library() : nextId(1) {}

    void addBook(string title, string author, int year) {
        books.emplace_back(nextId++, title, author, year);
        cout << "Book added successfully!" << endl;
    }

    void deleteBook(int id) {
        auto it = remove_if(books.begin(), books.end(), [id](const Book &book) { return book.id == id; });
        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book deleted successfully!" << endl;
        } else {
            cout << "Book not found!" << endl;
        }
    }

    void displayBooks() const {
        if (books.empty()) {
            cout << "No books in the library!" << endl;
        } else {
            for (const auto &book : books) {
                book.display();
            }
        }
    }

    void searchByTitle(const string &title) const {
        bool found = false;
        for (const auto &book : books) {
            if (book.title.find(title) != string::npos) {
                book.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No books found with the title containing \"" << title << "\"!" << endl;
        }
    }
};

int main() {
    Library library;
    int choice, year, id;
    string title, author;

    while (true) {
        cout << "\n Welcome to our Library Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Display All Books \n";
        cout << "4. Search Book by Title\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Year: ";
                cin >> year;
                library.addBook(title, author, year);
                break;
            case 2:
                cout << "Enter Book ID to delete: ";
                cin >> id;
                library.deleteBook(id);
                break;
            case 3:
                library.displayBooks();
                break;
            case 4:
                cout << "Enter Title to search: ";
                cin.ignore();
                getline(cin, title);
                library.searchByTitle(title);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
