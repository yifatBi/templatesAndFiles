#include <iostream>
#include "CFile.h"
#include "CElement.h"

using namespace std;
int main() {
    try {
        CFile<CElement> file("test.txt");
        CElement elemntToWrite(5);
        CElement elemntToWrite2(7);
        CElement** writeList=new CElement*[2]{&elemntToWrite2,&elemntToWrite};
        file.write(*writeList,2);
        CElement** readList;
        int readNum =file.read(readList, 2);
        for (int i = 0; i < readNum; ++i) {
            cout<<readList[i];
        }
        elemntToWrite.setVar(12);
        file.write(elemntToWrite);
        cout << file.read() << endl;
        cout << file.read() << endl;
        cout << "size:"<<file.size() << endl;
        file.write(elemntToWrite);
        file.write(elemntToWrite);
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