#ifndef BIGINT_H
#define BIGINT_H
#include <string.h>
#include <cstring>
#include <iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include <sstream> //to can convert number from string to integer
using namespace std;

class bigint
{
     private:
        string number;

    public:
        int len;
        bool check;         //check if numbers equal or not
        bool check0;        //check if number1 > number2 or number1 < number2
        bigint();
        bigint( string n1);
        bigint( int n2);
        void calc_len ( string &n1);
        void setnum (string num2);
        string getnum ();
        bigint operator+ (bigint &n1);
        bigint operator- (bigint &n1);
        bigint operator= (bigint n1);
        bool operator==  (bigint &n1);
        friend ostream& operator<<( ostream&out, bigint & n1)  ;

        virtual ~bigint();


    protected:


};

#endif // BIGINT_H
