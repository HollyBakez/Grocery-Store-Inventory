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
//function prototypes that are created
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
//Default constructor
GroceryItem::GroceryItem()
{

}
//Grocery Store constructor that recieves name, quantity, product price, and taxable from the user
GroceryItem::GroceryItem(const string& name, const int& quantity, const float& unitPrice, const bool& taxable){
  _name = name;
  _quantity = quantity;
  _unitPrice = unitPrice;
  _taxable = taxable;
}
//returns the name when called
string GroceryItem::getName() const{
  return _name;
}
//recieves user input string 'name' and sets it to variable _name
void GroceryItem::setName(const string& name){
  _name = name;
}
//returns the _quantity when called
int GroceryItem::getQuantity() const{
  return _quantity;
}
//recieves user input int 'quantity' and sets it to variable _quantity
void GroceryItem::setQuantity(const int& quantity){
  _quantity = quantity;
}
//returns the unit price when called
float GroceryItem::getUnitPrice() const{
  return _unitPrice;
}
//
void GroceryItem::setUnitPrice(const float& unitPrice){
  _unitPrice = unitPrice;
}
//sets a conditional statement for an item when called whether it is taxable or not
bool GroceryItem::isTaxable() const{
return _taxable;
}
//if the conditional statement bool passes then the taxable value is set to _taxable
void GroceryItem::setTaxable(const bool& taxable){
  _taxable = taxable;
}
