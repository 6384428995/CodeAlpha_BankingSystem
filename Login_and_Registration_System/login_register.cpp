#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* ---------- FUNCTION TO REGISTER USER ---------- */
void registerUser() {
    string username, password;
    cout << "\n--- User Registration ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    string u, p;

    while (infile >> u >> p) {
        if (u == username) {
            cout << "Username already exists! Try another.\n";
            infile.close();
            return;
        }
    }
    infile.close();

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration successful!\n";
}

/* ---------- FUNCTION TO LOGIN USER ---------- */
void loginUser() {
    string username, password;
    cout << "\n--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    string u, p;
    bool found = false;

    while (infile >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    infile.close();

    if (found)
        cout << "Login successful! Welcome " << username << ".\n";
    else
        cout << "Invalid username or password!\n";
}

/* ---------- MAIN FUNCTION ---------- */
int main() {
    int choice;

    while (true) {
        cout << "\n===== LOGIN & REGISTRATION SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Thank you for using the system!\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
