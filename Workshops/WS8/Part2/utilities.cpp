#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

// Complete the mergeSmart() function in the Utilities module using smart pointer syntax

namespace seneca
{
    List<Product> mergeRaw(const List<Description> &desc, const List<Price> &price)
    {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
		//         using raw pointers

        for (unsigned int i = 0; i < desc.size(); i++)
        {
            for (unsigned int j = 0; j < price.size(); j++)
            {
                if (desc[i].code == price[j].code)
                {
                    Product *product = new Product(desc[i].desc, price[j].price);
                    if (!(desc[i].code))
                    {
                        delete product;
                        throw std::string("*** Negative prices are invalid ***");
                    }
                    else
                    {
                        try
                        {
                            product->validate();
                        }
                        catch (std::string err)
                        {
                            delete product;
                            throw std::string(err);
                        }
                    }
                    priceList += product;
                    delete product;
                }
            }
        }

        return priceList;
    }

    List<Product> mergeSmart(const List<Description> &desc, const List<Price> &price)
    {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using smart pointers
        for (unsigned int i = 0; i < desc.size(); i++)
        {

            for (unsigned int j = 0; j < price.size(); j++)
            {

                if (desc[i].code == price[j].code)
                {
                    std::unique_ptr<Product> product = std::make_unique<Product>(desc[i].desc, price[j].price);

                    if (!(desc[i].code))
                    {
                        throw std::string("*** Negative prices are invalid ***");
                    }
                    else
                    {
                        product.get()->validate();
                    }

                    priceList += product;
                }
            }
        }

        return priceList;
    }
}