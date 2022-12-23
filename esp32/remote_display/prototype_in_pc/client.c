#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char const *argv[])
{
    // guide at https://www.binarytides.com/server-client-example-c-sockets-linux/#comments
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // Set the address and port of the server to connect to
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    connect(sock, (struct sockaddr*) &addr, sizeof(addr));
    while(1){
        // Receive a message from the server
        char response[1024];
        recv(sock, response, sizeof(response), 0);
        fprintf(stdout, "Received from the server: %s\n", response);

        // Send a message to the server
        char* message = "Success";
        send(sock, message, strlen(message), 0);
    }

    // Close the socket
    close(sock);

    return 0;
}

