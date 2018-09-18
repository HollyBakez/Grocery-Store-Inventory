#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GroceryItem.h"
using namespace std;

class GroceryInventory {
private:
    vector<GroceryItem> _inventory;
    float _taxRate;

public:
    GroceryInventory();

    GroceryItem& getEntry(const string&);
    void addEntry(const string&, const int&, const float&, const bool&);
    float getTaxRate() const;
    void setTaxRate(const float&);

    void createListFromFile(const string&);
    float calculateUnitRevenue() const;
    float calculateTaxRevenue() const;
    float calculateTotalRevenue() const;

    GroceryItem& operator[](const int&);
};

void GroceryInventory::createListFromFile(const string& filename) {
    ifstream input_file(filename);

    if (input_file.is_open()) {
        cout << "Successfully opened file " << filename << endl;
        string name;
        int quantity;
        float unit_price;
        bool taxable;
        while (input_file >> name >> quantity >> unit_price >> taxable) {
            addEntry(name, quantity, unit_price, taxable);
        }
        input_file.close();
    } else {
        throw invalid_argument("Could not open file " + filename);
    }
}
//Default Constructor GroceryInventory
GroceryInventory::GroceryInventory() {

}

GroceryItem& getEntry(const string&){
  
}

void GroceryInventory::addEntry(const string& name, const int& quantity, const float& unitPrice, const bool& taxable){
  //Since entry is a GroceryItem object it accepts the same parameters
  GroceryItem entry(name, quantity, unitPrice, taxable);
 /*
  entry.setName(name);
  entry.setQuantity(quantity);
  entry.setUnitPrice(unitPrice);
  entry.setTaxable(taxable);
  */
  //Adds the entry to the inventory vector
_inventory.push_back(entry);
}
float GroceryInventory::getTaxRate() const{

}
void GroceryInventory::setTaxRate(const float& taxRate){
  _taxRate = taxRate;

}

float GroceryInventory::calculateUnitRevenue() const {

}

float GroceryInventory::calculateTaxRevenue() const {

}

float GroceryInventory::calculateTotalRevenue() const {

}
