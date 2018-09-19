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

GroceryItem& GroceryInventory::getEntry(const string& item){
        for(int i=0; i < _inventory.size(); i++)
        {
                if(_inventory[i].getName() == item)
                {
                        return _inventory[i];
                }


        }
        throw range_error("Error item entry was not found");
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
float GroceryInventory::getTaxRate() const {
        return _taxRate;
}
void GroceryInventory::setTaxRate(const float& taxRate){
        _taxRate = taxRate;

}

float GroceryInventory::calculateUnitRevenue() const {
//unitprice * quantity
float revenue;
for(int j = 0; j < _inventory.size(); j++)
{
  float total;
  total = _inventory[j].getUnitPrice() * _inventory[j].getQuantity();

  revenue +=total;
}
return revenue;

}


float GroceryInventory::calculateTaxRevenue() const {
//total = unitprice * quantity if the item is taxable , then it will be multiplied by the taxrate
//taxRev += total
  float revenue;
for (int i = 0; i < _inventory.size(); i++) {
  float total;

  if(_inventory[i].isTaxable())
  {
    total = _inventory[i].getQuantity() * _inventory[i].getUnitPrice() * ( getTaxRate() * .01);
    revenue += total;
  }

}
return revenue;
}

float GroceryInventory::calculateTotalRevenue() const {

  return calculateTaxRevenue() + calculateUnitRevenue();
}

GroceryItem& GroceryInventory::operator[](const int& entryhead) {
  return _inventory[entryhead];
}
