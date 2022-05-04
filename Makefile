
CXXFLAGS = -Itorch_deps/libtorch/include -Itorch_deps/libtorch/include/torch/csrc/api/include -Ltorch_deps/libtorch/lib -ltorch_cpu -lc10 -D_GLIBCXX_USE_CXX11_ABI=0

xcoder: xcoder.o
	$(CXX) src/test.cpp obj/xcoder.o -o build/xcoder_test $(CXXFLAGS)

xcoder.o:
	@echo "Compile xcoder..."
	$(CXX) -c src/xcoder.cpp -o obj/xcoder.o $(CXXFLAGS)
	@echo "Done."
