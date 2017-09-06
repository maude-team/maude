//
//      Implementation for class Indent
//
#include "macros.hh"
#include "tty.hh"

const char* const Tty::ansiCode[] =
{
  "\033[0m",
  "\033[1m",
  "\033[2m",
  "\033[4m",
  "\033[5m",
  "\033[7m",
  "\033[8m",

  "\033[30m",
  "\033[31m",
  "\033[32m",
  "\033[33m",
  "\033[34m",
  "\033[35m",
  "\033[36m",
  "\033[37m",

  "\033[40m",
  "\033[41m",
  "\033[42m",
  "\033[43m",
  "\033[44m",
  "\033[45m",
  "\033[46m",
  "\033[47m"
};

bool Tty::allowedFlag = true;

const char*
Tty::ctrlSequence() const
{
  if (allowedFlag)
    return ansiCode[attr];
  return "";
}
