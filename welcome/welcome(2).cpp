#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
   if (argc != 3)
   {
      cout << "usage(輸入方法）:" << endl;
      cout << "  " << argv[0] << "    訪客名稱    主人名稱"<< endl;
   }
   else
   {
       cout << "Hello, " << argv[1] << "." << endl;
       cout << "This is " << argv[2] << ", welcome."<< endl;
   }
    
return 0;
}
