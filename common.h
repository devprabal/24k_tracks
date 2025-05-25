#ifndef COMMON_H
#define COMMON_H

#include <time.h>

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

typedef enum RECORD_TYPE
{
    GYM,
    STUDY,
    KOREAN,
    SPOILER,
    RECORD_TYPE_MAX,
} RECORD_TYPE;
#define NUMBER_OF_RECORD_TYPES (RECORD_TYPE_MAX)

#define DAYS_IN_YEAR_2024 (366)

typedef struct GymRecord GymRecord;
typedef struct KoreanLangRecord KoreanLangRecord;
typedef struct SpoilerRecord SpoilerRecord;
typedef struct StudyRecord StudyRecord;

typedef union SingleRecord SingleRecord;
typedef union SingleRecord
{
    GymRecord* gym_rec;
    KoreanLangRecord* koreanlang_rec;
    SpoilerRecord* spoiler_rec;
    StudyRecord* study_rec;
} SingleRecord;

typedef struct Note
{
    //// You can replace this datatype with your user-defined type
    //// to make more structured data format.
    //// Change free_note_message() accordingly.
    char* message;
} Note;

SingleRecord* get_record_for_yday(int yday, RECORD_TYPE type);
Note* get_note_for_yday(int yday, RECORD_TYPE type);
void free_note_message(Note* note);
struct tm yyyymmdd_to_struct_tm(int yyyy, int mm, int dd);
int day_of_the_year(int yyyy, int mm, int dd);
void day_of_year_today(void);
void print_tm_info(struct tm tm_info);
void print_records_for_day(int yyyy, int mm, int dd);

#endif // COMMON_H
