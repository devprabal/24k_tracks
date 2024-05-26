#ifndef GYM_H
#define GYM_H

#include "common.h"

typedef enum GYM_ACTIVITY
{
    GYM_NOTHING,
    WEIGHTS,
    CARDIO,
    HIIT,
    SPINNING,
    HOME_TRAINING,
    GYM_ACTIVITY_MAX,
} GYM_ACTIVITY;

void print_gym_rec_info(SingleRecord* s_info);
void make_gym_record(int yyyy, int mm, int dd, int intensity, int n_activites, int* activities);
void free_gym_rec_info(SingleRecord* s_info);

#endif // GYM_H
