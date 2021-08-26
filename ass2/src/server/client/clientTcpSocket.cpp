#include "clientTcpSocket.hpp"
clientTcpSocket::clientTcpSocket(int sock, stringIO *serverIO) : sock(sock), serverIO(serverIO){};