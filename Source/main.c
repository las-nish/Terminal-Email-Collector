#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define _DATA_FILE_ "/home/lasan0432/.tool/MailC/collected_email.list"

int main(void) {
  system("clear");

  FILE *__temp_file__ = fopen(_DATA_FILE_, "r+");

  if (__temp_file__ == NULL) {
    fprintf(stdout, "Check permission for the %s file\n", _DATA_FILE_);
    exit(1);
  }

  fprintf(stdout, "  ┌────┬───────────────────────┬────┐\n");
  fprintf(stdout, "  │┼┼┼┼│                       │┼┼┼┼│\n");
  fprintf(stdout, "  │┼┼┼┼│ MailC Email Collector │┼┼┼┼│\n");
  fprintf(stdout, "  │┼┼┼┼│                       │┼┼┼┼│\n");
  fprintf(stdout, "  └────┴───────────────────────┴────┘\n\n");

  int data_count = 0;

  char data_type[16 * sizeof(char *)];
  char data_category[16 * sizeof(char *)];
  char data_email[1024 * sizeof(char *)];
  char data_website[1024 * sizeof(char *)];

  for (;;) {
    if (fscanf(__temp_file__, "%s %s %s %s", data_type, data_category,
               data_email, data_website) != 4) {
      if (feof(__temp_file__)) {
        break;
      }

      if (data_type[0] == '#') {
        while (fgetc(__temp_file__) != '\n') {
        }

        continue;
      }
    }

    fprintf(stdout, "- %s [ %s ]\n", data_email, data_website);

    data_count = data_count + 1;
  }

  fprintf(stdout, "\n");

  fprintf(stdout, "+ Data File   : %s\n", _DATA_FILE_);
  fprintf(stdout, "+\n");

  fprintf(stdout, "+ Enter \"add\" for add new data\n");
  fprintf(stdout, "+ Enter \"exit\" for exit\n\n");

  char shell_cmd[128 * sizeof(char *)];
  int shell_added = 0;

  for (;;) {
    fprintf(stdout, "MailC > ");
    scanf("%s", shell_cmd);

    if (!strcmp(shell_cmd, "exit")) {
      fprintf(stdout, "\n");
      break;
    } else if (!strcmp(shell_cmd, "add")) {
      fprintf(stdout, "\n\tTotal Emails      : %d\n", data_count);
      fprintf(stdout, "\tNewly Added Emails: %d\n\n", shell_added);

      fprintf(stdout, "\n\t┌──────────────────────────────────────┐\n");
      fprintf(stdout, "\t│ Options for Types:                   │\n");
      fprintf(stdout, "\t│   [1]  Individual                    │\n");
      fprintf(stdout, "\t│   [2]  Startup                       │\n");
      fprintf(stdout, "\t│   [3]  Company                       │\n");
      fprintf(stdout, "\t│   [4]  Organization                  │\n");
      fprintf(stdout, "\t│   [5]  Foundation                    │\n");
      fprintf(stdout, "\t│                                      │\n");
      fprintf(stdout, "\t│ Options for Category:                │\n");
      fprintf(stdout, "\t│   [1]  Android Mobile App Developer  │\n");
      fprintf(stdout, "\t│   [2]  Android Mobile Game Developer │\n");
      fprintf(stdout, "\t│   [3]  iOS Mobile App Developer      │\n");
      fprintf(stdout, "\t│   [4]  iOS Mobile Game Developer     │\n");
      fprintf(stdout, "\t│   [5]  Android + iOS App Developer   │\n");
      fprintf(stdout, "\t│   [6]  Android + iOS Game Developer  │\n");
      fprintf(stdout, "\t│   [7]  Linux software Developer      │\n");
      fprintf(stdout, "\t│   [8]  Unix Software Developer       │\n");
      fprintf(stdout, "\t│   [9]  Windows Software Developer    │\n");
      fprintf(stdout, "\t│   [10] MacOS Software Developer      │\n");
      fprintf(stdout, "\t│   [11] Blogger                       │\n");
      fprintf(stdout, "\t│   [12] Youtuber                      │\n");
      fprintf(stdout, "\t│   [13] Gamer                         │\n");
      fprintf(stdout, "\t│   [14] Graphic Designer              │\n");
      fprintf(stdout, "\t│   [15] Music Artist                  │\n");
      fprintf(stdout, "\t│   [16] Graphic Artist                │\n");
      fprintf(stdout, "\t│   [17] Unknown                       │\n");
      fprintf(stdout, "\t└──────────────────────────────────────┘\n\n");

      char get_type[16 * sizeof(char *)];
      char get_category[16 * sizeof(char *)];
      char get_email[1024 * sizeof(char *)];
      char get_website[1024 * sizeof(char *)];

      fprintf(stdout, " > Enter Type     -> ");
      scanf("%s", get_type);

      fprintf(stdout, " > Enter Category -> ");
      scanf("%s", get_category);

      fprintf(stdout, " > Enter Email    -> ");
      scanf("%s", get_email);

      fprintf(stdout, " > Enter Website: -> ");
      scanf("%s", get_website);

      char converted_type[16 * sizeof(char *)];
      char converted_category[16 * sizeof(char *)];

      if (!strcmp(get_type, "1")) {
        strcpy(converted_type, "Individual");
      } else if (!strcmp(get_type, "2")) {
        strcpy(converted_type, "Startup");
      } else if (!strcmp(get_type, "3")) {
        strcpy(converted_type, "Company");
      } else if (!strcmp(get_type, "4")) {
        strcpy(converted_type, "Organization");
      } else if (!strcmp(get_type, "5")) {
        strcpy(converted_type, "Foundation");
      } else {
        strcpy(converted_type, "UNKNOWN");
      }

      if (!strcmp(get_category, "1")) {
        strcpy(converted_category, "Android_Mobile_App_Developer");
      } else if (!strcmp(get_category, "2")) {
        strcpy(converted_category, "Android_Mobile_Game_Developer");
      } else if (!strcmp(get_category, "3")) {
        strcpy(converted_category, "iOS_Mobile_App_Developer");
      } else if (!strcmp(get_category, "4")) {
        strcpy(converted_category, "iOS_Mobile_Game_Developer");
      } else if (!strcmp(get_category, "5")) {
        strcpy(converted_category, "Android_+_iOS_App_Developer");
      } else if (!strcmp(get_category, "6")) {
        strcpy(converted_category, "Android_+_iOS_Game_Developer");
      } else if (!strcmp(get_category, "7")) {
        strcpy(converted_category, "Linux_software_Developer");
      } else if (!strcmp(get_category, "8")) {
        strcpy(converted_category, "Unix_Software_Developer");
      } else if (!strcmp(get_category, "9")) {
        strcpy(converted_category, "Windows_Software_Developer");
      } else if (!strcmp(get_category, "10")) {
        strcpy(converted_category, "MacOS_Software_Developer");
      } else if (!strcmp(get_category, "11")) {
        strcpy(converted_category, "Blogger");
      } else if (!strcmp(get_category, "12")) {
        strcpy(converted_category, "Youtuber");
      } else if (!strcmp(get_category, "13")) {
        strcpy(converted_category, "Gamer");
      } else if (!strcmp(get_category, "14")) {
        strcpy(converted_category, "Graphic_Designer");
      } else if (!strcmp(get_category, "15")) {
        strcpy(converted_category, "Music_Artist");
      } else if (!strcmp(get_category, "16")) {
        strcpy(converted_category, "Graphic_Artist");
      } else if (!strcmp(get_category, "17")) {
        strcpy(converted_category, "Unknown");
      } else {
        strcpy(converted_category, "UNKNOWN");
      }

      fprintf(__temp_file__, "%-20s %-40s %-50s %s\n", converted_type,
              converted_category, get_email, get_website);

      shell_added = shell_added + 1;
    } else {
      fprintf(stdout, "~ invalid command ~\n\n");
      continue;
    }

    fprintf(stdout, "\n");
  }

  fclose(__temp_file__);

  return EXIT_SUCCESS;
}
