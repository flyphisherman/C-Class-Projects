/***********************
Name: Single Item Ordering
Author: Zach Thompson
Version: 1.0 4/20/2019
Purpose: To be able to order an amount of a single item
Variables:
    itemName As String
    itemPrice As Float
    numberOfItems As Int
************************/

#include <iostream>
#include <string>

using namespace std;

// Here is the class.  I have set the variables as private and used functions to get to them
class ShopItemOrder {
    public:
        ShopItemOrder();
        setItemName(string itemName);
        string getItemName();
        setItemPrice(float itemPrice);
        float getItemPrice();
        setNumberOfItems(int numberOfItems);
        int getNumberOfItems();
    private:
        string itemName;
        float itemPrice;
        int numberOfItems;
};

// Here is the list of functions for my class
ShopItemOrder::ShopItemOrder() {
    cout << "Class made:" << endl;
}

ShopItemOrder::setItemName(string itemName) {
    this->itemName = itemName;
}

ShopItemOrder::setItemPrice(float itemPrice) {
    this->itemPrice = itemPrice;
}

ShopItemOrder::setNumberOfItems(int numberOfItems) {
    this->numberOfItems = numberOfItems;
}

string ShopItemOrder::getItemName() {
    return this->itemName;
}

float ShopItemOrder::getItemPrice() {
    return this->itemPrice;
}

int ShopItemOrder::getNumberOfItems() {
    return this->numberOfItems;
}

int main()
{
    // Here is the main program
    // Setting up the variables
    string itemName;
    float itemPrice, totalPrice;
    int numberOfItems;
    ShopItemOrder order;

    // Getting the user input
    cout << "What item would you like to buy: ";
    getline(cin, itemName);
    order.setItemName(itemName);
    cout << "What is the price of " << itemName << ": ";
    cin >> itemPrice;
    order.setItemPrice(itemPrice);
    cout << "How many of " << itemName << " would you like to buy at $" << itemPrice << ": ";
    cin >> itemPrice;
    order.setNumberOfItems(itemPrice);

    // Printing out the receipt
    cout << "\n\n\t\t\tOrder" << endl << endl;
    cout << "\tItem\tNumber of Items\t\tPrice" << endl << "\t";
    for (int i = 0; i <= 40; i++) {
        cout << "-";
    }
    cout << endl;
    cout << "\t" << order.getItemName() << "\t" << order.getNumberOfItems() << "\t\t\t" << order.getItemPrice() << endl << endl;
    totalPrice = order.getNumberOfItems() * order.getItemPrice();
    cout << "\t\t\tFinal Price: $" << totalPrice << endl;

    return 0;
}
