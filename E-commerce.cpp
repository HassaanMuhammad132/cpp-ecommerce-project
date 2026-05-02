#include <iostream>
#include <string>
using namespace std;

// Function for login  ( 1st function )	
void login(string &email)
{
    int pass;

    while (true) // repeat until login is successful
    {
        cout << "Enter your email here: ";
        cin >> email;
        cout<<endl;

        if (email == "example@gmail.com")
        {
            while (true) // loop until password is correct
            {
                cout << "Enter your password here: ";
                cin >> pass;

                if (pass == 1111)
                {
                    cout << "\nYou have entered your daraz account!\n\n";
                    return; // exit function on successful login
                }
                else
                {
                    cout << "Password incorrect. Try again.\n";
                }
            }
        }
        else
        {
            cout << "Email not found. Try again.\n";
        }
    }
}

// Function for product selection ( 2nd function )

void selectProducts(string &tproduct, int &tquantity, int &totalbill)
{
    string product;
    int price, quantity, bill;
    char otherp;

    do
    {
        // Loop until a valid product is entered
        while (true)
        {
            cout << "Which product do you want to buy?\n";
            cout << "Chair, Table, Laptop, Mobile, Cloths: ";
            cin >> product;
            cout<<endl;

            if (product == "chair" || product == "Chair" || product == "CHAIR")
            {
                price = 2000;
                break;
            }
            else if (product == "table" || product == "Table" || product == "TABLE")
            {
                price = 5000;
                break;
            }
            else if (product == "laptop" || product == "Laptop" || product == "LAPTOP")
            {
                price = 15000;
                break;
            }
            else if (product == "mobile" || product == "Mobile" || product == "MOBILE")
            {
                price = 30000;
                break;
            }
            else if (product == "cloths" || product == "Cloths" || product == "CLOTHS")
            {
                price = 1000;
                break;
            }
            else
            {
                cout << "Product not available. Please enter a valid product.\n";
                cout<<endl;
            }
        }

        // Loop until valid quantity  ( 3rd function )
        while (true)
        {
            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity > 0)
                break;
            else
                cout << "Quantity must be positive. Try again.\n";
        }

        // Calculate bill
        bill = price * quantity;
        tquantity += quantity;
        totalbill += bill;
        tproduct = tproduct + product + " ";

        cout << "Bill for " <<quantity << product << ": " << bill << endl<<endl;

        cout << "Do you want to buy another product? (y/n): ";
        cin >> otherp;
        cout<<endl;

    } while (otherp == 'y' || otherp == 'Y');
}

// Function for payment ( 4rd function )

bool paymentProcess(string &payment)
{
    string pin;
    int attempts = 0;

    while (true) // loop until valid payment method
    {
        cout << "\nPlease confirm payment method.\n";
        cout << "Jazzcash, Easypaisa, Bank: ";
        cin >> payment;
        cout<<endl;

        if (payment == "jazzcash" || payment == "easypaisa" || payment == "bank")
            break;
        else
            cout << "Invalid payment method. Try again.\n";
    }

    while (attempts < 3) // pin verification loop
    {
        cout << "Enter pin (3 tries only): ";
        cin >> pin;

        if (pin == "2222")
            return true;
        else
        {
            attempts++;
            if (attempts == 3)
            {
                cout << "Account blocked due to too many attempts.\n";
                return false;
            }
            else
                cout << "Wrong pin. Try again.\n";
        }
    }

    return false;
}

// Function for order summary ( 5th function )	

void orderSummary(string email, string tproduct, int tquantity, string payment, int totalbill)
{
    cout << "\nSummary of your order:\n"<<endl;
    cout << "Email: " << email << endl;
    cout << "Products: " << tproduct << endl;
    cout << "Total Quantity: " << tquantity << endl;
    cout << "Total Bill: " << totalbill << endl;
    cout << "Payment method: " << payment << endl;
    cout << "Status: Confirmed\n"<<endl;
    cout << "Your order will arrive soon!\n\n";
}

int main()  // ( 6th main function )
	{
    char restart;

    do
    {
        string email, payment;
        string tproduct = "";
        int tquantity = 0;
        int totalbill = 0;

        // Login loop inside function now handles retries
        login(email);

        // Product selection
        selectProducts(tproduct, tquantity, totalbill);
        cout << "------------------------\n";
        cout << "Bill for " << tquantity << " " << tproduct << ": " << totalbill << endl;
        cout << "------------------------\n";

        // Payment
        if (paymentProcess(payment))
        {
            orderSummary(email, tproduct, tquantity, payment, totalbill);
        }

        cout << "Do you want to start a new order? (y/n): ";
        cin >> restart;

    } while (restart == 'y' || restart == 'Y');

    cout << "Thank you for shopping with us!\n";

    return 0;
}
