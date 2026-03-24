/*Storage of music CD information in a collection.*/


#include <stdio.h>
#include <string.h>

typedef struct{
    int day;
    int month;
    int year;
} Release_date;

typedef struct{
    int min;
    int sec;
} Track_duration;

typedef struct{
    char title[70];
    Track_duration track_duration;
} Total_tracks;

typedef struct {
    char artist_name[70];
    char album_name[70];
    char record_label[70];
    Release_date date;
    int genre_code;
    Total_tracks total[100];
    int identification;
} Collection;

typedef struct {
    int code;
    char name[30];
} Genre;

typedef struct {
    int type;
    char category[30];
} Identification;

int main(){

    Collection collection;
    char answer[10];
    int keepGoing = 1;
    int size;

    Genre genreList[] = {
        {1, "Rock"},
        {2, "Pop"},
        {3, "Kpop"},
        {4, "MPB"}
    };

    Identification identificationList[] = {
        {1, "Single"},
        {2, "Double"},
        {3, "Box"}
    };

    int total_genres = 4;
    int total_id = 3;

    while(keepGoing){

        printf("Enter the artist/band/group name: ");
        fgets(collection.artist_name, 70, stdin);
        collection.artist_name[strcspn(collection.artist_name, "\n")] = '\0';

        printf("\n");

        printf("Enter the album name: ");
        fgets(collection.album_name, 70, stdin);
        collection.album_name[strcspn(collection.album_name, "\n")] = '\0';

        printf("\n");

        printf("Enter the release date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &collection.date.day, &collection.date.month, &collection.date.year);

        while(getchar() != '\n');

        printf("\n");

        printf("Enter the record label: ");
        fgets(collection.record_label, 70, stdin);
        collection.record_label[strcspn(collection.record_label, "\n")] = '\0';

        printf("\n");

        printf("Choose the genre:\n");
        for(int i = 0; i < total_genres; i++){
            printf("%d - %s\n", genreList[i].code, genreList[i].name);
        }

        printf("Enter the genre code: ");
        scanf("%d", &collection.genre_code);

        while(getchar() != '\n');

        for(int i = 0; i < total_genres; i++){
            if(genreList[i].code == collection.genre_code){
                printf("Selected genre: %s\n", genreList[i].name);
            }
        }

        printf("\n");

        printf("Enter the number of tracks in the album: ");
        scanf("%d", &size);

        while(getchar() != '\n');

        for(int i = 0; i < size; i++){
            
            printf("Enter the title of track %d:\n", i + 1);
            fgets(collection.total[i].title, 70, stdin);
            collection.total[i].title[strcspn(collection.total[i].title, "\n")] = '\0';

            printf("Enter the track duration (min:sec): ");
            scanf("%d:%d", &collection.total[i].track_duration.min, &collection.total[i].track_duration.sec);

            while(getchar() != '\n');
        }

        printf("\n");

        printf("Choose the type:\n");
        for(int i = 0; i < total_id; i++){
            printf("%d - %s\n", identificationList[i].type, identificationList[i].category);
        }

        printf("Enter the type: ");
        scanf("%d", &collection.identification);

        for(int i = 0; i < total_id; i++){
            if(identificationList[i].type == collection.identification){
                printf("Selected type: %s\n", identificationList[i].category);
            }
        }

        while(getchar() != '\n');

        printf("\n");

        printf("Registration completed! Do you want to register another artist? (y/n): ");
        fgets(answer, 10, stdin);
        answer[strcspn(answer, "\n")] = '\0';

        if(strcmp(answer, "n") == 0 || strcmp(answer, "N") == 0) {
            keepGoing = 0;
        }
    }

    return 0;
}
