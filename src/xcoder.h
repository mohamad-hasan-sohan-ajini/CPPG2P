#ifndef __TIHU__XCODER_H
#define __TIHU__XCODER_H

#include <torch/script.h>

using namespace std;

class Xcoder {
    torch::jit::script::Module model;

public:
    bool load_model(const string);
}

#endif
