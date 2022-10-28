#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double mySine (double x){

double
term,
fNum,
current,
previous;
 
// set up first term
term = x;
fNum = 1;

//set up current val
current = 0;

do {
//copy current val to previous val
previous = current;

//update current val
current = current + term;

//set up next term
term = -term * x * x / ((fNum + 1) * (fNum + 2));
fNum += 2;



} while (current != previous);

return current;

}


double myCosine (double x) {

double
term,
fNum,
current,
previous;
 
// set up first term
term=1;
fNum=0;

//set up current val
current=0;

do {
//copy current val to previous val
previous = current;

//update current val
current = current + term;

//set up next term
term = -term * x * x / ((fNum + 1) * (fNum + 2));
fNum += 2;



} while (current != previous);

return current;

}


double mySqrt(double x){

  double 
  num , y , precision ;
  num = x ;
  // initial guess for num
  y = 1;
  //setting precision

  precision = 1e-15 ; 

  while((fabs(num - y)/fabs(num)) > precision){

    num = (num + y)/2;
    y = x/num ; 

  }
  return num ; 

}

void myApprox(double x, int &num, int &den){

int
nLow=0, dLow=1,
nHigh=1, dHigh=0;



do {
 num = nLow + nHigh;
 den = dLow + dHigh;

if ((x * den) < num) {
 nHigh = num;
 dHigh = den;

}

else {

nLow = num;
dLow = den;

}
}

while (den <= 1000000000 && fabs((x * den) - num) > ((1e-8)) * den);

} 

int main(){
double
x,y1,y2,y3,
test_1,test_2,test_3;

int 
fNum,num,den;


//sine
cout << "enter x for sine: ";
cin >> x;
y2 = mySine(x);
test_2 = sin(x);

cout << setprecision(15) << "mySine: " << y2 << endl;
cout << "sin: "<< test_2 << endl;
cout << "difference (mySine - sin): " << (y2 - test_2) << endl;


//cosine
cout<< "enter x for cosine : ";
cin >> x;

y1 = myCosine(x);



test_1 = cos(x);



cout << setprecision(15) << "myCosine: " << y1 << endl;
cout << "Cos: "<< test_1 << endl;
cout << "difference (myCosine - cos): " << (y1 - test_1) << endl;

//sqrt

cout <<"The number you want squareroot of: ";
cin >> x;
y3 = mySqrt(x);
test_3 = sqrt(x);

cout<< "mySqrt" << y3 << endl;
cout << "sqrt: "<< test_3 << endl;
cout << "difference (mySqrt - sqrt): " << (y3 - test_3) << endl;


//approximation

cout <<"Enter value for rational approximation: ";
cin>>x ; 
if (x <= 0) {

cout << "x must be positive" << endl;
  return 1;
}

myApprox(x,num,den);

cout << "Approximation: " << x << "=" << num << "/" << den << endl;

cout << "Difference: " << (x - ((double) num/den) )<< endl;

return 0;


}
