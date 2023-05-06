#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<sstream>
using namespace std;
const int ARR_SIZE = 23;//hash
static const int PRIME_CONST = 11;
//Class declaration of actor_movie_node and movie_actor_node
//to use there members before definition
class actor_movie_node;
class movie_actor_node;



//class Movie data to store data of Movie
class MovieData {
public:
	//public data members
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
	string actor_Start;
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
//Class for AVL iplementation

class MovieNode {
public:
	//constructor to pass values to datamembers of MovieNode for a specific node
	MovieNode(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actor_start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics);
	//Moviedata tyoe datta variabes to access the data in MovieNode
	MovieData data;
	//Left and Right Child for AVL
	MovieNode* lch;
	MovieNode* rch;
	//integer vairable of keep track of height of AVL tree
	int height1;
};
//Paraerterized Constructor for MovieNode class

MovieNode::MovieNode(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actor_start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics) {
	//Conversion to original datatype after reading from csv file as strings
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

	data.actor_Start = actor_start;

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

	lch = NULL;
	rch = NULL;
	height1 = 1;
}
//Class movie_avl_year for AVL functions implementations based on the value of Year
class movie_avl_year
{
public:

	//Function which returns the address of newly created node
	MovieNode* create_node(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actor_Start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
	{
		MovieNode* newnode = new MovieNode(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_Start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		return newnode;
	}
	//Function which returns max of two values
	int max(int a, int b)
	{
		if (a > b)return a;
		return b;
	}
	//Function which returns the heigth of current node
	int get_height(MovieNode* temp) {
		if (temp == NULL) {
			return 0;
		}
		return temp->height1;
	}
	//Function to return the balance factor of two nodes(hieght_of_lefttree-height _of_rightsubtree)
	int getBalanceFactor(MovieNode* n)
	{
		if (n == NULL)
		{
			return 0;
		}
		return (get_height(n->lch) - get_height(n->rch));
	}

	//Function which right rotates the passed node
	MovieNode* rightrotate(MovieNode* y)
	{
		MovieNode* x = y->lch;
		MovieNode* T2 = x->rch;

		x->rch = y;
		y->lch = T2;
		//Update height after Rotations

		y->height1 = max(get_height(y->rch), get_height(y->lch)) + 1;
		x->height1 = max(get_height(x->rch), get_height(x->lch)) + 1;
		//Returns the new Parent after Rotation
		return x;
	}
	//Function which left rotates the passed node
	MovieNode* leftrotate(MovieNode* x)
	{
		MovieNode* y = x->rch;
		MovieNode* T2 = y->lch;

		y->lch = x;
		x->rch = T2;
		//Update height after rotations
		x->height1 = max(get_height(x->rch), get_height(x->lch)) + 1;
		y->height1 = max(get_height(y->rch), get_height(y->lch)) + 1;

		//Returns the new Parent after Rotation
		return y;
	}

	MovieNode* insert(MovieNode* rn, string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actor_start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
	{
		//Simple BST insertion
		if (rn == NULL)
		{
			return create_node(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);

		}
		if (rn->data.title_id < title_id)
		{
			rn->lch = insert(rn->lch, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		}
		else if (rn->data.title_id > title_id)
		{
			rn->rch = insert(rn->rch, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);

		}
		else//Duplication is not allowed
			return rn;
		//Update heigth After every Insertion
		rn->height1 = 1 + max(get_height(rn->lch), get_height(rn->rch));
		//Checking balance node of current node wheter it becomes unbalakced tree or not
		int bf = getBalanceFactor(rn);
		//if node become unbalanced then there are 4 rotations cases
		//right rotate case
		if (bf > 1 && rn->lch->data.title_id < title_id)
		{
			return rightrotate(rn);
		}
		//left rotate case
		else if (bf<-1 && rn->rch->data.title_id >title_id)
		{
			return leftrotate(rn);
		}
		//left right
		else if (bf > 1 && rn->lch->data.title_id > title_id)
		{
			rn->lch = leftrotate(rn->lch);
			return rightrotate(rn);
		}
		//right left
		else if (bf < -1 && rn->rch->data.title_id < title_id)
		{
			rn->rch = rightrotate(rn->rch);
			return leftrotate(rn);
		}

		return rn;
	}
};
//Class movie_avl for AVL functions implementations
class Movie_AVL
{
public:
	MovieNode* root;
	Movie_AVL()
	{
		root = NULL;
	}
	//Function which returns the address of newly created node
	MovieNode* create_node(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actor, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
	{
		MovieNode* newnode = new MovieNode(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		return newnode;
	}
	//Function which returns max of two values
	int max(int a, int b)
	{
		if (a > b)return a;
		return b;
	}
	//Function which returns the heigth of current node
	int get_height(MovieNode* temp) {
		if (temp == NULL) {
			return 0;
		}
		return temp->height1;
	}
	//Function to return the balance factor of two nodes(hieght_of_lefttree-height _of_rightsubtree)
	int getBalanceFactor(MovieNode* n)
	{
		if (n == NULL)
		{
			return 0;
		}
		return (get_height(n->lch) - get_height(n->rch));
	}

	//Function which right rotates the passed node
	MovieNode* rightrotate(MovieNode* y)
	{
		MovieNode* x = y->lch;
		MovieNode* T2 = x->rch;

		x->rch = y;
		y->lch = T2;

		//Update height after Rotations
		y->height1 = max(get_height(y->rch), get_height(y->lch)) + 1;
		x->height1 = max(get_height(x->rch), get_height(x->lch)) + 1;
		//Returns the new Parent after Rotation
		return x;
	}
	//Function which left rotates the passed node
	MovieNode* leftrotate(MovieNode* x)
	{
		MovieNode* y = x->rch;
		MovieNode* T2 = y->lch;

		y->lch = x;
		x->rch = T2;
		//Update height after rotations
		x->height1 = max(get_height(x->rch), get_height(x->lch)) + 1;
		y->height1 = max(get_height(y->rch), get_height(y->lch)) + 1;

		//Returns the new Parent after Rotation
		return y;
	}

	MovieNode* insert(MovieNode* n, string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actor_start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
	{
		//Simple BST insertion
		if (n == NULL)
		{
			return create_node(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		}
		if (title_id < n->data.title_id)
		{
			n->lch = insert(n->lch, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		}
		else if (title_id > n->data.title_id)
		{
			n->rch = insert(n->rch, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		}
		else//Duplication is not allowed
			return n;
		//Update heigth After every Insertion
		n->height1 = 1 + max(get_height(n->lch), get_height(n->rch));
		//Checking balance node of current node wheter it becomes unbalakced tree or not
		int bf = getBalanceFactor(n);
		//if node become unbalanced then there are 4 rotations cases
		//right rotate case
		if (bf > 1 && title_id < n->lch->data.title_id)
		{
			return rightrotate(n);
		}
		//left rotate case
		else if (bf<-1 && title_id > n->rch->data.title_id)
		{
			return leftrotate(n);
		}
		//left right
		else if (bf > 1 && title_id > n->lch->data.title_id)
		{
			n->lch = leftrotate(n->lch);
			return rightrotate(n);
		}
		//right left
		else if (bf < -1 && title_id < n->rch->data.title_id)
		{
			n->rch = rightrotate(n->rch);
			return leftrotate(n);
		}

		return n;
	}

	//void Print_PreOrder(MovieNode* temp) {
	//	if (temp == NULL) {
	//		//Base Case
	//		return;
	//	}
	//	//Go to the left child recursively
	//	Print_PreOrder(temp->lch);
	//	//print node
	//	cout << temp->data.genre << endl;
	//	//Then go to the right child recursively
	//	Print_PreOrder(temp->rch);
	//}
};

//Hash Class to implement hash
class movie_hash_year
{
	//public data members
public:
	//initializing arr of size ARR_SIZE to NUL
	MovieNode* arr_of_keys[ARR_SIZE] = { NULL };
	//FUnction to find hash_value
	int find_hash_value(string);
	//Function to input_value_in_hash
	void input_value_in_hash(int, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string);
};
//global object of movie_avl_year to use its functions..
movie_avl_year mavl;
int movie_hash_year::find_hash_value(string year)
{
	//Finding hash index index and returning it
	int temp;
	stringstream geek(year);
	geek >> temp;
	return temp % 23;
}
void movie_hash_year::input_value_in_hash(int index, string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actor_start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
{
	//Calling avl  insert function which returns its root and stores it in index of Hash_table
	arr_of_keys[index] = mavl.insert(arr_of_keys[index], title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
}


//Class movie_avl_genre to implement avl function based on the value of genre
class movie_avl_genre
{
	//Public member functions
public:
	//Function which returns the address of newly created node
	MovieNode* create_node(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actor_Start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
	{
		MovieNode* newnode = new MovieNode(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_Start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		return newnode;
	}
	//Function which returns max of two values
	int max(int a, int b)
	{
		if (a > b)return a;
		return b;
	}
	//Function which returns the heigth of current node
	int get_height(MovieNode* temp) {
		if (temp == NULL) {
			return 0;
		}
		return temp->height1;
	}
	//Function to return the balance factor of two nodes(hieght_of_lefttree-height _of_rightsubtree)
	int getBalanceFactor(MovieNode* n)
	{
		if (n == NULL)
		{
			return 0;
		}
		return (get_height(n->lch) - get_height(n->rch));
	}
	//Function which right rotates the passed node
	MovieNode* rightrotate(MovieNode* y)
	{
		MovieNode* x = y->lch;
		MovieNode* T2 = x->rch;

		x->rch = y;
		y->lch = T2;
		//Update height after Rotations
		y->height1 = max(get_height(y->rch), get_height(y->lch)) + 1;
		x->height1 = max(get_height(x->rch), get_height(x->lch)) + 1;
		//Returns the new Parent after Rotation
		return x;
	}
	//Function which left rotates the passed node
	MovieNode* leftrotate(MovieNode* x)
	{
		MovieNode* y = x->rch;
		MovieNode* T2 = y->lch;

		y->lch = x;
		x->rch = T2;

		//Update height after rotations
		x->height1 = max(get_height(x->rch), get_height(x->lch)) + 1;
		y->height1 = max(get_height(y->rch), get_height(y->lch)) + 1;

		//Returns the new Parent after Rotation
		return y;
	}
	//Function to insert values on AVL tree
	MovieNode* insert(MovieNode* rn, string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actor_start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
	{
		//Simple BST insertion
		if (rn == NULL)
		{
			return create_node(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);

		}
		if (rn->data.title_id < title_id)
		{
			rn->lch = insert(rn->lch, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		}
		else if (rn->data.title_id > title_id)
		{
			rn->rch = insert(rn->rch, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);

		}
		else//Duplication is not allowed
			return rn;
		//Update heigth After every Insertion
		rn->height1 = 1 + max(get_height(rn->lch), get_height(rn->rch));
		//Checking balance node of current node wheter it becomes unbalakced tree or not
		int bf = getBalanceFactor(rn);
		//if node become unbalanced then there are 4 rotations cases
		//right rotate case
		if (bf > 1 && rn->lch->data.title_id < title_id)
		{
			return rightrotate(rn);
		}
		//left rotate case
		else if (bf<-1 && rn->rch->data.title_id > title_id)
		{
			return leftrotate(rn);
		}
		//left right
		else if (bf > 1 && rn->lch->data.title_id > title_id)
		{
			rn->lch = leftrotate(rn->lch);
			return rightrotate(rn);
		}
		//right left
		else if (bf < -1 && rn->rch->data.title_id < title_id)
		{
			rn->rch = rightrotate(rn->rch);
			return leftrotate(rn);
		}

		return rn;
	}
};


//CLass to implement hash table 
class movie_hash_genre
{
public:
	//initiallizing array of size ARR_SIZE to NULL
	MovieNode* arr_of_keys[ARR_SIZE] = { NULL };
	// function to return index 
	int find_hash_value(string);
	//function to input address of avl into hash through chaining
	void input_value_in_hash(int, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string);
};
//global object of class movie_avl_genre to use its functions
movie_avl_genre mavl1;

int movie_hash_genre::find_hash_value(string genre)
{
	int sum = 0;
	for (int i = 0; i < genre.length(); i++) {
		sum += (genre[i] * (int)pow(PRIME_CONST, i)) % ARR_SIZE;
	}
	return sum % ARR_SIZE;
}

void movie_hash_genre::input_value_in_hash(int index, string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actor_start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
{
	//calling  avl of class genre which retruns the root of avl and its inserted to arr at an index
	arr_of_keys[index] = mavl1.insert(arr_of_keys[index], title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
}

//Function to store data read ffrom Rating.csv
class Ratings_data
{
public:
	//public data members
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
	MovieNode* movie_ptr;
};
//Class use to store data into the data fields of rating which also stores the building varialbles of avl tree
class RatingsNode {
public:
	RatingsNode(string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, MovieNode*);
	Ratings_data data;
	RatingsNode* lchild;
	RatingsNode* rchild;
	int height1;
};
//Paramerterized constructor which passes values to Data class and stores in the varaible for a specific node
RatingsNode::RatingsNode(string imdb_title_id, string weighted_average_vote, string  total_votes, string mean_vote, string median_vote, string votes_10, string votes_9, string votes_8, string votes_7, string votes_6, string votes_5, string votes_4, string votes_3, string votes_2, string votes_1, string allgenders_0age_avg_vote, string allgenders_0age_votes, string allgenders_18age_avg_vote, string allgenders_18age_votes, string allgenders_30age_avg_vote, string allgenders_30age_votes, string allgenders_45age_avg_vote, string allgenders_45age_votes, string males_allages_avg_vote, string males_allages_votes, string males_0age_avg_vote, string males_0age_votes, string males_18age_avg_vote, string males_18age_votes, string males_30age_avg_vote, string males_30age_votes, string males_45age_avg_vote, string males_45age_votes, string females_allages_avg_vote, string females_allages_votes, string females_0age_avg_vote, string females_0age_votes, string females_18age_avg_vote, string females_18age_votes, string females_30age_avg_vote, string females_30age_votes, string females_45age_avg_vote, string females_45age_votes, string top1000_voters_rating, string top1000_voters_votes, string us_voters_rating, string us_voters_votes, string non_us_voters_rating, string non_us_voters_votes, MovieNode* movie_ptr) {
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
	stringstream geek24(males_45age_avg_vote);
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
	data.imdb_title_id = imdb_title_id;
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
	//string pointer of movie node
	data.movie_ptr = movie_ptr;
	lchild = NULL;
	rchild = NULL;
	height1 = 1;
}
//class to implement functions related to Ratin AVL
class Ratings_AVL
{
public:
	//public member function and data membrs
	RatingsNode* root;
	Ratings_AVL()
	{
		root = NULL;
	}
	//Function to create a node
	RatingsNode* create_node(string imdb_title_id, string weighted_average_vote, string  total_votes, string mean_vote, string median_vote, string votes_10, string votes_9, string votes_8, string votes_7, string votes_6, string votes_5, string votes_4, string votes_3, string votes_2, string votes_1, string allgenders_0age_avg_vote, string allgenders_0age_votes, string allgenders_18age_avg_vote, string allgenders_18age_votes, string allgenders_30age_avg_vote, string allgenders_30age_votes, string allgenders_45age_avg_vote, string allgenders_45age_votes, string males_allages_avg_vote, string males_allages_votes, string males_0age_avg_vote, string males_0age_votes, string males_18age_avg_vote, string males_18age_votes, string males_30age_avg_vote, string males_30age_votes, string males_45age_avg_vote, string males_45age_votes, string females_allages_avg_vote, string females_allages_votes, string females_0age_avg_vote, string females_0age_votes, string females_18age_avg_vote, string females_18age_votes, string females_30age_avg_vote, string females_30age_votes, string females_45age_avg_vote, string females_45age_votes, string top1000_voters_rating, string top1000_voters_votes, string us_voters_rating, string us_voters_votes, string non_us_voters_rating, string non_us_voters_votes, MovieNode* movie_ptr)
	{
		RatingsNode* newnode = new RatingsNode(imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes, movie_ptr);
		return newnode;
	}
	//Function to returna max of two values
	int max(int a, int b)
	{
		if (a > b)return a;
		return b;
	}
	//function whihch returns hieght of current node
	int get_height(RatingsNode* temp) {
		if (temp == NULL) {
			return 0;
		}
		return temp->height1;
	}
	//function which returns the balance factor of the current node
	int getBalanceFactor(RatingsNode* n)
	{
		if (n == NULL)
		{
			return 0;
		}
		return (get_height(n->lchild) - get_height(n->rchild));
	}
	//Function to Right Rotate the current node
	RatingsNode* rightrotate(RatingsNode* y)
	{
		RatingsNode* x = y->lchild;
		RatingsNode* T2 = x->rchild;

		x->rchild = y;
		y->lchild = T2;

		y->height1 = max(get_height(y->rchild), get_height(y->lchild)) + 1;
		x->height1 = max(get_height(x->rchild), get_height(x->lchild)) + 1;
		return x;
	}
	//Function to left rotate the current node
	RatingsNode* leftrotate(RatingsNode* x)
	{
		RatingsNode* y = x->rchild;
		RatingsNode* T2 = y->lchild;

		y->lchild = x;
		x->rchild = T2;

		x->height1 = max(get_height(x->rchild), get_height(x->lchild)) + 1;
		y->height1 = max(get_height(y->rchild), get_height(y->lchild)) + 1;

		return y;
	}
	//Function to insert node in the AVL tree
	RatingsNode* insert(RatingsNode* n, string imdb_title_id, string weighted_average_vote, string  total_votes, string mean_vote, string median_vote, string votes_10, string votes_9, string votes_8, string votes_7, string votes_6, string votes_5, string votes_4, string votes_3, string votes_2, string votes_1, string allgenders_0age_avg_vote, string allgenders_0age_votes, string allgenders_18age_avg_vote, string allgenders_18age_votes, string allgenders_30age_avg_vote, string allgenders_30age_votes, string allgenders_45age_avg_vote, string allgenders_45age_votes, string males_allages_avg_vote, string males_allages_votes, string males_0age_avg_vote, string males_0age_votes, string males_18age_avg_vote, string males_18age_votes, string males_30age_avg_vote, string males_30age_votes, string males_45age_avg_vote, string males_45age_votes, string females_allages_avg_vote, string females_allages_votes, string females_0age_avg_vote, string females_0age_votes, string females_18age_avg_vote, string females_18age_votes, string females_30age_avg_vote, string females_30age_votes, string females_45age_avg_vote, string females_45age_votes, string top1000_voters_rating, string top1000_voters_votes, string us_voters_rating, string us_voters_votes, string non_us_voters_rating, string non_us_voters_votes, MovieNode* movie_ptr)
	{
		//simple BST insertion procedure
		if (n == NULL)
		{

			return create_node(imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes, movie_ptr);
		}
		if (imdb_title_id < n->data.imdb_title_id)
		{
			n->lchild = insert(n->lchild, imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes, movie_ptr);
		}
		else if (imdb_title_id > n->data.imdb_title_id)
		{
			n->rchild = insert(n->rchild, imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes, movie_ptr);
		}
		else//Duplication is not allowed
			return n;

		//Update heigth After every Insertion
		n->height1 = 1 + max(get_height(n->lchild), get_height(n->rchild));
		//Checking balance node of current node wheter it becomes unbalakced tree or not
		int bf = getBalanceFactor(n);
		//if node become unbalanced then there are 4 rotations cases
		//right rotate case
		if (bf > 1 && imdb_title_id < n->lchild->data.imdb_title_id)
		{
			return rightrotate(n);
		}
		//left rotate case
		else if (bf<-1 && imdb_title_id > n->rchild->data.imdb_title_id)
		{
			return leftrotate(n);
		}
		//left right
		else if (bf > 1 && imdb_title_id > n->lchild->data.imdb_title_id)
		{
			n->lchild = leftrotate(n->lchild);
			return rightrotate(n);
		}
		//right left
		else if (bf < -1 && imdb_title_id < n->rchild->data.imdb_title_id)
		{
			n->rchild = rightrotate(n->rchild);
			return leftrotate(n);
		}
		return n;
	}
};
//Class to implement Hash Table for Ratings file
class ratings_hash
{
	//public data members and member function
public:
	RatingsNode* arr_of_keys[ARR_SIZE] = { NULL };
	//Function to find hash index
	int find_hash_value(string);
	//TO input avl in index position thorugh chainin
	void input_value_in_hash(int, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, MovieNode*);
};
//Global object of Ratings_AVL to use its functions
Ratings_AVL ravl1;

int ratings_hash::find_hash_value(string ratings)
{
	double temp;
	stringstream geek(ratings);
	geek >> temp;
	if (temp > 0 && temp <= 1)
	{
		return 0;
	}
	else if (temp > 1 && temp <= 2)
	{
		return 1;
	}
	else if (temp > 2 && temp <= 3)
	{
		return 2;
	}
	else if (temp > 3 && temp <= 4)
	{

		return 3;
	}
	else if (temp > 4 && temp <= 5)
	{
		return 4;

	}
	else if (temp > 5 && temp <= 6)
	{
		return 5;
	}
	else if (temp > 6 && temp <= 7)
	{
		return 6;

	}
	else if (temp > 7 && temp <= 8)
	{
		return 7;

	}
	else if (temp > 8 && temp <= 9)
	{
		return 8;

	}
	else if (temp > 9 && temp <= 10)
	{
		return 9;
	}
}


void ratings_hash::input_value_in_hash(int index, string imdb_title_id, string weighted_average_vote, string  total_votes, string mean_vote, string median_vote, string votes_10, string votes_9, string votes_8, string votes_7, string votes_6, string votes_5, string votes_4, string votes_3, string votes_2, string votes_1, string allgenders_0age_avg_vote, string allgenders_0age_votes, string allgenders_18age_avg_vote, string allgenders_18age_votes, string allgenders_30age_avg_vote, string allgenders_30age_votes, string allgenders_45age_avg_vote, string allgenders_45age_votes, string males_allages_avg_vote, string males_allages_votes, string males_0age_avg_vote, string males_0age_votes, string males_18age_avg_vote, string males_18age_votes, string males_30age_avg_vote, string males_30age_votes, string males_45age_avg_vote, string males_45age_votes, string females_allages_avg_vote, string females_allages_votes, string females_0age_avg_vote, string females_0age_votes, string females_18age_avg_vote, string females_18age_votes, string females_30age_avg_vote, string females_30age_votes, string females_45age_avg_vote, string females_45age_votes, string top1000_voters_rating, string top1000_voters_votes, string us_voters_rating, string us_voters_votes, string non_us_voters_rating, string non_us_voters_votes, MovieNode* movie_ptr)
{
	arr_of_keys[index] = ravl1.insert(arr_of_keys[index], imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes, movie_ptr);
}


//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//Function to READ two files
//Movies.csv and Ratings.csv
//Created an AVL tree just for Movie file and 3 Hash tables 2 for Movies bases of different values and 1 avl for rating files 
void read(Movie_AVL* ml, movie_hash_year* mhash, movie_hash_genre* mhash1, ratings_hash* rhash) {


	//---------Movie  Storage------------
	int count = 0;
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
				getline(File, description, ',');
				getline(File, age_vote, ',');
				getline(File, votes, ',');
				getline(File, budget, ',');
				getline(File, usa_gross_income, ',');
				getline(File, meta_score, ',');
				getline(File, reviews_from_user, ',');
				getline(File, reviews_from_critics);
				//Creating Hash Tables based on the value of year
				mhash->input_value_in_hash(mhash->find_hash_value(year), title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actors, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
				//Creating Hash based on the value of genre
				//1 column in csv file of movies contains many genre separated by '-' so delimiting it and making hash values on there individual basis
				string s = genre;
				string delimiter = "-";
				size_t pos = 0;
				string token;
				bool flag = false;
				int index;
				while ((pos = s.find(delimiter)) != string::npos) {
					token = s.substr(0, pos);
					index = mhash1->find_hash_value(token);
					mhash1->input_value_in_hash(index, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actors, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
					s.erase(0, pos + delimiter.length());
				}
				index = mhash1->find_hash_value(s);
				mhash1->input_value_in_hash(index, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actors, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
				ml->root = ml->insert(ml->root, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actors, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
			}
		}
	}
	else {
		cout << "Give Error\n" << endl;
	}

	//Now Reading file Ratings
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
				getline(File1, allgenders_0age_avg_vote, ',');
				getline(File1, allgenders_0age_votes, ',');
				getline(File1, allgenders_18age_avg_vote, ',');
				getline(File1, allgenders_18age_votes, ',');
				getline(File1, allgenders_30age_avg_vote, ',');
				getline(File1, allgenders_30age_votes, ',');
				getline(File1, allgenders_45age_avg_vote, ',');
				getline(File1, allgenders_45age_votes, ',');
				getline(File1, males_0age_avg_vote, ',');
				getline(File1, males_0age_votes, ',');
				getline(File1, males_18age_avg_vote, ',');
				getline(File1, males_18age_votes, ',');
				getline(File1, males_30age_avg_vote, ',');
				getline(File1, males_30age_votes, ',');
				getline(File1, males_45age_avg_vote, ',');
				getline(File1, males_45age_votes, ',');
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
				//Creating Hash Table on the basis of Rating(wieghted average votes)
				MovieNode* traverser = ml->root;
				//Traversing through whole movie avl and finsing the AVL node of same imdb titles ad in rating
				while (traverser != NULL && traverser->data.title_id != imdb_title_id) {
					if (traverser->data.title_id > imdb_title_id) {
						traverser = traverser->lch;
					}
					else {
						traverser = traverser->rch;
					}
				}
				//checking if the upper while loop breaks on equality
				if (traverser != NULL) {
					//creating hash table on the values of weighted average vote and aslo the Address of Movie node of same imdb titles....
					rhash->input_value_in_hash(rhash->find_hash_value(weighted_average_vote), imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes, traverser);
				}
				//	rl->insert(imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes);

			}
		}
	}
	else {
		cout << "Give Error1\n";
	}
}

//-----------------------------------------------------------
//-----------------------------------------------------------
//Function to Travers movies
void traverse_movies(MovieNode* start)
{
	if (start == NULL) {
		return;
	}
	cout << start->data.title << endl;
	traverse_movies(start->lch);
	traverse_movies(start->rch);
}
//Function check specific genre
void print_specific_genre(movie_hash_genre mh1, string genre)
{
	cout << "All " << genre << " movies are :\n";
	int index = mh1.find_hash_value(genre);
	traverse_movies(mh1.arr_of_keys[index]);
}

//-----------------------------------------------------------
//-----------------------------------------------------------
//Function to traverse moveis based on year
void traverse_movies_per_year(MovieNode* start, int year)
{
	if (start == NULL) {
		return;
	}
	else {
		if(year==start->data.year)
			cout << start->data.original_title << endl;
		traverse_movies_per_year(start->lch, year);
		traverse_movies_per_year(start->rch, year);
	}
}

//Function to print al movies of a certain year
void print_selected_year(movie_hash_year mh, string year)
{
	cout << "All movies in year " << year << " are :\n";
	int index = mh.find_hash_value(year);
	int temp;
	stringstream geek(year);
	geek >> temp;
	traverse_movies_per_year(mh.arr_of_keys[index], temp);
}

//-----------------------------------------------------------
void traverse_movies3(RatingsNode* r)
{
	if (r == NULL)
		return;
	cout << r->data.movie_ptr->data.title << endl;
	traverse_movies3(r->rchild);
	traverse_movies3(r->lchild);
}

void print_in_avgevote(string rating, ratings_hash rhash)
{
	int index = rhash.find_hash_value(rating);
	cout << "All movies in weighted average weight of range " << index + 1 << " and " << index << " are \n";
	traverse_movies3(rhash.arr_of_keys[index]);
}

int main() {
	Movie_AVL ml;
	movie_hash_year mhash;
	movie_hash_genre mhash1;
	ratings_hash rhash1;
	bool menu = true;
	int option;
	string rating = "";
	string genre = "";
	string year = "";
	read(&ml, &mhash, &mhash1, &rhash1);
	cout << "\t\t\t\t\t\t----IMDB----" << endl;
	cout << "\n\t\t\t\t\t     1. Genre Wise Movies" << endl;
	cout << "\n\t\t\t\t\t     2. Rating Search" << endl;
	cout << "\n\t\t\t\t\t     3. Year Wise Movies" << endl;
	cout << "\n\t\t\t\t\t\t  4. Exit" << endl;
	while (menu) {
		cout << "\nEnter Option : ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Enter Genre : ";
			cin >> genre;
			print_specific_genre(mhash1, genre);
			break;
		case 2:
			cout << "Enter Rating : ";
			cin >> rating;
			print_in_avgevote(rating, rhash1);
			break;
		case 3:
			cout << "Enter Year : ";
			cin >> year;
			print_selected_year(mhash, year);
			break;
		default:
			menu = false;
			break;
		}
	}
	return 0;
}