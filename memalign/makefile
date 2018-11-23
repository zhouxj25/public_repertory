TARGET=memalign
pubDir=../public
CXXFLAGS=-std=c++11 -g2 -O2
CXX=g++
memalign:memalign.h memalign.cpp
	$(CXX) -I $(pubDir) $(CXXFLAGS) memalign.cpp main.cpp $(pubDir)/public.cpp -o $(TARGET)

clean:
	rm -rf $(TARGET)
