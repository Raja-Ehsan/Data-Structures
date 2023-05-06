#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;

class actor_movie_node;
class MovieNode;

//-----------------Names-------------------link list

class Name_Data
{
public:
	string name_id;
	string name;
	string birth_name;
	int height;
	string bio;
	string birth_details;
	string date_of_birth;
	string place_of_birth;
	string death_details;
	string date_of_death; string place_of_death; string reason_of_death; string spouses_string; int spouses; int divorces; int spouses_with_children; int children;
};

//Name Node in a Linked List

class NameNode
{
public:
	NameNode(string name_id, string name, string birth_name, string height, string bio, string birth_details, string date_of_birth, string place_of_birth, string death_details, string date_of_death, string place_of_death, string reason_of_death, string spouses_string, string spouses, string divorces, string spouses_with_children, string children);
	Name_Data data;
	NameNode* next;
};

//Name Node Constructor to get data

NameNode::NameNode(string name_id, string name, string birth_name, string height, string bio, string birth_details, string date_of_birth, string place_of_birth, string death_details, string date_of_death, string place_of_death, string reason_of_death, string spouses_string, string spouses, string divorces, string spouses_with_children, string children)
{
	data.name_id = name_id;
	data.name = name;
	data.birth_name = birth_name;
	data.bio = bio;
	data.birth_details = birth_details;
	data.death_details = death_details;
	data.place_of_birth = place_of_birth;
	data.place_of_death = place_of_death;
	data.reason_of_death = reason_of_death;
	data.spouses_string = spouses_string;
	int temp;
	stringstream geek(height);
	geek >> temp;
	data.height = temp;

	stringstream geek1(spouses);
	geek1 >> temp;
	data.spouses = temp;

	stringstream geek2(divorces);
	geek2 >> temp;
	data.divorces = temp;

	stringstream geek3(spouses_with_children);
	geek3 >> temp;
	data.spouses_with_children = temp;

	stringstream geek4(children);
	geek4 >> temp;
	data.children = temp;
}

//List of names to Name_Nodes

class NameList
{
public:
	NameNode* start;
	NameNode* last;
	NameList();
	//Insertion into the list
	void insert(string name_id, string name, string birth_name, string height, string bio, string birth_details, string date_of_birth, string place_of_birth, string death_details, string date_of_death, string place_of_death, string reason_of_death, string spouses_string, string spouses, string divorces, string spouses_with_children, string children);
	void display();
};

//NameList Constructor that initializes the list
NameList::NameList()
{
	start = NULL;
	last = NULL;
}

//Insert Function 
void NameList::insert(string name_id, string name, string birth_name, string height, string bio, string birth_details, string date_of_birth, string place_of_birth, string death_details, string date_of_death, string place_of_death, string reason_of_death, string spouses_string, string spouses, string divorces, string spouses_with_children, string children)
{
	NameNode* newnode = new NameNode(name_id, name, birth_name, height, bio, birth_details, date_of_birth, place_of_birth, death_details, date_of_death, place_of_death, reason_of_death, spouses_string, spouses, divorces, spouses_with_children, children);

	if (start == NULL) {
		start = newnode;
		last = newnode;
	}
	else {
		last->next = newnode;
		last = newnode;
	}
}

//Display Name List
void NameList::display()
{
	NameNode* temp = start;
	while (temp != NULL) {
		cout << temp->data.name << endl;
		temp = temp->next;
	}
}

//Node contain pointer towards a movie
class movie_node_ptr {
public:
	movie_node_ptr();
	MovieNode* m_ptr;
	movie_node_ptr* next;
};


movie_node_ptr::movie_node_ptr() {
	m_ptr = NULL;
	next = NULL;
}

//Actor Node for actor list and contains pointer towards name list nodes
class Actor_Node {
public:
	Actor_Node();
	NameNode* ptr;
	movie_node_ptr* movie_ptr;
	Actor_Node* next;
};

//Actor Node Constructor
Actor_Node::Actor_Node() {
	ptr = NULL;
	movie_ptr = NULL;
	next = NULL;
}

//Contains Actor list functions
class Actor_List {
public:
	Actor_List();
	Actor_Node* start;
	Actor_Node* last;
	void insert(NameNode*);
	void display();
};

Actor_List::Actor_List() {
	start = NULL;
	last = NULL;
}

//insertion just like previous fields
void Actor_List::insert(NameNode* ptr) {
	Actor_Node* newnode = new Actor_Node();
	newnode->ptr = ptr;
	if (start == NULL) {
		start = newnode;
		last = newnode;
	}
	else {
		last->next = newnode;
		last = newnode;
	}
}

//Display actors in list
void Actor_List::display() {
	Actor_Node* triv = start;
	while (triv != NULL) {
		cout << triv->ptr->data.name << endl;
		triv = triv->next;
	}
}

//Genre_Node is the node of genre list
class Genre_Node {
public:
	Genre_Node();
	Genre_Node* next;
	movie_node_ptr* movie_ptr;
	string genre;
};

//Genre Node initializer 
Genre_Node::Genre_Node() {
	next = NULL;
	movie_ptr = NULL;
}

//Genre List that contains genre and their movies pointer 
class Genre_List {
public:
	Genre_List();
	Genre_Node* start;
	Genre_Node* last;
	void insert(string);
	void display();
};

//Genre List
Genre_List::Genre_List() {
	start = NULL;
	last = NULL;
}

