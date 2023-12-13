#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class Shape {

public:
    ~Shape() {}
    virtual int get_area() = 0;
};

class Square : public Shape {
public:
    Square(int width_) : width(width_){}
    int get_area() {
        return width * width;
    }
private:
    int width;
};

class Rectangle : public Shape {
public:
    Rectangle(int width_, int length_) : width(width_), length(length_) {}
    int get_area() {
        return width * length;
    }
private:
    int width;
    int length;
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    shapes.emplace_back(new Square(10));
    shapes.emplace_back(new Rectangle(10, 4));
    for (auto &shape : shapes)
        cout << shape->get_area() << endl;

    //Gir utskriften:
    //100
    //40
}