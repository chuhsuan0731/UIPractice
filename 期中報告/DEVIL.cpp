//2020.11.22 TSENGCHUHSUAN 

#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>


void error(const std::string& cmd, const std::string& msg) {
    std::cout << "Error: " << msg << std::endl;
    std::cout << " type '" << cmd << " -?' to see usage." << std::endl;

    exit(-1);
}


void numInBase(const std::string& dec, const std::string& base, const std::string& num)
{
    std::cout<< "Decimal number "<< dec << "in"<< base << ":" << num << std::endl;
}


std::string dec2bin(const std::string& dec)
{
    std::stringstream bin;

    bin << std::bitset<16>(std::stoi(dec));

    numInBase(dec, " in 16 bits binary: ", bin.str());

    return bin.str();
} // decToBin()


std::string dec2hex(const std::string& dec) 
{
    std::stringstream hex;

    hex << "0x" << std::hex << std::stoi(dec);

    numInBase(dec, " in hexadecimal: ", hex.str());

    return hex.str();
} // decToHex()


std::string dec2oct(const std::string& dec) 
{
    std::stringstream oct;

    oct << "0" << std::oct << std::stoi(dec);

    numInBase(dec, " in octal: ", oct.str());

    return oct.str();
} // decToOct()


void numInDec(const std::string& base, const std::string& num, const std::string& dec)
{
    std::cout << base  << " number "<< num<< " in decimal: "<< dec<< std::endl;
} // numInDec()


std::string bin2dec(const std::string& bin)
{
    std::stringstream dec;

    dec << std::stol(bin, nullptr, 2);

    numInDec("Binary", bin, dec.str());

    return dec.str();
} // bin2dec()


std::string oct2dec(const std::string& oct) 
{
    std::stringstream dec;

    dec << std::stol(oct, nullptr, 8);

    numInDec("Octal", oct, dec.str());

    return dec.str();
} // oct2dec()


std::string hex2dec(const std::string& hex) 
{
    std::stringstream dec;

    dec << std::stol(hex, nullptr, 16);

    numInDec("Hexadecimal", hex, dec.str());

    return dec.str();
} // hex2dec()


bool is_number(const std::string& str, int base = 10) 
{
    size_t sz;

    try {
        std::stol(str, &sz, base);
    }
    catch (const std::invalid_argument& e) {
        ;
    }

    return (sz == str.length());
} // is_number()


bool test_dec_bin(const std::string& cmd, const std::string& dec) 
{
    std::string bin;
    std::string num;

    std::cout << "C:\\" << cmd << " -b " << dec << std::endl;
    bin = dec2bin(dec);

    std::cout << "C:\\" << cmd << " -B " << num << std::endl;
    num = bin2dec(bin);

    std::cout << std::endl;

    return (dec == num);
} // test_dec_bin();


bool test_dec_hex(const std::string& cmd, const std::string& dec)
{
    std::string hex;
    std::string num;

    std::cout << "C:\\" << cmd << " -h " << dec << std::endl;
    hex = dec2hex(dec);

    std::cout << "C:\\" << cmd << " -H " << num << std::endl;
    num = hex2dec(hex);

    std::cout << std::endl;

    return (dec == num);
} // test_dec_hex();


bool test_dec_oct(const std::string& cmd, const std::string& dec) 
{
    std::string oct;
    std::string num;

    std::cout << "C:\\" << cmd << " -o " << dec << std::endl;
    oct = dec2oct(dec);

    std::cout << "C:\\" << cmd << " -O " << num << std::endl;
    num = oct2dec(oct);

    std::cout << std::endl;

    return (dec == num);
} // test_dec_oct();


void sample_usage(const std::string& cmd, const std::string& dec) 
{
    std::cout << "Examples: " << std::endl << std::endl;

    test_dec_bin(cmd, dec) ? (void)0 : error(cmd, "Dec-Bin converting error!");
    test_dec_hex(cmd, dec) ? (void)0 : error(cmd, "Dec-Hex converting error!");
    test_dec_oct(cmd, dec) ? (void)0 : error(cmd, "Dec-Oct converting error!");
} // sample_usage()


void usage(const std::string& cmd) 
{
    std::string num;

    std::cout << cmd << " v0.1.0 " << std::endl;
    std::cout << "usage: " << std::endl;
    std::cout << " -H hexadecimal to decimal." << std::endl;
    std::cout << " -h decimal to hexadecimal." << std::endl;
    std::cout << " -O octal to decimal." << std::endl;
    std::cout << " -o decimal to octal." << std::endl;
    std::cout << " -B binary to decimail." << std::endl;
    std::cout << " -b decimal to binary." << std::endl;
    std::cout << " -? print this usage." << std::endl;
    std::cout << " -x some usage samples." << std::endl;
    std::cout << std::endl;

    sample_usage(cmd, "101");
} // usage()


void args_dump(int argc, char* argv[]) 
{
    // 列印所有的 *命令列參數*
    std::cout << "command line arguments: argv[i]" << std::endl;

    for (int i = 0; i < argc; i++) {
        std::cout
            << std::setfill(' ') << std::setw(3)
            << i << ": "
            << argv[i] << std::endl;
    }
}

/**
 *  程式進入點。
 *
 *  @param const int argc           命令列參數個數
 *  @param const char *argv[]       命令列參數陣列
 *  @return int
 *  @since  0.1.0
 **/
int main(int argc, char* argv[])
{
    std:: cout << "列印所有的 *命令列參數*\n"<<std::endl;
    args_dump(argc, argv);

    std::string arg = argv[1];

    if (argc != 3 && argc != 2)
    {
        error(argv[0],argv[1]);
        usage(argv[0]);
    }

    else if (argc == 2)
    {
        if (arg == "-?")
        {
            usage(argv[0]);
        }
        else
        {
            error(argv[0], argv[1]);
            usage(argv[0]);
        }
    }

    else
    {
        if (arg == "-b")
        {
            dec2bin(argv[2]);
        }

        else if (arg == "-B")
        {
            bin2dec(argv[2]);
        }

        else if (arg == "-h")
        {
            dec2hex(argv[2]);
        }

        else if (arg == "-H")
        {
            hex2dec(argv[2]);
        }

        else if (arg == "-o")
        {
            dec2oct(argv[2]);
        }

        else if (arg == "-O")
        {
            oct2dec(argv[2]);
        }

        else if (arg == "-x")
        {
            sample_usage(argv[0], argv[2]);
        }

        else
        {
            error(argv[0], argv[1]);
            usage(argv[0]);
        }

    }

    return 0;

}
