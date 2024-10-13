#include "RoomHash.h"

static const char *DIGITS = "XgmiJRYSF3O7wfEUnLsMcvKetNZobIAG25ld481kTuDWyHjPa6pQ9BhxVzqrC";

bool RoomHash::greaterThan(const RoomHash &other)
{
  for (int i = HASH_LEN - 1; i >= 0; i--)
  {
    if (num[i] > other.num[i])
      return true;
    if (num[i] < other.num[i])
      return false;
  }
  return false;
}

bool RoomHash::lessThan(const RoomHash &other)
{
  for (int i = HASH_LEN - 1; i >= 0; i--)
  {
    if (num[i] < other.num[i])
      return true;
    if (num[i] > other.num[i])
      return false;
  }
  return false;
}

std::string RoomHash::toString() const
{
  std::string ret = "";
  for (int i = 0; i < HASH_LEN; i++)
    ret += DIGITS[num[i]];
  return ret;
}