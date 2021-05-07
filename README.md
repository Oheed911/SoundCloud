# SoundCloud
{Implementation of Soudcloud System in C++}

Develop a Database of Music. The System consists of following parts:
1. Music Metadata Database (MMD).
2. Author Metadata Database (AMD).
3. Album Database (AD).
4. Discography Database (DD).


                                                            Music Metadata Database (MMD):
MMD is to keep records of all music tracks. Each track would be identified by a unique
MBID. Each record contains following information of each track.
i. MBID (4-digit unique number)
ii. Song Name
iii. Writer
iv. Length
MMD must have following features:
i. Data Structure must be strongly connected that each node contains address of its next node
as well as previous node.
ii. List must be maintained in Ascending order based on MBID upon new Record entry.
iii. Locating and Updating Record must be based on MBID.


                                                             Author Metadata Database (AMD):
AMD is to keep records of all authors. Each author would be identified by a unique AID.
Each record contains following information of each author.
i. AID (4-digit unique number)
ii. Name
iii. Band
iv. Gender
v. Date of Birth
vi. Career Start Date
vii. Genre
AMD must have following features:
i. Data Structure must be strongly connected and also the last node can access head of the list
and head can access last node of list.
ii. List must be maintained in Ascending order based on AID upon new Record entry.
National University of Computer and Emerging Sciences
FAST School of Computing Fall 2020 Islamabad Campus
iii. Locating and Updating Record must be based on AID.
Album Database (AD):
AD is to maintain data related to music tracks of each album. Each record contains following
information of each citizen.
i. ABID (4-digit unique number)
ii. Album Name
iii. AID (4-digit unique number)
iv. Publisher
v. Number of Tracks
vi. Total Duration
vii. Tracks
    a. Track Number
    b. MBID (4-digit unique number)
AD must have following features:

  i. Data Structure must be connected in a way that each node has address of next node and the
  last node of list can access head of list.
  ii. List must be maintained in Ascending order based on ABID upon new Record entry.
  iii. Locating and Updating Record must be based on ABID. a. Add, Delete and Update
  numbers.
  iv. “Tracks” is a Singly Linked List, each Node of a List contains all the information related to
  that music track of the album.’
  v. AD database will be connected to the MMD and AMD databases. The MMD will be
  connected via the MBID, while the AMD will be connected via the AID.
  vi. Node in MMD and AD having same MBID must have a two-way relationship i.e. If pointer
  is at some Node in AD and wants to access music metadata about that track, it should be able to
  directly access that Node in MMD without the need of searching the whole Music Metadata
  Database to locate and see Music record against concerned MBID and vice-versa.
  vii. Node in AMD and AD having same AID must have a two-way relationship i.e. If pointer is
  at some Node in AD and wants to access author metadata about that album, it should be able to
  directly access that Node in AMD without the need of searching the whole Author Metadata
  Database to locate and see Author record against concerned AID and vice-versa.



                                                                   Author Discography Playlist (ADP):
ADP is the centralised database, meaning MMD, AMD, and AD will be connected to ADP.
ASP is meant to keep records of all music tracks released by an author with respect to albums.
Each record contains following information of each music track.
i. DID (4-digit unique number)
ii. AID (4-digit unique number)
iii. Albums
  a. ABID (4-digit unique number)
  b. Year

ADP must have following features:
 
i. Data Structure must be connected in a way that each node has address of next node and the
last node of list can access head of list.
ii. List must be maintained in Ascending order based on DID upon new Record entry.
iii. Locating and Updating Record must be based on DID. a. Add, Delete and Update numbers.
iv. “Albums” is a Singly Linked List, each Node of a List contains all the information related
to that album.
v. ADP database will be connected to the AMD and AD databases. The AMD will be
connected via the AID, while the AD will be connected via the ABID.
vi. Node in AD and ADP having same ABID must have a two-way relationship i.e. If pointer is
at some Node in ADP and wants to access album data about that discography, it should be able to
directly access that Node in AD without the need of searching the whole Album Database to locate
and see Album record against concerned ABID and vice-versa.
vii. Node in AMD and ADP having same AID must have a two-way relationship i.e. If pointer
is at some Node in ADP and wants to access author metadata about that discography, it should be
able to directly access that Node in AMD without the need of searching the whole Author Metadata
Database to locate and see Author record against concerned AID and vice-versa.
viii. Through the connection with AD database, it should be possible to view MMD database
data using the appropriate MBID.


                                                                      General Functionalities Included:
i. Upon running the program, it should read data for each Database from related Data Files and
store it in a Linked-List-Based-Queue following FIFO rule. After loading all data into Queue, program
should start populating each Database with related Queue Data following First-In-First-Out Rule
i.e. FIFO.
ii. Search music by MBID in MMD and display all Record from MMD
iii. Search author by AID in AMD and display all Record from AMD
iv. Search albums by ABID in AD and display all Record from AD
v. Search discographies by DID in ADP and display all Record from ADP
vi. Search music by albums, given ABID, display all track details from MMD of all tracks.
vii. Search music by author, given DID, display all track names from MMD, of all tracks
released by author
