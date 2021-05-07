
/*Oheed Imran*/
#pragma once
#include <fstream>
#include <iostream>

using namespace std;

template <class a, class b, class c>
class AD;
template<class a, class b, class c>
class MMD;
template<class a>
class Tracks;
template <class a, class b>
class AMD;
template<class a>
class Albums;
template<class a>
class ADP;


template<class A, class B, class C>
class MMD
{
public:
	//data members
	A mbid;
	B songName;
	B WriteName;
	C length;
	//pointer to album
	AD<A, B, C>* album;
	//connections
	MMD<A, B, C>* next;
	MMD<A, B, C>* previous;
	//now the construcor of the class
};
template<class A, class B, class C>
class MMDList
{

	//creating the first head
	MMD<A, B, C>* head;
public:
	MMDList()
	{
		head = NULL;
		//album = NULL;
	}
	//now the inserting function
	//inserting the mbid in ascending order
	void Insert(A t_mbid, B t_songN, B t_WriteN, C t_length)
	{

		//now if the lsit is empty or first index is greater than the new input node
		//then we have to insert it onto the first node
		if (head == NULL)
		{
			MMD<A, B, C>* New_Node = new MMD<A, B, C>;
			//now inserting the values
			New_Node->mbid = t_mbid;
			New_Node->length = t_length;
			New_Node->songName = t_songN;
			New_Node->WriteName = t_WriteN;
			//New_Node->album = NULL;
			New_Node->next = NULL;
			New_Node->previous = NULL;
			head = New_Node;
			return;
		}
		//if the first node is not NULL
		else if (head != NULL)
		{
			MMD<A, B, C>* New_Node = new MMD<A, B, C>;
			//now inserting the values
			New_Node->mbid = t_mbid;
			New_Node->length = t_length;
			New_Node->songName = t_songN;
			New_Node->WriteName = t_WriteN;
			//New_Node->album = NULL;
			MMD<A, B, C>* iterate = head;
			MMD<A, B, C>* temp = NULL;
			while (iterate != NULL && iterate->mbid <= t_mbid)
			{
				temp = iterate;
				iterate = iterate->next;
			}
			temp->next = New_Node;
			New_Node->next = iterate;
			if (iterate == NULL)
			{
				New_Node->previous = temp;
			}
			else
			{
				iterate->previous = New_Node;
				New_Node->previous = temp;
			}
		}
	}
	void Display()
	{
		MMD<A, B, C>* iterate = new MMD<A, B, C>;
		iterate = head;
		if (iterate == NULL)
		{
			cout << "Nothing";
		}

		else
		{
			while (iterate != NULL)
			{
				cout << iterate->mbid << endl;
				cout << iterate->songName << endl;
				cout << iterate->WriteName << endl;
				cout << iterate->length << endl;
				iterate = iterate->next;
			}
		}
	}
	MMD<A, B, C>* getHead()
	{
		return head;
	}
	//now deleting the node
	void Delete(A t_mbid)
	{
		MMD<A, B, C>* iterate = head;
		MMD<A, B, C>* temp = NULL;
		while (iterate->mbid != t_mbid && iterate != NULL)
		{
			temp = iterate;
			iterate = iterate->next;
		}
		if (iterate == NULL)
		{
			cout << "Cant find the mbid in the list." << endl;
		}
		else
		{
			if (iterate == head)
			{
				head = iterate->next;
				delete iterate;
			}
			else
			{
				iterate->next->previous = iterate->previous;
				iterate->previous->next = iterate->next;
				delete iterate;
			}
		}
	}

};


/*
	Author meta Data base
*/
template <class A, class B>
class AMD
{
public:
	//data members
	A aid;
	B A_Name;
	B A_Band;
	B A_Gender;
	B A_Genre;
	A A_DOB;
	A A_CSD;

	//for the databases to be connected 
	AD<int, string, float>* albums;
	ADP<int>* adp;
	//connections
	AMD<A, B>* next;
};
//class of link list
template<class A, class B>
class AMDList
{
public:
	AMD<A, B>* head;
	//constructor of class
	AMDList()
	{
		head = NULL;
	}

