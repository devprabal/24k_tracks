#ifndef SPOILER_H
#define SPOILER_H

#include "common.h"

typedef enum SPOILER_ACTIVITY
{
    SPOILER_NOTHING,
    SPOILER_1,
    SPOILER_ACTIVITY_MAX,
} SPOILER_ACTIVITY;

void print_spoiler_rec_info(SingleRecord* s_info);
void make_spoiler_record(int yyyy, int mm, int dd, int intensity, int n_activites, int* activities);
void free_spoiler_rec_info(SingleRecord* s_info);

#endif // SPOILER_H
