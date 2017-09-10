#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define NUM_COUNTERS 	(100)
#define COUNTER_FILE 	"/tmp/hit"
#define NEW_COUNTER_FILE COUNTER_FILE "~"

// Prototypes
void welcome(void);

// For system maintenance
void system_maintenance(void);
void update(void);
void antivirus(_path);
// end system maintenance

// For Event sections
void eventHandler(char *message, char *time, char* date);
// end Prototypes

// SYSTEM MAINTENANCE
void system_maintenance(void)
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
		printf(PT_WIN"Update complete!\n");
	else
		printf(PT_FAIL"Update failed...\n");
		exit(EXIT_FAILURE);
}

void antivirus(_path)
{
	if (_path != "") {
		scanPath = _path;
	}

	char *updateClam = malloc(strlen("clamscan -r -i %s", scanPath));
	char scan[64];

	strcpy(updateClam, "sudo freshclam");
	strcpy(scan, "sudo clamscan -r /home/theippo1000/ComputerScience/" );

	printf(PT_ANN"Updating virus...\n");
	system(updateClam);
	printf(PT_WIN"Update complete\n");
	printf(PT_ANN"Scanning for virus...\n");
	system(scan);

	if (system(scan) == 0)
		printf(PT_WIN"Scanning complete!\n");
	else
		printf(PT_FAIL"Scanning failed!\n");
		exit(EXIT_FAILURE);
}
// END SYSTEM MAINTENANCE

// Just some welcome screen
void welcome(void)
{
	char clear[50];
	strcpy(clear, "clear");
	system(clear);

	// TODO: Add banner!
	printf("Hello, there!\n");
}

int main(int argc, char **argv)
{
	welcome();
	system_maintenance();
}
