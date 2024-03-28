#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

/* Your Task: Implement the mergeRaw() function. This function compares the elements in the two received lists for common product
codes and builds the user-friendly list from the matching pairs. For each successful comparison, your function allocates dynamic memory of
Product type using that description and the price. Your function then validates the Product object and adds it to its list.
Your function returns a copy of this list. */

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

}