#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{

  key_t key; /* key to be passed to msgget() */ 
  int msgflg;/* msgflg to be passed to msgget() */ 
  int ret  = msgget(key, msgflg);

  return 0;
}