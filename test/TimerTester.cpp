#include <iostream>
using namespace std;
#include "hdr/Timer.h"

int main()
{
   while(1){
      static Timer lastcall;
      if(lastcall.elapsed(750)){
         cout << "..";
      }
      if(lastcall.elapsed(800)){
         lastcall.set();
         cout << "called!" << endl;
      }
   }
}
