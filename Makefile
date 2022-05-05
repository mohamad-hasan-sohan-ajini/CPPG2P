
CXXFLAGS = -Itorch_deps/libtorch/include -Itorch_deps/libtorch/include/torch/csrc/api/include -Ltorch_deps/libtorch/lib -ltorch_cpu -lc10 -D_GLIBCXX_USE_CXX11_ABI=0

all: xcoder.o encoder

encoder: encoder.o
	$(CXX) src/test.cpp obj/encoder.o obj/xcoder.o -o build/encoder_test $(CXXFLAGS)

encoder.o:
	@echo "Compile encoder..."
	$(CXX) -c src/encoder.cpp -o obj/encoder.o $(CXXFLAGS)
	@echo "Done."

xcoder: xcoder.o
	$(CXX) src/test.cpp obj/xcoder.o -o build/xcoder_test $(CXXFLAGS)

xcoder.o:
	@echo "Compile xcoder..."
	$(CXX) -c src/xcoder.cpp -o obj/xcoder.o $(CXXFLAGS)
	@echo "Done."
