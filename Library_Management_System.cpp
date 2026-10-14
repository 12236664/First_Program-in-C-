#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    double price;
    long ISBN;

    Book() {
        title = "";
        author = "";
        price = 0.0;
        ISBN = 0;
    }
};

class Library {
private:
    Book books[50];
    int count;

public:
    Library() {
        count = 0;
    }

    void addBook() {
        if (count >= 50) {
            cout << "Library is full. Cannot add more books." << endl;
            return;
        }

        Book b;
        cin.ignore(); // Clear buffer
        cout << "\nEnter book details:" << endl;
        cout << "Title: ";
        getline(cin, b.title);
        cout << "Author: ";
        getline(cin, b.author);
        cout << "Price: ";
        cin >> b.price;
        cin.ignore();
        cout << "ISBN: ";
        cin >> b.ISBN;
        system("cls");

        books[count++] = b;
        cout << "Book added successfully." << endl;
    }

    void displayBooks() {
        if (count == 0) {
            cout << "No books in the library." << endl;
        }
else
        cout << "\n\n";
        cout << "==========================================="<<endl;
        cout << "\n   -----Books in the library:-----\n";
        cout << "==========================================="<<endl;
        for (int i = 0; i < count; i++) {
            cout << "\nBook " << i + 1 << ":\n";
            cout << "  Title: " << books[i].title << endl;
            cout << "  Author: " << books[i].author << endl;
            cout << "  Price: " << books[i].price << " ZMW" << endl;
            cout << "  ISBN: " << books[i].ISBN << endl;
        cout << "___________________________________________\n\n";
        }
    }

    void searchBook() {
        if (count == 0) {
            cout << "Library is empty." << endl;
            return;
        }

        long ISBN2;
        cin.ignore();
        cout << "Enter the ISBN to search: ";
        cin >> ISBN2;

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (books[i].ISBN == ISBN2) {
                cout << "\n";
                cout << "  Title: " << books[i].title << endl;
                cout << "  Author: " << books[i].author << endl;
                cout << "  Price: " << books[i].price << " ZMW:" << endl;
                cout << "  ISBN: " << books[i].ISBN << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    void deleteBook() {
        if (count == 0) {
            cout << "Library is empty." << endl;
            return;
        }

        long ISBN2;
        cin.ignore();
        cout << "Enter the ISBN to delete: ";
        cin >> ISBN2;
        system("cls");

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (books[i].ISBN == ISBN2) {
                for (int j = i; j < count - 1; j++) {
                    books[j] = books[j + 1];
                }
                count--;
                found = true;
                cout << "Book deleted successfully." << endl;
                break;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    void editBook() {
        if (count == 0) {
            cout << "Library is empty." << endl;
            return;
        }

        long ISBN2;
        cin.ignore();
        cout << "Enter the ISBN to edit: ";
        cin >> ISBN2;

        bool found = false;
        for (int i = 0; i < count; i=+1) {
            if (ISBN2 == books[i].ISBN) {
                cout << "Editing Book \"" << books[i].title << "\"\n" << endl;
                cin.ignore();
                cout << "Enter new title: ";
                getline(cin, books[i].title);
                cout << "Enter new author: ";
                getline(cin, books[i].author);
                cout << "Enter new price: ";
                cin >> books[i].price;
                cout << "Enter new ISBN: ";
                cin >> books[i].ISBN;
                found = true;
                system("cls");
                cout << "Book updated successfully." << endl;
                break;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    Library *lib = new Library();
    int choice;

    do {
        cout << "\n\n";
        cout << "==========================================="<<endl;
        cout << "        ------ Library Menu ------\n";
        cout << "==========================================="<<endl;
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book by ISBN.\n";
        cout << "4. Delete Book by ISBN.\n";
        cout << "5. Edit Book by ISBN.\n";
        cout << "\n" << endl;
        cout << "6. Exit\n";
        cout << "___________________________________________\n";
        cout << "Enter your choice (from 1 to 6): ";
        cin >> choice;
        cout << "\n\n";
        system("cls");

        switch (choice) {
            case 1:
                lib->addBook();
                break;
            case 2:
                lib->displayBooks();
                break;
            case 3:
                lib->searchBook();
                break;
            case 4:
               lib->deleteBook();
                break;
            case 5:
               lib->editBook();
                break;
            case 6:

                cout << "Exiting program.PRESS enter to completely exit..!" << endl;
                return 0;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}

