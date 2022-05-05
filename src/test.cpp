#include "g2p.h"

using namespace std;


int main() {
    string g2p_model_path = "resources/g2p_script_module_batchfirst.pt";
    string graphemes_file = "resources/graphemes.txt";
    string phonemes_file = "resources/phonemes.txt";

    string word = "سلام";

    cout << "Test G2P..." << endl;
    cout << "word: " << word << endl;
    G2P my_g2p(g2p_model_path, graphemes_file, phonemes_file);
    vector<string> result = my_g2p.forward(word);
    cout << "phonemes: [";
    for (string s : result) {
        cout << s << " ";
    }
    cout << "]" << endl ;
    cout << "G2P test is done..." << endl;
}
