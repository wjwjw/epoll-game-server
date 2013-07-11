/*  
    Copyright (C) <2013>  <jjchen.lian@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _SERVER_H
#define _SERVER_H

#include "engine.h"
#include "link_list.h"

typedef struct _socket_t
{
    struct double_link_node dnode;
    int32_t status;
    // int32_t isactived;
    // int32_t readable;
    // int32_t writeable;
    int32_t fd;
    int32_t fdx;
    link_list * pending_send; //待发送列表
    link_list * pending_recv; //待接收列表
}socket_t;

void	server_work();
void	tcp_listen(engine_t * e, const char * ip, uint16_t port, struct sockaddr_in *servaddr, int backlog);
socket_t * 	open_socket(int32_t family, int32_t type, int32_t protocol);
int32_t	    socket_bind(int32_t fd, const struct sockaddr * servaddr, socklen_t addrlen);
int32_t	    socket_listen(int32_t fd, int32_t backlog);
int32_t     socket_accept(int32_t sockfd, struct sockaddr *sa, socklen_t *len);
handler_t	recv_data(void * e, void * fd);
socket_t *  init_socket(int32_t sockfd);

#endif


