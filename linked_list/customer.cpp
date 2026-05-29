#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Customer Node Structure
struct Customer
{
    int code;
    string name;
    string dob;
    int balance;
    Customer *next;
};

// Transaction Node Structure
struct Transaction
{
    int id;
    int customerCode;
    string type;
    int amount;
    string date;
    Transaction *next;
};

Customer *customerHead = nullptr;
Transaction *transactionHead = nullptr;
int transactionID = 1; // AUTO_INCREMENT

string getCurrentDateTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

void addCustomer()
{

    Customer *newCustomer = new Customer;
    cout << "Enter Customer Code: ";
    cin >> newCustomer->code;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newCustomer->name);

    cout << "Enter Date of Birth (dd/mm/yyyy): ";
    getline(cin, newCustomer->dob);

    cout << "Enter Initial Balance: ";
    cin >> newCustomer->balance;

    newCustomer->next = nullptr;
    if (customerHead == nullptr)
    {
        customerHead = newCustomer;
    }
    else
    {
        Customer *temp = customerHead;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newCustomer;
    }

    cout << "Customer added successfully! 🎉🎉🎉\n";
}

// Function to view customers
void viewCustomers()
{
    if (customerHead == nullptr)
    {
        cout << "No customers available. \n";
        return;
    }

    Customer *temp = customerHead;
    while (temp != nullptr)
    {
        cout << "Code: " << temp->code << ", Name: " << temp->name << ", DOB: " << temp->dob
             << ", Balance: " << temp->balance << "\n";
        temp = temp->next;
    }
}

// Find a customer
Customer *findCustomer(int code)
{
    Customer *temp = customerHead;
    while (temp != nullptr)
    {
        if (temp->code == code)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Function to record a transaction
void recordTransaction(int customerCode, string type, int amount)
{
    Transaction *newTransaction = new Transaction;
    newTransaction->id = transactionID++;
    newTransaction->customerCode = customerCode;
    newTransaction->type = type;
    newTransaction->amount = amount;
    newTransaction->date = getCurrentDateTime();
    newTransaction->next = nullptr;

    if (transactionHead == nullptr)
    {
        transactionHead = newTransaction;
    }
    else
    {
        Transaction *temp = transactionHead;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newTransaction;
    }
}

// Function to withdraw money
void withdraw()
{
    int code;
    int amount;
    cout << "Enter Customer Code: ";
    cin >> code;
    Customer *customer = findCustomer(code);

    if (customer == nullptr)
    {
        cout << "Customer not found!\n";
        return;
    }

    cout << "Enter Amount to Withdraw: ";
    cin >> amount;

    if (amount > customer->balance)
    {
        cout << "Insufficient balance!\n";
        return;
    }

    customer->balance -= amount;
    recordTransaction(code, "Withdrawal", amount);
    cout << "Withdrawal successful! 🎉🎉🎉 New Balance: " << customer->balance << "\n";
}

// Function to deposit money
void deposit()
{
    int code;
    int amount;
    cout << "Enter Customer Code: ";
    cin >> code;

    Customer *customer = findCustomer(code);
    if (customer == nullptr)
    {
        cout << "Customer not found!\n";
        return;
    }

    cout << "Enter Amount to Deposit: ";
    cin >> amount;

    customer->balance += amount;
    recordTransaction(code, "Deposit", amount);
    cout << "Deposit successful! 🎉🎉🎉 New Balance: " << customer->balance << "\n";
}

// Function to check balance
void checkBalance()
{
    int code;
    cout << "Enter Customer Code: ";
    cin >> code;
    Customer *customer = findCustomer(code);

    if (customer == nullptr)
    {
        cout << "Customer not found!\n";
        return;
    }

    cout << "Current Balance: " << customer->balance << "\n";
}

// Main menu
void menu()
{
    int choice;

    do
    {
        cout << "\nMoney Management System\n";
        cout << "1. Add Customer\n";
        cout << "2. View Customers\n";
        cout << "3. Withdraw\n";
        cout << "4. Deposit\n";
        cout << "5. Check Balance\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addCustomer();
            break;
        case 2:
            viewCustomers();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            deposit();
            break;
        case 5:
            checkBalance();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 6);
}

int main()
{
    menu();
    return 0;
}