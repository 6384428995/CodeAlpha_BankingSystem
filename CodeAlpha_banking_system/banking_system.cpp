#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* ---------------- TRANSACTION CLASS ---------------- */
class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};

/* ---------------- CUSTOMER CLASS ---------------- */
class Customer {
public:
    string name;
    int customerID;

    Customer(string n, int id) {
        name = n;
        customerID = id;
    }
};

/* ---------------- ACCOUNT CLASS ---------------- */
class Account {
private:
    int accountNumber;
    double balance;
    Customer customer;
    vector<Transaction> transactions;

public:
    Account(int accNo, Customer cust)
        : accountNumber(accNo), customer(cust), balance(0.0) {}

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposit successful!\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }
        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdraw", amount));
        cout << "Withdrawal successful!\n";
    }

    void displayBalance() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name: " << customer.name << endl;
        cout << "Current Balance: ₹" << balance << endl;
    }

    void showTransactions() {
        if (transactions.empty()) {
            cout << "No transactions available.\n";
            return;
        }
        cout << "\n--- Transaction History ---\n";
        for (auto &t : transactions) {
            cout << t.type << " : ₹" << t.amount << endl;
        }
    }
};

/* ---------------- MAIN FUNCTION ---------------- */
int main() {
    int choice;
    int accountNumber = 1001;
    int customerID = 1;
    Account* account = nullptr;

    while (true) {
        cout << "\n====== BANKING SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (account != nullptr) {
                cout << "Account already exists!\n";
                break;
            }
            string name;
            cout << "Enter customer name: ";
            cin >> name;

            Customer cust(name, customerID++);
            account = new Account(accountNumber++, cust);
            cout << "Account created successfully!\n";
            break;
        }

        case 2: {
            if (!account) {
                cout << "Create an account first!\n";
                break;
            }
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account->deposit(amount);
            break;
        }

        case 3: {
            if (!account) {
                cout << "Create an account first!\n";
                break;
            }
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account->withdraw(amount);
            break;
        }

        case 4:
            if (account)
                account->displayBalance();
            else
                cout << "Create an account first!\n";
            break;

        case 5:
            if (account)
                account->showTransactions();
            else
                cout << "Create an account first!\n";
            break;

        case 6:
            cout << "Thank you for using Banking System!\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
