#include <stdio.h>
#include <stdlib.h>

#include "gym.h"
#include "common.h"

typedef struct GymRecord
{
    INTENSITY intensity[GYM_ACTIVITY_MAX];
    GYM_ACTIVITY activities[GYM_ACTIVITY_MAX];
} GymRecord;


void print_gym_rec_info(SingleRecord* s_info)
{
    GymRecord* info = s_info->gym_rec;
    if(!info)
    {
        return;
    }
    printf("\n\nGYM");
    printf("\nIntensity: %d\nActivities: ", info->intensity);
    for (int i = 0; i < GYM_ACTIVITY_MAX; i++)
    {
        switch (info->activities[i])
        {
        case GYM_NOTHING:
            break;
        case WEIGHTS:
            printf("Weights, ");
            break;
        case CARDIO:
            printf("Cardio, ");
            break;
        case HIIT:
            printf("HIIT, ");
            break;
        case SPINNING:
            printf("Spinning, ");
            break;
        case HOME_TRAINING:
            printf("Home Training, ");
            break;
        default:
            break;
        }
    }
}

void make_gym_record(int yyyy, int mm, int dd, int intensity, int n_activites, int* activities)
{
    if(!activities)
    {
        return;
    }
    if(n_activites >= GYM_ACTIVITY_MAX)
    {
        return;
    }
    int curr_yday = day_of_the_year(yyyy, mm, dd);
    SingleRecord* srec = get_record_for_yday(curr_yday, GYM);
    srec->gym_rec = calloc(1, sizeof(GymRecord));
    srec->gym_rec->intensity = intensity;
    for(int i = 0; i < n_activites; i++)
    {
        srec->gym_rec->activities[i] = activities[i];
    }
}

void free_gym_rec_info(SingleRecord* s_info)
{
    GymRecord* info = s_info->gym_rec;
    if(!info)
    {
        return;
    }
    else
    {
        free(info);
    }
}
