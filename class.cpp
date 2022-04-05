#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;
int queue[100], n = 100, front = -1, rear = -1;
int stack[100], nm = 100, top = -1;

class Book {
public:
    char name[100];
    char author[100];
    float price;
    int book_year;
    char book_genre[30];
    float id;

    static Book GetBook();
    static void SortBookTitle(Book books[], int num);
    static void SortBookPrice(Book books[], int num);
    static void OutputBooks(Book books[], int num);

    void show_book();
    void check_book();
    void update_book();
    void del_book();

};

int static Book_ID[10];
int p = 0;

Book Book::GetBook() {
    fstream BookID;
    fstream file;

    string a_name, b_name;

    float b_id = 0;

    BookID.open("bookID.txt", ios::app); //append

    Book temp;
    cout << "\nEnter the following information of the book: " << endl;

    fflush(stdin);
    cout << "Book ID       : ";
    cin >> temp.id;
    BookID << "Book ID : " << temp.id << endl;
    Book_ID[p++];

    fflush(stdin);
    cout << "Title         : ";
    cin.getline(temp.name, 100);

    cout<<"Year Released : ";
    cin>>temp.book_year;

    fflush(stdin);
    cout << "Author        : ";
    cin.getline(temp.author, 100);

    fflush(stdin);
    cout<<"Genre         : ";
    cin.getline(temp.book_genre,30);

    cout << "Price         : ";
    cin >> temp.price;

    file.open("book.txt", ios::out | ios::app);
    file << temp.id << " " << temp.name << " " << temp.author << "\n";
    file.close();


    BookID.close();

    return temp;
}

// Function to display book
void Book::show_book() {
    system("cls");
    fstream file;
    string book_name, book_id, author_name;
    cout << "\n\t\t\t\tAll BOOKS";

    // Open the file in input mode
    file.open("book.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\nBook ID\t\t\tBook Title"
             << "\t\t\tAuthor\n\n";
        file >> book_id >> book_name;
        file >> author_name;

        // Till end of file is reached
        while (!file.eof()) {
            cout << "  " << book_id
                 << "\t\t\t\t" << book_name
                 << "\t\t\t\t\t" << author_name
                 << "\n\n";
            file >> book_id >> book_name;
            file >> author_name;
        }

        system("pause");

        // Close the file
        file.close();
    }
}