//Insertion
void Genre_List::insert(string genre) {
	Genre_Node* newnode = new Genre_Node();
	newnode->genre = genre;
	if (start == NULL) {
		start = newnode;
		last = newnode;
	}
	else {
		last->next = newnode;
		last = newnode;
	}
}

void Genre_List::display() {
	Genre_Node* traverser = start;
	while (traverser != NULL) {
		cout << traverser->genre << endl;
		traverser = traverser->next;
	}
}

//Director Node for directors
class Director_Node {
public:
	Director_Node();
	NameNode* ptr;
	movie_node_ptr* movie_ptr;
	Director_Node* next;
};

Director_Node::Director_Node() {
	ptr = NULL;
	movie_ptr = NULL;
	next = NULL;
}

class Director_List {
public:
	Director_List();
	Director_Node* start;
	Director_Node* last;
	void insert(NameNode*);
	void display();
};

Director_List::Director_List() {
	start = NULL;
	last = NULL;
}

void Director_List::insert(NameNode* ptr) {
	Director_Node* newnode = new Director_Node();
	newnode->ptr = ptr;
	if (start == NULL) {
		start = newnode;
		last = newnode;
	}
	else {
		last->next = newnode;
		last = newnode;
	}
}

void Director_List::display() {
	Director_Node* triv = start;
	while (triv != NULL) {
		cout << triv->ptr->data.name << endl;
		triv = triv->next;
	}
}

//Actor Pointer Node that contain pointer that points to the actors
class actor_node_ptr
{
public:
	Actor_Node* ptr;
	actor_node_ptr* next;
	actor_node_ptr();
};

actor_node_ptr::actor_node_ptr()
{
	ptr = NULL;
	next = NULL;
}

//-----------------Movies-------------------
class MovieData {
public:
	string title_id;
	string title;
	string original_title;
	int year;
	string date;
	string genre;
	int duration;
	string country;
	string language;
	string director;
	string writer;
	string production_company;
	actor_node_ptr * actor_Start;
	string description;
	double age_vote;
	int votes;
	string budget;
	string usa_gross_income;
	string worldwide_gross_income;
	int meta_score;
	int reviews_from_user;
	int reviews_from_critics;
};

//Movie Node for movie
class MovieNode {
public:
	MovieNode(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, actor_node_ptr* actor_Start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics);
	MovieNode* next;
	MovieData data;
};

MovieNode::MovieNode(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, actor_node_ptr* actor_Start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics) {
	int temp;
	data.title_id = title_id;
	data.title = title;
	data.original_title = original_title;
	stringstream geek(year);
	geek >> temp;
	data.year = temp;
	data.date = date;
	data.genre = genre;
	stringstream geek1(duration);
	geek >> temp;
	data.duration = temp;
	data.country = country;
	data.language = language;
	data.director = director;
	data.writer = writer;
	data.production_company = production_company;
	data.actor_Start = actor_Start;
	data.description = description;
	stringstream geek2(age_vote);
	geek >> temp;
	data.age_vote = double(temp);
	stringstream geek6(age_vote);
	geek >> temp;
	data.votes = temp;
	data.budget = budget;
	data.usa_gross_income = usa_gross_income;
	stringstream geek3(meta_score);
	geek >> temp;
	data.meta_score = temp;
	data.worldwide_gross_income = worldwide_gross_income;
	stringstream geek4(reviews_from_user);
	geek >> temp;
	data.reviews_from_user = temp;
	stringstream geek5(reviews_from_critics);
	geek >> temp;
	data.reviews_from_critics = temp;
}

class MovieList {
public:
	MovieNode* start;
	MovieNode* last;
	MovieList();
	void insert(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, actor_node_ptr* actor_Start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics);
	void display();
};

MovieList::MovieList() {
	start = NULL;
	last = NULL;
}

