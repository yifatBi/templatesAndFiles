#include <iostream>
#include "CFile.h"
#include "CElement.h"

using namespace std;
int main() {
    try {
        CFile<CElement> file("text.txt");
        CElement elemntToWrite(8);
        file.write(elemntToWrite);
        cout << file.read() << endl;
        cout << "size:"<<file.size() << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        catch (...) {
            cout << "general exception occured" << endl;
        }
        return 0;
}