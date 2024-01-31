# Music-Playlist-Using-C

**Author**: Ma. Jazmine P. Rosello

**Purpose**: For the completion of exercise in CMSC 21: Fundamentals of Programming

## Program Description

program that implements a music playlist using structures and files. The program must continue to run
until the user picks exit.

### Functionalities

1. Created two structures. One for the playlist with the details: name, song count, array of songs (size
10) and one for the song with the details: title, artist, album.
11) 
2. The program must load the data each time it is ran and must save the data each time the user picks exit.
(a) Save Data
- You must check whether there is a data to be saved. If there are none, simply print a prompt saying
so. Also, save count as 0 so that you will be able to keep track if file is empty.
(b) Load Data
- You must check whether the file exists. If the file exists, check if the count is 0. If the count is not
0, read each of the data in the file and save it in the array of structures.

3. a menu that shows:
(a) Add Playlist
- The user can put up to 10 playlists in the system. Make sure to check if the system is not yet full.
- If the system is not yet full, ask for the details of the playlist, and initialize the song count to 0.
Remember to check that the name of the playlist is unique. If the name already exists, it musn’t be
added to the system.
- If the system is full, simply say that it is.
(b) Add Song to Playlist
- Make sure to check if there a playlist to add to. Ask which playlist to add the song to. If the playlist
exists and it doesn’t have 10 songs yet, ask for the details of the song. Else, print the appropriate
prompts.
(c) Remove Song from Playlist
- Make sure to check if there is a playlist to remove from. Ask which playlist to remove songs from.
If the playlist exists, and it isn’t empty, ask which song to remove. If found, remove the song. Else,
print the appropriate prompts.
(d) View a Playlist
- Make sure to check if there is a playlist to print. Ask which playlist to print. If the playlist exists,
print all the details about it along with the songs. Else, print the appropriate prompts.
(e) View all Data
- This simply prints all of the available data in the system. Both the playlists and songs. Make sure
to check if there is data to print.
(f) Exit
- When the user picks this, the program terminates.
