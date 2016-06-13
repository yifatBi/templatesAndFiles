//
// Created by yifat biezuner on 11/06/2016.
// This class implement the function of generic functionality reading and writing to file
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
    //read from the file aNum-(number of T element) to the given list
    //return- the number of elements written the the given list
    int read(T **apBuf, int aNum){
        bool isValid= true;
        *apBuf=new T[aNum];
        for (int i = 0; i<aNum; i++)
        {
            T var = read();
            //check that there is val
            if (var == var.DEFAULT_VAL)
            {
                if (!rd.good())
                {
                    return (i);
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
    //Write to the file aNum-(number of T) from the apBuf(list) to the file
    void write(T *apBuf, int aNum){
        for (int i = 0; i < aNum; i++)
            write(apBuf[i]);
    }
    //The number of T elements in the file
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
