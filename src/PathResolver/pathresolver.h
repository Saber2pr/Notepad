#ifndef PATHRESOLVER_H
#define PATHRESOLVER_H
#include<iostream>

class PathResolver {
private:
    PathResolver();
    /**
     * @brief _instance
     */
    static PathResolver* _instance;

public:
    ~PathResolver();
    /**
     * @brief getInstance
     * @return
     */
    static PathResolver* getInstance();
    /**
     * @brief value
     */
    std::string value;

};

#endif // PATHRESOLVER_H
