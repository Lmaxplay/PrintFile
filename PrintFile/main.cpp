#include <iostream>
#include <sstream>
#include <fstream>
#include <codecvt>

std::wstring readFile(const char* filename)
{
    std::wifstream wif(filename);
    wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
    std::wstringstream wss;
    wss << wif.rdbuf();
    return wss.str();
}

int main(int argc, char** argv)
{
    if (argc >= 2) {
        std::wstring text = readFile(argv[1]);
        std::wcout << text;
    }
    else {
        std::cout << "Requires 1 argument, 0 found";
    }
    std::cout << "\n";
    return 0;
}