	void Insert(A taid, B tname, B tband, B tgender, A tdob, A tcsd, B tgenre)
	{

		if (head == NULL)
		{
			AMD<A, B>* new_Node = new AMD<A, B>;
			new_Node->aid = taid;
			new_Node->A_Name = tname;
			new_Node->A_Band = tband;
			new_Node->A_Gender = tgender;
			new_Node->A_Genre = tgenre;
			new_Node->A_DOB = tdob;
			new_Node->A_CSD = tcsd;
			new_Node->albums = NULL;
			//new_Node->next = new_Node;
			head = new_Node;
			new_Node->next = head;
		}
		else
		{
			AMD<A, B>* new_Node = new AMD<A, B>;
			new_Node->aid = taid;
			new_Node->A_Name = tname;
			new_Node->A_Band = tband;
			new_Node->A_Gender = tgender;
			new_Node->A_Genre = tgenre;
			new_Node->A_DOB = tdob;
			new_Node->A_CSD = tcsd;
			new_Node->albums = NULL;
			//now the iterate node
			AMD<A, B>* iterate = head;
			AMD<A, B>* temp = NULL;
			while (iterate->next != head && iterate->aid <= taid)
			{
				temp = iterate;
				iterate = iterate->next;
			}
			if (iterate->next == head)
			{
				new_Node->next = iterate->next;
				iterate->next = new_Node;
			}
			else
			{
				temp->next = new_Node;
				new_Node->next = iterate;

			}
			//new_Node->next = iterate->next;
			//iterate->next = new_Node;


		}

	}
	AMD<A, B>* getHead()
	{
		return head;
	}
};
AMDList<int, string> loadAMD;
//declaring the global object of load mmd 
MMDList<int, string, float> loadMMD;


template <class A>
class Tracks
{
public:
	//data members
	A trackNumber;
	A trackmbid;
	MMD<int, string, float>* trackRef;
	//connections
	Tracks<A>* next;
};
//Album DataBase (A circular linked list)
template <class A, class B, class C>
class AD
{
public:
	//data members
	A abid;
	B album_name;
	A aid;
	B publisher_name;
	A no_tracks;
	C total_dur;
	AMD<A, B>* author;
	Tracks<A>* tracks;
	ADP<A>* adp;
	//connections
	AD<A, B, C>* next;
	AD()
	{
		next = NULL;
		tracks = NULL;
	}
};
template <class A, class B, class C>
class ADList
{
public:
	AD<A, B, C>* head;
	ADList()
	{
		head = NULL;
	}
	//insert function
	void insert(A tabid, B talbum_name, A taid, B tpublisher_name, A tno_tracks, C Ttotal_dur, A t_trackNumber, A t_trackmbid)
	{
		if (head == NULL)
		{
			AD<A, B, C>* new_Node = new AD<A, B, C>;
			Tracks<A>* temptrack = new Tracks<A>;
			new_Node->abid = tabid;
			new_Node->album_name = talbum_name;
			new_Node->aid = taid;
			new_Node->publisher_name = tpublisher_name;
			new_Node->no_tracks = tno_tracks;
			new_Node->total_dur = Ttotal_dur;
			temptrack->trackmbid = t_trackmbid;
			temptrack->trackNumber = t_trackNumber;
			temptrack->next = NULL;
			new_Node->tracks = temptrack;
			head = new_Node;
			new_Node->next = head;
		}
		else
		{
			AD<A, B, C>* iterate = head;
			while (iterate->next != head && iterate->abid != tabid)
			{
				iterate = iterate->next;
			}
			if (iterate->abid == tabid)
			{
				Tracks<A>* temptrack = new Tracks<A>;
				temptrack->trackmbid = t_trackmbid;
				temptrack->trackNumber = t_trackNumber;
				temptrack->next = NULL;
				Tracks<A>* iterate1 = iterate->tracks;
				while (iterate1->next != NULL)
				{
					iterate1 = iterate1->next;
				}
				iterate1->next = temptrack;
			}
			else if (iterate->abid != tabid)
			{

				AD<A, B, C>* new_Node = new AD<A, B, C>;
				Tracks<A>* temptrack = new Tracks<A>;
				new_Node->abid = tabid;
				new_Node->album_name = talbum_name;
				new_Node->aid = taid;
				new_Node->publisher_name = tpublisher_name;
				new_Node->no_tracks = tno_tracks;
				new_Node->total_dur = Ttotal_dur;
				temptrack->trackmbid = t_trackmbid;
				temptrack->trackNumber = t_trackNumber;
				temptrack->next = NULL;
				new_Node->tracks = temptrack;
				//sorted insertion
				AD<A, B, C>* iterate2 = head;
				AD<A, B, C>* temp2 = NULL;
				while (iterate2->next != head && iterate2->abid <= tabid)
				{
					temp2 = iterate2;
					iterate2 = iterate2->next;
				}
				if (iterate2->next == head)
				{
					new_Node->next = iterate2->next;
					iterate2->next = new_Node;
				}
				else
				{
					temp2->next = new_Node;
					new_Node->next = iterate2;
				}
				//new_Node->next = iterate->next;
				//iterate->next = new_Node;

			}
		}
	}
	AD<A, B, C>* gethead()
	{
		return head;
	}
};

