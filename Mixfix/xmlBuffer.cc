//
//      Implementation for class XmlBuffer.
//
#ifdef __GNUG__
#pragma implementation
#endif

//      utility stuff
#include "macros.hh"

#include "xmlBuffer.hh"

XmlBuffer::XmlBuffer(ostream& output, int flushLevel)
  : output(output),
    flushLevel(flushLevel)
{
  output << "<?xml version=\"1.0\" encoding=\"US-ASCII\" standalone=\"yes\"?>\n";
  indentLevel = 0;
  startTagIncomplete = false;
}

XmlBuffer::~XmlBuffer()
{
  while (!(elements.empty()))
    endElement();
}

void
XmlBuffer::characterData(const string& charData)
{
  if (startTagIncomplete)
    {
      output << ">\n";
      startTagIncomplete = false;
    }
  output << charData;
}
void
XmlBuffer::comment(const string& text)
{
  if (startTagIncomplete)
    {
      output << ">\n";
      startTagIncomplete = false;
    }
  indent();
  output << "<!-- " << text << " -->\n";
}

void
XmlBuffer::beginElement(const string& name)
{
  if (startTagIncomplete)
    output << ">\n";
  indent();
  output << '<' << name;
  startTagIncomplete = true;
  ++indentLevel;
  elements.push(name);
}

void
XmlBuffer::endElement()
{
  Assert(!(elements.empty()), cerr << "empty element stack");

  --indentLevel;
  if (startTagIncomplete)
    {
      output << "/>\n";
      startTagIncomplete = false;
    }
  else
    {
      indent();
      output << "</" << elements.top() << ">\n";
    }
  if (indentLevel <= flushLevel)
    output.flush();
  elements.pop();
}

void
XmlBuffer::attributePair(const string& name, const string& value)
{
  output << ' ' << name << "=\"";
  translate(value);
  output << '"';
}

void
XmlBuffer::attributePair(const string& name, const string& value, int index)
{
  output << ' ' << name << "=\"";
  translate(value);
  output << index << '"';
}

void
XmlBuffer::indent()
{
  for (int i = indentLevel; i > 0 ; i--)
    output << ' ';
}

void
XmlBuffer::translate(const string& value)
{
  const string::const_iterator e = value.end();
  for (string::const_iterator i = value.begin(); i != e; ++i)
    {
      switch (*i)
	{
	case '<':
	  output << "&lt;";
	  break;
	case '&':
	  output << "&amp;";
	  break;
	case '"':
	  output << "&quot;";
	  break;
	default:
	  output << *i;
	}
    }
}
