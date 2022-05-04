#include "encoder.h"


Encoder::Encoder(const string graphemes_file, const string model_path) {
    grapheme2index = create_symbols2index(graphemes_file);
    index2grapheme = create_index2symbols(graphemes_file);
    load_model(model_path);
}


at::Tensor Encoder::forward(string word) {
    // create input tensor
    // model forward pass
    // return encoded vectors
}