//insertion and dislay
void MovieList::insert(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, actor_node_ptr* actor_Start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics) {
	MovieNode* newnode = new MovieNode(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_Start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
	if (start == NULL) {
		start = newnode;
		last = newnode;
	}
	else {
		last->next = newnode;
		last = newnode;
	}
}

void MovieList::display() {
	MovieNode* temp = start;
	while (temp != NULL) {
		cout << temp->data.title << endl;
		temp = temp->next;
	}
}

//Node that contains pointer towards a movie done by an actor
class actor_movie_node {
public:
	MovieNode* ptr;
	actor_movie_node* next;
	actor_movie_node();
};

actor_movie_node::actor_movie_node() {
	ptr = NULL;
	next = NULL;
}

//-----------------ratings-------------------
class Ratings_data
{
public:
	string imdb_title_id;
	double weighted_average_vote;
	int	total_votes;
	double mean_vote;
	int median_vote;
	int votes_10;
	int votes_9;
	int votes_8;
	int votes_7;
	int	votes_6;
	int	votes_5;
	int	votes_4;
	int	votes_3;
	int	votes_2;
	int	votes_1;
	double allgenders_0age_avg_vote;
	int allgenders_0age_votes;
	double allgenders_18age_avg_vote;
	int allgenders_18age_votes;
	double allgenders_30age_avg_vote;
	int allgenders_30age_votes;
	double allgenders_45age_avg_vote;
	int allgenders_45age_votes;
	double males_allages_avg_vote;
	int males_allages_votes;
	double males_0age_avg_vote;
	int males_0age_votes;
	double males_18age_avg_vote;
	int males_18age_votes;
	double males_30age_avg_vote;
	int males_30age_votes;
	double males_45age_avg_vote;
	int males_45age_votes;
	double females_allages_avg_vote;
	int females_allages_votes;
	double females_0age_avg_vote;
	int females_0age_votes;
	double females_18age_avg_vote;
	int females_18age_votes;
	double females_30age_avg_vote;
	int females_30age_votes;
	double females_45age_avg_vote;
	int females_45age_votes;
	double top1000_voters_rating;
	int top1000_voters_votes;
	double us_voters_rating;
	int us_voters_votes;
	double non_us_voters_rating;
	int non_us_voters_votes;
};

class RatingsNode {
public:
	RatingsNode(string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string);
	Ratings_data data;
	RatingsNode* next;
};

RatingsNode::RatingsNode(string imdb_title_id, string weighted_average_vote, string  total_votes, string mean_vote, string median_vote, string votes_10, string votes_9, string votes_8, string votes_7, string votes_6, string votes_5, string votes_4, string votes_3, string votes_2, string votes_1, string allgenders_0age_avg_vote, string allgenders_0age_votes, string allgenders_18age_avg_vote, string allgenders_18age_votes, string allgenders_30age_avg_vote, string allgenders_30age_votes, string allgenders_45age_avg_vote, string allgenders_45age_votes, string males_allages_avg_vote, string males_allages_votes, string males_0age_avg_vote, string males_0age_votes, string males_18age_avg_vote, string males_18age_votes, string males_30age_avg_vote, string males_30age_votes, string males_45age_avg_vote, string males_45age_votes, string females_allages_avg_vote, string females_allages_votes, string females_0age_avg_vote, string females_0age_votes, string females_18age_avg_vote, string females_18age_votes, string females_30age_avg_vote, string females_30age_votes, string females_45age_avg_vote, string females_45age_votes, string top1000_voters_rating, string top1000_voters_votes, string us_voters_rating, string us_voters_votes, string non_us_voters_rating, string non_us_voters_votes) {
	int temp;
	stringstream geek(allgenders_0age_avg_vote);
	geek >> temp;
	data.allgenders_0age_avg_vote = temp;
	stringstream geek1(allgenders_0age_votes);
	geek1 >> temp;
	data.allgenders_0age_votes = temp;

	stringstream geek2(allgenders_18age_avg_vote);
	geek2 >> temp;

	data.allgenders_18age_avg_vote = temp;

	stringstream geek3(allgenders_18age_votes);
	geek3 >> temp;

	data.allgenders_18age_votes = temp;

	stringstream geek4(allgenders_30age_avg_vote);
	geek4 >> temp;

	data.allgenders_30age_avg_vote = temp;

	stringstream geek5(allgenders_30age_votes);
	geek5 >> temp;

	data.allgenders_30age_votes = temp;

	stringstream geek6(allgenders_45age_avg_vote);
	geek6 >> temp;

	data.allgenders_45age_avg_vote = temp;

	stringstream geek7(allgenders_45age_votes);
	geek7 >> temp;

	data.allgenders_45age_votes = temp;

	stringstream geek8(females_0age_avg_vote);
	geek8 >> temp;

	data.females_0age_avg_vote = temp;

	stringstream geek9(females_0age_votes);
	geek9 >> temp;

	data.females_0age_votes = temp;

	stringstream geek10(females_0age_avg_vote);
	geek10 >> temp;

	data.females_18age_avg_vote = temp;

	stringstream geek11(females_18age_votes);
	geek11 >> temp;

	data.females_18age_votes = temp;

	stringstream geek12(females_30age_avg_vote);
	geek12 >> temp;

	data.females_30age_avg_vote = temp;

	stringstream geek13(females_30age_votes);
	geek13 >> temp;

	data.females_30age_votes = temp;

	stringstream geek14(females_45age_avg_vote);
	geek14 >> temp;

	data.females_45age_avg_vote = temp;

	stringstream geek15(females_45age_votes);
	geek15 >> temp;

	data.females_45age_votes = temp;

	stringstream geek16(females_allages_avg_vote);
	geek16 >> temp;

	data.females_allages_avg_vote = temp;

	stringstream geek17(females_allages_votes);
	geek17 >> temp;

	data.females_allages_votes = temp;

	stringstream geek18(males_0age_avg_vote);
	geek18 >> temp;

	data.males_0age_avg_vote = temp;

	stringstream geek19(males_0age_votes);
	geek19 >> temp;

	data.males_0age_votes = temp;

	stringstream geek20(males_0age_avg_vote);
	geek20 >> temp;

	data.males_18age_avg_vote = temp;

	stringstream geek21(males_18age_votes);
	geek21 >> temp;

	data.males_18age_votes = temp;

	stringstream geek22(males_30age_avg_vote);
	geek22 >> temp;

	data.males_30age_avg_vote = temp;

	stringstream geek23(males_30age_votes);
	geek23 >> temp;

	data.males_30age_votes = temp;

	stringstream geek24(males_45age_avg_vote);//conversion of string to double
	geek24 >> temp;

	data.males_45age_avg_vote = temp;

	stringstream geek25(males_45age_votes);
	geek25 >> temp;

	data.males_45age_votes = temp;

	stringstream geek26(males_allages_avg_vote);
	geek26 >> temp;

	data.males_allages_avg_vote = temp;

	stringstream geek27(males_allages_votes);
	geek27 >> temp;

	data.males_allages_votes = temp;

	stringstream geek28(imdb_title_id);
	geek28 >> temp;

	data.imdb_title_id = temp;

	stringstream geek29(mean_vote);
	geek29 >> temp;

	data.mean_vote = temp;

	stringstream geek30(median_vote);
	geek30 >> temp;

	data.median_vote = temp;

	stringstream geek31(non_us_voters_rating);
	geek31 >> temp;

	data.non_us_voters_rating = temp;

	stringstream geek32(non_us_voters_votes);
	geek32 >> temp;

	data.non_us_voters_votes = temp;

	stringstream geek33(top1000_voters_rating);
	geek33 >> temp;

	data.top1000_voters_rating = temp;

	stringstream geek34(top1000_voters_votes);
	geek34 >> temp;

	data.top1000_voters_votes = temp;

	stringstream geek35(total_votes);
	geek35 >> temp;

	data.total_votes = temp;

	stringstream geek36(us_voters_rating);
	geek36 >> temp;

	data.us_voters_rating = temp;

	stringstream geek37(us_voters_votes);
	geek37 >> temp;

	data.us_voters_votes = temp;

	stringstream geek38(votes_1);
	geek38 >> temp;

	data.votes_1 = temp;

	stringstream geek39(votes_10);
	geek39 >> temp;

	data.votes_10 = temp;

	stringstream geek40(votes_2);
	geek40 >> temp;

	data.votes_2 = temp;

	stringstream geek41(votes_3);
	geek41 >> temp;

	data.votes_3 = temp;

	stringstream geek42(votes_4);
	geek42 >> temp;

	data.votes_4 = temp;

	stringstream geek43(votes_5);
	geek43 >> temp;

	data.votes_5 = temp;

	stringstream geek44(votes_6);
	geek44 >> temp;

	data.votes_6 = temp;

	stringstream geek45(votes_7);
	geek45 >> temp;

	data.votes_7 = temp;

	stringstream geek46(votes_8);
	geek46 >> temp;

	data.votes_8 = temp;

	stringstream geek47(votes_9);
	geek47 >> temp;

	data.votes_9 = temp;

	stringstream geek48(weighted_average_vote);
	geek48 >> temp;

	data.weighted_average_vote = temp;
}

class RatingsList {
public:
	RatingsNode* start;
	RatingsNode* last;
	RatingsList();
	void insert(string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string);
	void display();
};

RatingsList::RatingsList() {
	start = NULL;
	last = NULL;
}

void RatingsList::insert(string imdb_title_id, string weighted_average_vote, string  total_votes, string mean_vote, string median_vote, string votes_10, string votes_9, string votes_8, string votes_7, string votes_6, string votes_5, string votes_4, string votes_3, string votes_2, string votes_1, string allgenders_0age_avg_vote, string allgenders_0age_votes, string allgenders_18age_avg_vote, string allgenders_18age_votes, string allgenders_30age_avg_vote, string allgenders_30age_votes, string allgenders_45age_avg_vote, string allgenders_45age_votes, string males_allages_avg_vote, string males_allages_votes, string males_0age_avg_vote, string males_0age_votes, string males_18age_avg_vote, string males_18age_votes, string males_30age_avg_vote, string males_30age_votes, string males_45age_avg_vote, string males_45age_votes, string females_allages_avg_vote, string females_allages_votes, string females_0age_avg_vote, string females_0age_votes, string females_18age_avg_vote, string females_18age_votes, string females_30age_avg_vote, string females_30age_votes, string females_45age_avg_vote, string females_45age_votes, string top1000_voters_rating, string top1000_voters_votes, string us_voters_rating, string us_voters_votes, string non_us_voters_rating, string non_us_voters_votes) {
	RatingsNode* newnode = new RatingsNode(imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes);
	if (start == NULL) {
		start = newnode;
		last = newnode;
	}
	else {
		last->next = newnode;
		last = newnode;
	}
}

void RatingsList::display() {
	RatingsNode* temp = start;
	while (temp != NULL) {
		cout << temp->data.allgenders_0age_avg_vote << endl;
		temp = temp->next;
	}
}


//-----------------title_principles----------------
class title_principles_Data {
public:
	string imdb_title_id;
	int order;
	string imdb_name_id;
	string category;
	string job;
	string characters;
};

class title_principles_Node {
public:
	title_principles_Node(string, string, string, string, string, string);
	title_principles_Data data;
	title_principles_Node* next;
};

title_principles_Node::title_principles_Node(string imdb_title_id, string order, string imdb_name_id, string category, string job, string characters) {
	int temp;
	data.imdb_title_id = imdb_title_id;
	stringstream geek(order);
	geek >> temp;
	data.order = temp;
	data.imdb_name_id = imdb_name_id;
	data.category = category;
	data.job = job;
	data.characters = characters;
}

class title_principles_Node_List {
public:
	title_principles_Node* start;
	title_principles_Node* last;
	title_principles_Node_List();
	void insert(string, string, string, string, string, string);
	void display();
};

title_principles_Node_List::title_principles_Node_List() {
	start = NULL;
	last = NULL;
}

void title_principles_Node_List::insert(string imdb_title_id, string order, string imdb_name_id, string category, string job, string characters) {
	title_principles_Node* newnode = new title_principles_Node(imdb_title_id, order, imdb_name_id, category, job, characters);
	if (start == NULL) {
		start = newnode;
		last = newnode;
	}
	else {
		last->next = newnode;
		last = newnode;
	}
}

void title_principles_Node_List::display() {
	title_principles_Node* temp = start;
	while (temp != NULL) {
		cout << temp->data.imdb_title_id << endl;
		temp = temp->next;
	}
}


void read(MovieList* ml, RatingsList* rl, title_principles_Node_List* t1, NameList* t2, Actor_List* al, Director_List* dl,Genre_List* gl){

	//-----------------name Storage----------------
	int count = 0;
	string name_id;
	string name;
	string birth_name;
	string height;
	string bio;
	string birth_details;
	string date_of_birth;
	string place_of_birth;
	string death_details;
	string date_of_death; string place_of_death; string reason_of_death; string spouses_string; string spouses; string divorces; string spouses_with_children; string children;

	ifstream File3("names.csv");

	if (File3.is_open()) {
		while (!File3.eof()) {
			if (count == 0) {
				string temp;
				getline(File3, temp);
				count = 1;
			}
			else {
				getline(File3, name_id, ',');
				getline(File3, name, ',');
				getline(File3, birth_name, ',');
				getline(File3, height, ',');
				getline(File3, bio, ',');
				getline(File3, birth_details, ',');
				getline(File3, date_of_birth, ',');
				getline(File3, place_of_birth, ',');
				getline(File3, death_details, ',');
				getline(File3, date_of_death, ',');
				getline(File3, place_of_death, ',');
				getline(File3, reason_of_death, ',');
				getline(File3, spouses_string, ',');
				getline(File3, spouses, ',');
				getline(File3, divorces, ',');
				getline(File3, spouses_with_children, ',');
				getline(File3, children);
				t2->insert(name_id, name, birth_name, height, bio, birth_details, date_of_birth, place_of_birth, death_details, date_of_death, place_of_death, reason_of_death, spouses_string, spouses, divorces, spouses_with_children, children);
			}
		}
	}
	else {
		cout << "Give Error3";
	}

	//---------------Title Principal Storage-------------

	count = 0;
	string imdb_title_id1;
	string order;
	string imdb_name_id1;
	string category;
	string job;
	string characters;

	ifstream File2("title_principals.csv");

	if (File2.is_open()) {
		while (!File2.eof()) {
			if (count == 0) {
				string temp;
				getline(File2, temp);

				count = 1;
			}
			else {
				getline(File2, imdb_title_id1, ',');
				getline(File2, order, ',');
				getline(File2, imdb_name_id1, ',');
				getline(File2, category, ',');
				getline(File2, job, ',');
				getline(File2, characters);
				t1->insert(imdb_title_id1, order, imdb_name_id1, category, job, characters);
			}
		}
	}
	else {
		cout << "Give Error2";
	}

	
	//----------------Actor List Formation----------------
	NameNode* name_list_traverser = t2->start;
	while (name_list_traverser != NULL) {
		string IMDB_Name_ID;
		title_principles_Node* title_principles_traverser = t1->start;
		while (title_principles_traverser != NULL) {
			if (name_list_traverser->data.name_id == title_principles_traverser->data.imdb_name_id) {
				if (title_principles_traverser->data.category == "actor" || title_principles_traverser->data.category == "actress") {
					al->insert(name_list_traverser);
					break;
				}
			}
			title_principles_traverser = title_principles_traverser->next;
		}
		name_list_traverser = name_list_traverser->next;
	}

	//Director List Formation
	name_list_traverser = t2->start;
	while (name_list_traverser != NULL) {
		string IMDB_Name_ID;
		title_principles_Node* title_principles_traverser = t1->start;
		while (title_principles_traverser != NULL) {
			if (name_list_traverser->data.name_id == title_principles_traverser->data.imdb_name_id) {
				if (title_principles_traverser->data.category == "director") {
					dl->insert(name_list_traverser);
					break;
				}
			}
			title_principles_traverser = title_principles_traverser->next;
		}
		name_list_traverser = name_list_traverser->next;
	}
	
	//---------Movie List Storage------------
	count = 0;
	string title_id;
	string title;
	string original_title;
	string year;
	string date;
	string genre;
	string duration;
	string country;
	string language;
	string director;
	string writer;
	string production_company;
	string actors;
	string description;
	string age_vote;
	string votes;
	string budget;
	string usa_gross_income;
	string worldwide_gross_income;
	string meta_score;
	string reviews_from_user;
	string reviews_from_critics;
	ifstream File("movies.csv");

	if (File.is_open()) {

		while (!File.eof()) {

			if (count == 0) {
				string temp;
				getline(File, temp);
				count = 1;
			}
			else {
				getline(File, title_id, ',');
				getline(File, title, ',');
				getline(File, original_title, ',');
				getline(File, year, ',');
				getline(File, date, ',');
				getline(File, genre, ',');
				getline(File, duration, ',');
				getline(File, country, ',');
				getline(File, language, ',');
				getline(File, director, ',');
				getline(File, writer, ',');
				getline(File, production_company, ',');
				getline(File, actors, ',');

				//Add List of all pointers of actors act in a movie 
				actor_node_ptr* actor_Start = NULL;
				string s = actors;
				string delimiter = "-";
				size_t pos = 0;
				string token;
				Actor_Node* traverser = al->start;
				actor_node_ptr* traverser1 = NULL;

				while ((pos = s.find(delimiter)) != string::npos) {
					token = s.substr(0, pos);
					traverser = al->start;
					while (traverser != NULL && traverser->ptr->data.name != token) {
						traverser = traverser->next;
					}
					if (traverser != NULL) {
						actor_node_ptr* newnode = new actor_node_ptr();
						newnode->ptr = traverser;
						if (actor_Start == NULL)
						{
							actor_Start = newnode;
						}
						else {
							traverser1 = actor_Start;
							while (traverser1 != NULL && traverser1->next != NULL) {
								traverser1 = traverser1->next;
							}
							traverser1->next = newnode;
						}
					}
					s.erase(0, pos + delimiter.length());
				}

				traverser = al->start;
				while (traverser != NULL && traverser->ptr->data.name != s) {
					traverser = traverser->next;
				}

				if (traverser != NULL) {
					actor_node_ptr* newnode = new actor_node_ptr();
					newnode->ptr = traverser;
					traverser1 = actor_Start;
					while (traverser1 != NULL && traverser1->next != NULL) {
						traverser1 = traverser1->next;
					}
					traverser1->next = newnode;
				}

				getline(File, description, ',');
				getline(File, age_vote, ',');
				getline(File, votes, ',');
				getline(File, budget, ',');
				getline(File, usa_gross_income, ',');
				getline(File, meta_score, ',');
				getline(File, reviews_from_user, ',');
				getline(File, reviews_from_critics);
				ml->insert(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_Start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
			}
		}
		File.close();
	}
	else {
		cout << "Give Error\n" << endl;
	}
	//---------Rating List Storage------------

	count = 0;
	string imdb_title_id;
	string weighted_average_vote;
	string	total_votes;
	string mean_vote;
	string median_vote;
	string votes_10;
	string votes_9;
	string votes_8;
	string votes_7;
	string	votes_6;
	string	votes_5;
	string	votes_4;
	string	votes_3;
	string	votes_2;
	string	votes_1;
	string allgenders_0age_avg_vote;
	string allgenders_0age_votes;
	string allgenders_18age_avg_vote;
	string allgenders_18age_votes;
	string allgenders_30age_avg_vote;
	string allgenders_30age_votes;
	string allgenders_45age_avg_vote;
	string allgenders_45age_votes;
	string males_allages_avg_vote;
	string males_allages_votes;
	string males_0age_avg_vote;
	string males_0age_votes;
	string males_18age_avg_vote;
	string males_18age_votes;
	string males_30age_avg_vote;
	string males_30age_votes;
	string males_45age_avg_vote;
	string males_45age_votes;
	string females_allages_avg_vote;
	string females_allages_votes;
	string females_0age_avg_vote;
	string females_0age_votes;
	string females_18age_avg_vote;
	string females_18age_votes;
	string females_30age_avg_vote;
	string females_30age_votes;
	string females_45age_avg_vote;
	string females_45age_votes;
	string top1000_voters_rating;
	string top1000_voters_votes;
	string us_voters_rating;
	string us_voters_votes;
	string non_us_voters_rating;
	string non_us_voters_votes;


	ifstream File1("ratings.csv");

	if (File1.is_open()) {
		while (!File1.eof()) {
			if (count == 0) {
				string temp;
				getline(File1, temp);

				count = 1;
			}
			else {
				getline(File1, imdb_title_id, ',');
				getline(File1, weighted_average_vote, ',');
				getline(File1, total_votes, ',');
				getline(File1, mean_vote, ',');
				getline(File1, median_vote, ',');
				getline(File1, votes_10, ',');
				getline(File1, votes_9, ',');
				getline(File1, votes_8, ',');
				getline(File1, votes_7, ',');
				getline(File1, votes_6, ',');
				getline(File1, votes_5, ',');
				getline(File1, votes_4, ',');
				getline(File1, votes_3, ',');
				getline(File1, votes_2, ',');
				getline(File1, votes_1, ',');
				getline(File1, votes_9, ',');
				getline(File1, allgenders_0age_avg_vote, ',');
				getline(File1, allgenders_0age_votes, ',');
				getline(File1, allgenders_18age_avg_vote, ',');
				getline(File1, allgenders_18age_votes, ',');
				getline(File1, allgenders_18age_votes, ',');
				getline(File1, allgenders_30age_avg_vote, ',');
				getline(File1, allgenders_30age_avg_vote, ',');
				getline(File1, allgenders_45age_avg_vote, ',');
				getline(File1, allgenders_45age_avg_vote, ',');
				getline(File1, females_allages_avg_vote, ',');
				getline(File1, females_allages_votes, ',');
				getline(File1, females_0age_avg_vote, ',');
				getline(File1, females_0age_votes, ',');
				getline(File1, females_18age_avg_vote, ',');
				getline(File1, females_18age_votes, ',');
				getline(File1, females_30age_avg_vote, ',');
				getline(File1, females_30age_votes, ',');
				getline(File1, females_45age_avg_vote, ',');
				getline(File1, top1000_voters_rating, ',');
				getline(File1, top1000_voters_votes, ',');
				getline(File1, us_voters_rating, ',');
				getline(File1, us_voters_votes, ',');
				getline(File1, non_us_voters_rating, ',');
				getline(File1, non_us_voters_votes);

				rl->insert(imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes);
			}
		}
	}
	else {
		cout << "Give Error1\n";
	}

	//Set pointers towards movies of actors
	Actor_Node* actor_triv = al->start;
	while (actor_triv != NULL) {
		string actor_name = actor_triv->ptr->data.name;
		MovieNode* movie_triv = ml->start;
		while (movie_triv!=NULL){
			actor_node_ptr* movie_actor_triv = movie_triv->data.actor_Start;
			while (movie_actor_triv!=NULL) {
				if (actor_name == movie_actor_triv->ptr->ptr->data.name) {
					break;
				}
				movie_actor_triv = movie_actor_triv->next;
			}
			if (movie_actor_triv != NULL) {
				movie_node_ptr* newnode = new movie_node_ptr();
				newnode->m_ptr = movie_triv;
				if (actor_triv->movie_ptr == NULL) {
					actor_triv->movie_ptr = newnode;
				}
				else {
					movie_node_ptr* traverser = actor_triv->movie_ptr;
					while (traverser!=NULL && traverser->next != NULL) {
						traverser = traverser->next;
					}
					traverser->next = newnode;
				}
			}
			movie_triv = movie_triv->next;
		}
		actor_triv = actor_triv->next;
	}

	//Pointers of movies directed by a director
	Director_Node* director_triv = dl->start;
	while (director_triv != NULL) {
		string director_name = director_triv->ptr->data.name;
		MovieNode* movie_triv = ml->start;
		while (movie_triv != NULL) {
			if (movie_triv->data.director==director_name) {
				movie_node_ptr* newnode = new movie_node_ptr();
				newnode->m_ptr = movie_triv;
				if (director_triv->movie_ptr == NULL) {
					director_triv->movie_ptr = newnode;
				}
				else {
					movie_node_ptr* traverser = director_triv->movie_ptr;
					while (traverser!=NULL && traverser->next != NULL) {
						traverser = traverser->next;
					}
					traverser->next = newnode;
				}
			}
			movie_triv = movie_triv->next;
		}
		director_triv = director_triv->next;
	}

	//Store all Genres
	MovieNode* m_traverser = ml->start;
	bool rep;
	while (m_traverser != NULL)
	{
		Genre_Node* g_traverser = gl->start;
		string s = m_traverser->data.genre;
		string delimiter = "-";
		size_t pos = 0;
		string token;
		while ((pos = s.find(delimiter)) != string::npos) {
			token = s.substr(0, pos);
			rep = true;
			Genre_Node* triv = gl->start;
			while (triv != NULL)
			{
				if (triv->genre == token)
					rep = false;
				triv = triv->next;
			}
			if (rep == true)
				gl->insert(token);
			s.erase(0, pos + delimiter.length());
		}
		token = s.substr(0, pos);
		rep = true;
		Genre_Node*triv = gl->start;
		while (triv != NULL)
		{
			if (triv->genre == token)
				rep = false;
			triv = triv->next;
		}
		if (rep == true)
			gl->insert(token);
		m_traverser = m_traverser->next;
	}

	//Maintain pointers towards movies of certain genre
	Genre_Node* g_triv = gl->start;
	while (g_triv != NULL) {
		string genre_name = g_triv->genre;
		MovieNode* movie_triv = ml->start;
		while (movie_triv != NULL) {
			string s = movie_triv->data.genre;
			string delimiter = "-";
			size_t pos = 0;
			string token;
			while ((pos = s.find(delimiter)) != string::npos) {

				token = s.substr(0, pos);
				if (token == genre_name) {
					movie_node_ptr* newnode = new movie_node_ptr();
					newnode->m_ptr = movie_triv;
					if (g_triv->movie_ptr == NULL) {
						g_triv->movie_ptr = newnode;
					}
					else {
						movie_node_ptr* traverser = g_triv->movie_ptr;
						while (traverser->next != NULL) {
							traverser = traverser->next;
						}
						traverser->next = newnode;
					}

				}
				s.erase(0, pos + delimiter.length());
			}
			if (s == genre_name) {
				movie_node_ptr* newnode = new movie_node_ptr();
				newnode->m_ptr = movie_triv;
				if (g_triv->movie_ptr == NULL) {
					g_triv->movie_ptr = newnode;
				}
				else {
					movie_node_ptr* traverser = g_triv->movie_ptr;
					while (traverser->next != NULL) {
						traverser = traverser->next;
					}
					traverser->next = newnode;
				}
			}
			movie_triv = movie_triv->next;
		}
		g_triv = g_triv->next;
	}
}

//Determines the coactors by using the existing lists
void co_actors_of_co_actors(string name, Actor_List* al, bool stopper = true) {
	Actor_Node* actor_traverser = al->start;
	while (actor_traverser != NULL && actor_traverser->ptr->data.name != name) {
		actor_traverser = actor_traverser->next;
	}
	if (actor_traverser != NULL && actor_traverser->ptr->data.name == name) {
		movie_node_ptr* movie_traverser = actor_traverser->movie_ptr;
		while (movie_traverser != NULL) {
			actor_node_ptr* co_actor_traverser = movie_traverser->m_ptr->data.actor_Start;
			while (co_actor_traverser != NULL) {
				if (stopper == true) {
					if(co_actor_traverser->ptr->ptr->data.name != name)
						cout << "\nThe co_actors of co_actor " << co_actor_traverser->ptr->ptr->data.name << " are : " << endl;
					else
						cout << "The co_actors of actor " << co_actor_traverser->ptr->ptr->data.name << " are : " << endl;
					co_actors_of_co_actors(co_actor_traverser->ptr->ptr->data.name, al, false);
				}
				else {
					if (co_actor_traverser->ptr->ptr->data.name != name) {
						cout << co_actor_traverser->ptr->ptr->data.name << endl;
					}
				}
				co_actor_traverser = co_actor_traverser->next;
			}
			movie_traverser = movie_traverser->next;
		}
	}
	else {
		cout << "Actor Not Found" << endl;
	}
}

void co_actors(string name, Actor_List* nl) {
	Actor_Node* actor_traverser = nl->start;
	while (actor_traverser != NULL && actor_traverser->ptr->data.name != name) {
		actor_traverser = actor_traverser->next;
	}
	if (actor_traverser != NULL && actor_traverser->ptr->data.name == name) {
		movie_node_ptr* movie_traverser = actor_traverser->movie_ptr;
		while (movie_traverser != NULL) {
			actor_node_ptr* co_actor_traverser = movie_traverser->m_ptr->data.actor_Start;
			cout << "Co_Actors of actor " << name << " are : " << endl;
			while (co_actor_traverser != NULL) {
				if (co_actor_traverser->ptr->ptr->data.name != name)
					cout << co_actor_traverser->ptr->ptr->data.name << endl;
				co_actor_traverser = co_actor_traverser->next;
			}
			movie_traverser = movie_traverser->next;
		}
	}
	else {
		cout << "Actor Not Found" << endl;
	}
}

//Movies of Director
void director_movies(string name, Director_List* dl)
{
	Director_Node* d_traverser = dl->start;
	while (d_traverser != NULL) {
		if (d_traverser->ptr->data.name == name)
			break;
		d_traverser = d_traverser->next;
	}
	if (d_traverser != NULL) {
		movie_node_ptr* movie_ptr = d_traverser->movie_ptr;
		cout << name << " Movies : " << endl;
		while (movie_ptr != NULL) {
			cout << "\t" << movie_ptr->m_ptr->data.title << endl;
			movie_ptr = movie_ptr->next;
		}
	}
	else {
		cout << "Director Not Found" << endl;
	}
}

//Movies with certain genre and director 
void director_movie_genre(string genre,Genre_List* gl) {

	Genre_Node* g_triv = gl->start;
	while (g_triv != NULL)
	{
		if (g_triv->genre == genre)
			break;
		g_triv = g_triv->next;
	}
	if (g_triv != NULL)
	{
		movie_node_ptr* m_triv = g_triv->movie_ptr;
		while (m_triv != NULL)
		{
			cout << m_triv->m_ptr->data.director << endl;
			m_triv = m_triv->next;
		}
		if (m_triv == NULL)
			cout << "Director Not Found" << endl;
	}
	else {
		cout << "Genre Not Found" << endl;
	}
}

//Movies of certain genre
void genre_movies(string genre, Genre_List* gl) {
	Genre_Node* g_triv = gl->start;
	while (g_triv != NULL)
	{
		if (g_triv->genre == genre)
			break;
		g_triv = g_triv->next;
	}
	if (g_triv != NULL)
	{
		movie_node_ptr* m_triv = g_triv->movie_ptr;
		while (m_triv != NULL)
		{
			cout << m_triv->m_ptr->data.title << endl;
			m_triv = m_triv->next;
		}
	}
	else {
		cout << "Genre Not Found" << endl;
	}
}

int main() {
	bool menu = true;
	int option;
	string Genre = "";
	string Director = "";
	string Actor = "";
	Actor_List al;
	MovieList ml;
	RatingsList rl;
	NameList n1;
	Director_List dl;
	title_principles_Node_List t1;
	Genre_List gl;
	read(&ml, &rl, &t1, &n1, &al, &dl, &gl);
	cout << "\t\t\t\t\t\t----IMDB----" << endl;
	cout << "\n\t\t\t\t\t  1. Search Movie by Genre" << endl;
	cout << "\n\t\t\t\t\t  2. Search Director Movies" << endl;
	cout << "\n\t\t\t\t3. Search Director by his directed Movie's Genre" << endl;
	cout << "\n\t\t\t\t\t  4. Search Co-Actors of Co-Actors" << endl;
	cout << "\n\t\t\t\t\t  5. Search Co-Actors" << endl;
	cout << "\n\t\t\t\t\t\t  6. Exit" << endl;
	while (menu) {
		cout << "\nEnter Option : ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Enter Genre : ";
			cin >> Genre;
			genre_movies(Genre, &gl);
			break;
		case 2:
			cout << "Enter Director Name : ";
			cin >> Director;
			director_movies(Director, &dl);
			break; 
		case 3:
			cout << "Enter Genre : ";
			cin >> Genre;
			director_movie_genre(Genre, &gl);
			break;
		case 4:
			cout << "Enter Actor Name : ";
			cin >> Actor;
			co_actors(Actor, &al);
			break;
		case 5:
			cout << "Enter Actor Name : ";
			cin >> Actor;
			co_actors_of_co_actors(Actor, &al);
			break;
		default:
			menu = false;
			break;
		}
	}
	return 0;
}