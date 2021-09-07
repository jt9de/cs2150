
/*
 * Filename: mathfun.cpp
 * Author: Jinghui Tian
 * Date: 4.13.2020
 */

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product(int, int);
extern "C" int power(int, int);


int  main () {
    int int_1;
    int int_2;
    int product_answer;
    int power_answer;

    cout << "Enter integer 1: ";
    cin >> int_1;
    cout << "Enter integer 2: ";
    cin >> int_2;

    product_answer = product(int_1, int_2);
    power_answer = power(int_1, int_2);
    cout << "Product:  " << product_answer << endl;
    cout << "Power: " << power_answer << endl;
    return 0;

    }

  
