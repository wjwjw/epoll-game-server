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
#include "acceptor.h"
#include "server.h"
#include "global.h"

void
create_acceptor() {

}

void
add_listener(const char * ip, uint32_t port) {
    struct sockaddr_in serveraddr;
   // int socketfd;
    tcp_listen(ip, port, &serveraddr, 256);
}

void
acceptor_run() {

}