#ifndef CONSOLE
#define CONSOLE

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/**
 * @brief The Console class
 * @infor: by saber2pr
 */
class Console
{
public:
    template<typename T>
    static void log(T value) {
        cout << value << endl;
    }

    template<typename T>
    static void log_vector(vector<T> vector){
        for_each(vector.begin(), vector.end(), [](T item){
            cout << item << "," ;
        });
        cout << endl;
    }

    template<typename T1, typename T2>
    static void log(T1 value1, T2 value2) {
        cout << value1 << value2 << endl;
    }
};

#endif // CONSOLE

