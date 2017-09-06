//
//	Class to generate sequence partitions associated with A and AU matching.
//
#ifndef _sequencePartition_hh_
#define _sequencePartition_hh_

class SequencePartition
{
public:
  SequencePartition(int sequenceLength, int estNrParts = 0);

  void insertPart(int minLength, int maxLength);
  bool solve();
  int start(int partNr) const;
  int end(int partNr) const;
  int partCount() const;

private:
  struct Part
  {
    int minLength;
    int maxLength;
    int sumPrevMin;
    int sumPrevMax;
    int start;
  };

  bool mainSolve(bool findFirst);

  const int sequenceLength;
  Vector<Part> parts;
  int minSum;
  int maxSum;
  bool closed;
  bool failed;
};

inline int
SequencePartition::start(int partNr) const
{
  Assert(closed, "solve() not called");
  Assert(!failed, "non-existent solution");
  return parts[partNr].start;
}

inline int
SequencePartition::end(int partNr) const
{
  Assert(closed, "solve() not called");
  Assert(!failed, "non-existent solution");
  return (partNr == parts.length() - 1) ?
    sequenceLength - 1 : parts[partNr + 1].start - 1;
}

inline int
SequencePartition::partCount() const
{
  return parts.length();
}

#endif

