#include <command_list.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool gQuit = 0;
size_t gCommandListSize = 16;

void CommandHelp() {
	printf("This message is supposed to contain all the info on the commands\n");
}

void CommandExit() {
	gQuit = true;
}

void InitCommandList() {
	for (size_t i = 0; i < gCommandListSize; ++i) {
		g_command_list[i] = (Command*) malloc(sizeof(Command));
		if (!g_command_list[i]) {
			return; // no memory
		}
	}

	g_command_list[0]->name_length = 4;
	g_command_list[0]->callback = CommandHelp;
	strncpy(g_command_list[0]->name, "help", g_command_list[0]->name_length + 1); // +1 for the null byte
	strncpy(g_command_list[0]->description, "Show the help screen", 20 + 1);

	g_command_list[1]->name_length = 4;
	g_command_list[1]->callback = CommandExit;
	strncpy(g_command_list[1]->name, "exit", g_command_list[1]->name_length + 1);
	strncpy(g_command_list[1]->description, "Exit the pokedex", 16 + 1);
}

void ClearCommandList() {
	for (size_t i = 0; i < gCommandListSize; ++i) {
		free(g_command_list[i]);
	}
}

// searches the command list for the right command, returns it or NULL if not found
Command *ParseCommand(const char *input) {
	for (size_t i = 0; i < gCommandListSize; ++i) {
		if (!strncmp(input, g_command_list[i]->name, g_command_list[i]->name_length)) {
			return g_command_list[i];
		}
	}
	return NULL;
}

void PerformCommand(Command *c) {
	c->callback();
}

bool CheckCommand(Command *c) {
	return c->name[0] != '\0';
}
