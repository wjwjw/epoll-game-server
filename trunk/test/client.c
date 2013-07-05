#include "global.h"
#define MAXDATASIZE 100

struct Head
{
    int data_len;
    int cmd;
};
// struct Message
// {
//     struct Head head;
//     char data[10];
//   //  short check_code; //校验码
// };
int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in their_addr; // connector'saddress information
 
    if (( argc == 1) || (argc==2) ) 
    {
        fprintf(stderr,"usage: client hostname\nEx:\n$./client01 ip port\n");
        exit(1);
    }
 
    if ((he = gethostbyname(argv[1])) == NULL) 
    { // get the host info
        printf("gethostbyname");
        exit(1);
    }
 
    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1) 
    {
        printf("socket");
        exit(1);
    }
 
    their_addr.sin_family = AF_INET; // host byte order
    their_addr.sin_port = htons(atoi(argv[2])); // short, network byte order
    //their_addr.sin_addr = *(struct in_addr *)(*(he->h_addr_list));
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
   // memset(their_addr.sin_zero, '', sizeof(their_addr.sin_zero));
 
    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof their_addr) == -1) 
    {
        perror("connect");
        exit(1);
    }
   //  struct Head head;
   // // struct Message message = (struct Message*)malloc(sizeof(struct Message));
   //  char *data = "111";
   //  head.data_len = strlen(data);
   //  head.cmd = 1;
    //message.head = head;
    //message.data = data;
    int i;
    char *str = "abcd";
    char *str1 = "er";
    i = 6;
    while( 1 )
    {
       // send(sockfd, &i, sizeof(i), 0 );
        printf("----------------------------%d\n",send(sockfd, &i, sizeof(i), 0 ));
       // send(sockfd, str, strlen(str), 0 );
        printf("----------------------------%d\n",send(sockfd, str, strlen(str), 0 ));
         printf("----------------------------%d\n",send(sockfd, str1, strlen(str1), 0 ));
        // if(send(sockfd, &i, sizeof(i), 0 ) == -1)
        // {
        //     printf("come in-------111111111");
        //     perror("send");
        // }
        // if(send(sockfd, str, strlen(str), 0 ) == -1)
        // {
        //     printf("come in-------111111111");
        //     perror("send");
        // }
        // printf("%s\n",data);
        // if(send(sockfd, data, strlen(data), 0 ) == -1)
        // {
        //             printf("come in-------111111111");
        //             perror("send");
        // }
        printf("come in-------2222222222");
        if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1)
        {
            perror("recv");
        }
        else if( numbytes == 0 )
        {
            printf("Remote server has shutdown!\n");
            break;
        }
 
        buf[numbytes] = '\0';
 
        printf("Received: %s \n",buf);
        sleep(1);
    }
 
    close(sockfd);
    return 0;
}