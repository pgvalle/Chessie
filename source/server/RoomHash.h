#pragma once

#include <string>

struct RoomHash
{
  static const int HASH_LEN = 4;

  int num[HASH_LEN] = {0};

  bool greaterThan(const RoomHash &other);
  bool lessThan(const RoomHash &other);
  std::string toString() const;
};