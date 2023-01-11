#include "SimpleSocket.hpp"

//Default constructor

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface){
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    //Establish socket
    sock = socket(domain, service, protocol);
    test_connection(sock);
    //Establish network connection
    test_connection(connection);
}

// Test connection virtual function

void HDE::SimpleSocket::test_connection(int item_to_test){
    //Confirm connection gets properly established
    if (item_to_test < 0){
        perror("Failed to connect.");
        exit(EXIT_FAILED);
    }
}

//Getter functions

struct sockaddr_in HDE::SimpleSocket::get_address(){
    return address;
}

int HDE::SimpleSocket::get_sock(){
    return sock;
}

int HDE::SimpleSocket::get_connection(){
    return connection;
}