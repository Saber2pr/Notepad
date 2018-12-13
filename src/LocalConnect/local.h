#ifndef LOCAL_H
#define LOCAL_H
#include<fstream>
#include<string>
#include<streambuf>
#include<functional>

using namespace std;
/**
 * @brief The Local class
 * @infor: by saber2pr
 */
class Local
{   /**
     * @brief ThenCall
     */
    using ThenCall = function<void(string)>;
    /**
     * @brief Then
     */
    using Then = function<void(ThenCall)>;

private:
    Local();
    /**
     * @brief _instance
     */
    static Local* _instance;
    /**
     * @brief resolve
     */
    Then resolve;
    /**
     * @brief path_temp
     */
    string path_temp;
    /**
     * @brief readFile
     * @param path
     * @return
     */
    string readFile(string path);
    /**
     * @brief writeFile
     * @param path
     * @param value
     */
    void writeFile(string path, string value);

public:
    ~Local();
    /**
     * @brief getInstance
     * @return
     */
    static Local* getInstance();
    /**
     * @brief connect
     * @param path
     * @return
     */
    Then connect(string path);
    /**
     * @brief connect
     * @param path
     * @param value
     * @return
     */
    Then connect(string path, string value);

};

#endif // LOCAL_H
