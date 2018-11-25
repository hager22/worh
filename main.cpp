#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "bigint.h"

using namespace std;

bigint num1,num2;

int main()
{
     bigint num3,num4;
     string FileName, UserNum,UserNum0[2],UserNum1;
     cout <<"please enter number1 "<<endl;
        cin >>UserNum1;
        if(UserNum1.size()<9)
          {
              int n;
              n= atoi(UserNum1.c_str()) ;    //fn to convert string int integer
              num1=bigint (n);
          }
        else
          {
              num1=bigint(UserNum1);
          }


        cout <<"please enter number2 "<<endl;
        cin >>UserNum;
        if(UserNum.size()<9)
          {
              int n;
              n= atoi(UserNum.c_str()) ;  //fn to convert string int integer

              num2=bigint (n);
          }
           else
          {
              num2=bigint(UserNum);
          }


        num3=num1+(num2);
        cout <<"number1 + number2 =  "<<num3.getnum()<<endl;
        num4= num1-(num2);
        cout  <<"number2 - number1 =  "<<num4.getnum()<<endl;
        cout  <<"check if number1==number2  "<<(num1==num2)<<endl;
        //num3=num1;
        //cout<<"number3 =number 1 and print number 3 "<<num3<<endl;

    return 0;
}
