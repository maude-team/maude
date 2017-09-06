//
//      Class to handle XML syntax and formatting.
//
#ifndef _xmlBuffer_hh_
#define _xmlBuffer_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include <string>
#include <stack>

class XmlBuffer
{
  NO_COPYING(XmlBuffer);

public:
  XmlBuffer(ostream& output, int flushLevel = NONE);
  ~XmlBuffer();

  void beginElement(const string& name);
  void endElement();
  void attributePair(const string& name, const string& value);
  void attributePair(const string& name, const string& value, int index);
  void characterData(const string& charData);
  void comment(const string& text);

private:
  void indent();
  void translate(const string& value);

  ostream& output;
  const int flushLevel;
  stack<string> elements;
  int indentLevel;
  bool startTagIncomplete;
};

#endif
