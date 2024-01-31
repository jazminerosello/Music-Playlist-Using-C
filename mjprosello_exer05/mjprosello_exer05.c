#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//declaring 2 structures
//this struct songdetails contains the title, artist and album of the song
struct songdetails{
    char title[100];
    char artist[100];
    char album[100];
};

//this typedef struct playlist is containing name with size of 100, an integer named song_count and songdetailes songs with the size of 10
typedef struct playlist{
    char name[100]; //this is for the playlist name
    int song_count; //this is to determine how many songs does one playlist had
    struct songdetails songs[10]; //this is for the storage of all songs in this particular playlist

}track;


int AddPlaylist(struct playlist *collection, int count){ //this function is whenever users wants to add playlist
    char pname[100]; //initialize a character named pname witht he size of 100
    int bilang=0; //initialize integer named bilang as 0

    //ask users about the name of their playlist
    printf("\nEnter Playlist: ");
    scanf(" %99[^\n]",pname); //temporarily store it to pname variable

    //for the uniqueness of the playlist name and to determine if their input is already existing,
    //we need to access every playlist name in the array of structures and compare it to the pname where we have stored their input
    //by comparing those two we will know if the input of the users is the same sa isa roon sa name sa array of structures
    //therefore, we will access those names in the array of structures using loop
    for(int i=0; i<count; i++){ //
        if(strcmp(collection[i].name,pname)==0){ //if the comparison of the name in the array of structures and pname is equal 0
        //it means they are the same
            bilang++; //so we increment bilang variable to dictate that one of the name in the array of structures is the same as the 
            //input,
            break; //then we break the loop since we only need 1 as the value of bilang to say that the input of the users is not unique
        }
    }
    if (bilang==1){ //if the bilang is equal to 1
        return 1; //we return 1
    }else{ //if it is not, we will now copy the value of pname and store it the specific order in array of structures
        strcpy(collection[count].name, pname);
        collection[count].song_count = 0; // then we also set the song_count in that particular oorder in array of structures as the scount
        printf("\nSuccessfully added playlist!\n"); 
    }

    printf("-----------------------------\n");
}


void AddSong(struct playlist *collection, int count){ //this function is used whenever users want to add songs in a particular playlist
    int choice; //initialize integer named choice

    if(count == 0){ //if the count is equal to 0, meaning there is still no playlist so we print the appropriate prompt
    //global variable count is used to count how many playlist are already in the system
        printf("\nThere is still no playlist!\n");
    }else{ //however, if count is more than 0, the following codes are executed
        //first, we will print the available playlist which they can choose from 
        printf("\nPLAYLIST AVAILABLE: \n");
        //to display all the name of the playlists that the array of structure has, we need to use for loop
        for (int i=0; i<count; i++){
            printf("\t[%d] %s \n", i, collection[i].name);
        }
        printf("\n");

        //then we ask what playlist they want to add song to
        printf("What playlist : ");
        scanf("%d", &choice); //then we store their input to the variable integer

        if(choice>=count || choice<0){ //if the choice or the input of the users is greater than or equal to the count or if it is less than 0, it means they have input an invalid
        //playlist number or none of the choices
            printf("\nInvalid Playlist Number!!\n");
        }else{ //if it is not then,
            //we asks users fro the title,artist and album of the songs they want to add in a specific playlist
            if(collection[choice].song_count<10){
                printf("Enter Song Title: ");
                scanf(" %99[^\n]", collection[choice].songs[collection[choice].song_count].title);

                printf("Enter Song Artist: ");
                scanf(" %99[^\n]", collection[choice].songs[collection[choice].song_count].artist);

                printf("Enter Song Album: ");
                scanf(" %99[^\n]", collection[choice].songs[collection[choice].song_count].album);
                collection[choice].song_count = collection[choice].song_count + 1;

                printf("\nSuccessfully added song to playlist!\n");
            }else{ //also we need to catch the condition where there should have 10 songs only per playlist
                printf("There are already 10 songs in this playlist!\n");
            }
        }
    }
    printf("-----------------------------\n");
}

