#include "common.h"

TCPsocket SDLNet_TCP_AcceptB(TCPsocket server)
{
  TCPsocket sock = NULL;
  while (sock == NULL)
    sock = SDLNet_TCP_Accept(server);
  return sock;
}