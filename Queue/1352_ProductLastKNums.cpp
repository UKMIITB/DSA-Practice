// https://leetcode.com/problems/product-of-the-last-k-numbers/
#include <iostream>
#include <vector>

using namespace std;
class ProductOfNumbers
{
    vector<long long> prefixProduct;

public:
    ProductOfNumbers()
    {
        prefixProduct.push_back(1);
    }

    void add(int num)
    {
        if (num == 0)
        {
            prefixProduct.clear();
            prefixProduct.push_back(1);
        }
        else
        {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }

    int getProduct(int k)
    {
        if (k > prefixProduct.size() - 1)
            return 0;
        else
            return prefixProduct.back() / prefixProduct.at(prefixProduct.size() - k - 1);
    }
};