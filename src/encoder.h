#ifndef __TIHU__ENCODER_H
#define __TIHU__ENCODER_H

#include <map>
#include <fstream>
#include <torch/script.h>

#include "xcoder.h"

using namespace std;

class Encoder : Xcoder {
    map<string, int> grapheme2index;
    map<int, string> index2grapheme;

public:
    Encoder(const string, const string);
    ~Encoder();

    at::Tensor forward(string);
};

#endif
