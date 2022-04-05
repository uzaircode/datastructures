#include<iostream>
#include <fstream>
using namespace std;


int main() {
    fstream myFile;
    myFile.open("myFile.txt", ios::out); //write
    if(myFile.is_open()) {
        myFile << "satu\n";
        myFile << "dua\n";
        myFile.close();
    }

    myFile.open("myFile.txt", ios::app); //append (tambah)
    if(myFile.is_open()) {
        myFile << "tiga\n";
        myFile.close();
    }

    myFile.open("myFile.txt", ios::in); //read
    if(myFile.is_open()) {
        string line;
        while(getline(myFile,line)) {
            cout << line << endl;
        }
        myFile.close();
    }

}

