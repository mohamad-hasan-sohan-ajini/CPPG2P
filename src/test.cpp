#include <iostream>

#include "xcoder.h"
// #include "encoder.h"
// #include "decoder.h"

using namespace std;


int main() {
    string graphemes_file = "/home/aj/repo/CPPG2P/resources/graphemes.txt";
    string phonemes_file = "/home/aj/repo/CPPG2P/resources/phonemes.txt";
    string encoder_model_path = "/home/aj/repo/CPPG2P/resources/encoder_e10_jit.pt";
    string decoder_model_path = "/home/aj/repo/CPPG2P/resources/decoder_e10_jit.pt";

    cout << "Test Xcoder..." << endl;
    Xcoder my_xcoder = Xcoder();
    my_xcoder.create_index2symbols(graphemes_file);
    my_xcoder.create_symbols2index(graphemes_file);
    my_xcoder.load_model(encoder_model_path);
    cout << "xcoder test passed." << endl;

    // Encoder encoder = Encoder(graphemes_file, encoder_model_path);
    // Decoder decoder = Decoder(phonemes_file, decoder_model_path);
}
