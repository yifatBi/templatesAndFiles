#include <iostream>
#include "CFile.h"
#include "CElement.h"
//
// Created by yifat biezuner on 11/06/2016.
// This program write and read CElement objects from text file via template class
//
using namespace std;
int main() {
    try {
        CFile<CElement> file("test.txt");
        CElement elemntToWrite(45);
        CElement elemntToWrite2(33);
        CElement** writeList=new CElement*[3]{&elemntToWrite2,&elemntToWrite,&elemntToWrite};
        file.write(*writeList,1);
        CElement* readList[3];
        int readNum =file.read(readList, 3);
        cout<<"now the readNum: "<<readNum<<endl;
        for (int i = 0; i < readNum; ++i) {
            cout<<*readList[i]<<endl;
        }
        elemntToWrite.setVar(12);
        file.write(elemntToWrite);
        cout << file.read() << endl;
        readNum =file.read(readList, 3);
        cout<<"now the readNum: "<<readNum<<endl;
        for (int i = 0; i < readNum; ++i) {
            cout<<*readList[i]<<endl;
        }
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