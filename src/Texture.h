#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

class File;
class Image;

struct Texture {
    Texture(const File& file);
    Texture(const Image& image);
    ~Texture();

    const std::string _name;
    const std::string _path;
    unsigned char* _pData;
    int _width;
    int _height;
    int _nrChannels;
};

#endif
