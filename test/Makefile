CXX=g++
CXXFLAGS=-std=c++14 -I../

TARGET=fmt.test

$(TARGET):fmt_test.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)
  
clean:
	rm -f $(TARGET)
