#include <iostream>
using namespace std;

class Book {
private:
    string id, isbn, title, author, edition, publication, category;

public:
    Book(string empID = "", string empISBN = "", string empTitle = "",
         string empAuthor = "", string empEdition = "",
         string empPublication = "", string empCategory = "")
        : id(empID), isbn(empISBN), title(empTitle), author(empAuthor),
          edition(empEdition), publication(empPublication), category(empCategory) {}

    // Getters
    string getID() const { return id; }
    string getISBN() const { return isbn; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getEdition() const { return edition; }
    string getPublication() const { return publication; }
    string getCategory() const { return category; }

    // Setters
    void setID(const string &newID) { id = newID; }
    void setISBN(const string &newISBN) { isbn = newISBN; }
    void setTitle(const string &newTitle) { title = newTitle; }
    void setAuthor(const string &newAuthor) { author = newAuthor; }
    void setEdition(const string &newEdition) { edition = newEdition; }
    void setPublication(const string &newPublication) { publication = newPublication; }
    void setCategory(const string &newCategory) { category = newCategory; }

    void display() const {
        cout << id;
        int idSpaces = 11 - id.length();
        for (int i = 0; i < idSpaces; i++) { cout << " "; }
        
        cout << isbn.substr(0, 3) << "-" << isbn.substr(3, 1) << "-" << isbn.substr(4, 2) << "-" << isbn.substr(6, 5) << "-" << isbn.substr(11, 2) << endl; 
        int isbnSpaces = 13 - isbn.length();
        for (int i = 0; i < isbnSpaces; i++) { cout << " "; }
    
        cout << title;
        int titleSpaces = 31 - title.length();
        for (int i = 0; i < titleSpaces; i++) { cout << " "; }
    
        cout << author;
        int authorSpaces = 20 - author.length();
        for (int i = 0; i < authorSpaces; i++) { cout << " "; }
    
        cout << edition;
        int editionSpaces = 10 - edition.length();
        for (int i = 0; i < editionSpaces; i++) { cout << " "; }
    
        cout << publication;
        int pubSpaces = 18 - publication.length();
        for (int i = 0; i < pubSpaces; i++) { cout << " "; }
    
        cout << category << "\n";
    }
};

void toUpperCase(string &str) {
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c = c - ('a' - 'A');
        }
    }
}

bool isOnlySpace(const string &s) {
    for (char c : s) {
        if (c != ' ') {
            return false;
        }
    }
    return true;
}

class Library {
private:
    Book** books;
    int count;

public:
    Library() : books(nullptr), count(0) {}

    int getCount() const{    return count;    };
    Book** getBook() const{        return books;    };
    
    void setCount(const int newCount){    count = newCount;    }
    
    void addBook(Book* book) {
        Book** newBooks = new Book*[count + 1];

        for (int i = 0; i < count; i++) {
            newBooks[i] = books[i];
        }

        newBooks[count] = book;

        delete[] books;
        books = newBooks;
        count++;

        cout << "\nBook added successfully!\nPress Enter to Continue...";
        char ch;
        while ((ch = cin.get()) != '\n' && ch != EOF) {}
        cout << "\n\n\n";
    }

    bool isDuplicateID(const string &bookID) {
        for (int i = 0; i < count; i++) {
            if (books[i]->getID() == bookID) {
                return true;
            }
        }
        return false;
    }

    Book* findBookByID(const string &bookID) {
        for (int i = 0; i < count; i++) {
            if (books[i]->getID() == bookID) {
                return books[i];
            }
        }
        return nullptr;
    }
    
    Book* findBookByCategory(const string &bookCategory) {
        for (int i = 0; i < count; i++) {
            if (books[i]->getCategory() == bookCategory) {
                return books[i];
            }
        }
        return nullptr;
    }