ADList<int, string, float> loadAD;
//author 
//Albums (A singly linked list)
template<class A>
class Albums
{
public:
	//data members
	A year;
	A album_ABID;
	AD<int, string, float>* albumRef;

	//connections
	Albums* next;
};
//Author Discography Playlist (A circular linked list)
template<class A>
class ADP
{
public:
	//data members
	A did;
	A aid;
	AMD<int, string>* author;
	Albums<A>* albums;

	//connections
	ADP* next;
};
template<class A>
class ADPList
{
public:
	ADP<A>* head;
	ADPList()
	{
		head = NULL;
	}
	//now the insert funcions
	void insert(A t_did, A t_aid, A t_albumabid, A t_year)
	{
		if (head == NULL)
		{
			ADP<A>* new_Node = new ADP<A>;
			Albums<A>* new_album = new Albums<A>;
			new_Node->did = t_did;
			new_Node->aid = t_aid;
			new_album->album_ABID = t_albumabid;
			new_album->year = t_year;
			new_album->next = NULL;
			new_Node->albums = new_album;
			head = new_Node;
			new_Node->next = head;
		}
		else
		{
			ADP<A>* iterate = head;
			while (iterate->next != head && iterate->did != t_did)
			{
				iterate = iterate->next;
			}
			if (iterate->did == t_did)
			{
				Albums<A>* tempalb = new Albums<A>;
				tempalb->album_ABID = t_albumabid;
				tempalb->year = t_year;
				tempalb->next = NULL;
				Albums<A>* iterate1 = iterate->albums;
				while (iterate1->next != NULL)
				{
					iterate1 = iterate1->next;
				}
				iterate1->next = tempalb;
			}
			else if (iterate->did != t_did)
			{

				ADP<A>* new_Node = new ADP<A>;
				Albums<A>* new_album = new Albums<A>;
				new_Node->did = t_did;
				new_Node->aid = t_aid;
				new_album->album_ABID = t_albumabid;
				new_album->year = t_year;
				new_album->next = NULL;
				new_Node->albums = new_album;
				//for sorted insertion
				ADP<A>* iterate2 = head;
				ADP<A>* temp2 = NULL;
				while (iterate2->next != head && iterate2->did <= t_did)
				{
					temp2 = iterate2;
					iterate2 = iterate2->next;
				}
				if (iterate2->next == head)
				{
					new_Node->next = iterate2->next;
					iterate2->next = new_Node;
				}
				else
				{
					temp2->next = new_Node;
					new_Node->next = iterate2;
				}
				
				//new_Node->next = iterate->next;
				//iterate->next = new_Node;


			}
		}
	}
	ADP<A>* gethead()
	{
		return head;
	}
};

//The object that will load ADP
ADPList<int> loadADP;

