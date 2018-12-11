#ifndef VECTORHELPER_H
#define VECTORHELPER_H
#include<vector>

using namespace std;

class VectorHelper
{
public:
    VectorHelper();
    ~VectorHelper();
    template<typename V>
    /**
     * @brief merge
     * @param front
     * @param behind
     */
    static void merge(vector<V> &front, vector<V> &behind){
        front.insert(front.end(), behind.begin(), behind.end());
    }
};

#endif // VECTORHELPER_H
