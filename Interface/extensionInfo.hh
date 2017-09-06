//
//	Abstract base class for extension information.
//
#ifndef _extensionInfo_hh_
#define _extensionInfo_hh_
#ifdef __GNUG__
#pragma interface
#endif

class ExtensionInfo
{
public:
  virtual ~ExtensionInfo() {}

  bool validAfterMatch() const;
  void setValidAfterMatch(bool status);

  bool matchedWhole() const;
  void setMatchedWhole(bool status);

  virtual DagNode* buildMatchedPortion() const = 0;
  virtual ExtensionInfo* makeClone() const = 0;		// for saving extension info
  virtual void copy(ExtensionInfo* extensionInfo) = 0;	// for restoring extension info

private:
  //
  //	The match phase records if extension info is valid after
  //	the match phase or do we need to wait until after
  //	the solve phase is successful.
  //
  Bool validAfterMatchFlag;
  //
  //	Did we match the whole of the subject theory layer
  //	(extension is empty) or just part.
  //
  Bool matchedWholeFlag;
};

inline bool
ExtensionInfo::validAfterMatch() const
{
  return validAfterMatchFlag;
}

inline void
ExtensionInfo::setValidAfterMatch(bool status)
{
  validAfterMatchFlag = status;
}

inline bool
ExtensionInfo::matchedWhole() const
{
   return matchedWholeFlag;
}

inline void
ExtensionInfo::setMatchedWhole(bool status)
{
  matchedWholeFlag = status;
}

#endif
