#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <math.h>  

struct packet {
    uint16_t cksum; /* Ack and Data */
    uint16_t len; /* Ack and Data */
    uint32_t ackno; /* Ack and Data */
    uint32_t seqno; /* Data only */
    char data[500]; /* Data only; Not always 500 bytes, can be less */
};
typedef struct packet packet_t;
unsigned short checkSum(unsigned char *addr, int nBytes);
// complete
int rdt_socket(int address_family, int type, int protocol);

// complete
int rdt_bind(int socket_descriptor, const struct sockaddr *local_address, socklen_t address_length);

int rdt_recv(int socket_descriptor, char *buffer, int buffer_length, int flags, struct sockaddr *from_address, int *address_length);
packet udp_rcv(int socket_descriptor, char *buffer, int buffer_length, int flags, struct sockaddr *from_address, int *address_length, packet hPacket, int loopNum);

int rdt_sendto(int socket_descriptor, char *buffer, int buffer_length, int flags, struct sockaddr *destination_address, int address_length);
void udt_sendto(int socket_descriptor, char *buffer, int buffer_length, int flags, struct sockaddr *destination_address, int address_length, packet* hPacket);
// complete
int rdt_close(int fildes);

packet make_pkt(char *buffer, int length, uint32_t seqNo, packet hPacket, int loopNum);
unsigned short getCheckSum(packet cpacket, int length);
void extract_pk(char *buffer, int length, uint32_t seqNo, packet hPacket, int loopNum);
