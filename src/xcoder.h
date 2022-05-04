#ifndef __TIHU__XCODER_H
#define __TIHU__XCODER_H

#include <map>
#include <fstream>
#include <torch/script.h>

using namespace std;


class Xcoder {
    torch::jit::script::Module model;

public:
    bool load_model(const string);
    map<string, int> create_symbols2index(const string);
    map<int, string> create_index2symbols(const string);
};

#endif
