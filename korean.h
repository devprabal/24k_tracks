#ifndef KOREAN_H
#define KOREAN_H

#include "common.h"

typedef enum KOREAN_LANG_ACTIVITY
{
    KOREAN_NOTHING,
    IMMERSION,
    KSTUDY,
    KOREAN_LANG_ACTIVITY_MAX,
} KOREAN_LANG_ACTIVITY;

void print_korean_rec_info(SingleRecord* s_info);
void make_koreanlang_record(int yyyy, int mm, int dd, int intensity, int n_activites, int* activities);
void free_korean_rec_info(SingleRecord* s_info);

#endif // KOREAN_H