    void displayBooks(Book* books[], int count) {
        if(count == 0){
            cout << "\nNo books found!\n";
            return;
        }
        
        int idWidth = 10, isbnWidth = 13, titleWidth = 20, authorWidth = 15, editionWidth = 10, pubWidth = 15, categoryWidth = 10;
    
    
        for (int i = 0; i < count; i++) {
            if (books[i]->getID().length() > idWidth) idWidth = books[i]->getID().length();
            if (books[i]->getISBN().length() > isbnWidth) isbnWidth = books[i]->getISBN().length();
            if (books[i]->getTitle().length() > titleWidth) titleWidth = books[i]->getTitle().length();
            if (books[i]->getAuthor().length() > authorWidth) authorWidth = books[i]->getAuthor().length();
            if (books[i]->getEdition().length() > editionWidth) editionWidth = books[i]->getEdition().length();
            if (books[i]->getPublication().length() > pubWidth) pubWidth = books[i]->getPublication().length();
            if (books[i]->getCategory().length() > categoryWidth) categoryWidth = books[i]->getCategory().length();
        }
    
        int totalWidth = idWidth + isbnWidth + titleWidth + authorWidth + editionWidth + pubWidth + categoryWidth + 16;
        
        for (int i = 0; i < totalWidth; i++) cout << "=";
        cout << "\n";
    
        cout << "ID";
        for (int i = 2; i < idWidth; i++) cout << " ";
        cout << "  ";
    
        cout << "ISBN";
        for (int i = 4; i < isbnWidth; i++) cout << " ";
        cout << "      ";
    
        cout << "Title";
        for (int i = 5; i < titleWidth; i++) cout << " ";
        cout << "  ";
    
        cout << "Author";
        for (int i = 6; i < authorWidth; i++) cout << " ";
        cout << "  ";
    
        cout << "Edition";
        for (int i = 7; i < editionWidth; i++) cout << " ";
        cout << "  ";
    
        cout << "Publication";
        for (int i = 11; i < pubWidth; i++) cout << " ";
        cout << "  ";
    
        cout << "Category\n";
    
        for (int i = 0; i < totalWidth; i++) cout << "-";
        cout << "\n";
    
        for (int i = 0; i < count; i++) {
            string id = books[i]->getID();
            string isbn = books[i]->getISBN();
            string title = books[i]->getTitle();
            string author = books[i]->getAuthor();
            string edition = books[i]->getEdition();
            string publication = books[i]->getPublication();
            string category = books[i]->getCategory();
    
            cout << id;
            for (int j = id.length(); j < idWidth; j++) cout << " ";
            cout << "  ";
    
            cout << isbn.substr(0, 3) << "-"   
                 << isbn.substr(3, 1) << "-"   
                 << isbn.substr(4, 2) << "-"   
                 << isbn.substr(6, 5) << "-"   
                 << isbn.substr(11, 2);
            for (int j = isbn.length(); j < isbnWidth; j++) cout << " ";
            cout << "  ";
    
            cout << title;
            for (int j = title.length(); j < titleWidth; j++) cout << " ";
            cout << "  ";
    
            cout << author;
            for (int j = author.length(); j < authorWidth; j++) cout << " ";
            cout << "  ";
    
            cout << edition;
            for (int j = edition.length(); j < editionWidth; j++) cout << " ";
            cout << "  ";
    
            cout << publication;
            for (int j = publication.length(); j < pubWidth; j++) cout << " ";
            cout << "  ";
    
            cout << category << "\n";
        }
    
        for (int i = 0; i < totalWidth; i++) cout << "=";
        cout << "\n";
    }


    ~Library() {
        for (int i = 0; i < count; i++) {
            delete books[i];
        }
        delete[] books;
    }
};

class FindBook{
public:
    virtual void searchBookInfo(Library &myLibrary) = 0;
};

class AddBook {
private:
    string tempCategory, tempID, tempISBN, tempTitle, tempAuthor, tempEdition, tempPublication;
    bool loop = true;
    
public:
    void addBookInfo(Library &myLibrary) { 
        while (loop) {
            cout << "\n\nInput Category (FICTION/NON-FICTION): ";
            getline(cin, tempCategory);
            toUpperCase(tempCategory);

            if (tempCategory == "FICTION" || tempCategory == "NON-FICTION") {
                break;
            }
            cout << "Invalid Entry!\n";
        }

        while (loop) {
            cout << "Input ID: ";
            getline(cin, tempID);
            toUpperCase(tempID);
        
            if (tempID.empty() || isOnlySpace(tempID)) {
                cout << "Invalid Entry!\n\n";
                toUpperCase(tempID);
                continue;  
            }
        
            if (myLibrary.isDuplicateID(tempID)) {
                cout << "Error: Duplicate ID found! Try again.\n";
                continue;
            }
        
            break;
        }

        while (loop) {
            cout << "Input ISBN (Enter a valid 13-digit number): ";
            getline(cin, tempISBN);
        
            bool isValid = true;
            if (tempISBN.length() == 13) {
                for (int i = 0; i < 13; i++) {
                    if (!isdigit(tempISBN[i])) {
                        isValid = false;
                        break;
                    }
                }
            } 
            else {
                isValid = false;
            }
        
            if (isValid) {
                break;
            }
            cout << "Invalid Entry!\n\n";
        }

        while(loop){
            cout << "Input Title: ";
            getline(cin, tempTitle);
            if(!tempTitle.empty() && !isOnlySpace(tempTitle)) { break; }
            cout << "Invalid Entry!\n\n";
        }
        
        while(loop){
            cout << "Input Author: ";
            getline(cin, tempAuthor);
            if(!tempAuthor.empty() && !isOnlySpace(tempAuthor)) { break; }
            cout << "Invalid Entry!\n\n";
        }
        
        while(loop){
            cout << "Input Edition: ";
            getline(cin, tempEdition);
            if(!tempEdition.empty() && !isOnlySpace(tempEdition)) { break; }
            cout << "Invalid Entry!\n\n";
        }
        
        while(loop){
            cout << "Input Publication: ";
            getline(cin, tempPublication);
            if(!tempPublication.empty() && !isOnlySpace(tempPublication)) { break; }
            cout << "Invalid Entry!\n\n";
        }


        Book* newBook = new Book(tempID, tempISBN, tempTitle, tempAuthor, tempEdition, tempPublication, tempCategory);
        myLibrary.addBook(newBook);
    }
};

