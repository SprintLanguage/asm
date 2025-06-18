/**
 * Sprint benching utilities
 */

#pragma once

#define SprintBenchFunc(func, entry, ...) \
    double l = sprintbench_timeget(); \ 
    func(__VA_ARGS__); \
    double took = sprintbench_timeget() - l; \
    entry->total += took; 

#define SprintCategory(catName) \
    sprintbenchmarking_entryt* catName = malloc(sizeof(sprintbenchmarking_entryt)); \
    catName->total = 0l; \
    catName->display = #catName;

#define SprintShowCategory(cat) \
    printf("Category "); \
    printf(#cat); \
    printf(": \nTotal time taken: %.2f micros\n", cat->total);

typedef struct sprintbenchmarking_entryt  {
    char* display;

    double total;
} sprintbenchmarking_entryt;

double sprintbench_timeget();

