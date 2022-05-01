#include "xcoder.h"


map<string, int> Xcoder::create_symbols2index(const string graphemes_file) {
    std::ifstream infile(graphemes_file);
    std::string line;
    int index = 0;
    map<string, int> result;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        result[line] = index;
        index++;
    }
    return result;
}


map<int, string> Xcoder::create_index2symbols(const string graphemes_file) {
    std::ifstream infile(graphemes_file);
    std::string line;
    int index = 0;
    map<int, string> result;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        result[index] = line;
        index++;
    }
    return result;
}


bool Xcoder::load_model(const string model_path) {
    model = torch::jit::load(model_path);
}