// Function to check the book
void Book::check_book() {
    system("cls");
    fstream file;
    int count = 0;
    string b_id, b_name, a_name, b_idd;

    cout << "\n\n\t\t\t\tCheck "
         << "Particular Book";

    // Open the file in input mode
    file.open("book.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nBook ID : ";
        cin >> b_idd;
        file >> b_id >> b_name >> a_name;

        while (!file.eof()) {

            if (b_idd == b_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular Book";
                cout << "\n\nBook ID : "
                     << b_id;
                cout << "\nName : "
                     << b_name;
                cout << "\nAuthor : "
                     << a_name;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> b_id >> b_name >> a_name;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nBook ID Not Found..." << endl;
    }
}

// Function to update the book
void Book::update_book() {
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string b_name, b_na, a_name;
    string a_na, b_idd, b_id;

    cout << "\n\n\t\t\t\tUpdate Book Record";
    file1.open("book1.txt", ios::app | ios::out);
    file.open("book.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nBook ID : ";
        cin >> b_id;
        file >> b_idd >> b_name >> a_name;

        // Till end of file is reached
        while (!file.eof()) {
            if (b_id == b_idd) {
                system("cls");
                cout << "\t\t\t\t"
                     << "Update Book Record";
                cout << "\n\nNew Book Name : ";
                cin >> b_na;
                cout << "\nAuthor Name : ";
                cin >> a_na;
                file1 << " " << b_id << " "
                      << b_na << " "
                      << a_na << "\n\n";
                count++;
            } else
                file1 << " " << b_idd
                      << " " << b_name
                      << " " << a_name
                      << "\n\n";
            file >> b_idd >> b_name;
            file >> a_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nBook ID Not Found";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("book.txt");
    rename("book1.txt",
           "book.txt");
}

// Function to delete book
void Book::del_book() {
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string b_id, b_idd, b_name, a_name;
    cout << "\n\n\t\t\t\tDelete a Book";

    // Append file in output mode
    file1.open("book1.txt", ios::app | ios::out);
    file.open("book.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nBook ID : ";
        cin >> b_id;
        file >> b_idd;

        while (!file.eof()) {

            if (b_id == b_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Delete a Book";
                cout << "\n\nBook is Deleted "
                        "Successfully...\n\n";
                count++;
            } else
                file1 << " " << b_idd
                      << " " << b_name
                      << " " << a_name
                      << " " << no_copy
                      << "\n\n";
            file >> b_idd >> b_name;
            file >> a_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nBook ID Not Found..." << endl;
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("book.txt");
    rename("book1.txt", "book.txt");
}


//Sorts the books by Price
void Book::SortBookPrice(Book books[], int num) {
    int i, j;
    cout << " Books are now sorted by Price (Lowest to Highest)" << endl;

    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (books[i].price > books[j].price) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}


//Sorts the books by title
void Book::SortBookTitle(Book books[], int num) {
    int i, j;
    cout << "\nHere is a list of your book sorted by Title (A - Z)" << endl;

    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (books[i].id > books[j].id) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

}


//Outputs the information collected
void Book::OutputBooks(Book books[], int num) {
    cout << endl;

    cout << "Book Information: " << endl;
    for (int i = 0; i < num; ++i) {
        cout << "ID            : " << books[i].id << endl;
        cout << "Title         : " << books[i].name << endl;
        cout << "Year Released : " << books[i].book_year << endl;
        cout << "Author        : " << books[i].author << endl;
        cout << "Genre         : " << books[i].book_genre << endl;
        cout << "Price         : RM" << books[i].price  << endl;
        cout << endl;
    }
}

struct SEARCHbook {
    string SEARCHname, SEARCHemail;
    int SEARCHnoTele, SEARCHtarget;
};

//======================================================


void Insert() {
    srand((unsigned) time(0));
    int val;

    if (rear == n - 1)
        cout << "Queue Overflow" << endl;
    else {
        if (front == -1)
            front = 0;
        for (int index = 0; index < 10; index++) {
            val = (rand() % 20) + 1;
        }
        rear++;
        queue[rear] = val;
        cout << "Customer queue successfully added." << endl;
    }
}

void Delete() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow ";
        return;
    } else {
        cout << "Customer deleted from the first queue." << endl;
        front++;;
    }
}

void Display() {
    int count = 0;
    if (front == -1)
        cout << "Queue is empty" << endl;
    else {
//        cout<<"Queue elements are : ";
        for (int i = front; i <= rear; i++) {
//            cout<<queue[i]<<" ";
            count++;
        }
        cout << endl;
        cout << count << " customers in queue" << endl;

    }
}

//STACK
//====================================================

void push(float val) {
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    else {
        top++;
        stack[top] = val;
    }
}

void pop() {
    if (top <= -1)
        cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

void displayStack() {
    if (top >= 0) {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    } else
        cout << "Stack is empty" << endl;
}

//DISPLAY START
//====================================================

void queueDisplay() {
    int ch;

    system("CLS");
    cout << "========================================" << endl;
    cout << "\t\t\t\tQueue" << endl;
    cout << "========================================" << endl;
    cout << "[1] Insert Customer To Queue" << endl;
    cout << "[2] Delete Customer From Queue" << endl;
    cout << "[3] Display All The Customers Of Queue" << endl;
    cout << "[4] Back to Main Menu" << endl;
    do {
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                Insert();
                break;
            case 2:
                Delete();
                break;
            case 3:
                Display();
                break;
            case 4:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
    } while (ch != 4);
}


int l = 0;
int k = 100;

void sortingDisplay() {

    int NUMBER;
    Book books[k];


    system("CLS");
    int choice;
    do {
        cout << "========================================" << endl;
        cout << "\t\t\t\tSorting" << endl;
        cout << "========================================" << endl;
        cout << "[1] Add Book" << endl;
        cout << "[2] Sorts The Books By Name" << endl;
        cout << "[3] Sorts The Books By Price" << endl;
        cout << "[4] Back to Main Menu" << endl;

        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                NUMBER = 0;
                cout << "How many books you want to add? ";
                cin >> NUMBER;
                for (int i = 0; i < NUMBER; ++i) {
                    books[l] = Book::GetBook();
                    ++l;
                }
                break;
            case 2:
                Book::SortBookTitle(books, l);
                Book::OutputBooks(books, l);
                break;
            case 3:
                Book::SortBookPrice(books, l);
                Book::OutputBooks(books, l);
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
}

void stackDisplay() {
    fstream myFile;
    fstream file, file1;
    float b_idd;

    myFile.open("bookID.txt", ios::in); //read
    file.open("book.txt", ios::in);

    int cha;
    string name;
    float val;

    system("CLS");
    cout << "========================================" << endl;
    cout << "\t\t\t\t Stack" << endl;
    cout << "========================================" << endl;
    cout << "[1] Push In Stack" << endl;
    cout << "[2] Pop From Stack" << endl;
    cout << "[3] Display Stack" << endl;
    cout << "[4] Back to Main Menu" << endl;
    do {
        cout << "\nEnter Choice: ";
        cin >> cha;
        switch (cha) {
            case 1: {
                cout << "Enter Book ID to be pushed: " << endl;
                cin >> val;
                file >> b_idd;
                if (val == b_idd) {
                    push(val);
                } else {
                    cout << "Book ID not found." << endl;
                }
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                displayStack();
                break;
            }
            case 4: {
                cout << "Exit" << endl;
                break;
            }
            default: {
                cout << "Invalid Choice" << endl;
            }

        }
    } while (cha != 4);
}


int static Customer[10];
int z = 0;

void addCustomer() {
    fstream customerID;

    cout << "Enter customer ID            : ";
    cin >> Customer[z];
    customerID.open("customerID.txt", ios::app); //append
    if (customerID.is_open()) {
        customerID << Customer[z++];
        customerID.close();
    }
    cout << "Customer Successfully Added!" << endl;
}

void skipLines(ifstream &stream, int nLines) {
    string dummyLine;
    for (int i = 0; i < nLines; ++i)
        getline(stream, dummyLine);
}

void searchGenre() {
    struct SEARCHbook SB;
    int found;
    char choice;

    do {
        cout << "Customer Name         : ";
        fflush(stdin);
        getline(cin, SB.SEARCHname);
        cout << "Customer Email        : ";
        getline(cin, SB.SEARCHemail);
        cout << "Customer Phone Number : ";
        cin >> SB.SEARCHnoTele;

        cout << "========================================" << endl;
        cout << endl << "\t\tChoose The Book Genre" << endl;
        cout << "========================================" << endl;
        cout << "\n[1] Romance";
        cout << "\n[2] Horror";
        cout << "\n[3] Historical";
        cout << "\n[4] Fantasy";
        cout << "\n[5] Magical Realism";
        cout << "\n[6] Science Fiction";
        cout << "\n[7] Mystery" << endl;


        cout << "\nEnter genre that customer want [1-7]: ";
        cin >> SB.SEARCHtarget;
        found = 0;
        {
            if (SB.SEARCHtarget == 1) {
                found = 1;
                cout << "\nGenre found! ROMANCE";
            } else if (SB.SEARCHtarget == 2) {
                found = 1;
                cout << "\nGenre found! HORROR";
            } else if (SB.SEARCHtarget == 3) {
                found = 1;
                cout << "\nGenre found! HISTORICAL";
            } else if (SB.SEARCHtarget == 4) {
                found = 1;
                cout << "\nGenre found! FANTASY";
            } else if (SB.SEARCHtarget == 5) {
                found = 1;
                cout << "\nGenre found! MAGICAL REALISM";
            } else if (SB.SEARCHtarget == 6) {
                found = 1;
                cout << "\nGenre found! SCIENCE FICTION";
            } else if (SB.SEARCHtarget == 7) {
                found = 1;
                cout << "\nGenre found! MYSTERY";
            }
        }
        cout << "\nCustomer Name              : " << SB.SEARCHname;
        cout << "\nCustomer Email             : " << SB.SEARCHemail;
        cout << "\nCustomer Phone Number      : " << SB.SEARCHnoTele;
        cout << "\nGenre That Customer Choose : " << SB.SEARCHtarget;

        cout << "\n\nDo you want to continue? (Y/N) ";
        cin >> choice;

    } while (SB.SEARCHtarget < 7 && found == 1 && choice == 'Y');
}



void searchCustomer() {
    int key, loc;
    char ch;

    do {
        cout << "Enter the customer ID to be searched : ";
        cin >> key;
        for (int i = 0; i < 10; i++) {
            if (Customer[i] == key) {
                loc = i + 1;
                break;
            } else
                loc = 0;
        }
        if (loc != 0) {
            cout << "Key found at position " << loc << " in the array" << endl;
        } else {
            cout << "Could not find given key in the array" << endl;
        }
        cout << "\nDo you want search another customer ID? [Y/N] : ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');
}

void searchingDisplay() {

    system("CLS");
    int ch;


    cout << "========================================" << endl;
    cout << "\t\t\t\tSearching" << endl;
    cout << "========================================" << endl;

    cout << "[1] Add Customer" << endl;
    cout << "[2] Search Customer" << endl;
    cout << "[3] Search Genre" << endl;
    cout << "[4] Return to Main Menu" << endl;


    do {
        cout << "\nEnter Choice: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                addCustomer();
                break;
            }
            case 2: {
                searchCustomer();
                break;
            }
            case 3: {
                searchGenre();
                break;
            }
            default: {
                cout << "Invalid Choice" << endl;
            }
        }
    } while (ch != 4);
}

//==============================================
//DISPLAY END

int main() {

    Book b;

    int choice;

    do {
        system("CLS");
        cout << "========================================" << endl;
        cout << "\t\t\t\tAdmin Panel" << endl;
        cout << "========================================" << endl;

        cout << "[1] Queue" << endl;
        cout << "[2] Stack" << endl;
        cout << "[3] Sorting" << endl;
        cout << "[4] Searching" << endl << endl;

        cout << "[5] Display Book" << endl;
        cout << "[6] Update Book" << endl;
        cout << "[7] Delete Book" << endl;
        cout << "[8] Check Particular Book" << endl;
        cout << "[9] Exit" << endl;

        cout << "\nEnter your choice : ";
        cin >> choice;

        if (choice == 1)
             queueDisplay();
        else if (choice == 2)
             stackDisplay();
        else if (choice == 3)
             sortingDisplay();
        else if (choice == 4)
             searchingDisplay();
        else if (choice == 5)
            b.show_book();
        else if (choice == 6)
            b.update_book();
        else if (choice == 7)
            b.del_book();
        else if (choice == 8)
            b.check_book();
        else if (choice == 9) {
            cout << "\nThank you!" << endl;
            exit(0);
        }
    } while (choice != 9);

    return 0;
}