#include <fstream>
#include <iostream>
#include <iomanip>

#ifdef __EMSCRIPTEN__
#include "emscripten/val.h"

#include "emscripten.h"
#include "emscripten/bind.h"

emscripten::val
getOutputBin() {
  const size_t bufferLength = 4;
  char * buffer = new char[bufferLength];
  const char outputBinFile[] = "output.bin";

  std::ifstream outputBin( outputBinFile, std::ifstream::in | std::ifstream::binary );
  if( !outputBin.is_open() )
    {
    std::cerr << "Could not open outputBinFile." << std::endl;
    delete[] buffer;
    return emscripten::val::undefined();
    }
  outputBin.read( buffer, bufferLength );
  outputBin.close();

  const emscripten::val view( emscripten::typed_memory_view( bufferLength, reinterpret_cast< unsigned char * >( buffer ) ) );
  emscripten::val array = emscripten::val::global("Uint8Array");
  emscripten::val data = array.new_( bufferLength );
  data.call<void>( "set", view );
  delete[] buffer;

  return data;
}

EMSCRIPTEN_BINDINGS(embind_test_binding) {
  emscripten::function("getOutputBin", &getOutputBin);
}
#endif

int main( int argc, char * argv[] )
{
  if( argc < 5 )
    {
    std::cerr << argv[0] << " <input.txt> <input.bin> <output.txt> <output.bin>" << std::endl;
    return 1;
    }
  const char * inputTxtFile = argv[1];
  const char * inputBinFile = argv[2];
  const char * outputTxtFile = argv[3];
  const char * outputBinFile = argv[4];


  const size_t bufferLength = 2048;
  char * buffer = new char[bufferLength];


  std::ifstream inputTxt( inputTxtFile, std::ifstream::in );
  if( !inputTxt.is_open() )
    {
    std::cerr << "Could not open inputTxtFile." << std::endl;
    delete[] buffer;
    return 1;
    }
  inputTxt.read( buffer, bufferLength );
  size_t readLength = inputTxt.gcount();
  inputTxt.close();
  buffer[readLength] = '\0';


  std::cout << "Input text: " << buffer << std::endl;


  std::ofstream outputTxt( outputTxtFile, std::ofstream::out );
  if( !outputTxt.is_open() )
    {
    std::cerr << "Could not open outputTxtFile." << std::endl;
    delete[] buffer;
    return 1;
    }
  outputTxt.write( buffer, readLength );
  outputTxt.close();


  std::ifstream inputBin( inputBinFile, std::ifstream::in | std::ifstream::binary );
  if( !inputBin.is_open() )
    {
    std::cerr << "Could not open inputBinFile." << std::endl;
    delete[] buffer;
    return 1;
    }
  inputBin.read( buffer, bufferLength );
  readLength = inputBin.gcount();
  inputBin.close();

  std::cerr << "Input binary: ";
  for( size_t ii = 0; ii < readLength; ++ii )
    {
    std::cerr << std::hex << std::setfill('0') << std::setw(2) << int(buffer[ii]);
    }
  std::cerr << std::endl;

  std::ofstream outputBin( outputBinFile, std::ofstream::out | std::ofstream::binary );
  if( !outputBin.is_open() )
    {
    std::cerr << "Could not open outputBinFile." << std::endl;
    delete[] buffer;
    return 1;
    }
  outputBin.write( buffer, readLength );
  outputBin.close();


  delete[] buffer;
  return 0;
}
