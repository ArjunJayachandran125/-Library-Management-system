#include <bits/stdc++.h>
using namespace std;

class Book {
public:
    int id;
    string title, author;
    bool isIssued;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }
};

class User {
public:
    int userId;
    string name;
    list<int> borrowedBooks; 

    User(int id, string name) {
        this->userId = id;
        this->name = name;
    }

    void borrowBook(int bookId) {
        borrowedBooks.push_back(bookId);
    }

    void returnBook(int bookId) {
        borrowedBooks.remove(bookId);
    }
};

class Library {
    unordered_map<int, Book*> books;      
    unordered_map<int, User*> users;       
    queue<int> requestQueue;              

public:
    void addBook(int id, string title, string author) {
        books[id] = new Book(id, title, author);
        cout << " Book added: " << title << " by " << author << endl;
    }

    void addUser(int id, string name) {
        users[id] = new User(id, name);
        cout << "👤 User registered: " << name << endl;
    }

    void searchBook(string title) {
        for (auto &pair : books) {
            if (pair.second->title == title) {
                cout << " Found Book: [" << pair.second->id << "] "
                     << pair.second->title << " by " << pair.second->author
                     << (pair.second->isIssued ? " (Issued)" : " (Available)") << endl;
                return;
            }
        }
        cout << " Book not found.\n";
    }
 
    void issueBook(int userId, int bookId) {
        if (books.find(bookId) == books.end()) {
            cout << " Book does not exist.\n";
            return;
        }
        if (users.find(userId) == users.end()) {
            cout << " User not registered.\n";
            return;
        }
        if (books[bookId]->isIssued) {
            cout << " Book already issued. Added to request queue.\n";
            requestQueue.push(bookId);
            return;
        }

        books[bookId]->isIssued = true;
        users[userId]->borrowBook(bookId);
        cout << " Book issued: " << books[bookId]->title
             << " to " << users[userId]->name << endl;
    }

  
    void returnBook(int userId, int bookId) {
        if (books.find(bookId) == books.end() || users.find(userId) == users.end()) {
            cout << " Invalid return.\n";
            return;
        }
        books[bookId]->isIssued = false;
        users[userId]->returnBook(bookId);
        cout << " Book returned: " << books[bookId]->title << endl;

        if (!requestQueue.empty()) {
            int nextBookId = requestQueue.front();
            requestQueue.pop();
            cout << " Book " << books[nextBookId]->title << " is now available for next request.\n";
        }
    }

    void displayBooks() {
        cout << "\n Library Collection:\n";
        for (auto &pair : books) {
            cout << "[" << pair.second->id << "] "
                 << pair.second->title << " by " << pair.second->author
                 << (pair.second->isIssued ? " (Issued)" : " (Available)") << endl;
        }
    }
};

int main() {
    Library lib;

    lib.addBook(1, "C++ Programming", "Bjarne Stroustrup");
    lib.addBook(2, "Introduction to Algorithms", "CLRS");
    lib.addBook(3, "Artificial Intelligence", "Stuart Russell");

    lib.addUser(101, "Alice");
    lib.addUser(102, "Bob");

    lib.displayBooks();
    lib.searchBook("C++ Programming");

    lib.issueBook(101, 1);
    lib.issueBook(102, 1);

    lib.returnBook(101, 1); 
    lib.displayBooks();

    return 0;
}
