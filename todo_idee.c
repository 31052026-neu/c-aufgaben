#include <stdio.h>
#include <unistd.h>

#define TODO_FILE_PATH "todo2.txt"
#define AFLAG 'a'

const char todo_file[] = "todo2.txt";

int append_item(const char *);
int show_items(void);
void usage();

int main(int argc, char *argv[]) {

  int opt;
  int item_no = 0;
  int aflag = 0, lflag = 0, dflag = 0;

  char *new_item = NULL;

  while ((opt = getopt(argc, argv, ":a:l")) != -1) {
    switch (opt) {
    case AFLAG:
      aflag = 1;
      new_item = optarg;
      break;
    case 'l':
      lflag = 1;
      break;
    case '?':
    default:
      usage();
    }
  }

  if (aflag && lflag) {
    usage();
    return (1);
  }

  if (aflag)
    append_item(new_item);
  if (lflag)
    show_items();
  if (dflag)
    delete_item(item_no);
}

int append_item(const char *text) {
  FILE *datei = fopen(TODO_FILE_PATH, "a+");
  if (datei == NULL) {
    perror("Datei konnte nicht geöffnet werden");
    return 1;
  }
  fprintf(datei, "%s\n", text);
  fclose(datei);

  return (0);
}

int show_items() {
  char buf[1024];
  int count = 1;

  FILE *datei = fopen(todo_file, "r");
  if (datei == NULL) {
    perror("Datei konnte nicht geöffnet werden");
    return 1;
  }
  while (fgets(buf, sizeof(buf), datei) != NULL) {
    printf("%02d: %s", count++, buf);
  }
  fclose(datei);
  return (0);
}

void usage() { fprintf(stderr, "usage: ...\n"); }