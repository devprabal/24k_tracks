#include <stdio.h>
#include <stdlib.h>

#include "study.h"
#include "common.h"

typedef struct StudyRecord
{
    INTENSITY intensity;
    STUDY_ACTIVITY activities[STUDY_ACTIVITY_MAX];
} StudyRecord;

void print_study_rec_info(SingleRecord* s_info)
{
    StudyRecord* info = s_info->study_rec;
    if(!info)
    {
        return;
    }
    printf("\n\nSTUDY");
    printf("\nIntensity: %d\nActivities: ", info->intensity);
    for (int i = 0; i < STUDY_ACTIVITY_MAX; i++)
    {
        switch (info->activities[i])
        {
        case STUDY_NOTHING:
            break;
        case READING:
            printf("Reading, ");
            break;
        case WATCHING:
            printf("Watching, ");
            break;
        case CODING:
            printf("Coding, ");
            break;
        case WRITING:
            printf("Writing, ");
            break;
        case TEACHING:
            printf("Teaching, ");
            break;
        default:
            break;
        }
    }
}

void make_study_record(int yyyy, int mm, int dd, int intensity, int n_activites, int* activities)
{
    if(!activities)
    {
        return;
    }
    if(n_activites >= STUDY_ACTIVITY_MAX)
    {
        return;
    }
    int curr_yday = day_of_the_year(yyyy, mm, dd);
    SingleRecord* srec = get_record_for_yday(curr_yday, STUDY);
    srec->study_rec = calloc(1, sizeof(StudyRecord));
    srec->study_rec->intensity = intensity;
    for(int i = 0; i < n_activites; i++)
    {
        srec->study_rec->activities[i] = activities[i];
    }
}

void free_study_rec_info(SingleRecord* s_info)
{
    StudyRecord* info = s_info->study_rec;
    if(!info)
    {
        return;
    }
    else
    {
        free(info);
    }
}