//First function to load data into music meta deta
template<class A, class B, class C>
MMD<A, B, C>* Create_MMD(string path)
{
	//now the  file writing
	fstream myfile;
	myfile.open(path);
	int t = -1;
	while (!myfile.eof())
	{
		int comma_count = 0;
		string Read_Data = "";
		string temp = "";
		string temp1 = "";
		string temp2 = "";
		string temp3 = "";
		int comma_inv = 0;
		bool flg = false, flg2 = false, flg3 = false, flg4 = false;
		getline(myfile, Read_Data);
		if (Read_Data != "")
		{
			if (t != -1)
			{
				for (int i = 0; i < Read_Data.length(); i++)
				{
					//cout << Read_Data[i] << endl;
					if (Read_Data[i] == '"')
					{
						comma_inv--;
					}
					if (Read_Data[i] == ',' && comma_inv != 1)
					{
						comma_count++;
					}
					if (comma_count == 0 && flg == false)
					{
						flg = true;
						int C_ount = i;
						while (Read_Data[C_ount] != ',')
						{
							temp += Read_Data[C_ount];
							C_ount++;
						}

					}
					if (comma_count == 1 && flg2 == false)
					{
						flg2 = true;
						int C2 = i + 1;
						if (Read_Data[C2] == '"')
						{
							while (Read_Data[C2] != '"')
							{
								temp1 += Read_Data[C2];
								C2++;
							}
							comma_inv += 2;
						}
						else
						{
							while (Read_Data[C2] != ',')
							{
								temp1 += Read_Data[C2];
								C2++;

							}
						}

					}
					if (comma_count == 2 && flg3 == false)
					{
						flg3 = true;
						int C3 = i + 1;
						while (Read_Data[C3] != ',')
						{
							temp2 += Read_Data[C3];
							C3++;
						}

					}
					if (comma_count == 3 && flg4 == false)
					{
						flg4 = true;
						int C4 = i + 1;
						while (C4 != Read_Data.length())
						{
							temp3 += Read_Data[C4];
							C4++;
						}
					}

				}
			}
			else if (t == -1)
			{
				t++;
				continue;
			}
			loadMMD.Insert(stoi(temp), temp1, temp2, stof(temp3));
		}
		else
			continue;
	}
	return loadMMD.getHead();
}

