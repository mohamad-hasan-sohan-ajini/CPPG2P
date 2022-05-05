#include "xcoder.h"
#include "encoder.h"
// #include "decoder.h"

using namespace std;


int main() {
    string graphemes_file = "/home/aj/repo/CPPG2P/resources/graphemes.txt";
    string phonemes_file = "/home/aj/repo/CPPG2P/resources/phonemes.txt";
    string encoder_model_path = "/home/aj/repo/CPPG2P/resources/encoder_e10_jit.pt";
    string decoder_model_path = "/home/aj/repo/CPPG2P/resources/decoder_e10_jit.pt";
    string word = "سلام";

    cout << "Test Xcoder..." << endl;
    Xcoder my_xcoder = Xcoder();
    my_xcoder.create_index2symbols(graphemes_file);
    my_xcoder.create_symbols2index(graphemes_file);
    my_xcoder.load_model(encoder_model_path);
    cout << "Xcoder test passed." << endl << endl << endl;

    cout << "Test Encoder..." << endl;
    Encoder my_encoder = Encoder(graphemes_file, encoder_model_path);
    torch::Tensor tmp = my_encoder.get_input_tensor(word);
    for (int i = 0; i < 6; i++) {
        cout << "index: " << i << ", value: " << tmp.index({i, 0}) << endl;
    }
    cout << "Encoder test passed." << endl << endl << endl;

    // Decoder decoder = Decoder(phonemes_file, decoder_model_path);
}
