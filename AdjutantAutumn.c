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

#define NUM_COUNTERS 	(100)
#define COUNTER_FILE 	"/tmp/hit"
#define NEW_COUNTER_FILE COUNTER_FILE "~"

// Prototypes
void welcome(void);

// For system maintenance
void system_maintenance(void);
void update(void);
void antivirus(void);
// end system maintenance

// For Event sections
void eventHandler(char *message, char *time, char* date);
// end Prototypes

// SYSTEM MAINTENANCE
void system_maintenance(void)
{
	printf(ANC_WHITE"[*]"ANC_RESET" SYSTEM MAINTENANCE\n");
	update();
	antivirus();
	printf(ANC_GREEN"[*]"ANC_RESET" SYSTEMS MAINTENANCE COMPLETE\n");
}

// Notice the arch syntax!!
void update(void)
{
	char updateCommand[50];
	strcpy(updateCommand, "sudo pacman -Syu");

	printf(ANC_WHITE"[*]"ANC_RESET"Updating...\n");
	system(updateCommand);
	printf(ANC_GREEN"[*]"ANC_RESET"Update complete!\n");
}

void antivirus(void)
{
		char updateClam[50];
		char scan[50];

		strcpy(updateClam, "sudo freshclam");
		strcpy(scan, "sudo clamscan / -i -r" );

		printf(ANC_WHITE"[*]"ANC_RESET"Updating virus...\n");
		system(updateClam);
		printf(ANC_GREEN"[*]"ANC_RESET"Update complete\n");
		printf(ANC_WHITE"[*]"ANC_RESET"Scanning...\n");
		system(scan);
		printf(ANC_GREEN"[*]"ANC_RESET"Scanning complete!\n");
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