template<class A, class B>
AMD<A, B>* Create_AMD(string p)
{

	fstream myfile;
	myfile.open(p);
	int t = -1;
	while (!myfile.eof())
	{
		string Read_Data = "";
		int comma_count = 0;
		bool flg[7] = { true,true,true,true,true,true,true };
		string t1;
		string t2;
		string t3;
		string t4;
		string t5;
		string t6;
		string t7;
		getline(myfile, Read_Data);
		if (Read_Data != "")
		{
			if (t != -1)
			{

				for (int i = 0; i < Read_Data.length(); i++)
				{
					if (Read_Data[i] == ',')
					{
						comma_count++;
					}
					if (comma_count == 0 && flg[0] == true)
					{
						flg[0] = false;
						int c = i;
						while (Read_Data[c] != ',')
						{
							t1 += Read_Data[c];
							c++;
						}
					}
					else if (comma_count == 1 && flg[1] == true)
					{
						flg[1] = false;
						int c2 = i + 1;
						while (Read_Data[c2] != ',')
						{
							t2 += Read_Data[c2];
							c2++;
						}

					}
					else if (comma_count == 2 && flg[2] == true)
					{
						flg[2] = false;
						int c3 = i + 1;
						while (Read_Data[c3] != ',')
						{
							t3 += Read_Data[c3];
							c3++;
						}
					}
					else if (comma_count == 3 && flg[3] == true)
					{
						flg[3] = false;
						int c4 = i + 1;
						while (Read_Data[c4] != ',')
						{
							t4 += Read_Data[c4];
							c4++;
						}
					}
					else if (comma_count == 4 && flg[4] == true)
					{
						flg[4] = false;
						int c3 = i + 1;
						while (Read_Data[c3] != ',')
						{
							t5 += Read_Data[c3];
							c3++;
						}
					}
					else if (comma_count == 5 && flg[5] == true)
					{
						flg[5] = false;
						int c3 = i + 1;
						while (Read_Data[c3] != ',')
						{
							t6 += Read_Data[c3];
							c3++;
						}
					}
					else if (comma_count == 6 && flg[6] == true)
					{
						flg[6] = false;
						int c3 = i + 1;
						while (c3 != Read_Data.length())
						{
							t7 += Read_Data[c3];
							c3++;
						}
					}

				}
			}
			else
			{
				t++;
				continue;
			}
			loadAMD.Insert(stoi(t1), t2, t3, t4, stoi(t5), stoi(t6), t7);
		}
		else
			continue;


	}
	return loadAMD.getHead();
}
template<class a, class b, class c>
void connectFirst()
{
	AD<a, b, c>* tempalbum = loadAD.gethead();
	Tracks<a>* temptracks = tempalbum->tracks;
	MMD<a, b, c>* tempmmd = loadMMD.getHead();
	while (tempalbum->next != loadAD.gethead())
	{
		while (temptracks != NULL)
		{
			if (temptracks->trackmbid == tempmmd->mbid)
			{
				temptracks->trackRef = tempmmd;
				temptracks = temptracks->next;
				tempmmd = tempmmd->next;
			}
			
		}
		tempalbum = tempalbum->next;
		temptracks = tempalbum->tracks;
	}
	while (temptracks != NULL)
	{
		if (temptracks->trackmbid == tempmmd->mbid)
		{
			temptracks->trackRef = tempmmd;
			temptracks = temptracks->next;
			tempmmd = tempmmd->next;
		}
	}
	//now connecting the mmd with ad on basis of mbid
	tempalbum = loadAD.gethead();
	temptracks = tempalbum->tracks;
	tempmmd = loadMMD.getHead();
	while (tempalbum->next != loadAD.gethead())
	{
		while (temptracks != NULL)
		{
			if (temptracks->trackmbid == tempmmd->mbid)
			{
				tempmmd->album = tempalbum;
			}
			temptracks = temptracks->next;
			tempmmd = tempmmd->next;
		}
		tempalbum = tempalbum->next;
		temptracks = tempalbum->tracks;
	}
	//connecting the last node
	while (temptracks != NULL)
	{
		if (temptracks->trackmbid == tempmmd->mbid)
		{
			tempmmd->album = tempalbum;
		}
		temptracks = temptracks->next;
		tempmmd = tempmmd->next;
	}
}
template<class a, class b, class c>
void connectScnd()
{
	AMD<a, b>* tempAmd = loadAMD.getHead();
	AD<a, b, c>* tempAD = loadAD.gethead();
	while (tempAD->next != loadAD.gethead())
	{
		tempAmd = loadAMD.getHead();
		while (tempAmd->next != NULL)
		{
			if (tempAD->aid == tempAmd->aid)
			{
				tempAD->author = tempAmd;
				break;
			}
			tempAmd = tempAmd->next;
		}
		tempAD = tempAD->next;
	}
	if (tempAD->aid == tempAmd->aid)
	{
		tempAD->author = tempAmd;
	}
	//now connecting the author wiht album dat
	tempAmd = loadAMD.getHead();
	tempAD = loadAD.gethead();
	while (tempAmd->next != loadAMD.getHead())
	{
		if (tempAmd->aid == tempAD->aid)
		{
			tempAmd->albums = tempAD;
		}
		tempAmd = tempAmd->next;
		while (tempAD->aid != tempAmd->aid) //this is because data is sorted and will have aid in sequence
			tempAD = tempAD->next;
	}

}


