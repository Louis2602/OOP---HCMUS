#include "SplitFile.h"

using namespace std;

int main()
{
    // input.jpg size = 479404 bytes
    string source = "./text.txt";
    SplitFile file;
    cout << "Size: " << file.getSize(source) << endl;
    file.split(source, 5);
    return 0;
}
