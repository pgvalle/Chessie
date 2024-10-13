#include "common.h"

int main() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();

  TCPsocket server;
  IPaddress serverip;

  // connect to server
  SDLNet_ResolveHost(&serverip, "localhost", 40000);
  server = SDLNet_TCP_Open(&serverip);

  Uint32 p2host;
  bool listen;
  SDLNet_TCP_Recv(server, &p2host, sizeof(p2host));
  SDLNet_TCP_Recv(server, &listen, sizeof(listen));
  SDLNet_TCP_Close(server);

  TCPsocket psock;
  if (listen)
  {
    SDLNet_ResolveHost(&serverip, NULL, 38000);
    server = SDLNet_TCP_Open(&serverip);
    psock = SDLNet_TCP_AcceptB(server);
    SDLNet_TCP_Close(server);
  }
  else
  {
    SDLNet_ResolveHost(&serverip, NULL, 38000);
    SDL_Delay(2000); // guarantee that other player is listening
    serverip.host = p2host;
    psock = SDLNet_TCP_Open(&serverip);
  }

  SDLNet_TCP_Close(psock);

  SDLNet_Quit();
  SDL_Quit();

  return 0;
}
