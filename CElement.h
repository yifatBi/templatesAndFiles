//
// Created by yifat biezuner on 11/06/2016.
//

#ifndef TEMPLATESPROJECT_CELEMENT_H
#define TEMPLATESPROJECT_CELEMENT_H
#include <iostream>
#include <string>
using namespace std;

class CElement {
private:
    int m_var;
public:

    int getVar() const {
        return m_var;
    }
    CElement(const int var=0) : m_var(var) {
    }
};
    ostream& operator<<(ostream& out, const CElement& element);
    iostream& operator>>(iostream& in, CElement& element);


#endif //TEMPLATESPROJECT_CELEMENT_H
