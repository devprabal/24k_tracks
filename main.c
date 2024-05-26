#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "common.h"
#include "gym.h"
#include "spoiler.h"
#include "study.h"
#include "korean.h"

static void print_records_for_day(int yyyy, int mm, int dd)
{
    printf("\n=================");
    struct tm this_day =  yyyymmdd_to_struct_tm(yyyy, mm, dd);
    print_tm_info(this_day);

    int yday = day_of_the_year(yyyy, mm, dd);
    {
        SingleRecord* srec = get_record_for_yday(yday, GYM);
        print_gym_rec_info(srec);
    }
    {
        SingleRecord* srec = get_record_for_yday(yday, STUDY);
        print_study_rec_info(srec);
    }
    {
        SingleRecord* srec = get_record_for_yday(yday, KOREAN);
        print_korean_rec_info(srec);
    }
    {
        SingleRecord* srec = get_record_for_yday(yday, SPOILER);
        print_spoiler_rec_info(srec);
    }
    printf("\n=================\n");
}

static void entries_MAY(void)
{
    {
        make_gym_record(2024, 05, 19, INTENSITY_5, 2, (int []){WEIGHTS, CARDIO});
        make_koreanlang_record(2024, 05, 19, INTENSITY_2, 1, (int []){KSTUDY});
        make_spoiler_record(2024, 05, 19, INTENSITY_4, 1, (int []){SPOILER_1});
        make_study_record(2024, 05, 19, INTENSITY_5, 3, (int []){CODING, WATCHING, READING});
        print_records_for_day(2024, 05, 19);
    }
    {   
        make_gym_record(2024, 05, 25, INTENSITY_0, 0, 0);
        make_koreanlang_record(2024, 05, 25, INTENSITY_0, 0, 0);
        make_spoiler_record(2024, 05, 25, INTENSITY_5, 1, (int []){SPOILER_1});
        make_study_record(2024, 05, 25, INTENSITY_2, 1, (int []){CODING,});
        print_records_for_day(2024, 05, 25);
    }
}

static void cleanup(void)
{
    for(int i = 0; i < DAYS_IN_YEAR_2024; i++)
    {
        {
            SingleRecord* srec = get_record_for_yday(i, GYM);
            free_gym_rec_info(srec);
        }
        {
            SingleRecord* srec = get_record_for_yday(i, KOREAN);
            free_korean_rec_info(srec);
        }
        {
            SingleRecord* srec = get_record_for_yday(i, STUDY);
            free_study_rec_info(srec);
        }
        {
            SingleRecord* srec = get_record_for_yday(i, SPOILER);
            free_spoiler_rec_info(srec);
        }
    }
}

int main(void)
{
    day_of_year_today();
    entries_MAY();
    cleanup();
    return 0;
}
