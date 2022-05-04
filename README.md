# An implementation of G2P algorithm in C++

The intention of this repo is to provide a C++ interface to infer the pronunciation of unknown words. It's meant to be used in [Tihu project](https://github.com/tihu-nlp/tihu).

The main repo that the models are trained with is [here](https://github.com/hajix/G2P). After the encoder and decoder models are trained, they must be converted to the script module. Also grapheme and phoneme tables must be provided. The assets must be located in `resources` folder.

# notices:
Don't forget to set `LD_LIBRARY_PATH`:

```bash
    export LD_LIBRARY_PATH=/home/aj/repo/CPPG2P/torch_deps/libtorch/lib
```
