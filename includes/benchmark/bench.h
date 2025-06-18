/**
 * Sprint benching utilities
 */

#pragma once

typedef struct sprintbenchmarking_entryt  {
    char* display;

    long long total;
} sprintbenchmarking_entryt;

long sprintbench_timeget();