#pragma once

#include <string>
using namespace std;

class GroceryItem {
private:
    string _name;
    int _quantity;
    float _unitPrice;
    bool _taxable;

public:
    GroceryItem();
    GroceryItem(const string&, const int&, const float&, const bool&);

    string getName() const;
    void setName(const string&);
    int getQuantity() const;

    void setQuantity(const int&);
    float getUnitPrice() const;
    void setUnitPrice(const float&);
    bool isTaxable() const;
    void setTaxable(const bool&);
};

Groceryitem::GroceryItem()
{

}

Groceryitem::GroceryItem(const string& name, const int& quantity, const float& unitPrice, const bool& taxable){
  _name = name;
  _quantity = quantity;
  _unitPrice = unitPrice;
  _taxable = taxable;
}

string Groceryitem::getName() const{
  return _name;
}
void Groceryitem::setName(const string& name){
  _name = name;
}
int Groceryitem::getQuantity() const{
  return _quantity;
}

void Groceryitem::setQuantity(const int& quantity){
  _quantity = quantity;
}
float Groceryitem::getUnitPrice() const{
  return _unitPrice;
}
void Groceryitem::setUnitPrice(const float& unitPrice){
  _unitPrice = unitPrice;
}
bool Groceryitem::isTaxable() const{

}
void Groceryitem::setTaxable(const bool& taxable){
  _taxable = taxable;
}