template<class A, class B, class C>
AD<A, B, C>* Create_AD(string p)
{
	fstream myfile;
	myfile.open(p);
	//now file is open 
	int t = -1;
	string taid = "";
	int count = 0;
	bool first = true;
	bool scnd = false;
	while (!myfile.eof())
	{
		string Read_Data = "";
		string temp[8] = { "" };
		bool flag[8] = { true,true,true,true,true,true,true,true };
		int comma_count = 0;
		getline(myfile, Read_Data);
		if (Read_Data != "")
		{
			if (t != -1)
			{
				int c = 0;
				while (Read_Data[c] != ',')
				{
					temp[0] += Read_Data[c];
					c++;
				}
				for (int i = 0; i < Read_Data.length(); i++)
				{
					if (Read_Data[i] == ',')
					{
						comma_count++;
					}
					if (comma_count == 1 && flag[0] == true)
					{
						flag[0] = false;
						int a = i + 1;
						while (Read_Data[a] != ',')
						{
							temp[1] += Read_Data[a];
							a++;
						}
					}
					if (comma_count == 2 && flag[1] == true)
					{
						flag[1] = false;
						int a = i + 1;
						while (Read_Data[a] != ',')
						{
							temp[2] += Read_Data[a];
							a++;
						}
					}
					if (comma_count == 3 && flag[2] == true)
					{
						flag[2] = false;
						int a = i + 1;
						while (Read_Data[a] != ',')
						{
							temp[3] += Read_Data[a];
							a++;
						}
					}
					if (comma_count == 4 && flag[3] == true)
					{
						flag[3] = false;
						int a = i + 1;
						while (Read_Data[a] != ',')
						{
							temp[4] += Read_Data[a];
							a++;
						}
					}
					if (comma_count == 5 && flag[4] == true)
					{
						flag[4] = false;
						int a = i + 1;
						while (Read_Data[a] != ',')
						{
							temp[5] += Read_Data[a];
							a++;
						}
					}
					if (comma_count == 6 && flag[5] == true)
					{
						flag[5] = false;
						int a = i + 1;
						while (Read_Data[a] != ',')
						{
							temp[6] += Read_Data[a];
							a++;
						}
						//cout << temp[6] << endl;
					}
					if (comma_count == 7 && flag[6] == true)
					{
						flag[6] = false;
						int a = i + 1;
						while (a != Read_Data.length())
						{
							temp[7] += Read_Data[a];
							a++;
						}
						//cout << temp[7] << endl;
					}
				}
				//cout << temp[0] << endl;
				loadAD.insert(stoi(temp[0]), temp[1], stoi(temp[2]), temp[3], stoi(temp[4]), stof(temp[5]), stoi(temp[6]), stoi(temp[7]));
			}
			else
			{
				t = 0;
				continue;
			}
		}
		else
		{
			continue;
		}
	}
	//first two way relationship function called
	connectFirst<A, B, C>();
	//2nd two way relationship function called
	connectScnd<A, B, C>();
	return loadAD.gethead();
}
template<class a, class b, class c>
void ADPconnecAD()
{
	ADP<a>* tempADP = loadADP.gethead();
	AD<a, b, c>* tempAD = loadAD.gethead();
	Albums<a>* tempalbums = tempADP->albums;
	//now the loop of the 
	while (tempADP->next != loadADP.gethead())
	{
		while (tempalbums != NULL)
		{
			if (tempalbums->album_ABID == tempAD->abid)
			{
				tempalbums->albumRef = tempAD;
			}
			tempalbums = tempalbums->next;
			tempAD = tempAD->next;
		}
		tempADP = tempADP->next;
		tempalbums = tempADP->albums;
	}
	//last node connecting
	while (tempalbums != NULL)
	{
		if (tempalbums->album_ABID == tempAD->abid)
		{
			tempalbums->albumRef = tempAD;
		}
		tempalbums = tempalbums->next;
		tempAD = tempAD->next;
	}
	tempADP = loadADP.gethead();
	tempAD = loadAD.gethead();
	tempalbums = tempADP->albums;
	//2nd connection
	while (tempADP->next != loadADP.gethead())
	{
		while (tempalbums != NULL)
		{
			if (tempalbums->album_ABID == tempAD->abid)
			{
				tempAD->adp = tempADP;
			}
			tempalbums = tempalbums->next;
			tempAD = tempAD->next;
		}
		tempADP = tempADP->next;
		tempalbums = tempADP->albums;
	}
	//connecting the last node
	while (tempalbums != NULL)
	{
		if (tempalbums->album_ABID == tempAD->abid)
		{
			tempAD->adp = tempADP;
		}
		tempalbums = tempalbums->next;
		tempAD = tempAD->next;
	}
}

