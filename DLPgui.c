#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char URL[] = "";
char folder[] = "";


int main(){

    int flag = 0;
    int locat = 0;
    int choice = 0;
    char path[] = "-P C:\\Users\\Gekko\\Desktop\\yt-dlp\\"; 
    char location[30];

    system("cd C:\\yt-dlp");
    system("md C:\\Users\\Gekko\\Desktop\\yt\\download");
    
    /**/
    
    while(1){
      

      printf("\nChoose command: \n1.Download audio \n2.Download video\n3.Change pwd(not working) \n4.Update yt-dlp \n5.Exit\n");
      scanf("%d", &choice);
      
      switch(choice){
          
          case 1: 
            
            while(1){
          
            //char pwd[] = ("pwd.txt", "r");
            char command[]= "yt-dlp -x --audio-format mp3 ";
             
            if(locat){
                strcat(command, location);
            }
            
            printf("\nGive the URL: ");
            scanf("%s", &URL);
            strcat(command, URL);
            system(command);
            
            printf("Press 1 to continue... or 2 to exit\n");
            scanf("%d", &flag);
            if(flag == 2){
            flag = 0;
            break;
            };
            
            
            }
           
            break;

          case 2:
            
          while(1){

            char video[] = "yt-dlp ";
            printf("\nGive the URL: ");
            scanf("%s", &URL);
            strcat(video, URL);
            system(video);


            printf("Press 1 to continue... or 2 to exit\n");
            scanf("%d", &flag);
            if(flag == 2){
            flag = 0;
            break;
            }

          } 

          break;

          case 3:
           
           //printf("Choose folder: \n");
           
           
           printf("Write the correct path to the folder, example: music\n");
           scanf("%s", &folder);
           sprintf(location, "%s%s%s", path, folder, " ");
           
          //printf("Location: %s", location);
           locat = 1;

           
/*
           char pwd[] = "C:\\yt-dlp\\";
           printf("pwd: %s", pwd);
           printf("\ntest: %%\n");
           char title[] = "\\%%(title)s.%%(ext)s";
           printf(" title: %s", title);
           strcat(pwd, folder);
           printf(" pwd: %s", pwd);
           strcat(pwd, title);
           printf(" pwd: %s", pwd);

           
          FILE *file = fopen("pwd.txt", "w");

           if (file == NULL) {
           printf("Unable to open the file for clearing.\n");
           return 1;
           } else { printf("File opened... "); }

           
           
           fprintf(file, "%s", pwd);
           fclose(file);
*/

          break;

          case 4:
          
            system("yt-dlp -U\n");

          break;

          case 5:
          
            printf("Exiting...\n");
            exit(0);

          default:
            
            printf("Choose again: \n");
          
     }
     
     printf("Press Enter to continue...");
     getchar();

    }
  return 0;
}