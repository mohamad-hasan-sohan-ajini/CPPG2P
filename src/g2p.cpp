#include "g2p.h"

G2P::G2P(const string model_path, const string graphemes_file, const string phonemes_file) {
    grapheme2index = load_grapheme2index(graphemes_file);
    index2phoneme = load_index2phoneme(phonemes_file);
    g2p_model = load_g2p_model(model_path);
}

torch::jit::script::Module G2P::load_g2p_model(const string model_path) {
    return torch::jit::load(model_path);
}

map<string, int> G2P::load_grapheme2index(const string graphemes_file) {
    ifstream infile(graphemes_file);
    string line;
    int index = 0;
    map<string, int> result;
    while (getline(infile, line)) {
        result[line] = index;
        index++;
    }
    return result;
}

map<int, string> G2P::load_index2phoneme(const string phonemes_file) {
    ifstream infile(phonemes_file);
    string line;
    int index = 0;
    map<int, string> result;
    while (getline(infile, line)) {
        result[index] = line;
        index++;
    }
    return result;
}

vector<torch::jit::IValue> G2P::get_input_tensor(const string word) {
    // get graphemes indices
    int start_index = 0;
    int end_index = 1;
    string query = "";
    vector<long int> input_vector;
    while (word[start_index] != '\0')
    {
        query = word.substr(start_index, end_index - start_index);
        if (grapheme2index.count(query)) {
            start_index = end_index;
            input_vector.push_back(grapheme2index[query]);
        }
        end_index++;
    }

    // put the values in torch tensor
    auto options = torch::TensorOptions().dtype(torch::kInt64).requires_grad(false);
    long int timesteps = input_vector.size() + 2;
    torch::Tensor input_tensor = torch::zeros({1, timesteps}, options);
    for (long int i = 0; i < input_vector.size(); i++) {
        input_tensor.index_put_({0, i + 1}, input_vector.at(i));
    }
    input_tensor.index_put_({0, timesteps - 1}, 1);

    // put input_tensor in a vector
    vector<torch::jit::IValue> batch;
    batch.push_back(input_tensor);
    return batch;
}

torch::jit::IValue G2P::run_model(vector<torch::jit::IValue> batch) {
    torch::jit::IValue pred = g2p_model.forward(batch);
    return pred;
}

vector<string> G2P::convert_to_phonemes(torch::jit::IValue pred, int eos_token, int max_len = 100) {
    torch::Tensor pred_tensor = pred.toTensor();
    vector<string> result;
    int phoneme_index;
    for (int i = 0; i < max_len; i++) {
        phoneme_index = pred_tensor.index({i}).item().toInt();
        if (phoneme_index == eos_token) {
            break;
        }
        result.push_back(index2phoneme[phoneme_index]);
    }
    return result;
}

vector<string> G2P::forward(const string word) {
    vector<torch::jit::IValue> batch = get_input_tensor(word);
    torch::jit::IValue pred = run_model(batch);
    vector<string> result = convert_to_phonemes(pred, 1, 100);
    return result;
}