template<class a, class b>
void ADPtoAuthor()
{
	ADP<a>* tempADP = loadADP.gethead();
	AMD<a, b>* tempAMD = loadAMD.getHead();
	while (tempADP->next != loadADP.gethead())
	{
		if (tempADP->aid == tempAMD->aid)
		{
			tempADP->author = tempAMD;
		}
		tempADP = tempADP->next;
		tempAMD = tempAMD->next;
	}
	if (tempADP->aid == tempAMD->aid)
	{
		tempADP->author = tempAMD;
	}
	tempAMD = loadAMD.getHead();
	tempADP = loadADP.gethead();

	while (tempAMD->next != loadAMD.getHead())
	{
		if (tempAMD->aid == tempADP->aid)
		{
			tempAMD->adp = tempADP;
		}
		tempADP = tempADP->next;
		tempAMD = tempAMD->next;
	}
	if (tempAMD->aid == tempADP->aid)
	{
		tempAMD->adp = tempADP;
	}
}
//now loading the create_AD link list
template<class A>
ADP<A>* Create_ADP(string p)
{
	fstream myfile;
	myfile.open(p);
	if (myfile.is_open())
	{
		bool first = true;
		string tdid = "";
		int t = -1;
		while (!myfile.eof())
		{
			string Read_Data = "";
			int comma_count = 0;
			string temp[4] = { "" };
			bool flag[3] = { true,true,true };

			getline(myfile, Read_Data);

			if (Read_Data != "")
			{
				if (t != -1)
				{
					int c = 0;
					while (Read_Data[c] != ',')
					{
						temp[0] += Read_Data[c];
						c++;
					}
					for (int i = 0; i < Read_Data.length(); i++)
					{
						if (Read_Data[i] == ',')
						{
							comma_count++;
						}
						if (comma_count == 1 && flag[0] == true)
						{
							flag[0] = false;
							int c2 = i + 1;
							while (Read_Data[c2] != ',')
							{
								temp[1] += Read_Data[c2];
								c2++;
							}
						}
						if (comma_count == 2 && flag[1] == true)
						{
							flag[1] = false;
							int c2 = i + 1;
							while (Read_Data[c2] != ',')
							{
								temp[2] += Read_Data[c2];
								c2++;
							}
							//cout << temp[2] << endl;
						}
						if (comma_count == 3 && flag[2] == true)
						{
							flag[2] = false;
							int c2 = i + 1;
							while (c2 != Read_Data.length())
							{
								temp[3] += Read_Data[c2];
								c2++;
							}

						}

					}
					loadADP.insert(stoi(temp[0]), stoi(temp[1]), stoi(temp[2]), stoi(temp[3]));
				}
				else
				{
					t++;
					continue;
				}

			}
			else
			{
				continue;
			}
		}
	}
	else {
		cout << "File cant be opened." << endl;
	}
	ADPconnecAD<A, string, float>();
	ADPtoAuthor<A, string>();
	return loadADP.gethead();
}
//now the search music list
template <class A, class B, class C>
MMD<A, B, C>* Search_Music(A tempmbid)
{
	MMD<A, B, C>* iterate = loadMMD.getHead();
	while (iterate->next != NULL)
	{
		if (iterate->mbid == tempmbid)
		{
			return iterate;
		}
		iterate = iterate->next;
	}
}
template<class a, class b>
AMD<a, b>* Search_Author(a temp)
{
	AMD<a, b>* tempamd = loadAMD.getHead();
	while (tempamd->next != loadAMD.getHead())
	{
		if (tempamd->aid == temp)
		{
			return tempamd;
		}
		else
			tempamd = tempamd->next;
	}
	if (tempamd->aid == temp)
	{
		return tempamd;
	}
}
template <class a, class b, class c>
AD<a, b, c>* Search_Album(a temp)
{
	AD<a, b, c>* tempad = loadAD.gethead();
	while (tempad->next != loadAD.gethead())
	{

		if (tempad->abid == temp)
		{
			return tempad;
		}
		tempad = tempad->next;
	}
	if (tempad->abid == temp)
	{
		return tempad;
	}

}
template <class a>
ADP<a>* Search_Discography(a temp)
{
	ADP<a>* tempadp = loadADP.gethead();
	while (tempadp->next != loadADP.gethead())
	{
		if (tempadp->did == temp)
		{
			return tempadp;
		}
		tempadp = tempadp->next;
	}
	if (tempadp->did == temp)
	{
		return tempadp;
	}
}
template<class A>
Tracks<A>* Search_Music_By_Album(A temp)
{
	AD<int, string, float>* iterate = loadAD.gethead();
	while (iterate->next != loadAD.gethead())
	{
		if (iterate->abid == temp)
		{
			return iterate->tracks;
		}
		iterate = iterate->next;
	}
	if (iterate->abid == temp)
	{
		return iterate->tracks;
	}
}
template <class a>
Albums<a>* Search_Music_By_Author(a temp)
{
	ADP<a>* tempadp = loadADP.gethead();
	Albums<a>* tempalbums = tempadp->albums;
	while (tempadp->next != loadADP.gethead())
	{
		if (tempadp->did == temp)
		{
			return tempalbums;
		}
		tempadp = tempadp->next;
		tempalbums = tempadp->albums;
	}
	if (tempadp->did == temp)
	{
		return tempalbums;
	}
}
