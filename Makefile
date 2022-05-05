
CXXFLAGS = -Itorch_deps/libtorch/include -Itorch_deps/libtorch/include/torch/csrc/api/include -Ltorch_deps/libtorch/lib -ltorch_cpu -lc10 -D_GLIBCXX_USE_CXX11_ABI=0

all: g2p

g2p: g2p.o
	$(CXX) src/test.cpp obj/g2p.o -o build/g2p_test $(CXXFLAGS)

g2p.o:
	@echo "Compile G2P..."
	$(CXX) -c src/g2p.cpp -o obj/g2p.o $(CXXFLAGS)
	@echo "G2P compilation is done."
