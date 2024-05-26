#include <time.h>
#include <stdio.h>

#include "common.h"

typedef struct Day
{
    struct tm yyyymmdd;
    SingleRecord records[NUMBER_OF_RECORD_TYPES];
} Day;

static Day days[DAYS_IN_YEAR_2024] = {0};

SingleRecord* get_record_for_yday(int yday, RECORD_TYPE type)
{
    return &(days[yday].records[type]);
}

struct tm yyyymmdd_to_struct_tm(int yyyy, int mm, int dd)
{
    struct tm this_date = {
        .tm_year = yyyy - 1900,
        .tm_mon = mm - 1,
        .tm_mday = dd};
    return this_date;
}

int day_of_the_year(int yyyy, int mm, int dd)
{
    struct tm this_day = yyyymmdd_to_struct_tm(yyyy, mm, dd);
    time_t this_epoch = mktime(&this_day);
    struct tm *parsable_time = localtime(&this_epoch);
    return parsable_time->tm_yday;
}

void day_of_year_today(void)
{
    printf("\n~~~~~~~~~~~~~~~~~\n");
    time_t today_epoch;
    time(&today_epoch);
    struct tm *parsable_time = localtime(&today_epoch);
    printf("Today is %dth day of the year.\n[0 based index, 0th day == Jan 1]\n", parsable_time->tm_yday);
    printf("~~~~~~~~~~~~~~~~~\n");
}

void print_tm_info(struct tm tm_info)
{
    printf("\n%s", asctime(&tm_info));
}
