#ifndef __TIHU__G2P_H
#define __TIHU__G2P_H

#include <map>
#include <fstream>
#include <list>

#include <torch/script.h>

using namespace std;


class G2P {
    torch::jit::script::Module g2p_model;
    map<string, int> grapheme2index;
    map<int, string> index2phoneme;

public:
    G2P(const string, const string, const string);

    vector<string> forward(const string);

private:
    torch::jit::script::Module load_g2p_model(const string);
    map<string, int> load_grapheme2index(const string);
    map<int, string> load_index2phoneme(const string);
    vector<torch::jit::IValue> get_input_tensor(const string);
    torch::jit::IValue run_model(vector<torch::jit::IValue>);
    vector<string> convert_to_phonemes(torch::jit::IValue, int, int);
};


#endif
