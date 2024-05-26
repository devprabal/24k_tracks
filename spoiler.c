#include <stdio.h>
#include <stdlib.h>

#include "spoiler.h"
#include "common.h"

typedef struct SpoilerRecord
{
    INTENSITY intensity;
    SPOILER_ACTIVITY activities[SPOILER_ACTIVITY_MAX];
} SpoilerRecord;

void print_spoiler_rec_info(SingleRecord* s_info)
{
    SpoilerRecord* info = s_info->spoiler_rec;
    if(!info)
    {
        return;
    }
    printf("\n\nSPOILER");
    printf("\nIntensity: %d\nActivities: ", info->intensity);
    for (int i = 0; i < SPOILER_ACTIVITY_MAX; i++)
    {
        switch (info->activities[i])
        {
        case SPOILER_NOTHING:
            break;
        case SPOILER_1:
            printf("Oops!, ");
            break;
        default:
            break;
        }
    }
}

//// TODO: why does this, int x[N], doesn't work?
// void make_spoiler_record(int yyyy, int mm, int dd, int intensity, int activities[SPOILER_ACTIVITY_MAX])
void make_spoiler_record(int yyyy, int mm, int dd, int intensity, int n_activites, int* activities)
{
    if(!activities)
    {
        return;
    }
    if(n_activites >= SPOILER_ACTIVITY_MAX)
    {
        return;
    }
    int curr_yday = day_of_the_year(yyyy, mm, dd);
    SingleRecord* srec = get_record_for_yday(curr_yday, SPOILER);
    srec->spoiler_rec = calloc(1, sizeof(SpoilerRecord));
    srec->spoiler_rec->intensity = intensity;
    for(int i = 0; i < n_activites; i++)
    {
        srec->spoiler_rec->activities[i] = activities[i];
    }
}

void free_spoiler_rec_info(SingleRecord* s_info)
{
    SpoilerRecord* info = s_info->spoiler_rec;
    if(!info)
    {
        return;
    }
    else
    {
        free(info);
    }
}
