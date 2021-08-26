#include "clientUdpSocket.hpp"
clientUdpSocket::clientUdpSocket(int sock, stringIO *serverIO) : sock(sock), serverIO(serverIO){};