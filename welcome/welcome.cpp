#include <iostream>
using namespace std;

int main(int argc, char *argv[]) 
{
   if (argc < 2 || argc > 2) 
   {
       cout << "usage(使用方法):" << endl;
       cout << "   " << argv[0] << " user name" << endl;
   }
   else
   {
     cout << "Hello, " << argv[1] << "." << endl;
     cout << "Welcome to the CHUHSUAN's world." << endl;
   }
return 0;
}
