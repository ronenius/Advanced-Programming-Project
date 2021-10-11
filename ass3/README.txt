This exercise includes a client and a TCP server
that has some options for operations, including:
uploading train and test files for classifiying, classifying the test file
according to the train file, printing the results,
downloading the results and showing the confusion matrix of the classifier.
The classifier that the server uses is the knn classifier from exercise 1.
There is a classifier directory which is basically the
classifier from exercise 1, a cli directory to group all of the operations
and the user interface, an IO directory for the input and output methods
and a server directory for the tcp and client sides of the server.

The buffer size that we chose for receiving messages is 8192,
the TCP port number is 42069 and the queue size that the TCP server can accept at once is 5.
Also the server has a timeout feature with timeout after 1 minute of not connecting to new clients.

To compile all of the sides of the server go to ass3 folder (cd ass3) and run:

for the server: g++ src/server/tcpServer/serverMain.cpp src/classifier/classifiable.cpp src/classifier/knnClassifier.cpp src/classifier/stringIO.cpp src/io/socketIO.cpp src/cli/classifyCommand.cpp src/cli/cli.cpp src/cli/command.cpp src/cli/confusionMatrix.cpp src/cli/printClassificationCommand.cpp src/cli/saveFileCommand.cpp src/cli/setParametersCommand.cpp src/cli/uploadCommand.cpp src/server/tcpServer/tcpServer.cpp src/server/tcpServer/tcpSocket.cpp -pthread -o serverMain
./serverMain

for the client: g++ src/classifier/classifiable.cpp src/classifier/knnClassifier.cpp src/classifier/stringIO.cpp src/io/socketIO.cpp src/cli/classifyCommand.cpp src/cli/cli.cpp src/cli/command.cpp src/cli/confusionMatrix.cpp src/cli/printClassificationCommand.cpp src/cli/saveFileCommand.cpp src/cli/setParametersCommand.cpp src/cli/uploadCommand.cpp src/server/client/clientMain.cpp src/server/client/clientTcpSocket.cpp src/server/tcpServer/tcpServer.cpp src/server/tcpServer/tcpSocket.cpp -pthread -o clientMain
./clientMain
