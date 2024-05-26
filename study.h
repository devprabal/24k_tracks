#ifndef STUDY_H
#define STUDY_H

#include "common.h"

typedef enum STUDY_ACTIVITY
{
    STUDY_NOTHING,
    READING,
    WATCHING,
    CODING,
    WRITING,
    TEACHING,
    STUDY_ACTIVITY_MAX,
} STUDY_ACTIVITY;

void print_study_rec_info(SingleRecord* s_info);
void make_study_record(int yyyy, int mm, int dd, int intensity, int n_activites, int* activities);
void free_study_rec_info(SingleRecord* s_info);

#endif // STUDY_H
