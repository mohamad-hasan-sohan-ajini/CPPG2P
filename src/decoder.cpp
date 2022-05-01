#include "decoder.h"


Decoder::Decoder(const string phonemes_file, const string model_path) {
    phoneme2index = create_symbols2index(phonemes_file);
    index2phoneme = create_index2symbols(phonemes_file);
    load_model(model_path);
}
