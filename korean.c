#include <stdio.h>
#include <stdlib.h>

#include "korean.h"
#include "common.h"

typedef struct KoreanLangRecord
{
    INTENSITY intensity;
    KOREAN_LANG_ACTIVITY activities[KOREAN_LANG_ACTIVITY_MAX];
} KoreanLangRecord;


void print_korean_rec_info(SingleRecord* s_info)
{
    KoreanLangRecord* info = s_info->koreanlang_rec;
    if(!info)
    {
        return;
    }
    printf("\n\nKOREAN");
    printf("\nIntensity: %d\nActivities: ", info->intensity);
    for (int i = 0; i < KOREAN_LANG_ACTIVITY_MAX; i++)
    {
        switch (info->activities[i])
        {
        case KOREAN_NOTHING:
            break;
        case IMMERSION:
            printf("Immersion, ");
            break;
        case KSTUDY:
            printf("Study, ");
            break;
        default:
            break;
        }
    }
}

void make_koreanlang_record(int yyyy, int mm, int dd, int intensity, int n_activities, int* activities)
{
    if(!activities)
    {
        return;
    }
    if(n_activities >= KOREAN_LANG_ACTIVITY_MAX)
    {
        return;
    }
    int curr_yday = day_of_the_year(yyyy, mm, dd);
    SingleRecord* srec = get_record_for_yday(curr_yday, KOREAN);
    srec->koreanlang_rec = calloc(1, sizeof(KoreanLangRecord));
    srec->koreanlang_rec->intensity = intensity;
    for(int i = 0; i < n_activities; i++)
    {
        srec->koreanlang_rec->activities[i] = activities[i];
    }
}

void free_korean_rec_info(SingleRecord* s_info)
{
    KoreanLangRecord* info = s_info->koreanlang_rec;
    if(!info)
    {
        return;
    }
    else
    {
        free(info);
    }
}
