#ifndef __TIHU__DECODER_H
#define __TIHU__DECODER_H

#include <map>
#include <vector>
#include <torch/script.h>

#include "xcoder.h"

using namespace std;

class Decoder : Xcoder {
    map<string, int> phoneme2index;
    map<int, string> index2phoneme;

public:
    Decoder(const string Decoder2index, const string model_path);
    ~Decoder();

    vector<at::Tensor> forward(string);
};

#endif
