#ifndef __TIHU__ENCODER_H
#define __TIHU__ENCODER_H

#include <map>
#include <torch/script.h>
#include "xcoder.h"

using namespace std;

class Encoder : Xcoder {
    map<string, int> grapheme2index;
    map<int, string> index2grapheme;

public:
    Encoder(const string grapheme2index, const string model_path);
    ~Encoder();

    at::Tensor forward(string);
}

#endif
