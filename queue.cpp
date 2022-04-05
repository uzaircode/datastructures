#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int queue[100], n = 100, front = - 1, rear = - 1;

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
        cout<<"Customers successfully added" << endl;
    }
}
void Delete() {
    if (front == - 1 || front > rear) {
        cout<<"Queue Underflow ";
        return ;
    } else {
        cout<<"Customers deleted from the first queue" << endl;
        front++;;
    }
}
void Display() {
    if (front == - 1)
        cout<<"Queue is empty"<<endl;
    else {
        cout<<"Queue elements are : ";
        for (int i = front; i <= rear; i++)
            cout<<queue[i]<<" ";
        cout<<endl;
    }
}

int main() {
    int ch;
    cout<<"1) Insert customer to queue"<<endl;
    cout<<"2) Delete customer from queue"<<endl;
    cout<<"3) Display all the customers of queue"<<endl;
    cout<<"4) Exit"<<endl;
    do {
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch (ch) {
            case 1: Insert();
                break;
            case 2: Delete();
                break;
            case 3: Display();
                break;
            case 4: cout<<"Exit"<<endl;
                break;
            default: cout<<"Invalid choice"<<endl;
        }
    } while(ch!=4);
    return 0;
}