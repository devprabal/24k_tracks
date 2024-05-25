#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>

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

typedef enum KOREAN_LANG_ACTIVITY
{
    KOREAN_NOTHING,
    IMMERSION,
    KSTUDY,
    KOREAN_LANG_ACTIVITY_MAX,
} KOREAN_LANG_ACTIVITY;

typedef enum SPOILER_ACTIVITY
{
    SPOILER_NOTHING,
    SPOILER_1,
    SPOILER_ACTIVITY_MAX,
} SPOILER_ACTIVITY;

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

typedef enum INTENSITY
{
    INTENSITY_0,
    INTENSITY_1,
    INTENSITY_2,
    INTENSITY_3,
    INTENSITY_4,
    INTENSITY_5,
    INTENSITY_INVALID,
} INTENSITY;

#define INTENSITY_MAX (INTENSITY_INVALID)

typedef struct GymRecord
{
    INTENSITY intensity;
    GYM_ACTIVITY activities[GYM_ACTIVITY_MAX];
} GymRecord;

typedef struct KoreanLangRecord
{
    INTENSITY intensity;
    KOREAN_LANG_ACTIVITY activities[KOREAN_LANG_ACTIVITY_MAX];
} KoreanLangRecord;

typedef struct SpoilerRecord
{
    INTENSITY intensity;
    SPOILER_ACTIVITY activities[SPOILER_ACTIVITY_MAX];
} SpoilerRecord;

typedef struct StudyRecord
{
    INTENSITY intensity;
    STUDY_ACTIVITY activities[STUDY_ACTIVITY_MAX];
} StudyRecord;

typedef union SingleRecord
{
    GymRecord gym_rec;
    KoreanLangRecord koreanlang_rec;
    SpoilerRecord spoiler_rec;
    StudyRecord study_rec;
} SingleRecord;

typedef enum RECORD_TYPE
{
    GYM,
    STUDY,
    KOREAN,
    SPOILER,
    RECORD_TYPE_MAX,
} RECORD_TYPE;
#define NUMBER_OF_RECORD_TYPES (RECORD_TYPE_MAX)

typedef struct Day
{
    struct tm yyyymmdd;
    SingleRecord records[NUMBER_OF_RECORD_TYPES];
} Day;

#define DAYS_IN_YEAR_2024 (366)
Day days[DAYS_IN_YEAR_2024] = {0};

