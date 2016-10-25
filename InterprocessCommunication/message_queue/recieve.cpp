#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#include <stdio.h>
#include <stdlib.h>

//getuid
#include <unistd.h>
#include <sys/types.h>


#define MAX_MSG_SIZE  1024

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
  
   printf("message queue opened, queue id '%d'.\n", msgid);
  struct msgbuf* msg;       /* structure used for received messages. */
  msg = (struct msgbuf*)malloc(sizeof(struct msgbuf)+MAX_MSG_SIZE);
 

  /*
  #include <sys/types.h>
  #include <sys/ipc.h>
  #include <sys/msg.h>

  int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
  ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);

*/
  
  int msg_type = 1;
 for(;;)
 {
    
    int rc = msgrcv(msgid, msg, MAX_MSG_SIZE+1, msg_type,0);
    
    if (rc == -1) {
         return 1;
    }

    printf("Receiver:[%s]\n", msg->mtext);
        /* slow down a little... */
     //sleep(1);

 }

  return 0;
}