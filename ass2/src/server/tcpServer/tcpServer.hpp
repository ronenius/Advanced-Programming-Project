class tcpServer
{
private:
    int sock;

public:
    tcpServer(int sock);
    void bind();
    void listen();
    int accept();
};