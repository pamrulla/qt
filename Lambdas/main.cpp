#include <iostream>

using namespace std;

int main()
{
    /*
     * [capute list](parameters)->return_type{};
     */
    auto funct = [](){
        cout << "Calling explicitly" << endl;
    };
    funct();

    [](){
            cout << "Calling implicitly" << endl << endl;
        }();

    //Parameters
    cout << "Calling with Parameters" << endl;
    [](int a, int b){
        cout << "The Sum : " << (a+b) << endl << endl;
    }(3, 7);

    //Return type
    cout << "Calling with Parameters and Return " << endl;
    cout << "The Sum : " <<
            [](int a, int b)->int{
                return (a+b);
            }(3, 7)
    << endl << endl;

    //Capturing Variables
    int x = 10;
    int y = 56;
    cout << "Calling with Capturing x and y" << endl;
    [x, y]() {
        cout << "The Sum : " << (x+y) << endl << endl;
    }();

    cout << "Calling with copy by value capture" << endl;
    x = 11;
    auto func1 = [x]() {
        cout << "Inner X is " << x << endl;
    };
    for(auto i = 1; i <= 5; ++i) {
        cout << "Outer X is " << x << endl;
        func1();
        x++;
    }
    cout  << endl;

    cout << "Calling with copy by reference capture" << endl;
    x = 11;
    auto func2 = [&x]() {
        cout << "Inner X is " << x << endl;
    };
    for(auto i = 1; i <= 5; ++i) {
        cout << "Outer X is " << x << endl;
        func2();
        x++;
    }
    cout << endl;

    cout << "Capture all copy by value" << endl;
    x = 11;
    [=]() {
        cout << "The Sum is " << (x+y) << endl << endl;
    }();

    cout << "Capture all copy by reference" << endl;
    x = 11;
    [&]() {
        cout << "The Sum is " << (x+y) << endl << endl;
    }();

    return 0;
}
