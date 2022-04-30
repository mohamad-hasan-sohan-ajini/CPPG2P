#include "xcoder.h"

bool Xcoder::load_model(const string model_path) {
    model = torch::jit::load(model_path);
}