void RemoveSong(struct playlist *collection, int count){ //this function is use whenever users want to remove song from a specfic playlist 
    int choice, pick; //intialize choice and pick
   

    if(count==0){ //if the count of playlist is 0, meaning there is still no playlsit in the system, we notify users
        printf("There are no playlists yet!\n");
    }
    else{ //if not then we print the playlist available which they can choose from and also to determine what palylist they want to remove the song from
        printf("\nTHE PLAYLIST AVAILABLE ARE: \n");
        //use for-loop to access and print all the playlist name an array of structure have
        for (int i=0; i<count; i++){
            printf("\t[%d] %s \n", i, collection[i].name);
        }
        //ask for users input
        printf("\nEnter playlist number: ");
        scanf("%d", &choice); //store their input into the variable choice

        if(choice>=count || choice<0){ //if the users input is none of the choices or playlist available
            printf("Invalid Playlist Number!!\n");
        }else if(collection[choice].song_count == 0){ //if the playlist choice of users does not have any songs yet
            printf("Playlist named %s is still empty!\n", collection[choice].name);
        }else{ //if the input of the users met the condition
            //we now print all the songs in the particular playlist they chose to
            printf("\nTHE SONGS AVAILABLE ARE:\n");
            //uses fro-loop to access all the songs a playlist contain
            for(int k=0; k<collection[choice].song_count; k++){
                printf("\t[%d] %s by %s\n", k, collection[choice].songs[k].title, collection[choice].songs[k].artist);
            }
            //asks for users input about the song they want to delete
            printf("\nEnter song number to delete: ");
            scanf("%d", &pick); //store their input to vairable pick

            if(pick >=collection[choice].song_count || pick <0){ //if the users input is greater than or equal to the number of songs, it meand
            //they have input an invalid song number 
                printf("Invalid Song Number!!\n");
            }else{ //if not then, the song they chose to delete will now be deleted
                //we need to access the song they chose so we use for loop
                int scount = collection[choice].song_count;
                for(int j=pick; j<scount; j++){

                    strcpy(collection[choice].songs[j].title, collection[choice].songs[j+1].title); 
                    strcpy(collection[choice].songs[j].artist, collection[choice].songs[j+1].artist);
                    strcpy(collection[choice].songs[j].album, collection[choice].songs[j+1].album); 
                      
                }
                printf("Successfully deleted song!\n");
                collection[choice].song_count = collection[choice].song_count -1; //ofcourse, in deleting the song, we need to decrease the song count in
                //the specific playlist
            }   
        }
    }
    printf("-----------------------------\n");
}

void ViewPlaylist(struct playlist *collection, int count){ //this function is use whenever users wants to view a particular playlist
    int choice; //declare variable choice

    if (count ==0){ //to know if there is no playlist yet, we use if statement that whenever count is 0, it means there is no playlist since count signifies
    //the count of how many playlist are there in the system
        printf("\nThere is still no playlist!\n");
    }else{ //if count is greater than 0, meaning there is/are playlist in the system
        //we will now print all the playlist name that is available
        printf("\nTHE PLAYLIST AVAILABLE ARE: \n");

        for (int i=0; i<count; i++){
            printf("\t[%d] %s \n", i, collection[i].name);
        }
        //we asks users for the playlist number they want to view it's data
        printf("\nEnter playlist number: ");
        scanf("%d", &choice); 

        if (choice >= count || choice<0){ //if the users input is greater than or equal to the count or if it is less than 0, it means that they have invalid input
            printf("\nInvalid Playlist Number!\n");
        }else{ //if not, then we now print the data of their chosen playlist

            printf("\nPLAYLIST NAME: %s", collection[choice].name);
            printf("\nSONG COUNT: %d\n", collection[choice].song_count);
            if (collection[choice].song_count>0){
                for(int k=0; k<collection[choice].song_count; k++){
                    printf("\tSONG TITLE: %s\n", collection[choice].songs[k].title);
                    printf("\tSONG ARTIST: %s\n", collection[choice].songs[k].artist);
                    printf("\tSONG ALBUM: %s\n", collection[choice].songs[k].album);
                    printf("\n");
                }
            }
        }
    }
    printf("-----------------------------\n");
}

void ViewAll(struct playlist *collection, int count){ //this function is use if users wants to view all the playlist along their data
    
    if(count==0){ //if count is 0, meaning there is still no playlist avaible, we notify users
        printf("\nThere is still no playlist!\n"); 
    }else{ //if not, then we access all the playlist along with their data and print them using for loop and the count as the limitation of the loop since count serves as the number of playlist there
    //are in the system
        for (int index=0; index<count; index++){
            printf("\nPLAYLIST NAME: %s", collection[index].name);
            printf("\nSONG COUNT: %d\n", collection[index].song_count);
            if (collection[index].song_count>0){ //if there are songs in this playlist then we write them too in the file using for loop and the limitation of tht for loop is the song count of that playlist in the colleciton
                for(int k=0; k<collection[index].song_count; k++){
                    printf("\tSONG TITLE: %s\n", collection[index].songs[k].title);
                    printf("\tSONG ARTIST: %s\n", collection[index].songs[k].artist);
                    printf("\tSONG ALBUM: %s\n", collection[index].songs[k].album);
                    printf("\n");
                }
            }
        }
    }
    printf("-----------------------------\n");
}

