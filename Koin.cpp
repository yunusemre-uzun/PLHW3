#include "Koin.h"
#include "Utilizer.h"
#include <iomanip>

using namespace std;

Koin::Koin(double value){
    this->value = value;
    this->next = nullptr;
}
Koin::Koin(const Koin& rhs){
    this->value = rhs.getValue();
    this->next = rhs.getNext();
}
Koin& Koin::operator=(const Koin& rhs){
    delete this->next;
    this->value = rhs.getValue();
    Koin *p;
    p = rhs.getNext();
    this->next = p;
}

double Koin::getValue() const{
    return this->value;
}
Koin* Koin::getNext() const{
    return this->next;
}

void Koin::setNext(Koin *next){
    this->next = next;
}

bool Koin::operator==(const Koin& rhs) const{
    int diff = (value-rhs.getValue())<0 ? (-1)*(value-rhs.getValue()) : (value-rhs.getValue());
    if(diff<Utilizer::doubleSensitivity()){
        return true;
    }
    else{
        return false;
    }
}

bool Koin::operator!=(const Koin& rhs) const{
    if((*this)==rhs){
        return false;
    }
    else{
        return true;
    }
}

Koin& Koin::operator*=(int multiplier){
    this->value *= multiplier;
    return (*this);
}

Koin& Koin::operator/=(int divisor){
    this->value /= divisor;
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Koin& koin){
    Koin *p;
    os.precision(Utilizer::koinPrintPrecision());
    p = koin.getNext();
    os << fixed;
    os << koin.getValue();
    while(p!=nullptr){
        os << fixed;
        os << "--"  << p->getValue() ;
        p = p->getNext();
    }
    os << "|" ;

}