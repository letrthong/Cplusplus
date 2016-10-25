#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#include <stdio.h>
#include <stdlib.h>

//getuid
#include <unistd.h>
#include <sys/types.h>

//strcpy
#include <string.h>

int main()
{

  key_t key =getuid();; /* key to be passed to msgget() */ 
  int mask =0666;/* msgflg to be passed to msgget() */ 
  int msgid  = msgget(key, mask);

  if (msgid == -1) 
  {
    msgid = msgget(key, mask | IPC_CREAT);
    if (msgid == -1) {
      fprintf(stderr, "Could not create message queue.\n");
      return 1;
    }
  }

    char* msg_text = "hello world  ";
    /* allocate a message with enough space for length of string and */
    /* one extra byte for the terminating null character.            */
    struct msgbuf* msg =(struct msgbuf*)malloc(sizeof(struct msgbuf) + strlen(msg_text) );
    /* set the message type. for example - set it to '1'. */
    msg->mtype = 1;
    /* finally, place the "hello world" string inside the message. */
    strcpy(msg->mtext, msg_text);
  
  int i= 0;
  for(;;)
  {
     i++;


      int rc = msgsnd(msgid, msg, strlen(msg_text)+1, 0);
      if (rc == -1) {
          perror("msgsnd");
          exit(1);
      }
      usleep(100);
      printf("Sender: %s\n",msg_text);
  }
   
  return 0;
}