class EditBook : public FindBook{
private:
    string tempID, tempISBN, tempTitle, tempAuthor, tempEdition, tempPublication, tempCategory;
    bool loop = true;
    Book* book;
    
public:
    void searchBookInfo(Library &myLibrary) override{
            cout << "\nInput ID of book to edit: ";
            getline(cin, tempID);
            toUpperCase(tempID);
    
            book = myLibrary.findBookByID(tempID);
            if (!book) {
                cout << "Book not found!\nPress Enter to Continue...";
                char ch;
                while ((ch = cin.get()) != '\n' && ch != EOF) {}
                return;
            }
        while (loop) {
            cout << "Input new ISBN (Enter a valid 13-digit number): ";
            getline(cin, tempISBN);
        
            bool isValid = true;
            if (tempISBN.length() == 13) {
                for (int i = 0; i < 13; i++) {
                    if (!isdigit(tempISBN[i])) {
                        isValid = false;
                        break;
                    }
                }
            } 
            else {
                isValid = false;
            }
        
            if (isValid) {
                break;
            }
            cout << "Invalid Entry\n\n";
        }
        
        while (loop) {
            cout << "Enter new Title: ";
            getline(cin, tempTitle);
            if (!tempTitle.empty() && !isOnlySpace(tempTitle)) {
                book->setTitle(tempTitle);
                break;
            }
            cout << "Invalid Entry\n\n";
        }
        
        while (loop) {
            cout << "Enter new Author: ";
            getline(cin, tempAuthor);
            if ((!tempAuthor.empty()) && !isOnlySpace(tempAuthor)) {
                book->setAuthor(tempAuthor);
                break;
            }
            cout << "Invalid Entry\n\n";
        }
        
        while (loop) {
            cout << "Enter new Edition: ";
            getline(cin, tempEdition);
            if (!tempEdition.empty()  && !isOnlySpace(tempEdition)) {
                book->setEdition(tempEdition);
                break;
            }
            cout << "Invalid Entry\n\n";
        }
        
        while (loop) {
            cout << "Enter new Publication: ";
            getline(cin, tempPublication);
            if (!tempPublication.empty() && !isOnlySpace(tempPublication)) {
                book->setPublication(tempPublication);
                break;
            }
            cout << "Invalid Entry\n\n";
        }
        
        while (loop) {
            cout << "Enter new Category: ";
            getline(cin, tempCategory);
            toUpperCase(tempCategory);
            if (tempCategory == "FICTION" || tempCategory == "NON-FICTION") {
                book->setCategory(tempCategory);
                break;
            }
            cout << "Invalid Entry\n\n";
        }


        cout << "\nBook edited successfully!\nPress Enter to Continue...";
        char ch;
        while ((ch = cin.get()) != '\n' && ch != EOF) {}
        cout << "\n\n\n";
    }
};

