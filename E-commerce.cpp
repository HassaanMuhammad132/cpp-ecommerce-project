#include <iostream>
#include <string>
using namespace std;

// UI LINE FUNCTION
void line()
{
    cout << "-------------------------------------------\n";
}

// LOGIN FUNCTION
void login(string &email)
{
    int pass;

    while (true)
    {
        line();
        cout << "           LOGIN SYSTEM\n";
        line();

        cout << "Enter your email here: ";
        cin >> email;
        cout << endl;

        if (email == "example@gmail.com")
        {
            while (true)
            {
                cout << "Enter your password here: ";
                cin >> pass;

                if (pass == 1111)
                {
                    cout << "\nLogin Successful! Welcome\n\n";
                    return;
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

// PRODUCT SELECTION
void selectProducts(string &tproduct, int &tquantity, int &totalbill)
{
    string choice;
    int price, quantity, bill;
    char otherp;
    string product;

    do
    {
        while (true)
        {
            line();
            cout << "            PRODUCT MENU\n";
            line();

            cout << "1. Chair   (2000)\n";
            cout << "2. Table   (5000)\n";
            cout << "3. Laptop  (15000)\n";
            cout << "4. Mobile  (30000)\n";
            cout << "5. Cloths  (1000)\n";
            line();

            cout << "Enter your choice (1-5): ";
            cin >> choice;
            cout << endl;

            if (choice == "1") { product = "Chair"; price = 2000; break; }
            else if (choice == "2") { product = "Table"; price = 5000; break; }
            else if (choice == "3") { product = "Laptop"; price = 15000; break; }
            else if (choice == "4") { product = "Mobile"; price = 30000; break; }
            else if (choice == "5") { product = "Cloths"; price = 1000; break; }
            else
            {
                cout << "Invalid choice. Please select between 1-5.\n\n";
            }
        }

        while (true)
        {
            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity > 0)
                break;
            else
                cout << "Quantity must be positive. Try again.\n";
        }

        bill = price * quantity;
        tquantity += quantity;
        totalbill += bill;
        tproduct = tproduct + product + " ";

        line();
        cout << " Added to Cart\n";
        line();
        cout << product << " x " << quantity << " = " << bill << endl;
        line();

        cout << "Do you want to buy another product? (y/n): ";
        cin >> otherp;
        cout << endl;

    } while (otherp == 'y' || otherp == 'Y');
}

// PAYMENT FUNCTION
bool paymentProcess(string &payment)
{
    string pin;
    int attempts = 0;

    while (true)
    {
        line();
        cout << "          PAYMENT METHOD\n";
        line();

        cout << "1. Bank\n";
        cout << "2. JazzCash\n";
        cout << "3. EasyPaisa\n";
        line();

        cout << "Enter your choice (1-3): ";
        cin >> payment;
        cout << endl;

        if (payment == "1") { payment = "bank"; break; }
        else if (payment == "2") { payment = "jazzcash"; break; }
        else if (payment == "3") { payment = "easypaisa"; break; }
        else
        {
            cout << "Invalid choice. Please select between 1-3.\n";
        }
    }

    while (attempts < 3)
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

// ORDER SUMMARY
void orderSummary(string email, string tproduct, int tquantity, string payment, int totalbill)
{
    line();
    cout << "          ORDER SUMMARY\n";
    line();

    cout << "Email: " << email << endl;
    cout << "Products: " << tproduct << endl;
    cout << "Total Quantity: " << tquantity << endl;
    cout << "Total Bill: " << totalbill << endl;
    cout << "Payment method: " << payment << endl;

    line();
    cout << "Status: Confirmed\n";
    cout << "Your order will arrive soon!\n";
    line();
}

// MAIN FUNCTION
int main()
{
    char restart;

    do
    {
        string email, payment;
        string tproduct = "";
        int tquantity = 0;
        int totalbill = 0;

        login(email);

        selectProducts(tproduct, tquantity, totalbill);

        line();
        cout << "            FINAL BILL\n";
        line();

        cout << "Total Items: " << tquantity << endl;
        cout << "Total Bill: " << totalbill << endl;
        line();

        if (paymentProcess(payment))
        {
            orderSummary(email, tproduct, tquantity, payment, totalbill);
        }

        cout << "Do you want to start a new order? (y/n): ";
        cin >> restart;

    } while (restart == 'y' || restart == 'Y');

    cout << "\n========================================\n";
    cout << "     Thank you for shopping with us!\n";
    cout << "========================================\n";

    return 0;
}
