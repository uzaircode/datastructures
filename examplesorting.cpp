#include <iostream>
#include<stdlib.h>
using namespace std;

// Struct
struct Book
{
    char name[100];
    char author[100];
    float price;
    float id;
};


// Gets Book Information
Book GetBook()
{
    Book temp;
    cout << "Enter the following information of the book: " << endl;
    cout << "Name: ";
    fflush(stdin);
    cin.getline(temp.name, 100);
    fflush(stdin);
    cout << "Author: ";
    cin.getline(temp.author, 100);
    cout << "Price: ";
    cin >> temp.price;
    cout << "ID: ";
    cin >> temp.id;
    cin.get();
    return temp;
}


//Sorts the books by Price
void SortBookPrice( Book books[], int num )
{
    int i, j;
    cout << "Here is a list of your books sorted by Price: " << endl;
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
void SortBookTitle( Book books[], int num )
{
    int i, j;
    cout << "\nHere is a list of your book sorted by Title: " << endl;
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
void OutputBooks( Book books[], int num )
{
    cout << endl;
    for(int i=0;i<num;++i)
    {
        cout << "Book Information: " << endl;
        cout << "Name: " << books[i].name << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Price: " << books[i].price << endl;
        cout << endl;
    }
}



const int NUMBER = 3;
int main()
{
    int choice = 0;

    Book books[NUMBER];

    cout << "\n\n1. ADD BOOK";
    cout << "\n2. UPDATE BOOK";
    cout << "\n3. DELETE BOOK";
    cout << "\n4. CHECK PARTICULAR BOOK";
    cout << "\n5. DISPLAY BOOKS";
    cout << "\n7. SORTS THE BOOKS BY PRICE";
    cout << "\n8. EXIT";

    cout << "\n\nEnter your choice: ";
    cin >> choice;

    while (choice != 8)
    {
        if (choice == 1) {
            for(int i=0;i<NUMBER;++i)
                books[i]=GetBook();
        } else if(choice == 6) {
            SortBookTitle(books, NUMBER);
            OutputBooks(books, NUMBER);
        } else if(choice == 7) {
            SortBookPrice(books, NUMBER);
            OutputBooks(books, NUMBER);
        }
        else if(choice == 8) {
            exit(0);
        }



        cout << "\n\nEnter your choice: ";
        cin >> choice;
    }

    do {
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                for(int i=0;i<NUMBER;++i)
                    books[i]=GetBook();
                break;
            case 6:
                SortBookTitle(books, NUMBER);
                OutputBooks(books, NUMBER);
                break;
            case 7:
                SortBookPrice(books, NUMBER);
                OutputBooks(books, NUMBER);
                break;
            case 4: cout<<"Exit"<<endl;
                break;
            default: cout<<"Invalid choice"<<endl;
        }
    } while(choice!=4);













}