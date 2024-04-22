#pragma once
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H 

#include <iostream> 
#include "Pair.h"
#include <string>

namespace seneca
{
    /// <summary>
    /// Design and code of a class template named Collection. This template manages a statically allocated array of any datatype. 
    /// The template parameters in order of their specification are:
    /// </summary>
    /// <typeparam name="T">  the type of any element in the collection </typeparam>
    /// <typeparam name="CAPACITY">  the capacity of the collection (a non-type parameter; an integer without sign). 
    /// This is the maximum number of elements that can be added to the collection </typeparam>
    /// 
    template<class T, size_t CAPACITY> 

    class Collection
    {
    protected: 
        T m_array[CAPACITY]{};           // statically allocated array of any datatype 
        size_t m_numElements{ 0 };       // keeps track of the current number of elements stored in the collection (which may differ from the capacity of the collection). Initially the collection has no elements.
        T m_dummyObject{};               // <-- class member : An object of type T (a dummy object). This object will be returned by member-functions when the client requests an object that is not in the collection 

    public:
        // Default No-arg constructor
        Collection() {};

        // Destructor
        virtual ~Collection() {};

        // a query that returns the current number of elements in the collection
        size_t size() const { return m_numElements; }   

        // a query that receives as the parameter an output stream (with default value std::cout) 
        // and inserts into the stream all items from the collection (see the sample output for formatting hints).
        void display(std::ostream& ostr = std::cout) const 
        {
            ostr << "----------------------" << std::endl;
            ostr << "| " << "Collection Content" << " |" << std::endl;
            ostr << "----------------------" << std::endl;
            for (size_t i = 0; i < m_numElements; i++) 
            {
                ostr << m_array[i] << std::endl; 
            }
            ostr << "----------------------" << std::endl;
        }

        // a mutator that adds a copy of the parameter to the collection if there still is capacity. 
        // If the item has been added, this function return true; false otherwise.
        virtual bool add(const T& item) 
        {
            bool res = false; 
            if (m_numElements < CAPACITY)  
            {
                m_array[m_numElements] = item; 
                m_numElements++;
                res = true;
            }
            return res;
        }

        // a query that receives an index as parameter and returns a copy(reference)* of the element stored in the collection at the specified index.
        // If the index is not valid (outside the boundaries of the collection), this query returns the dummy object.
        T& operator[](int index) 
        {
            if (index >= 0 && (unsigned)index < m_numElements) 
            {
                return m_array[index];  
            }
            return m_dummyObject; 
        }
    };
 

    // specialization of the dummy object when type T = Pair and CAPACITY = 100 so the key is "No Key" and the value is "No Value".
    template<>  // denotes specialization
    Collection<Pair, 100>::Collection() 
    { 
        m_dummyObject = Pair("No Key", "No Value");  
    };
    
}   // namespace seneca

#endif  // ! SENECA_COLLECTION_H 
