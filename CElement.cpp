#include "CElement.h"
ostream& operator<<(ostream& out, const CElement& element) {
    out<<element.getVar();
    return out;
}
ifstream& operator>>(ifstream& in, CElement& element) {
    int inputTemp;
    in>>inputTemp;
    element=CElement(inputTemp);
    return in;
}
ofstream& operator<<(ofstream& out, CElement& element) {
    out<<element.getVar()<<endl;
    return out;
}


