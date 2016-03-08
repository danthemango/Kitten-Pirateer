#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <fstream>
using namespace std;

int main()
{


   ifstream f;
   f.open("INPUTFILE",std::ifstream::in);

   int a=0;
   int c=0;


   // read in the first number -- the number of "tiles"
   f >> a;

   int *nobjects = new int[a];

   // read in the respective number of objects on each tile...
   for(int i=0;i<a;i++){
      f>> nobjects[i];
   }


   // read in the number of attraibuest per object
   f >> c;

	//   cout << "Cube: " << a;
	//for(int k=0;k<a;k++){
		//cout << " " << nobjects[k];
	//}
	//cout << " " << c << endl;


   // create big array
   int ***array = new int**[a];

	for(int k=0;k<a;k++){

      array[k] = new int*[nobjects[k]];

      for(int j=0;j<nobjects[k];j++){
         array[k][j] = new int[c];
      }
   }

   cout << "Allocated ram" << endl;


   // read in the objects sequetinaly -- whitespace is ignored in the input file

   // note that the int j is bound by nobjects[k]
	for(int k=0;k<a;k++){
      for(int j=0;j<nobjects[k];j++){
         for(int i=0;i<c;i++){

            f >> array[k][j][i];
         }
      }
   }

   // print it all out
	for(int k=0;k<a;k++){
      for(int j=0;j<nobjects[k];j++){
         for(int i=0;i<c;i++){
            cout << array[k][j][i] << ", ";
         }
         cout << endl;
      }
      cout << endl;
   }


   // delete shit in reverse order and then clean up nobjects
	for(int k=0;k<a;k++){
      for(int j=0;j<nobjects[k];j++){
        delete [] array[k][j];
      }
      delete [] array[k];
   }
   delete [] array;

   delete [] nobjects;
}
