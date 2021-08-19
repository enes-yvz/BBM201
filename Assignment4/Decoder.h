#ifndef DECODER_H
#define DECODER_H
#include "Sorter.h"

class Decoder
{
    vector <Node*> charArrayDecoder;
    vector <int> intArrayDecoder;
    string itemDecoder;
public:
    Decoder(vector <Node*> charArrayDecoder,vector <int> intArrayDecoder);
    ~Decoder();
    string decode(string itemDecoder,Node* node); 

};

#endif // DECODER_H
