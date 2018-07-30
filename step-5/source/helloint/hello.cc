#include <step-5/base/config.h>

#include <step-5/helloint/hello.h>

#ifdef STEP_5_HAVE_LIBZ
#include <zlib.h>
#endif // STEP_5_HAVE_LIBZ

#include <iostream>
#include <vector>

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

#ifdef STEP_5_HAVE_LIBZ
  uLongf compressed_buffer_size = compressBound(message.size());
  std::vector<Bytef> compressed_buffer(compressed_buffer_size);
  compress2(compressed_buffer.data(),
            &compressed_buffer_size,
            reinterpret_cast<const Bytef *>(message.c_str()),
            message.size(),
            Z_BEST_COMPRESSION);
  compressed_buffer.resize(compressed_buffer_size);
#endif // STEP_5_HAVE_LIBZ

  std::cout << "hello, world from the integer " << step << '\n';
#ifdef STEP_5_HAVE_LIBZ
  std::cout << "Original buffer size: " << message.size() << '\n';
  std::cout << "Compressed buffer size: " << compressed_buffer.size() << '\n';
#endif // STEP_5_HAVE_LIBZ
}
