#include "encoder.h"


Encoder::Encoder(const string graphemes_file, const string model_path) {
    grapheme2index = Xcoder::create_symbols2index(graphemes_file);
    index2grapheme = Xcoder::create_index2symbols(graphemes_file);
    Xcoder::load_model(model_path);
}


torch::Tensor Encoder::get_input_tensor(const string word) {
    // get graphemes indices
    int start_index = 0;
    int end_index = 1;
    string query = "";
    vector<long int> input_vector;
    while (word[start_index] != '\0')
    {
        cout << "start_index: " << start_index << ", end_index: " << end_index << endl;
        query = word.substr(start_index, end_index - start_index);
        if (grapheme2index.count(query)) {
            cout << "query found: " << query << ", value: " << grapheme2index[query] << endl;
            start_index = end_index;
            input_vector.push_back(grapheme2index[query]);
            cout << "---------------------------" << endl;
        }
        end_index++;
    }
    cout << "input_vector length: " << input_vector.size() << endl;

    // put the values in torch tensor
    auto options = torch::TensorOptions().dtype(torch::kInt64).requires_grad(false);
    long int timesteps = input_vector.size() + 2;
    torch::Tensor input_tensor = torch::zeros({timesteps, 1}, options);
    for (long int i = 0; i < input_vector.size(); i++) {
        input_tensor.index_put_({i + 1, 0}, input_vector.at(i));
    }
    input_tensor.index_put_({timesteps - 1, 0}, 1);
    return input_tensor;
}


// at::Tensor Encoder::forward(string word) {
//     // create input tensor
//     // x = [0] + [self.ds.g2idx[ch] for ch in word] + [1]
//     // x = torch.tensor(x).long().unsqueeze(1)
//     torch::Tensor x = get_input_tensor(word);

//     // model forward pass
//     // with torch.no_grad():
//     //     enc = self.encoder_model(x)


//     // return encoded vectors
// }
