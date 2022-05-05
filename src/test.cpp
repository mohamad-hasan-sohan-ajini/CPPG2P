#include "g2p.h"

using namespace std;


int main() {
    string g2p_model_path = "/home/aj/repo/CPPG2P/resources/g2p_script_module_batchfirst.pt";
    string graphemes_file = "/home/aj/repo/CPPG2P/resources/graphemes.txt";
    string phonemes_file = "/home/aj/repo/CPPG2P/resources/phonemes.txt";

    string word = "سلام";

    cout << "Test G2P..." << endl;
    G2P my_g2p(g2p_model_path, graphemes_file, phonemes_file);
    vector<string> result = my_g2p.forward(word);
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl ;
    cout << "G2P test is done..." << endl;
}
