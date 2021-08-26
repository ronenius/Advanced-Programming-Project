class tcpServer
{
private:
    int sock;

public:
    static const int TCP_PORT;

    tcpServer(int sock);
    void bind();
    void listen();
    int accept();
};