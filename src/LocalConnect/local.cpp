#include "local.h"

Local::Local()
{
    this->resolve = [=](ThenCall callback){
        callback(this->readFile(this->path_temp));
    };
}

Local::~Local()
{
    delete Local::_instance;
}

Local* Local::_instance = nullptr;

Local* Local::getInstance(){
    if(!_instance){
        _instance = new Local();
        return _instance;
    }
    return _instance;
}

Local::Then Local::connect(string path){
    this->path_temp = path;
    return this->resolve;
}

Local::Then Local::connect(string path, string value){
    this->path_temp = path;
    this->writeFile(path, value);
    return this->resolve;
}

string Local::readFile(string path){
    ifstream readFile(path);
    readFile.is_open()? void() : exit(404);
    string res((istreambuf_iterator<char>(readFile)), istreambuf_iterator<char>());
    readFile.close();
    return res;
}

void Local::writeFile(string path, string value){
    ofstream writeFile(path);
    writeFile.is_open()? void() : exit(404);
    writeFile << value;
    writeFile.close();
}
