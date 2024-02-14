#include <iostream>

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister() : cashOnHand(500) {}
    cashRegister(int initialCash) : cashOnHand(initialCash) {}

    int getCurrentBalance() const {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int typeCost;

public:
    dispenserType() : numberOfItems(50), typeCost(10) {}
    dispenserType(int noOfItems, int cost) : numberOfItems(noOfItems), typeCost(cost) {}

    int getNoOfItems() const {
        return numberOfItems;
    }

    int getCost() const {
        return typeCost;
    }

    void makeSale() {
        numberOfItems--;
    }
};

void showSelection(const dispenserType& dispenser) {
    std::cout << "Product: " << dispenser.getNoOfItems() << " items, Cost: " << dispenser.getCost() << " rubles" << std::endl;
}

void sellProduct(dispenserType& dispenser, cashRegister& cashRegister) {
    int cost = dispenser.getCost();
    int cash = cashRegister.getCurrentBalance();

    if (dispenser.getNoOfItems() > 0) {
        std::cout << "You have chosen this product. The cost is " << cost << " rubles." << std::endl;
        std::cout << "Please insert " << cost << " rubles." << std::endl;

        int amount;
        std::cin >> amount;

        if (amount >= cost) {
            cashRegister.acceptAmount(amount);
            dispenser.makeSale();
            std::cout << "You have successfully bought this product, thank you!" << std::endl;
        }
        else {
            std::cout << "You have not inserted enough money. Please try again." << std::endl;
        }
    }
    else {
        std::cout << "This product is out of stock. Please try another product." << std::endl;
    }
}

int main() {
    dispenserType dispenser1(10, 20);
    dispenserType dispenser2(8, 10);
    dispenserType dispenser3(2, 5);

    cashRegister cashRegister1;

    while (true) {
        std::cout << "Welcome to the vending machine!" << std::endl;
        std::cout << "Please choose a product:" << std::endl;
        std::cout << "1. Candy" << std::endl;
        std::cout << "2. Chips" << std::endl;
        std::cout << "3. Gum" << std::endl;
        std::cout << "4. Cookies" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            showSelection(dispenser1);
            sellProduct(dispenser1, cashRegister1);
            break;
        case 2:
            showSelection(dispenser2);
            sellProduct(dispenser2, cashRegister1);
            break;
        case 3:
            showSelection(dispenser3);
            sellProduct(dispenser3, cashRegister1);
            break;
        case 4:
            showSelection(dispenser2);
            sellProduct(dispenser2, cashRegister1);
            break;
        case 5:
            std::cout << "Thank you for using the vending machine! Have a nice day!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
}