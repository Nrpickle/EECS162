#include "main.hpp"

int main(){
  Document d("Hello world!");
  Document d2;
  d.output();
  d2 = d;
  d2.output();


  cout << endl << endl;
  Email e("Nick","Hayden","Lab 5","This is lab 5");
  Email e2;
  e.output();
  e2 = e;
  cout << endl;
  e2.output();

  cout << endl << endl;
  
  File f("/files/morefiles/2/","Text!");
  f.output();
  File f2;
  f2 = f;
  f2.output();
  return 0;
}



