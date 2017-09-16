#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// If ya can't see 'tis is colors, then it's prob'rly the best ya phucked off!
#define ANC_RED				"\x1b[31m"
#define ANC_GREEN			"\x1b[32m"
#define ANC_YELLOW		"\x1b[33m"
#define ANC_BLUE			"\x1b[34m"
#define ANC_MAGENTA		"\x1b[35m"
#define ANC_CYAN			"\x1b[36m"
#define ANC_WHITE			"\x1b[37m"
#define ANC_RESET			"\x1b[0m"

#define PT_ANN				"\x1b[37m[*]\x1b[0m "
#define PT_WIN				"\x1b[32m[*]\x1b[0m "
#define PT_FAIL				"\x1b[31m[*]\x1b[0m "

// Prototypes
// For system maintenance
void system_maintenance();
void update(void);
void antivirus(void);
// end system maintenance

// For note thingy
void noteHandler(void);
void createNote(void);
void readNote(void);
void readNoteList(void);
void updateNote(void);
void deleteNote(void);
// end note
// end Prototypes

// SYSTEM MAINTENANCE
void system_maintenance()
{
	printf(PT_ANN"SYSTEM MAINTENANCE\n");
		update();
		antivirus();
	printf(PT_WIN"SYSTEMS MAINTENANCE COMPLETE\n");
}

// Notice the arch syntax!!
void update(void)
{
	char *updateCommand = malloc(64);
	strcpy(updateCommand, "sudo pacman -Syu");

	printf(PT_ANN"Updating...\n");
	if (system(updateCommand) == 0)
	{
		printf(PT_WIN"Update complete!\n");
	}
	else
	{
		printf(PT_FAIL"Update failed...\n");
		exit(EXIT_FAILURE);
	}
}

void antivirus()
{
	char *scanPath;
	char *basicCmd;
	char *updateCmd;
	char *updateClam;
	char *scan;
	size_t totalCmdSize;

	updateCmd = "sudo freshclam";
	basicCmd = "sudo clamscan -r -i ";
	scanPath = "/";

	totalCmdSize = (sizeof(basicCmd) + sizeof(scanPath));

	updateClam = malloc(sizeof(updateCmd));
	scan = malloc(sizeof(totalCmdSize));

	strcat(scan, basicCmd);
	strcat(scan, scanPath);

	strcpy(updateClam, updateCmd);

	printf(PT_ANN"Updating virus...\n");
	system(updateClam);
	printf(PT_WIN"Update complete\n");
	printf("Executing command: %s\n", scan);
	printf(PT_ANN"Scanning for virus...\n");
	if (system(scan) == 0)
	{
		printf(PT_WIN"Scanning complete!\n");
	}
	else
	{
		printf(PT_FAIL"Scanning failed!\n");
		exit(EXIT_FAILURE);
	}
}
// END SYSTEM MAINTENANCE

// NOTES
void noteHandler(void)
{
	char *choice;
	choice = malloc(4);

	printf("1) Add new note\n");
	printf("2) Add new note\n");
	printf("3) Add new note\n");
	printf("4) Add new note\n");

	scanf("%s", choice);
	if (strcmp(choice, "add") == 0) { createNote(); }
	else 	if (strcmp(choice, "read") == 0 ) { readNote(); }
	else 	if (strcmp(choice, "read*") == 0 ) { readNoteList(); }
	else 	if (strcmp(choice, "update") == 0 ) { updateNote(); }
	else 	if (strcmp(choice, "delete") == 0 ) { deleteNote(); }
}

void createNote(void)
{

}

void readNote(void)
{

}

void readNoteList(void)
{

}

void updateNote(void)
{

}

void deleteNote(void)
{

}

// END NOTES

int main(int argc, char **argv)
{
	int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
	int c;

	while ((c = getopt (argc, argv, "abmnc:")) != -1)
	{
    switch (c)
      {
			case 'm':
				system_maintenance();
				break;
			case 'n':
				noteHandler();
				break;
			case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
	}

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  return 0;

}
