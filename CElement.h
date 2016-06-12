//
// Created by yifat biezuner on 11/06/2016.
//

#ifndef TEMPLATESPROJECT_CELEMENT_H
#define TEMPLATESPROJECT_CELEMENT_H
#include <iostream>
#include <fstream>
using namespace std;


class CElement {
private:
    int m_var;
public:
    static const int DEFAULT_VAL= -99999;
    int getVar() const {
        return m_var;
    }
    CElement(const int var=DEFAULT_VAL) : m_var(var) {
    }
    void setVar(int m_var) {
        CElement::m_var = m_var;
    }

};
inline bool operator==(const CElement& lhs, const CElement& rhs){return lhs.getVar()==rhs.getVar();}
ostream& operator<<(ostream& out, const CElement& element);
ifstream& operator>>(ifstream& in, CElement& element);
ofstream& operator<<(ofstream& out, CElement& element);


#endif //TEMPLATESPROJECT_CELEMENT_H
