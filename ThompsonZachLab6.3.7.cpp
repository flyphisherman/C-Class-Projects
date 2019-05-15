/***********************
Name: IP Address Checker
Author: Zach Thompson
Version: 1.0 4/25/2019
Purpose: To check if an IP Address is valid
Comments: I have not put in catches for reserved IP Addresses
Variables:
    address As String
    ipCorrect As Boolean
    periodLocation As Int
    ptrLocation As Int
    numberFound As Int
    number As Int
    addressSegments As Int
    tempNumber As Int
************************/

#include <iostream>
#include <string>

using namespace std;

// This is the base IP Address class
class IPAddress {
    public:
        IPAddress(string address = "0.0.0.0");
        IPAddress(IPAddress &source);
        void print() {
            cout << address << endl;
        }
    private:
        string address = "0.0.0.0";
};

IPAddress::IPAddress(string address) {
    this->address = address;
}

IPAddress::IPAddress(IPAddress &source) {
    this->address = source.address;
}

// This is the IP Address class for when it is checked
class IPAddressChecked: public IPAddress {
    public:
        IPAddressChecked(string address);
        IPAddressChecked(IPAddressChecked &source);
        void print();
    private:
        string address = "0.0.0.0";
        bool ipCorrect = true;
};

void IPAddressChecked::print() {
    cout << address;
    if (ipCorrect) {
        cout << " - Correct" << endl;
    }
    else {
        cout << " - Not Correct" << endl;
    }
}

// I check to see if the address is a valid IP Address at this point.
IPAddressChecked::IPAddressChecked(string address) {
    this->address = address;
    int periodLocation = address.find(".");
    int ptrLocation = 0;
    int numberFound = 0;
    int number;
    int addressSegments[4] = { };
    while (numberFound < 4) {
        number = 0;
        if (periodLocation > (ptrLocation + 1)) {
            while (periodLocation > ptrLocation) {
                int tempNumber = address.at(ptrLocation) - '0';
                ptrLocation++;
                number = (number * 10) + tempNumber;
            }
        }
        else if (numberFound = 3) {
            if (address.length() > (ptrLocation + 1)) {
                while (address.length() > ptrLocation) {
                    int tempNumber = address.at(ptrLocation) - '0';
                    ptrLocation++;
                    number = (number * 10) + tempNumber;
                }
            }
            else {
                number = address.at(ptrLocation) - '0';
            }
        }
        else {
            number = address.at(ptrLocation) - '0';
        }
        addressSegments[numberFound] = number;
        numberFound++;
        if (numberFound < 3) {
            ptrLocation = periodLocation + 1;
            periodLocation = address.find(".", periodLocation + 1);
        }
        else {
            ptrLocation = periodLocation + 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (addressSegments[i] >= 0 && addressSegments[i] <= 255 && ipCorrect) {
            this->ipCorrect = true;
        }
        else {
            this->ipCorrect = false;
        }
    }
}

int main()
{
    // We ask for the user to enter the IP addresses and then check them
    cout << "First IP Address: ";
    string address = "";
    getline(cin, address);
    IPAddress newAddress(address);
    cout << "Second IP Address: ";
    getline(cin, address);
    IPAddressChecked newAddressChecked(address);
    cout << "Third IP Address: ";
    getline(cin, address);
    IPAddressChecked newAddressChecked2(address);
    newAddress.print();
    newAddressChecked.print();
    newAddressChecked2.print();
    return 0;
}
