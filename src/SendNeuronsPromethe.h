/*
 * SendNeuronsPromethe.h
 *
 *  Created on: 2 juin 2015
 *      Author: jfellus
 */

#ifndef SENDNEURONSPROMETHE_H_
#define SENDNEURONSPROMETHE_H_

#include <pg.h>
#include <matrix.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PACKET_SIZE 2000

typedef struct  __attribute__((__packed__)) {
	size_t nb_neurons;
	int which_s;
	size_t extsize;
	int bCompressed;

	char __padding__[3]; // For 4-bytes alignment
	char MAGIC_CHAR;
} UDP_FRAME_SPECIAL_HEADER;

#define UDP_FRAME_SPECIAL_HEADER_SIZE(header) ((header).MAGIC_CHAR==UDPBYTE_BEGIN ? sizeof(UDP_FRAME_SPECIAL_HEADER) : 1)

#define UDPBYTE_BEGIN 'B'

#ifndef MIN
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#endif


#define ROUND_MULTIPLE(a,b) (((a)/((size_t)(b))+1)*((size_t)(b)))


class SendNeuronsPromethe {
public:
	int port;
	std::string ip;

private:

	unsigned char buf[PACKET_SIZE];

public:
	SendNeuronsPromethe() {
		sockfd = -1;
		target_addr = NULL;
		ip = "localhost";
		port = 10002;
	}


	void init() {
		try {create_socket();} catch(...) { sockfd = -1;}
	}


	void process(const Matrix& m) {
		if(sockfd==-1) return;

		// Header for first packet
		UDP_FRAME_SPECIAL_HEADER header;
		header.MAGIC_CHAR = UDPBYTE_BEGIN;
		header.nb_neurons = m.n;
		header.extsize = 0;
		header.which_s = 1;
		header.bCompressed = 0;
		memcpy(&buf[PACKET_SIZE-sizeof(UDP_FRAME_SPECIAL_HEADER)], &header, sizeof(UDP_FRAME_SPECIAL_HEADER));

		// Send neurons
		send_neurons(m, buf, &header);
	}

private:

	void send_neurons(const Matrix& m, unsigned char* packet_buf, UDP_FRAME_SPECIAL_HEADER* header) {
		float* neuronsbuf = (float*)packet_buf;
		for (uint i=0; i< m.n; i++) {

			*(neuronsbuf++) = m[i];

			if ((unsigned char*)neuronsbuf >= &packet_buf[PACKET_SIZE - UDP_FRAME_SPECIAL_HEADER_SIZE(*header)]) {
				send_packet(packet_buf);
				neuronsbuf = (float*)packet_buf;
				header->MAGIC_CHAR = packet_buf[PACKET_SIZE-1] = 0;
			}
		}
		if(neuronsbuf!=(float*)packet_buf) send_packet(packet_buf);
	}


	struct addrinfo* target_addr;
	int sockfd;

	inline int send_packet(void* buf) {
	   return sendto(sockfd, buf, PACKET_SIZE, 0, target_addr->ai_addr, target_addr->ai_addrlen);
	}

	inline void create_socket() {
	   struct addrinfo hints;
	   memset(&hints, 0, sizeof hints);
	   hints.ai_family = AF_UNSPEC;
	   hints.ai_socktype = SOCK_DGRAM;

	   struct addrinfo  *servinfo,*p;
	   char port[10]; sprintf(port, "%u", this->port);
	   if (getaddrinfo(ip.c_str(), port, &hints, &servinfo) != 0) ERROR("Can't open send UDP socket");

	   for (p = servinfo; p != NULL; p = p->ai_next) {
	      if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) continue;
	      break;
	   }

	   target_addr = p;
	}
};



#endif /* SENDNEURONSPROMETHE_H_ */
