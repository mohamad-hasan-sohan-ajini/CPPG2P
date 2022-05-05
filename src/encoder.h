#ifndef __TIHU__ENCODER_H
#define __TIHU__ENCODER_H

#include <map>
#include <fstream>
#include <torch/script.h>

#include "xcoder.h"

using namespace std;


class Encoder : public Xcoder {
    map<string, int> grapheme2index;
    map<int, string> index2grapheme;

public:
    Encoder(const string, const string);

    torch::Tensor get_input_tensor(const string);
    // torch::Tensor forward(string);
};

#endif
