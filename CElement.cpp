#include "CElement.h"

iostream& operator>>(iostream& in, CElement& element) {
    int inputTemp;
    in>>inputTemp;
    element=CElement(inputTemp);
    return in;
}
ostream& operator<<(ostream& out, const CElement& element) {
    out<<element.getVar();
    return out;
}
