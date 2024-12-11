#include <iostream>
#include <vector>
#include <string>
using namespace std;
//code for library management
class Book {
private:
    string title, author;
    int id;

public:
    Book(int id, string title, string author) : id(id), title(title), author(author) {}
    void display() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
    }
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
};

class Library {
private:
    vector<Book> books;
    int nextId = 1;

public:
    void addBook(const string& title, const string& author) {
        books.push_back(Book(nextId++, title, author));
        cout << "Book added successfully!\n";
    }
    void deleteBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                cout << "Book deleted successfully!\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }
    void displayBooks() const {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }
        for (const auto& book : books) {
            book.display();
        }
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Display Books\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cin.ignore();
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter author name: ";

            getline(cin, author);
            library.addBook(title, author);
        } else if (choice == 2) {
            int id;
            cout << "Enter book ID to delete: ";
            cin >> id;
            library.deleteBook(id);
        } else if (choice == 3) {
            library.displayBooks();
        } else if (choice == 4) {
            cout << "Exiting program. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";

        }
    }

    return 0;
}