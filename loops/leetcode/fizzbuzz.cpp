#include<iostream>
using namespace std;

int main(){
    int num;
    int counter3 = 0;
    int counter5 = 0;
    

    cout << "number:";
    cin >> num;
    for (int i = 1; i <= num;i++){
        counter3++;
        counter5++;

        if(counter3 == 3 && counter5 == 5){
            cout << "FizzBuzz" << endl;
            counter3 = 0;
            counter5 = 0;
        }
        else if(counter3 == 3){
            cout << "Fizz" << endl;
            counter3 = 0;
        }
        else if(counter5 == 5){
            cout << "Buzz" << endl;
            counter5 = 0;
        }
        else{
            cout << i << endl;
        }
        
    }

    return 0;
}