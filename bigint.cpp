#include "bigint.h"

bigint::bigint()
{
    //ctor
}
bigint::bigint(string n1 )
{
     number=n1;
}
bigint::bigint (int decInt)
{
    cout <<"this is DecimalInt (int ) "<<endl;
    stringstream ss ;
    ss<<decInt ;
    string Num =ss.str() ;//this fn convert int to string
    number=Num;
}
bigint::~bigint()
{
    //dtor
}
void bigint::setnum (string num2)
{
    number=num2;
}
string bigint::getnum ()
{
    return(number);
}
void bigint::calc_len ( string &n1)
{
    if (number.size() > n1.size())
    {
        while (number.size()>n1.size())
            n1.insert(0,"0");              //to add 0's but in the left

    }
        if (number.size() < n1.size())
    {
        while (n1.size()>number.size())
            number.insert(0,"0");
    }
}
bigint bigint::operator+ (bigint &n1)  //to sum 2 number
{
    string result;
    int z=0;        //remainder  add to next number
    int sum=0;
    int remainder;
    len=number.size();
    bigint number1 , number2;
    string num1,num2;
    int Plus[len-1];

            /***************************if number1 & number2 = -ve number*******************/
            if ( (number.at(0)=='-') && (n1.getnum().at(0)=='-') )
            {
                //save number without -
               for (int j=1 ; j<n1.getnum().size() ;j++)
                {
                    num2+=n1.getnum().at(j);

                }
                number2.setnum(num2);
                for (int j=1 ; j<number.size() ;j++)
                {
                    num1+=number.at(j);
                }
                number1.setnum(num1);

                //make the two numbers with same size
                if (number1.getnum().size() > number2.getnum().size())
                {
                 while (number1.getnum().size() > number2.getnum().size())
                    num2.insert(0,"0");              //to add 0's but in the left
                 number2.setnum(num2);
                }
                if (number1.getnum().size() < number2.getnum().size())
                {
                  while (number2.getnum().size()>number1.getnum().size())
                    num1.insert(0,"0");
                  number1.setnum(num1);
                }
                cout <<number1.getnum()<<"  "<<number2.getnum()<<endl;

                for (  int j=number1.getnum().size()-1 ;  j>-1  ;  j--  )
                {
                 char x= number2.getnum().at(j);      // num.get()[j]
                 char y= number1.getnum().at(j);



                 sum =int(x) + int(y)+ z ;   //sum in ASCII code

                 if (sum>58)       //if sum>10 and equal sum >58 in ASCII code
                  {
                    sum=sum -(48+48);    // because 0 in ASCII code = 48
                    z=(sum/10);
                    remainder=(sum%10);
                    if(j==0)             // if number for example =15 if j ==0 then Plus[0]=15
                    {
                      Plus[j]=sum;
                    }
                    else
                    {
                      Plus[j]=remainder;    //carry
                    }
                    sum=0;
                  }
                   else
                  {
                    sum=sum-(48+48);
                    Plus[j]=sum;
                    sum=0;
                  }

                }//end for

                result='-';
                 for (int j=0 ; j<len-1 ;j++ )
                 {
                    char k;        //k mean convert number to ASCII code


                 if (j==0)
                  {
                      char ASCnum, ASCnum2;
                      ASCnum=Plus[j]/10;         //ASCnum=first digit in last number
                      k=ASCnum+48;               //to convert number to ASCII code
                      result+=k;
                      ASCnum2=Plus[j]%10;        //ASCnum2=second digit in last number
                      k=ASCnum2+48;
                      result+=k;
                  }
                  else
                  {
                      k=Plus[j]+48;

                      result+=k;
                  }

                 }

              return result;
            }

         /******************************(if number1 is -ve  &  number2 =+ve number)********************************/

        else if ((number.at(0)=='-')&&(number.size()-1>=n1.getnum().size())&&(number.at(1)>n1.getnum().at(0)))
        {
              number2.setnum(n1.getnum());
              num2=number2.getnum();


                for (int j=1 ; j<number.size() ; j++)  //takes all number without negative sign
                {
                    num1+=number.at(j);
                    number1.setnum(num1);
                }
                if (number1.getnum().size() >number2.getnum().size())
                {
                   while (number1.getnum().size()>number2.getnum().size())
                     {
                       num2.insert(0,"0");
                       number2.setnum(num2);
                     }  //to add 0's but in the left
                }
                if (number1.getnum().size() < number2.getnum().size())
                  {
                    while (number2.getnum().size() > number1.getnum().size())
                      {
                        num1.insert(0,"0");
                        number1.setnum(num1);
                      }
                   }

            result='-';
            bigint r ;
            r= number1-number2;
            result+=r.getnum();

                  return result;

        }

    else if ((number.at(0)=='-'))
        {

              number2.setnum(n1.getnum());
              num2=number2.getnum();


                for (int j=1 ; j<number.size() ;j++) //takes all number without negative sign
                {
                    num1+=number.at(j);
                    number1.setnum(num1);
                }

                if (number1.getnum().size() > number2.getnum().size())
                {
                while (number1.getnum().size()>number2.getnum().size())
                  {
                       num2.insert(0,"0");

                       number2.setnum(num2);
                  }          //to add 0's but in the left

                }
                if (number1.getnum().size() < number2.getnum().size())
                {
                  while (number2.getnum().size()>number1.getnum().size())
                   {
                       num1.insert(0,"0");
                       number1.setnum(num1);
                   }
                }



            bigint r;
            r= number2-number1;
            result+=r.getnum();


          return result;

        }


/****************************** (if number1 & number2 are +ve number)********************************/
else{
    n1.calc_len(number);

    for(int j=len-1 ; j>-1 ; j--)
    {
      char x= n1.getnum().at(j);      // num.get()[j]
      char y= number.at(j);

       sum =int(x) + int(y)+ z ;   //sum in ASCII code

        if (sum>58)       //if sum>10 and equal sum >58 in ASCII code
        {
            sum=sum -(48+48);    // because 0 in ASCII code = 48
            z=(sum/10);
            remainder=(sum%10);
            if(j==0)             // if number for example =15 if j ==0 then Plus[0]=15
            {
                 Plus[j]=sum;

            }
            else
            {
               Plus [j]=remainder;
            }


            sum=0;

        }

        else
        {
            sum=sum-(48+48);
            Plus[j]=sum;
            sum=0;
        }

      }

    for (int j=0 ; j<len ;j++ )
      {
            char k;        //k mean convert number to ASCII code


          if (j==0)
          {
              char ASCnum, ASCnum2;
              ASCnum=Plus[j]/10;   //ASCnum=first digit in last number
              k=ASCnum+48;          //to convert number to ASCII code
              result+=k;
              ASCnum2=Plus[j]%10;   //ASCnum2=second digit in last number
              k=ASCnum2+48;
              result+=k;
          }
          else
          {
              k=Plus[j]+48;

              result+=k;
          }



    }
      return result;
}
}
bigint bigint::operator- (bigint &n1)    //to subtract 2 number
{
    n1.calc_len(number);
    string result;
    int z=0;
    int x0;                                //reduce number if he want to borrow
    int subract=0;

        len = number.size();

        int Minus[len-1];

    for(int j=len-1; j>-1; j--)
    {
      char x= number.at(j);
      char y= n1.getnum().at(j);
       x0=int(x)-z ;
       z=0;

        if (x0 < int(y))
        {
            x0=x0+10;
            z=1;

            subract= x0-int(y);
            Minus[j]=subract;
            x0=0;
        }

        else
        {
            subract= x0 -int(y);
            Minus[j]=subract;

        }
    }
    for (int j=0 ; j<len ;j++ )
      {
          char k;        //k mean convert number to ASCII code
          if (j==len)
          {
              char ASCnum, ASCnum2;
              ASCnum= Minus[j]/10;   //ASCnum=first digit in last number
              k=ASCnum+48;          //to convert number to ASCII code
              result+=k;
              ASCnum2= Minus[j]%10;   //ASCnum2=second digit in last number
              k=ASCnum2+48;
              result+=k;
          }
          else
          {
              k= Minus[j]+48;
              result+=k;
          }
     }

      return result;
}

bigint bigint::operator = (bigint n1)
{
    number =n1.number;
    return number;
}

bool  bigint::operator==(bigint &n1)
{
    n1.calc_len(number); //same length
    int i ;
    len = number.size();



    for( i=0; i<len ; i++)
    {
      char x= n1.getnum().at(i);
      char y= number.at(i);

      if( x != y )
      {
          break;
      }
    }

    if(i==len)
    {

       check=true;
    }
    else
    {
        check=false;
    }
    return check;
}
ostream& operator<<(  ostream& out , bigint& n1)
{
    out<<n1.getnum();
         return out ;


}




