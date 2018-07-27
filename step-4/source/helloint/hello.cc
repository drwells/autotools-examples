#include <iostream>
#include <vector>

#include <zlib.h>

#include <helloint/hello.h>

// adapted from: http://stackoverflow.com/questions/7540259/deflate-and-inflate-zlib-h-in-c
void write_hello(const int step)
{
  std::string message;
  if (step > 0)
    {
      for (int i = 0; i < step - 1; ++i)
        message += "Hello ";
      message += "Hello!";
    }

  uLongf compressed_buffer_size = compressBound(message.size());
  std::vector<Bytef> compressed_buffer(compressed_buffer_size);
  compress2(compressed_buffer.data(),
            &compressed_buffer_size,
            reinterpret_cast<const unsigned char *>(message.c_str()),
            message.size(),
            Z_BEST_COMPRESSION);
  compressed_buffer.resize(compressed_buffer_size);

  std::cout << "hello, world from the integer " << step << '\n';
  std::cout << "Original buffer size: " << message.size() << '\n';
  std::cout << "Compressed buffer size: " << compressed_buffer.size() << '\n';
}
