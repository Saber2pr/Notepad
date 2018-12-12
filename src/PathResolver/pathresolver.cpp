#include "./pathresolver.h"

PathResolver* PathResolver::_instance = nullptr;

PathResolver::PathResolver()
{
    this->value = "";
}

PathResolver::~PathResolver()
{
    delete PathResolver::_instance;
}

PathResolver* PathResolver::getInstance(){
    if(!_instance){
        _instance = new PathResolver();
        return _instance;
    }
    return _instance;
}
