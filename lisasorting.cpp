#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
int queue[100], n = 100, front = - 1, rear = - 1;
int stack[100], nm=100, top=-1;

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
    static void OutputBooks( Book books[], int num);

};

int static Book_ID[10];
int p = 0;

Book Book::GetBook()
{
    fstream BookID;
    fstream myFile;

    myFile.open("myFile.txt", ios::app); //append
    BookID.open("bookID.txt", ios::app); //append

    if(myFile.is_open())
    {
        Book temp;
        cout << "\nEnter the following information of the book: " << endl;

        fflush(stdin);
        cout << "Title         : ";
        cin.getline(temp.name, 100);
        myFile << "Title         : " << temp.name << endl;

        fflush(stdin);
        cout << "Book ID       : ";
        cin >> temp.id;
        myFile << "Book ID     : " << temp.id  << endl;
        BookID << "Book ID : " << temp.id << endl;
        Book_ID[p++];

        cout<<"Year Released : ";
        cin>>temp.book_year;
        myFile << "Year Released : " << temp.book_year << endl;

        fflush(stdin);
        cout << "Author        : ";
        cin.getline(temp.author, 100);
        myFile << "Author        : " << temp.author << endl;

        fflush(stdin);
        cout<<"Genre         : ";
        cin.getline(temp.book_genre,30);
        myFile << "Genre         : " << temp.book_genre << endl;

        cout << "Price         : ";
        cin >> temp.price;
        myFile << "Price         : " << temp.price << endl << endl;

        myFile.close();
        BookID.close();

        return temp;

    }
    cin.get();
}

