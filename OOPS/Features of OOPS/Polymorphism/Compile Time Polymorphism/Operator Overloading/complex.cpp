#include<iostream>
#include<string>
using namespace std;

class Complex {
    int real;
    int img;
public:
    Complex(int r, int i) {
        real = r;
        img = i;
    }
    void showValues() {
        cout << real << " + " << img << "i \n";
    }
    //Operator overloading
    Complex operator + (Complex& c2) {
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;

        Complex res(resReal, resImg);
        return res;
    }
};

int main() {
    Complex c1(2, 4);
    Complex c2(5, 3);

    c1.showValues();
    c2.showValues();
    Complex c3 = c1 + c2;

    cout << "Result: ";
    c3.showValues();

    return 0;
}