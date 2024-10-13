#include "common.h"
#include <vector>
#include <string>

struct RoomHash
{
  static const int HASH_LEN = 4;
  static constexpr char *DIGITS = "XgmiJRYSF3O7wfEUnLsMcvKetNZobIAG25ld481kTuDWyHjPa6pQ9BhxVzqrC";

  int num[HASH_LEN] = {0};

  bool greaterThan(const RoomHash &other);
  bool lessThan(const RoomHash &other);
  std::string toString() const;
};

struct ChessRoom
{
  static std::string generateHash();

  TCPsocket hostSock = NULL;
  std::string hash = generateHash();
};

std::string ChessRoom::generateHash()
{
  // 61 possibilities for each character composing the hash
  static const char *digits = "123456789"
                              "abcdefghijklmnopqrstuvwxyz"
                              "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  static int num[4] = {0},   // representation of hash as a number in base-61
      ord[4] = {3, 0, 2, 1}; // order in which the digits of num will increment

  std::string ret = "";

  // increment the number each call
  for (int i = 0; i < 4; i++)
  {
    if (num[ord[i]] == 60)
      num[ord[i]] = 0;
    else
    {
      num[ord[i]]++;
      break;
    }
  }

  // get each digit mapped to its corresponding character
  for (int i = 0; i < 4; i++)
    ret += digits[num[i]];

  return ret;
}

int main()
{
  SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS);
  SDLNet_Init();

  TCPsocket server;
  IPaddress serverip;

  SDLNet_ResolveHost(&serverip, NULL, 40000);
  server = SDLNet_TCP_Open(&serverip);

  TCPsocket sock = SDLNet_TCP_AcceptB(server);

  Uint8 reqType;

  SDLNet_TCP_Recv(sock, &reqType, sizeof(reqType));
  if (reqType == 1)
  {
    ChessRoom r;
    r.hostSock = sock;

    // enqueue

    SDLNet_TCP_Send(r.hostSock, r.hash.c_str(), r.hash.size());
  }
  else if (reqType == 2)
  {
    // search queue for room
  }

  return 0;
}