class SearchBook : public FindBook {
private:
    bool loop = true; 
public:
    void searchBookInfo(Library &myLibrary) override{
        string tempID;
        
        while(loop){
            cout << "\nInput ID: ";
            getline(cin, tempID);
            toUpperCase(tempID);
    
            Book* book = myLibrary.findBookByID(tempID);
            if (book) {
                Book* books[] = {book};
                int count = 1;
            
                cout << "\nBook Found:\n";
                myLibrary.displayBooks(books, count);
                cout << "Press Enter to Continue...";
                char ch;
                while ((ch = cin.get()) != '\n' && ch != EOF) {}
                cout << "\n\n\n";
                break;
            }
            else {
                cout << "\nBook not found!\nPress Enter to Continue...";
                char ch;
                while ((ch = cin.get()) != '\n' && ch != EOF) {}
                return;
            }
        }
    }
};

class DeleteBook : public FindBook{
private:
    string tempID;
    int tempCount;
    Book** tempBook;
    bool loop = true;
public:
    void searchBookInfo(Library &myLibrary) override{
        while(loop){
            loop = true;
            cout << "\nInput ID of book to delete: ";
            getline(cin, tempID);
            toUpperCase(tempID);
            
            tempCount = myLibrary.getCount();
            tempBook = myLibrary.getBook();
            
                Book* book = myLibrary.findBookByID(tempID);
                
            if(book){
                
                for (int i = 0; i < tempCount; i++) {
                    if (tempBook[i]->getID() == tempID) {
                        delete tempBook[i];
            
                        for (int j = i; j < tempCount - 1; j++) {
                            tempBook[j] = tempBook[j + 1];
                        }
                    }
                }
            
            myLibrary.setCount(tempCount - 1);
            cout << "\nBook deleted successfully!\nPress Enter to Continue...";
            char ch;
            while ((ch = cin.get()) != '\n' && ch != EOF) {}
            cout << "\n\n\n";
            break;
            }
            
            else{
                cout << "\nBook not found!\nPress Enter to Continue...";
                char ch;
                while ((ch = cin.get()) != '\n' && ch != EOF) {}
                return;
            }
        }
    }
};

class SearchBookByCategory : public FindBook {
private:
    bool loop = true; 
public:
    void searchBookInfo(Library &myLibrary) override {
        string tempCategory;
        
        while (loop) {
            cout << "\nInput Category: ";
            getline(cin, tempCategory);
            toUpperCase(tempCategory);
            
            int bookCount = myLibrary.getCount();
            Book** books = myLibrary.getBook();

            // Collect all matching books
            Book* matchingBooks[100]; // Assuming a max of 100 books in a category
            int count = 0;

            for (int i = 0; i < bookCount; i++) {
                if (books[i]->getCategory() == tempCategory) {
                    matchingBooks[count++] = books[i]; // Store book and increment count
                }
            }

            if (count == 0) {
                cout << "No books found in this category!\n";
                continue;
            }

            // Display all matching books
            cout << "\nBooks Found:\n";
            myLibrary.displayBooks(matchingBooks, count);

            cout << "Press Enter to Continue...";
            char ch;
            while ((ch = cin.get()) != '\n' && ch != EOF) {}
            cout << "\n\n\n";
            break;
        }
    }
};

int main() {
    Library myLibrary;
    string choice;
    bool loop = true;
    int bookCount;

    while (loop) {
        cout << "\nLibrary.\n1. Add Book\n2. Edit Book \n3. Search Book\n4. Delete Book\n5. View Books by Category\n6. View All Books\n7. Exit\nChoice: ";
        getline(cin, choice);

        if (choice == "1") {
            AddBook add;
            add.addBookInfo(myLibrary);
            bookCount = myLibrary.getCount();
        } 
        
        else if (choice == "2") {
            EditBook edit;
            edit.searchBookInfo(myLibrary);
        } 
    
        else if (choice == "3") {
            SearchBook search;
            search.searchBookInfo(myLibrary);
        } 
    
        else if (choice == "4") {
            DeleteBook del;
            del.searchBookInfo(myLibrary);
        } 
        
        else if (choice == "5") {
            if (bookCount == 0) {
                cout << "There are no books!\n\n";
            } 
            else {
                SearchBookByCategory searchCategory;
                searchCategory.searchBookInfo(myLibrary);
            }
        }
        
        else if (choice == "6") {
            if (bookCount == 0) {
                cout << "There are no books!\n\n";
            } 
            else {
                myLibrary.displayBooks(myLibrary.getBook(), myLibrary.getCount());
                cout << "Press Enter to Continue...";
                char ch;
                while ((ch = cin.get()) != '\n' && ch != EOF) {}
                cout << "\n\n";
            }
        }
        
        else if (choice == "7") {
            cout << "Exiting...\n";
            break;
        } 
        
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}