//Sorts the books by Price
void Book::SortBookPrice( Book books[], int num )
{
    int i, j;
    cout << " Books are now sorted by Price (Lowest to Highest)" << endl;

    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if( books[i].price > books[j].price )
            {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}


//Sorts the books by title
void Book::SortBookTitle( Book books[], int num )
{
    int i, j;
    cout << "\nHere is a list of your book sorted by Title (A - Z)" << endl;


    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if( books[i].id > books[j].id )
            {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

}


//Outputs the information collected
void Book::OutputBooks( Book books[], int num )
{
    cout << endl;

    cout << "Book Information: " << endl;
    for(int i=0;i<num;++i)
    {
        cout << "Name          : " << books[i].name << endl;
        cout << "ID            : " << books[i].id << endl;
        cout << "Year Released : " << books[i].book_year << endl;
        cout << "Author        : " << books[i].author << endl;
        cout << "Genre         : " << books[i].book_genre << endl;
        cout << "Price         : " << books[i].price << endl;
        cout << endl;
    }
}

struct SEARCHbook
{
    string SEARCHname, SEARCHemail;
    int SEARCHnoTele, SEARCHtarget;
};

//======================================================


void Insert() {
    srand((unsigned) time(0));
    int val;

    if (rear == n - 1)
        cout<<"Queue Overflow"<<endl;
    else {
        if (front == - 1)
            front = 0;
        for (int index = 0; index < 10; index++) {
            val = (rand() % 20) + 1;
        }
        rear++;
        queue[rear] = val;
        cout<<"Customers successfully added." << endl;
    }
}

void Delete() {
    if (front == - 1 || front > rear) {
        cout<<"Queue Underflow ";
        return ;
    } else {
        cout<<"Customers deleted from the first queue." << endl;
        front++;;
    }
}

void Display() {
    int count = 0;
    if (front == - 1)
        cout<<"Queue is empty"<<endl;
    else {
//        cout<<"Queue elements are : ";
        for (int i = front; i <= rear; i++)
        {
//            cout<<queue[i]<<" ";
            count++;
        }
        cout<<endl;
        cout << count << " customers in queue" << endl;

    }
}

//STACK
//====================================================

void push(float val) {
    if(top>=n-1)
        cout<<"Stack Overflow"<<endl;
    else {
        top++;
        stack[top]=val;
    }
}
void pop() {
    if(top<=-1)
        cout<<"Stack Underflow"<<endl;
    else {
        cout<<"The popped element is "<< stack[top] <<endl;
        top--;
    }
}
void displayStack() {
    if(top>=0) {
        cout<<"Stack elements are:";
        for(int i=top; i>=0; i--)
            cout<<stack[i]<<" ";
        cout<<endl;
    } else
        cout<<"Stack is empty" << endl;
}

//DISPLAY START
//====================================================

void queueDisplay() {
    int ch;

    system("CLS");
    cout << "========================================" << endl;
    cout << "\t\tQueue" << endl;
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

void sortingDisplay() {
    int NUMBER = 0;

    int k=100;
    Book books[k];


    system("CLS");
    int choice;
    do {
        cout << "========================================" << endl;
        cout << "\t\tSorting" << endl;
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
                for (int i = 0; i < NUMBER; ++i)
                {
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

    myFile.open("bookID.txt", ios::in); //read

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
                push(val);
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
    }while (cha != 4);
}



int static Customer[10];
int z = 0;

void addCustomer() {
    fstream customerID;

    cout << "Enter customer ID            : ";
    cin >> Customer[z];
    customerID.open("customerID.txt", ios::app); //append
    if(customerID.is_open()) {
        customerID << "Customer ID : " << Customer[z++];
        customerID.close();
    }
    cout << "Customer Successfully Added!";
}

void searchCustomer() {
    int key,loc;

    cout<<"Enter the key to be searched : ";
    cin>>key;
    for (int i = 0; i< 10; i++)
    {
        if(Customer[i] == key)
        {
            loc = i+1;
            break;
        }
        else
            loc = 0;
    }
    if(loc != 0)
    {
        cout<<"Key found at position "<<loc<<" in the array" << endl;
    }
    else
    {
        cout<<"Could not find given key in the array" << endl;
    }
}

void searchGenre() {
    struct SEARCHbook SB;
    int found;
    char choice;

    do{
        cout << "Customer Name         : ";
        fflush(stdin);
        getline(cin,SB.SEARCHname);
        cout << "Customer Email        : ";
        getline(cin,SB.SEARCHemail);
        cout << "Customer Phone Number : ";
        cin >> SB.SEARCHnoTele;

        cout << "========================================" << endl;
        cout<<endl<<"\t\tChoose The Book Genre" << endl;
        cout << "========================================" << endl;
        cout << "\n[1] Romance";
        cout << "\n[2] Horror";
        cout << "\n[3] Historical";
        cout << "\n[4] Fantasy";
        cout << "\n[5] Magical Realism";
        cout << "\n[6] Science Fiction";
        cout << "\n[7] Mystery"<< endl;


        cout<<"\nEnter genre that customer want [1-7]: ";
        cin>>SB.SEARCHtarget;
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
        cout << "\nCustomer Name              : "<<SB.SEARCHname;
        cout << "\nCustomer Email             : "<<SB.SEARCHemail;
        cout << "\nCustomer Phone Number      : "<<SB.SEARCHnoTele;
        cout << "\nGenre That Customer Choose : "<<SB.SEARCHtarget;

        cout << "\n\nDo you want to continue? (Y/N) ";
        cin >> choice;

    }while(SB.SEARCHtarget<7 && found==1 && choice == 'Y');
}

void skipLines(ifstream& stream, int nLines)
{
    string dummyLine;
    for(int i = 0; i < nLines; ++i)
        getline(stream, dummyLine);
}

void editBookID() {
    ofstream outFile("newID.txt");
    ifstream readFile("myFile.txt");


    string readLine;
    string search;
    string newID;

    cout<<"Enter The Id :: ";
    cin>>search;

    while(getline(readFile,readLine))
    {
        if(readLine == search)
        {
            outFile<<readLine;
            outFile<<endl;

            cout<<"Enter New First Name :: ";
            cin>>newID;

            outFile<<newID<<endl;
            skipLines(readFile, 2);
        }
        else
        {
            outFile<<readLine<<endl;
        }
    }
}

void searchingDisplay() {

    system("CLS");
    int ch;


    cout << "========================================" << endl;
    cout << "\t\t\t\tSearching" << endl;
    cout << "========================================" << endl;

    cout << "[1] Add Customer" << endl;
    cout << "[2] Edit Customer ID" << endl;
    cout << "[3] Search Customer" << endl;
    cout << "[4] Search Genre" << endl;
    cout << "[5] Return to Main Menu" << endl;


    do {
        cout << "\nEnter Choice: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                addCustomer();
                break;
            }
            case 2: {
                editBookID();
                break;
            }
            case 3: {
                searchCustomer();
                break;
            }
            case 4: {
                searchGenre();
                break;
            }
            default: {
                cout << "Invalid Choice" << endl;
            }
        }
    } while (ch != 3);
}

//==============================================
//DISPLAY END

int main() {

    int choice;

    do {
        system("CLS");
        cout << "========================================" << endl;
        cout << "\t\tAdmin Panel" << endl;
        cout << "========================================" << endl;
        cout << "[1] Queue" << endl;
        cout << "[2] Stack" << endl;
        cout << "[3] Sorting" << endl;
        cout << "[4] Searching" << endl;
        cout << "[5] Exit" << endl;

        cout << "\nEnter your choice : ";
        cin >> choice;

        if (choice == 1)
            queueDisplay();
        else if(choice == 2)
            stackDisplay();
        else if(choice == 3)
            sortingDisplay();
        else if(choice == 4)
            searchingDisplay();
        else if(choice == 5) {
            cout << "\nThank you!";
            exit(0);
        }
    }while(choice !=5);


    return 0;
}