struct tm yyyymmdd_to_struct_tm(int yyyy, int mm, int dd)
{
    struct tm this_date = {
        .tm_year = yyyy - 1900,
        .tm_mon = mm - 1,
        .tm_mday = dd};
    return this_date;
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

int day_of_the_year(int yyyy, int mm, int dd)
{
    struct tm this_day = yyyymmdd_to_struct_tm(yyyy, mm, dd);
    time_t this_epoch = mktime(&this_day);
    struct tm *parsable_time = localtime(&this_epoch);
    return parsable_time->tm_yday;
}

void print_tm_info(struct tm tm_info)
{
    printf("\n%s", asctime(&tm_info));
}

void print_gym_rec_info(SingleRecord s_info)
{
    printf("\n\nGYM");
    GymRecord info = s_info.gym_rec;
    printf("\nIntensity: %d\nActivities: ", info.intensity);
    for (int i = 0; i < GYM_ACTIVITY_MAX; i++)
    {
        switch (info.activities[i])
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

void print_study_rec_info(SingleRecord s_info)
{
    printf("\n\nSTUDY");
    StudyRecord info = s_info.study_rec;
    printf("\nIntensity: %d\nActivities: ", info.intensity);
    for (int i = 0; i < STUDY_ACTIVITY_MAX; i++)
    {
        switch (info.activities[i])
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

void print_korean_rec_info(SingleRecord s_info)
{
    printf("\n\nKOREAN");
    KoreanLangRecord info = s_info.koreanlang_rec;
    printf("\nIntensity: %d\nActivities: ", info.intensity);
    for (int i = 0; i < KOREAN_LANG_ACTIVITY_MAX; i++)
    {
        switch (info.activities[i])
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

void print_spoiler_rec_info(SingleRecord s_info)
{
    printf("\n\nSPOILER");
    SpoilerRecord info = s_info.spoiler_rec;
    printf("\nIntensity: %d\nActivities: ", info.intensity);
    for (int i = 0; i < SPOILER_ACTIVITY_MAX; i++)
    {
        switch (info.activities[i])
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

void print_records_for_day(int yyyy, int mm, int dd)
{
    int yday = day_of_the_year(yyyy, mm, dd);
    Day this_day = days[yday];
    printf("\n=================");
    print_tm_info(this_day.yyyymmdd);
    print_gym_rec_info(this_day.records[GYM]);
    print_study_rec_info(this_day.records[STUDY]);
    print_korean_rec_info(this_day.records[KOREAN]);
    print_spoiler_rec_info(this_day.records[SPOILER]);
    printf("\n=================\n");
}

static int curr_yday = 0;

void make_gym_record(GymRecord rec)
{
    days[curr_yday].records[GYM].gym_rec.intensity = rec.intensity;
    for(int i = 0; i < GYM_ACTIVITY_MAX; i++)
    {
        days[curr_yday].records[GYM].gym_rec.activities[i] = rec.activities[i];
    }
}

void make_koreanlang_record(KoreanLangRecord rec)
{
    days[curr_yday].records[KOREAN].koreanlang_rec.intensity = rec.intensity;
    for(int i = 0; i < KOREAN_LANG_ACTIVITY_MAX; i++)
    {
        days[curr_yday].records[KOREAN].koreanlang_rec.activities[i] = rec.activities[i];
    }
}

void make_spoiler_record(SpoilerRecord rec)
{
    days[curr_yday].records[SPOILER].spoiler_rec.intensity = rec.intensity;
    for(int i = 0; i < SPOILER_ACTIVITY_MAX; i++)
    {
        days[curr_yday].records[SPOILER].spoiler_rec.activities[i] = rec.activities[i];
    }
}

void make_study_record(StudyRecord rec)
{
    days[curr_yday].records[STUDY].study_rec.intensity = rec.intensity;
    for(int i = 0; i < STUDY_ACTIVITY_MAX; i++)
    {
        days[curr_yday].records[STUDY].study_rec.activities[i] = rec.activities[i];
    }
}

void make_day(int yyyy, int mm, int dd, GymRecord rec_gym, KoreanLangRecord rec_korean, SpoilerRecord rec_spoiler, StudyRecord rec_study)
{
    struct tm tm_x = yyyymmdd_to_struct_tm(yyyy, mm, dd);
    int yday = day_of_the_year(yyyy, mm, dd);
    curr_yday = yday;
    days[curr_yday].yyyymmdd = tm_x;

    make_gym_record(rec_gym);
    make_koreanlang_record(rec_korean);
    make_spoiler_record(rec_spoiler);
    make_study_record(rec_study);
}

void entries_MAY(void)
{
    {
        GymRecord rec_gym = {
            .intensity = INTENSITY_5,
            .activities = {WEIGHTS, CARDIO},
        };
        KoreanLangRecord rec_korean =  {
            .intensity = INTENSITY_2,
            .activities = {KSTUDY},
        };
        SpoilerRecord rec_spoiler = {
            .intensity = INTENSITY_4,
            .activities = {SPOILER_1},
        };
        StudyRecord rec_study = {
            .intensity = INTENSITY_5,
            .activities = {CODING, WATCHING, READING},
        };

        make_day(2024, 05, 19, rec_gym, rec_korean, rec_spoiler, rec_study);
        print_records_for_day(2024, 05, 19);
    }
    {
        GymRecord rec_gym = {
            .intensity = INTENSITY_0,
        };
        KoreanLangRecord rec_korean =  {
            .intensity = INTENSITY_0,
        };
        SpoilerRecord rec_spoiler = {
            .intensity = INTENSITY_5,
            .activities = {SPOILER_1},
        };
        StudyRecord rec_study = {
            .intensity = INTENSITY_2,
            .activities = {CODING,},
        };

        make_day(2024, 05, 25, rec_gym, rec_korean, rec_spoiler, rec_study);
        print_records_for_day(2024, 05, 25);
    }
}

int main(void)
{
    day_of_year_today();
    entries_MAY();
    return 0;
}
