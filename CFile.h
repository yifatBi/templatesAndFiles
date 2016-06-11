//
// Created by yifat biezuner on 11/06/2016.
//
#include <iostream>
#include <fstream>
using namespace std;
#ifndef TEMPLATESPROJECT_CFILE_H
#define TEMPLATESPROJECT_CFILE_H


template<class T> class CFile {
    fstream m_file;
    ofstream wrt;
    ifstream  rd;
public:
    CFile(const char* path) {
        m_file.open(path,fstream::in|fstream::out);
        if (!m_file.is_open())
        {
            throw "COULDNT OPEN FILE";
        }
        rd.open(path);
        if (!rd.is_open())
        {
            throw"COULDNT OPEN FILE";
        }
        wrt.open(path);
        if (!wrt.is_open())
        {
            throw"COULDNT OPEN FILE";
        }
    }
    //read T from the file
    T read(){
        T returnVal;
        //validate that the file is open and it's not the end of the file
        if (m_file.is_open()&&!m_file.eof())
        {
            m_file >> returnVal;
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
            if (var == NULL)
            {
                if (m_file.eof())
                {
                    isValid = false;
                }
                else
                {
                    throw ("Error Reading File - Insufficient var type");
                }
            }
            else
            {
                (*apBuf)[i] = var;
            }
        }
        delete apBuf;
    }
    //Write to the file the given T
    void write(T &t){
            m_file << t;
        wrt<<t;
        m_file.close();
    }
    void write(T *apBuf, int aNum){
        for (int i = 0; i < aNum; i++)
            write(apBuf[i]);
    }
    //Thw size of the file according the numbers of T objects
    int size(){
        int counter=0;
        //validate that the file it's open and it's not the end of the file
        if(!m_file.eof()&&m_file.is_open()) {
            while (!m_file.eof()) {
                read();
                counter++;
            }
        }
        return counter;
    }

    virtual ~CFile() {
        if(m_file.is_open())
            m_file.close();
    }
};


#endif //TEMPLATESPROJECT_CFILE_H