void save(struct playlist *collection, int count) { //this function is use to save in a file all the data in the system 

    FILE *fp = fopen("Collection.txt", "w"); //open a file and make it as write mode
	    fprintf(fp, "%d\n", count); //print or write the count value

    if(count==0){ //if the users did not input anything, or there is no playlist to be saved, we notify users
        printf("\nThere is nothing to be saved!\n\n");

    }else{ //if there are playlsit to be save..

        //also, write all the data of playlist 
        //access each playlist with their songs using for loop, count is the limitation of the loop becuase it will serve how many playlist are there in the system
        for(int i=0; i < count; i++) {
		    fprintf(fp, "%s\n", collection[i].name );
            fprintf(fp, "%d\n",  collection[i].song_count );
            for(int j=0; j<collection[i].song_count; j++){ //we used the int i as the index of the eveyr palylist adn for their songs to be accessed we used the songcount as the limitation of the loop
                fprintf(fp, "%s\n",  collection[i].songs[j].title);
                fprintf(fp,"%s\n",  collection[i].songs[j].artist);
                fprintf(fp,"%s\n", collection[i].songs[j].album);
            }
        }
        printf("\nSuccessfully saved data!\n");
	}

    fclose(fp);
}


void load(struct playlist *collection, int *count){ //this is used to load the data in a file and store it into the structure of array

    FILE *fp; //declare FILE pointer as fp
 
    if (fp = fopen("Collection.txt", "r")){ //if we can open the file, meaning it is existing then we now store those values in the file in their respective places in the structures
        fscanf(fp, " %d\n", count);

        if(*count == 0){ //if count is 0, we notify users that there is still no record in the file
            printf("\nFile record is still empty!\n");
        }else{ //if there is more than 0 then we store those playlist and their songs with their respective palces in the structures
	        for(int i=0; i < (*count); i++) { //using for loop, we can access adn tell the program that this line in the file should eb stored in this member of structure
		        fscanf(fp, " %99[^\n]\n",collection[i].name );
                fscanf(fp, " %d\n", &collection[i].song_count );

                for(int j=0; j<collection[i].song_count; j++){
                    fscanf(fp, " %99[^\n]\n", collection[i].songs[j].title);
                    fscanf(fp," %99[^\n]\n", collection[i].songs[j].artist);
                    fscanf(fp," %99[^\n]\n", collection[i].songs[j].album);
                }
	        }printf("\nSuccessfully load data!\n");
        }
    fclose(fp); //close the file
    }else{ //if we cannot open the file then meaning it is still not existing so we notify users that there is no such file
        printf("\nThe file does not exist!\n");
    }
}


int main(){
    struct playlist collection[10]; //we declare an array of structures with the size of 10

    int choice;
    int count=0; //initialize count as 0 wherein count signifies as the count of playlist in the system

    load(collection, &count); //at the beginnig of the program we will load the data in the file 
    
    //while 1, the menu part will be print out
    while(1){
        printf("\n======= MENU =======");
        printf("\n[1] Add Playlist\n");
        printf("[2] Add Song to Playlist\n");
        printf("[3] Remove Song From Playlist\n");
        printf("[4] View a Playlist\n");
        printf("[5] View All Data\n");
        printf("[6] Exit\n");

        printf("\nEnter choice: "); //then we will ask users for their input
        scanf("%d",&choice); //then store it into choice variable

        if (choice ==1){ //if the choice value is 1, meaning users want to add playlist
            if(count==10){ //however, only 10 playlist can be stored so whenever the count variable value is 10, we will tell the users that there's already 10
            //playlist
                printf("\nThere's already 10 playlist!\n");
                printf("-----------------------------\n");
            }else{ //if count is less than 10
                if(AddPlaylist(collection, count)==1){ //we call out the add playlist but if it returns 1, it means that the playlist name they have input
                //is already existing
                    printf("\nPlaylist name already exists!\n");
                    printf("-----------------------------\n");
                }else{ //if it did not return 1, then we increment count for the next playlist name 
                    count++;
                }
            }
        }else if(choice ==2){ //if the choice is equal to 2, 
            AddSong(collection, count); //we call out the AddSong function
        }else if(choice==3){ //if the choice is equal to 3,
            RemoveSong(collection, count); //we call out the RemoveSong function
        }else if(choice ==4){ //if the choice is equal to 4,
            ViewPlaylist(collection, count); //we call out the ViewPlaylist function
        }else if(choice ==5){ //if the choice is equal to 5,
            ViewAll(collection, count); //we call out the ViewAll function
        }else if(choice ==6){ //if the choice is equal to 6,
            break; //we break the loop since it is EXIT
        }else if(choice<0 || choice>6){ //this is whenever users input is less than 0 or negative integers
            printf("Invalid choice!\n");
            printf("-----------------------------\n");
        }
    }
    save(collection, count); //at the end of program and once the while loop breaks, all the data that have stored in structure array will be written in the file
    
}