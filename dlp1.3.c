#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char URL[] = "";
char folder[] = "";

    char pwd[256]; // Assuming a reasonable size for the path
    

   

int main(){

    int flag = 0;
    int locat = 0;
    int choice = 0;
    char location[30] = " -P ";

    /*
    char path[] = "-P C:\\Users\\Gekko\\Desktop\\yt-dlp\\"; 
    char location[30];
    
    system("cd C:\\yt-dlp");
    system("md C:\\Users\\Gekko\\Desktop\\yt\\download");
    
    */
    int folder = 0;

     //creating folder download
    const char* folderName = "Download";
    if (access(folderName, F_OK) == 0) {
    } else {

        if (mkdir(folderName) == 0) {
            printf("The folder %s has been created.\n", folderName);
        } else {
            perror("Error creating folder");
            return EXIT_FAILURE;
        }
    }

    //getting pwd
    if (getcwd(pwd, sizeof(pwd)) == NULL) {
        perror("getcwd");
        return 1;
    }
    char path[30];
    strcpy(path, pwd);
    printf("Current working directory: %s\n", pwd);


    while(1){
      

      printf("\n\nChoose command: \n1.Download audio \n2.Download video \n3.Change pwd(not working) \n4.Update/install software \n5.Exit\n");
      scanf("%d", &choice);
      
      switch(choice){
          
          case 1: 
            
            while(1){

            char command[100] = "yt-dlp -x --audio-format mp3 ";

            if(folder == 0){
            //printf("\n%s", location);
            //printf("\n%s", location);
           // printf("\npwd : %s", path);
           strcat(location, path);
            strcat(location, "\\");
           // printf("\n%s", path);
            strcat(location, folderName);
            folder = 1;
            }
            //printf("\n%s", location);
            

            printf("\nGive the URL: ");
            scanf("%s", &URL);
            strcat(command, URL);
            strcat(command, location);

            printf("\n%s", command);
            system(command);
            printf("\n");
            
            //printf("\n%s", path);
            //printf("\n%s", pwd);

            break;
            
            }
           
            break;

          case 2:
            
          while(1){

            char video[] = "yt-dlp ";
            printf("\nGive the URL: ");
            scanf("%s", &URL);
            strcat(video, URL);
            system(video);

            /*
            printf("Press 1 to continue... or 2 to exit\n");
            scanf("%d", &flag);
            if(flag == 2){
            flag = 0;
            break;
            }
            */
           break;

          } 

          break;

          case 3:
           
        //    printf("Choose folder: \n");
           
           
        //    printf("Write the correct path to the folder, example: music\n");
        //    scanf("%s", &folder);
        //    sprintf(location, "%s%s%s", path, folder, " ");
           
        //   printf("Location: %s", location);
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
          printf("\n1.Install\n2.Update\n3.Go back\n");
          int iss;
          scanf("%d", &iss);
          switch(iss){
          case 1:
           system("powershell Invoke-WebRequest -OutFile ytdlp.exe -Uri https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp.exe");
          
          case 2:
            system("yt-dlp -U\n");

          case 3:
          }
          break;
          case 5:
          
            printf("Exiting...\n");
            exit(0);

          default:
            
            printf("Choose again: \n");
          
     }
     
    //printf("Press Enter to continue...");
     getchar();

    }
  return 0;
}