#pragma once

#include <stdbool.h>
#include <stddef.h>

// TODO(james): i can do better than this
extern bool gQuit;

typedef struct Command {
	char name[16];
	size_t name_length;
	char description[128];
	void (*callback)(void);
} Command;

static Command *g_command_list[16];

void InitCommandList();
void ClearCommandList();
Command *ParseCommand(const char *input);

void PerformCommand(Command *c);
bool CheckCommand(Command *c);
