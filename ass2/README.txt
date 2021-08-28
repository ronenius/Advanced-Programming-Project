This exercise includes a client and UDP and TCP servers
that get an unclassified message of irises from the client,
classify it with the KNN classifier (K=5) from exercise 1
according to the given classified samples
and send the classified irises back to the client.
There is a classifier directory which is basically the
classifier from exercise 1 and a new directory that is the server.

The buffer size that we chose for receiving messages is 4096,
the UDP port number is 6969, the TCP port number is 42069
and the queue size that the TCP server can accept at once is 5.

To compile all of the sides of the servers go to ass2 folder (cd ass2) and run:

for TCP: g++ src/server/tcpServer/main.cpp src/server/tcpServer/tcpSocket.cpp src/server/tcpServer/tcpServer.cpp src/server/classifyingServer.cpp src/classifier/iris.cpp src/classifier/irisBuilder.cpp src/classifier/knnClassifier.cpp src/classifier/stringIO.cpp -o tcpMain
./tcpMain

for UDP: g++ src/server/udpServer/main.cpp src/server/udpServer/udpSocket.cpp src/server/classifyingServer.cpp src/classifier/iris.cpp src/classifier/irisBuilder.cpp src/classifier/knnClassifier.cpp src/classifier/stringIO.cpp -o udpMain
./udpMain

for the client: g++ src/server/client/main.cpp src/server/client/clientTcpSocket.cpp src/server/client/clientUdpSocket.cpp src/server/tcpServer/tcpServer.cpp src/server/udpServer/udpSocket.cpp src/server/classifyingServer.cpp src/classifier/iris.cpp src/classifier/irisBuilder.cpp src/classifier/knnClassifier.cpp src/classifier/stringIO.cpp -o clientMain
./clientMain