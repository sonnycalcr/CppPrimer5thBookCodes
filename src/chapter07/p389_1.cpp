#include <string>

class Screen {
  public:
    typedef std::string::size_type pos;

  private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};