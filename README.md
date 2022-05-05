# An implementation of G2P algorithm in C++

The intention of this repo is to provide a C++ interface to infer the pronunciation of unknown words. It's meant to be used in [Tihu project](https://github.com/tihu-nlp/tihu).

## Prepare model and resources
The main repo that the models are trained with is [here](https://github.com/hajix/G2P). After the encoder and decoder models are trained, they must be converted to the script module. Encoder and Decoder script modules must be passed to the G2P model which is defined at `convertible_model.py`.

Also grapheme and phoneme tables must be provided as text file. The assets must be located in `resources` folder.

A trained and converted g2p model plus the corresponding graphemes and phonemes text files are provided.


## Prerequisites
The `Pre-cxx11 ABI` version of `Libtorch` for cpu must be downloaded from [here](https://pytorch.org/). The `libtorch` folder and it's contents is a must have to compile this project.

Also shared objects that are necessary for running the binaries are located in `libtorch/lib`.

## Compilation
A make file is provided to compile this project, but before running the `make` command, create `obj` and `build` directories.

---
**NOTE**

Don't forget to set `LD_LIBRARY_PATH` before running the executables in `build`:

```bash
export LD_LIBRARY_PATH=torch_deps/libtorch/lib
```

---
