#include <iostream>

using namespace std;

const double tax_percent = 25;
class Commodity {
public:
    Commodity(const string &name_, int id_, double price_);
    const string &get_name() const;
    int get_id() const;
    double get_price(double units = 1) const;
    void set_price(double price_);
    double get_price_with_sales_tax(double units = 1) const;

private:
    string name;
    int id;
    double price;
};

Commodity::Commodity(const string &name_, int id_, double price_) : name(name_), id(id_), price(price_) {}
const string &Commodity::get_name() const {
    return name;
}
int Commodity::get_id() const {
    return id;
}

double Commodity::get_price(double units_) const {
    return units_*price;
}

void Commodity::set_price(double price_) {
    price = price_;
}

double Commodity::get_price_with_sales_tax(double units_) const {
    double taxed_price = price + (price*(tax_percent/100));
    return units_*taxed_price;
}
