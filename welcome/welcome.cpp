#include <iostream>

using namespace std;

void error(const string& msg) {
    cerr << "Error:\n  " << msg << endl;
}

void usage(const string& cmd) {
    string opt[] = 
    {
        "where\n",
        " -h host      the host name.\n",
        " -v visitor   the guest name.\n",
        " -? usage     the usage.\n",
    };
    
    cout << "Usage(輸入方法）: \n";
    cout << "  "<< cmd << " -h host（主人姓名） -v visitor（拜訪者姓名）\n";
    
    
    for (int i = 0; i < (sizeof(opt) / sizeof(string)); i++) 
    {
        cout << opt[i];
    }
    exit(-1);
}

void welcome(const string& host, const string& guest) 
{
    cout << "Hello, " << guest << ".\n";
    cout << "This is " << host << ", welcome!!!\n";
}

int main(int argc, char *argv[])
{
    string host;
    string guest;

    if (argc != 5 && argc!= 2) 
    {
        error("Wrong number of parameters.");
        usage(argv[0]);
    }
    if (argc = 2)
    {
        string arg =argv[1];
        
        if(arg == "-?")
        {
            usage(argv[0]);
        }
        else
        {
            error("Wrong number of parameters.");
            usage(argv[0]);
        }
    }

    for (int i = 1; i < argc; i = i + 2) {
        string arg = argv[i];

        if (arg == "-h") {
            host = argv[i + 1];
        }
        else if (arg == "-v") {
            guest = argv[i + 1];
        }
        else {
            error("Unknown options: " + arg);
            usage(argv[0]);
        }
    }

    welcome(host, guest);

    return 0;
}
