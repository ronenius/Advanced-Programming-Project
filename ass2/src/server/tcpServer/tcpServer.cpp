#include "tcpServer.hpp"
const int tcpServer::TCP_PORT = 42069;
tcpServer::tcpServer(int sock) : sock(sock){};