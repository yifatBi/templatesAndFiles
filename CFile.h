//
// Created by yifat biezuner on 11/06/2016.
//
using namespace std;
#include <iostream>
#include <fstream>
#ifndef TEMPLATESPROJECT_CFILE_H
#define TEMPLATESPROJECT_CFILE_H


template<class T> class CFile {
    ofstream wrt;
    ifstream  rd;
public:
    CFile(const char* path) {
        rd.open(path);
        if (!rd.is_open())
        {
            throw "COULDNT OPEN FILE";
        }
        wrt.open(path);
        if (!wrt.is_open())
        {
            throw "COULDNT OPEN FILE";
        }
    }
    //read T from the file
    T read(){
        T returnVal;
        //validate that the file is open and it's not the end of the file
        if (rd.good())
        {
            rd>>returnVal;
        }
        return returnVal;
    }
    int read(T **apBuf, int aNum){
        bool isValid= true;
        apBuf=new T*[aNum];
        for (int i = 0; i<aNum&&isValid; i++)
        {
            T var = read();
            //check that there is val
            if (var == var.DEFAULT_VAL)
            {
                if (!rd.good())
                {
                    isValid = false;
                    return (i+1);
                }
                else
                {
                    throw ("Error Reading File - Insufficient var type");
                }
            }
            else
            {
                (apBuf[i]) = new T[1]{var};
            }
        }
        return aNum;
    }
    //Write to the file the given T
    void write(T &t){
        wrt<<(t);
    }
    void write(T *apBuf, int aNum){
        for (int i = 0; i < aNum; i++)
            write(apBuf[i]);
    }
    //Thw size of the file according the numbers of T objects
    int size(){
        //return the reader to the start and start read and count from the begining
        rd.clear();
        rd.seekg (0, ios::beg);
        int counter=0;
        read();
        //validate that the file it's open and it's not the end of the file
        if(rd.good()&&rd.is_open()) {
            while (rd.good()) {
                counter++;
                read();
            }
        }
        return counter;
    }

    virtual ~CFile() {
        if(rd.is_open())
            rd.close();
        if(wrt.is_open())
            wrt.close();
    }
};


#endif //TEMPLATESPROJECT_CFILE_H
