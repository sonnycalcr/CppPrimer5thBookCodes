#include <string>

class Screen {
  public:
    typedef std::string::size_type pos;
    Screen() = default; // needed because Screen has another constructor
    // cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const // get the character at the cursor
    {
        return contents[cursor];
    } // implicitly inline
    inline char get(pos ht, pos wd) const; // explicitly inline
    Screen &move(pos r, pos c);            // can be made inline later
  private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};