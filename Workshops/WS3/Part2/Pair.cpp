#define CRT_SECURE_NO_WARNINGS 
#include "Pair.h"

namespace seneca
{
    // This function recieves two references to objects(instances of a pair class) as paramters
    // It compares them based on their keys and returns true if identical or false otherwise
    bool Pair::haveSameKey(const Pair& A, const Pair& B) 
    {
        return A.m_key == B.m_key ? true : false;
    }

    // This query recieves a reference of the output stream. 
    // It sets the width to 20 and alignment to right and displays the key. 
    // sets Left alignment  and prints out the value 
    std::ostream& Pair::display(std::ostream& ostr) const 
    {
        ostr.width(20);
        ostr.setf(std::ios::right);  
        ostr << getKey();
        ostr.setf(std::ios::left);    
        ostr << ": " << getValue(); 
        return ostr;
    }

    // Helper function to overload the insertion operator
    std::ostream& operator<<(std::ostream& ostr, const Pair& P)   
    {
        return P.display(ostr); 
    }
}  // namespace seneca