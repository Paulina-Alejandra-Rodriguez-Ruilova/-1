#include <iostream>
using namespace std;

class VendingMachine {
private:
    int cashAvailable;

public:
    VendingMachine() {
        cashAvailable = 500;
    }

    VendingMachine(int initialCash) {
        cashAvailable = initialCash;
    }

    int getBalance() const {
        return cashAvailable;
    }

    void acceptAmount(int amountIn) {
        cashAvailable += amountIn;
    }
};

class ProductDispenser {
private:
    int availableItems;
    int price;

public:
    ProductDispenser() {
        availableItems = 50;
        price = 50;
    }

    ProductDispenser(int items, int priceIn) {
        availableItems = items;
        price = priceIn;
    }

    int getAvailableItems() const {
        return availableItems;
    }

    int getPrice() const {
        return price;
    }

    void sellProduct() {
        availableItems--;
    }
};

void displayMenu() {
    cout << "Welcome to the vending machine!\n";
    cout << "1. Gummies\n";
    cout << "2. Chips\n";
    cout << "3. Candies\n";
    cout << "4. Chocolate\n";
    cout << "Select product, enter number: ";
}

void processSale(ProductDispenser& productDispenser, VendingMachine& cashRegister) {
    int productPrice = productDispenser.getPrice();
    int currentBalance = cashRegister.getBalance();
    int userMoneyInput;

    if (productDispenser.getAvailableItems() > 0) {
        cout << "Product price: " << productPrice << " rubles. Please deposit the money: ";
        cin >> userMoneyInput;

        if (userMoneyInput >= productPrice) {
            if (currentBalance >= userMoneyInput - productPrice) {
                productDispenser.sellProduct();
                cashRegister.acceptAmount(productPrice);
                cout << "Your product has been issued!\n";
                cout << "Your change: " << userMoneyInput - productPrice << " rubles.\n";
            }
            else {
                cout << "There is no way to give out change :(\nPlease deposit a different amount.\n";
            }
        }
        else {
            cout << "Insufficient funds. Please deposit a larger amount.\n";
        }
    }
    else {
        cout << "The product is out of stock :(\n";
    }
}

int main() {
    VendingMachine cashRegister(1000);
    ProductDispenser Gummies(200, 50), Chips(50, 130), Candies(100, 45), Chocolate(25, 70);

    int choice;
    displayMenu();
    cin >> choice;

    switch (choice) {
    case 1:
        processSale(Gummies, cashRegister);
        break;
    case 2:
        processSale(Chips, cashRegister);
        break;
    case 3:
        processSale(Candies, cashRegister);
        break;
    case 4:
        processSale(Chocolate, cashRegister);
        break;
    default:
        cout << "Wrong choice.\n";
        break;
    }

    return 0;
}