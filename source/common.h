#pragma once

#include <SDL_net.h>

#define CHESS_PORT 40000

struct OpponentInfo {
  IPaddress addr;
  bool listen;
};

TCPsocket SDLNet_TCP_AcceptB(TCPsocket server);
