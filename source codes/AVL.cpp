#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

class actor_movie_node;
class movie_actor_node;
//-----------------Names-------------------avl
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
	string date_of_death;
	string place_of_death;
	string reason_of_death;
	string spouses_string;
	int spouses;
	int divorces;
	int spouses_with_children;
	int children;
	actor_movie_node* moviestart;
};

class NameNode
{
public:
	Name_Data data;
	NameNode* lchild;
	NameNode* rchild;
	int height1;
	NameNode(actor_movie_node* moviestart, string name_id, string name, string birth_name, string height, string bio, string birth_details, string date_of_birth, string place_of_birth, string death_details, string date_of_death, string place_of_death, string reason_of_death, string spouses_string, string spouses, string divorces, string spouses_with_children, string children);

};

NameNode::NameNode(actor_movie_node* moviestart, string name_id, string name, string birth_name, string height, string bio, string birth_details, string date_of_birth, string place_of_birth, string death_details, string date_of_death, string place_of_death, string reason_of_death, string spouses_string, string spouses, string divorces, string spouses_with_children, string children)
{
	data.moviestart = moviestart;
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


	lchild = NULL;
	rchild = NULL;
	height1 = 1;
}

class Name_AVL
{
public:
	NameNode* root;
	Name_AVL()
	{
		root = NULL;
	}
	NameNode* create_node(string name_id, string name, string birth_name, string height, string bio, string birth_details, string date_of_birth, string place_of_birth, string death_details, string date_of_death, string place_of_death, string reason_of_death, string spouses_string, string spouses, string divorces, string spouses_with_children, string children)
	{
		NameNode* newnode = new NameNode(NULL, name_id, name, birth_name, height, bio, birth_details, date_of_birth, place_of_birth, death_details, date_of_death, place_of_death, reason_of_death, spouses_string, spouses, divorces, spouses_with_children, children);
		return newnode;
	}
	int max(int a, int b)
	{
		if (a > b)return a;
		return b;
	}
	int get_height(NameNode* temp) {
		if (temp == NULL) {
			return 0;
		}
		return temp->height1;
	}
	int getBalanceFactor(NameNode* n)
	{
		if (n == NULL)
		{
			return 0;
		}
		return (get_height(n->lchild) - get_height(n->rchild));
	}

	NameNode* rightrotate(NameNode* y)
	{
		NameNode* x = y->lchild;
		NameNode* T2 = x->rchild;

		x->rchild = y;
		y->lchild = T2;

		y->height1 = max(get_height(y->rchild), get_height(y->lchild)) + 1;
		x->height1 = max(get_height(x->rchild), get_height(x->lchild)) + 1;
		return x;
	}
	NameNode* leftrotate(NameNode* x)
	{
		NameNode* y = x->rchild;
		NameNode* T2 = y->lchild;

		y->lchild = x;
		x->rchild = T2;

		x->height1 = max(get_height(x->rchild), get_height(x->lchild)) + 1;
		y->height1 = max(get_height(y->rchild), get_height(y->lchild)) + 1;

		return y;
	}

	NameNode* insert(NameNode* n, string name_id, string name, string birth_name, string height, string bio, string birth_details, string date_of_birth, string place_of_birth, string death_details, string date_of_death, string place_of_death, string reason_of_death, string spouses_string, string spouses, string divorces, string spouses_with_children, string children)
	{
		if (n == NULL)
		{
			return create_node(name_id, name, birth_name, height, bio, birth_details, date_of_birth, place_of_birth, death_details, date_of_death, place_of_death, reason_of_death, spouses_string, spouses, divorces, spouses_with_children, children);
		}
		if (name_id < n->data.name_id)
		{
			n->lchild = insert(n->lchild, name_id, name, birth_name, height, bio, birth_details, date_of_birth, place_of_birth, death_details, date_of_death, place_of_death, reason_of_death, spouses_string, spouses, divorces, spouses_with_children, children);
		}
		else if (name_id > n->data.name_id)
		{
			n->rchild = insert(n->rchild, name_id, name, birth_name, height, bio, birth_details, date_of_birth, place_of_birth, death_details, date_of_death, place_of_death, reason_of_death, spouses_string, spouses, divorces, spouses_with_children, children);
		}
		else
			return n;
		n->height1 = 1 + max(get_height(n->lchild), get_height(n->rchild));
		int bf = getBalanceFactor(n);
		if (bf > 1 && name_id < n->lchild->data.name_id)
		{
			return rightrotate(n);
		}
		else if (bf<-1 && name_id > n->rchild->data.name_id)
		{
			return leftrotate(n);
		}
		else if (bf > 1 && name_id > n->lchild->data.name_id)
		{
			n->lchild = leftrotate(n->lchild);
			return rightrotate(n);
		}
		else if (bf < -1 && name_id < n->rchild->data.name_id)
		{
			n->rchild = rightrotate(n->rchild);
			return leftrotate(n);
		}

		return n;
	}

	void Print_PreOrder(NameNode* temp) {
		if (temp == NULL) {
			//Base Case
			return;
		}
		//Go to the left child recursively
		Print_PreOrder(temp->lchild);
		//print node
		cout << temp->data.spouses << endl;
		//Then go to the right child recursively
		Print_PreOrder(temp->rchild);
	}
};
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
	movie_actor_node* actor_Start;
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

class MovieNode {
public:
	MovieNode(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, movie_actor_node* actor_start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics);
	MovieData data;
	MovieNode* lchild;
	MovieNode* rchild;
	int height1;
};

MovieNode::MovieNode(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, movie_actor_node* actor_start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics) {
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

	lchild = NULL;
	rchild = NULL;
	height1 = 1;
}
class Movie_AVL
{
public:
	MovieNode* root;
	Movie_AVL()
	{
		root = NULL;
	}
	MovieNode* create_node(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, movie_actor_node* actor_Start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
	{
		MovieNode* newnode = new MovieNode(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_Start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		return newnode;
	}
	int max(int a, int b)
	{
		if (a > b)return a;
		return b;
	}
	int get_height(MovieNode* temp) {
		if (temp == NULL) {
			return 0;
		}
		return temp->height1;
	}
	int getBalanceFactor(MovieNode* n)
	{
		if (n == NULL)
		{
			return 0;
		}
		return (get_height(n->lchild) - get_height(n->rchild));
	}

	MovieNode* rightrotate(MovieNode* y)
	{
		MovieNode* x = y->lchild;
		MovieNode* T2 = x->rchild;

		x->rchild = y;
		y->lchild = T2;

		y->height1 = max(get_height(y->rchild), get_height(y->lchild)) + 1;
		x->height1 = max(get_height(x->rchild), get_height(x->lchild)) + 1;
		return x;
	}
	MovieNode* leftrotate(MovieNode* x)
	{
		MovieNode* y = x->rchild;
		MovieNode* T2 = y->lchild;

		y->lchild = x;
		x->rchild = T2;

		x->height1 = max(get_height(x->rchild), get_height(x->lchild)) + 1;
		y->height1 = max(get_height(y->rchild), get_height(y->lchild)) + 1;

		return y;
	}

	MovieNode* insert(MovieNode* n, string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, movie_actor_node* actor_start, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
	{
		if (n == NULL)
		{
			return create_node(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		}
		if (title_id < n->data.title_id)
		{
			n->lchild = insert(n->lchild, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		}
		else if (title_id > n->data.title_id)
		{
			n->rchild = insert(n->rchild, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		}
		else
			return n;
		n->height1 = 1 + max(get_height(n->lchild), get_height(n->rchild));
		int bf = getBalanceFactor(n);
		if (bf > 1 && title_id < n->lchild->data.title_id)
		{
			return rightrotate(n);
		}
		else if (bf<-1 && title_id > n->rchild->data.title_id)
		{
			return leftrotate(n);
		}
		else if (bf > 1 && title_id > n->lchild->data.title_id)
		{
			n->lchild = leftrotate(n->lchild);
			return rightrotate(n);
		}
		else if (bf < -1 && title_id < n->rchild->data.title_id)
		{
			n->rchild = rightrotate(n->rchild);
			return leftrotate(n);
		}

		return n;
	}

	void Print_PreOrder(MovieNode* temp) {
		if (temp == NULL) {
			//Base Case
			return;
		}
		//Go to the left child recursively
		Print_PreOrder(temp->lchild);
		//print node
		cout << temp->data.genre << endl;
		//Then go to the right child recursively
		Print_PreOrder(temp->rchild);
	}
};


//-----------------ratings-------------------------

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
	RatingsNode* lchild;
	RatingsNode* rchild;
	int height1;
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


	lchild = NULL;
	rchild = NULL;
	height1 = 1;
}

class Ratings_AVL
{
public:
	RatingsNode* root;
	Ratings_AVL()
	{
		root = NULL;
	}
	RatingsNode* create_node(string imdb_title_id, string weighted_average_vote, string  total_votes, string mean_vote, string median_vote, string votes_10, string votes_9, string votes_8, string votes_7, string votes_6, string votes_5, string votes_4, string votes_3, string votes_2, string votes_1, string allgenders_0age_avg_vote, string allgenders_0age_votes, string allgenders_18age_avg_vote, string allgenders_18age_votes, string allgenders_30age_avg_vote, string allgenders_30age_votes, string allgenders_45age_avg_vote, string allgenders_45age_votes, string males_allages_avg_vote, string males_allages_votes, string males_0age_avg_vote, string males_0age_votes, string males_18age_avg_vote, string males_18age_votes, string males_30age_avg_vote, string males_30age_votes, string males_45age_avg_vote, string males_45age_votes, string females_allages_avg_vote, string females_allages_votes, string females_0age_avg_vote, string females_0age_votes, string females_18age_avg_vote, string females_18age_votes, string females_30age_avg_vote, string females_30age_votes, string females_45age_avg_vote, string females_45age_votes, string top1000_voters_rating, string top1000_voters_votes, string us_voters_rating, string us_voters_votes, string non_us_voters_rating, string non_us_voters_votes)
	{
		RatingsNode* newnode = new RatingsNode(imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes);
		return newnode;
	}
	int max(int a, int b)
	{
		if (a > b)return a;
		return b;
	}
	int get_height(RatingsNode* temp) {
		if (temp == NULL) {
			return 0;
		}
		return temp->height1;
	}
	int getBalanceFactor(RatingsNode* n)
	{
		if (n == NULL)
		{
			return 0;
		}
		return (get_height(n->lchild) - get_height(n->rchild));
	}

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

	RatingsNode* insert(RatingsNode* n, string imdb_title_id, string weighted_average_vote, string  total_votes, string mean_vote, string median_vote, string votes_10, string votes_9, string votes_8, string votes_7, string votes_6, string votes_5, string votes_4, string votes_3, string votes_2, string votes_1, string allgenders_0age_avg_vote, string allgenders_0age_votes, string allgenders_18age_avg_vote, string allgenders_18age_votes, string allgenders_30age_avg_vote, string allgenders_30age_votes, string allgenders_45age_avg_vote, string allgenders_45age_votes, string males_allages_avg_vote, string males_allages_votes, string males_0age_avg_vote, string males_0age_votes, string males_18age_avg_vote, string males_18age_votes, string males_30age_avg_vote, string males_30age_votes, string males_45age_avg_vote, string males_45age_votes, string females_allages_avg_vote, string females_allages_votes, string females_0age_avg_vote, string females_0age_votes, string females_18age_avg_vote, string females_18age_votes, string females_30age_avg_vote, string females_30age_votes, string females_45age_avg_vote, string females_45age_votes, string top1000_voters_rating, string top1000_voters_votes, string us_voters_rating, string us_voters_votes, string non_us_voters_rating, string non_us_voters_votes)
	{
		if (n == NULL)
		{
			return create_node(imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes);
		}
		if (imdb_title_id < n->data.imdb_title_id)
		{
			n->lchild = insert(n->lchild, imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes);
		}
		else if (imdb_title_id > n->data.imdb_title_id)
		{
			n->rchild = insert(n->rchild, imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes);
		}
		else
			return n;
		n->height1 = 1 + max(get_height(n->lchild), get_height(n->rchild));
		int bf = getBalanceFactor(n);
		if (bf > 1 && imdb_title_id < n->lchild->data.imdb_title_id)
		{
			return rightrotate(n);
		}
		else if (bf<-1 && imdb_title_id > n->rchild->data.imdb_title_id)
		{
			return leftrotate(n);
		}
		else if (bf > 1 && imdb_title_id > n->lchild->data.imdb_title_id)
		{
			n->lchild = leftrotate(n->lchild);
			return rightrotate(n);
		}
		else if (bf < -1 && imdb_title_id < n->rchild->data.imdb_title_id)
		{
			n->rchild = rightrotate(n->rchild);
			return leftrotate(n);
		}
		return n;
	}

	void Print_PreOrder(RatingsNode* temp) {
		if (temp == NULL) {
			//Base Case
			return;
		}
		//print node
		cout << temp->data.imdb_title_id << endl;
		//Go to the left child recursively
		Print_PreOrder(temp->lchild);
		//Then go to the right child recursively
		Print_PreOrder(temp->rchild);
	}
};

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
	title_principles_Node* lchild;
	title_principles_Node* rchild;
	int height1;
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
	lchild = NULL;
	rchild = NULL;
	height1 = 1;
}

class title_principles_AVL
{
public:
	title_principles_Node* root;
	title_principles_AVL()
	{
		root = NULL;
	}
	title_principles_Node* create_node(string imdb_title_id, string order, string imdb_name_id, string category, string job, string characters)
	{
		title_principles_Node* newnode = new title_principles_Node(imdb_title_id, order, imdb_name_id, category, job, characters);
		return newnode;
	}
	int max(int a, int b)
	{
		if (a > b)return a;
		return b;
	}
	int get_height(title_principles_Node* temp) {
		if (temp == NULL) {
			return 0;
		}
		return temp->height1;
	}
	int getBalanceFactor(title_principles_Node* n)
	{
		if (n == NULL)
		{
			return 0;
		}
		return (get_height(n->lchild) - get_height(n->rchild));
	}

	title_principles_Node* rightrotate(title_principles_Node* y)
	{
		title_principles_Node* x = y->lchild;
		title_principles_Node* T2 = x->rchild;

		x->rchild = y;
		y->lchild = T2;

		y->height1 = max(get_height(y->rchild), get_height(y->lchild)) + 1;
		x->height1 = max(get_height(x->rchild), get_height(x->lchild)) + 1;
		return x;
	}
	title_principles_Node* leftrotate(title_principles_Node* x)
	{
		title_principles_Node* y = x->rchild;
		title_principles_Node* T2 = y->lchild;

		y->lchild = x;
		x->rchild = T2;

		x->height1 = max(get_height(x->rchild), get_height(x->lchild)) + 1;
		y->height1 = max(get_height(y->rchild), get_height(y->lchild)) + 1;

		return y;
	}

	title_principles_Node* insert(title_principles_Node* n, string imdb_title_id, string order, string imdb_name_id, string category, string job, string characters)
	{
		if (n == NULL)
		{
			return create_node(imdb_title_id, order, imdb_name_id, category, job, characters);
		}
		if (imdb_name_id < n->data.imdb_name_id)
		{
			n->lchild = insert(n->lchild, imdb_title_id, order, imdb_name_id, category, job, characters);
		}
		else if (imdb_name_id > n->data.imdb_name_id)
		{
			n->rchild = insert(n->rchild, imdb_title_id, order, imdb_name_id, category, job, characters);
		}
		else
			return n;
		n->height1 = 1 + max(get_height(n->lchild), get_height(n->rchild));
		int bf = getBalanceFactor(n);
		if (bf > 1 && imdb_name_id < n->lchild->data.imdb_name_id)
		{
			return rightrotate(n);
		}
		else if (bf<-1 && imdb_name_id > n->rchild->data.imdb_name_id)
		{
			return leftrotate(n);
		}
		else if (bf > 1 && imdb_name_id > n->lchild->data.imdb_name_id)
		{
			n->lchild = leftrotate(n->lchild);
			return rightrotate(n);
		}
		else if (bf < -1 && imdb_title_id < n->rchild->data.imdb_title_id)
		{
			n->rchild = rightrotate(n->rchild);
			return leftrotate(n);
		}

		return n;
	}

	void Print_PreOrder(title_principles_Node* temp) {
		if (temp == NULL) {
			//Base Case
			return;
		}
		//Go to the left child recursively
		Print_PreOrder(temp->lchild);
		//print node
		cout << temp->data.category << endl;
		//Then go to the right child recursively
		Print_PreOrder(temp->rchild);
	}
};

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
class movie_actor_node
{
public:
	NameNode* points_to_actor;
	movie_actor_node* rch;
	movie_actor_node* lch;
	int height;
	string key_tits_id;
	movie_actor_node()
	{
		rch = NULL;
		lch = NULL;
	}
};
class movie_actor_avl
{
public:

	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	int height(movie_actor_node* temp)
	{
		if (temp == NULL)
			return 0;
		return temp->height;
	}

	int calc_balance_spectrum(movie_actor_node* temp)
	{
		return height(temp->rch) - height(temp->lch);
	}

	movie_actor_node* create_newnode(string val)
	{
		movie_actor_node* newnode = new movie_actor_node();//try not passing value or building constructor for newnode

		newnode->lch = NULL;
		newnode->rch = NULL;
		newnode->height = 1;
		newnode->key_tits_id = val; /*cout << newnode->key_tits_id;*/
		return newnode;
	}

	movie_actor_node* left_rotation(movie_actor_node* temp)
	{
		movie_actor_node* y = temp;
		movie_actor_node* x = temp->rch;

		y->rch = x->lch;
		x->lch = y;

		y->height = max(height(y->rch), height(y->lch)) + 1;
		x->height = max(height(x->rch), height(x->lch)) + 1;
		return x;
	}
	movie_actor_node* right_rotation(movie_actor_node* temp)
	{
		movie_actor_node* y = temp;
		movie_actor_node* x = temp->lch;

		y->lch = x->rch;
		x->rch = y;
		y->height = max(height(y->rch), height(y->lch)) + 1;
		x->height = max(height(x->rch), height(x->lch)) + 1;
		return x;
	}
	movie_actor_node* insertnode(string val, movie_actor_node* temp)
	{

		if (temp == NULL) {
			/*cout << "1\n";*/
			return create_newnode(val);
		}

		if (val > temp->key_tits_id)
			temp->rch = insertnode(val, temp->rch);
		else if (val < temp->key_tits_id)
			temp->lch = insertnode(val, temp->lch);
		else {
			cout << "duplicate value input is not allowed\n";
			return temp;
		}
		temp->height = max(height(temp->rch), height(temp->lch)) + 1;
		int bs = calc_balance_spectrum(temp);
		if (bs > 1 && val > temp->rch->key_tits_id)
		{
			return left_rotation(temp);
		}
		if (bs > 1 && val < temp->rch->key_tits_id)
		{
			temp->rch = right_rotation(temp->rch);
			return left_rotation(temp);
		}
		if (bs < -1 && val < temp->lch->key_tits_id)
		{
			return right_rotation(temp);
		}
		if (bs < -1 && val < temp->lch->key_tits_id)
		{
			temp->lch = left_rotation(temp->lch);
			return right_rotation(temp);
		}
		return temp;

	}

};

void find_actor_in_ma_avl(movie_actor_node* root, NameNode* name)
{
	if (root == NULL)
		return;
	if (root->key_tits_id == name->data.name)
		root->points_to_actor = name;
	find_actor_in_ma_avl(root->rch, name);
	find_actor_in_ma_avl(root->lch, name);
}

bool find_actor_in_names(NameNode* traverser, movie_actor_node* mavl, string token)
{
	if (traverser == NULL) {
		//cout << "actor notfound\n";
		return false;
	}

	find_actor_in_names(traverser->rchild, mavl, token);
	find_actor_in_names(traverser->lchild, mavl, token);
	if (traverser->data.name == token)
	{
		find_actor_in_ma_avl(mavl, traverser);
		return true;
	}
}

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------

class actor_movie_node
{
public:
	MovieNode* points_to_movie;
	actor_movie_node* rch;
	actor_movie_node* lch;
	int height;
	string key_name_id;
};

class actor_movie_avl
{
public:
	actor_movie_node* root = NULL;
	actor_movie_node* loc = NULL;
	actor_movie_node* ploc = NULL;
	//actor_movie_node* insertnode(string, actor_movie_node*);
	//void printtree(actor_movie_node*);


	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	int height(actor_movie_node* temp)
	{
		if (temp == NULL)
			return 0;
		return temp->height;
	}

	int calc_balance_spectrum(actor_movie_node* temp)
	{
		return height(temp->rch) - height(temp->lch);
	}

	actor_movie_node* create_newnode(string val, MovieNode* temp)
	{
		actor_movie_node* newnode = new actor_movie_node;
		newnode->lch = NULL;
		newnode->rch = NULL;
		newnode->height = 1;
		newnode->points_to_movie = temp;
		newnode->key_name_id = val;
		return newnode;
	}
	int count = 0;//test
	actor_movie_node* left_rotation(actor_movie_node* temp)
	{
		actor_movie_node* y = temp;
		actor_movie_node* x = temp->rch;

		y->rch = x->lch;
		x->lch = y;

		y->height = max(height(y->rch), height(y->lch)) + 1;
		x->height = max(height(x->rch), height(x->lch)) + 1;
		return x;
	}
	actor_movie_node* right_rotation(actor_movie_node* temp)
	{
		actor_movie_node* y = temp;
		actor_movie_node* x = temp->lch;

		y->lch = x->rch;
		x->rch = y;
		y->height = max(height(y->rch), height(y->lch)) + 1;
		x->height = max(height(x->rch), height(x->lch)) + 1;
		return x;
	}
	actor_movie_node* insertnode(string val, actor_movie_node* temp, MovieNode* movie)
	{

		if (temp == NULL || temp->key_name_id == val) {
			//cout << count++;//test
			/*cout << "inserted\n";*/
			return create_newnode(val, movie);
		}

		if (val > temp->key_name_id)
			temp->rch = insertnode(val, temp->rch, movie);
		else if (val < temp->key_name_id)
			temp->lch = insertnode(val, temp->lch, movie);
		//else {
		//	
		//	cout << "duplicate value input is not allowed in actor_movie avl\n";
		//	return temp;
		//}
		temp->height = max(height(temp->rch), height(temp->lch)) + 1;
		int bs = calc_balance_spectrum(temp);
		if (bs > 1 && val > temp->rch->key_name_id)
		{
			return left_rotation(temp);
		}
		if (bs > 1 && val < temp->rch->key_name_id)
		{
			temp->rch = right_rotation(temp->rch);
			return left_rotation(temp);
		}
		if (bs < -1 && val < temp->lch->key_name_id)
		{
			return right_rotation(temp);
		}
		if (bs < -1 && val < temp->lch->key_name_id)
		{
			temp->lch = left_rotation(temp->lch);
			return right_rotation(temp);
		}
		return temp;

	}
};

void read(Movie_AVL* ml, Ratings_AVL* rl, title_principles_AVL* t1, Name_AVL* t2) {




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
	actor_movie_node* points_to_movie;
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
				t2->root = t2->insert(t2->root, name_id, name, birth_name, height, bio, birth_details, date_of_birth, place_of_birth, death_details, date_of_death, place_of_death, reason_of_death, spouses_string, spouses, divorces, spouses_with_children, children);
			}
		}
	}
	else {
		cout << "Give Error3";
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
	movie_actor_avl m_a_avl;

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


				movie_actor_node* actor_start = NULL;
				string s = actors;
				string delimiter = "-";
				size_t pos = 0;
				string token;
				NameNode* traverser = t2->root;
				bool flag = false;

				while ((pos = s.find(delimiter)) != string::npos) {
					token = s.substr(0, pos);
					traverser = t2->root;
					actor_start = m_a_avl.insertnode(token, actor_start);
					/*cout << "che\n";*/
					flag = find_actor_in_names(traverser, actor_start, token);
					// if (flag == false)
					// 	cout << "actor not found in names file\n\n";

					s.erase(0, pos + delimiter.length());
				}
				actor_start = m_a_avl.insertnode(s, actor_start);
				flag = find_actor_in_names(traverser, actor_start, s);
				// if (flag == false)
				// 	cout << "actor not found in names file\n\n";
				getline(File, description, ',');
				getline(File, age_vote, ',');
				getline(File, votes, ',');
				getline(File, budget, ',');
				getline(File, usa_gross_income, ',');
				getline(File, meta_score, ',');
				getline(File, reviews_from_user, ',');
				getline(File, reviews_from_critics);
				ml->root = ml->insert(ml->root, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actor_start, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
			}
		}
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


	ifstream File1("Ratings.csv");

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

				rl->root = rl->insert(rl->root, imdb_title_id, weighted_average_vote, total_votes, mean_vote, median_vote, votes_10, votes_9, votes_8, votes_7, votes_6, votes_5, votes_4, votes_3, votes_2, votes_1, allgenders_0age_avg_vote, allgenders_0age_votes, allgenders_18age_avg_vote, allgenders_18age_votes, allgenders_30age_avg_vote, allgenders_30age_votes, allgenders_45age_avg_vote, allgenders_45age_votes, males_allages_avg_vote, males_allages_votes, males_0age_avg_vote, males_0age_votes, males_18age_avg_vote, males_18age_votes, males_30age_avg_vote, males_30age_votes, males_45age_avg_vote, males_45age_votes, females_allages_avg_vote, females_allages_votes, females_0age_avg_vote, females_0age_votes, females_18age_avg_vote, females_18age_votes, females_30age_avg_vote, females_30age_votes, females_45age_avg_vote, females_45age_votes, top1000_voters_rating, top1000_voters_votes, us_voters_rating, us_voters_votes, non_us_voters_rating, non_us_voters_votes);
			}
		}
	}
	else {
		cout << "Give Error1\n";
	}


	//-----------------title_principles Storage----------------
	count = 0;
	string imdb_title_id1;
	string order;
	string imdb_name_id;
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
				getline(File2, imdb_name_id, ',');
				getline(File2, category, ',');
				getline(File2, job, ',');
				getline(File2, characters);
				t1->root = t1->insert(t1->root, imdb_title_id1, order, imdb_name_id, category, job, characters);
			}
		}
	}
	else {
		cout << "Give Error2";
	}




}
void Print_PreOrder1(movie_actor_node* temp)/*related to movie_actor node*/ {
	if (temp == NULL) {
		//Base Case
		return;
	}
	//Go to the left child recursively
	Print_PreOrder1(temp->lch);
	//print node
	cout << temp->key_tits_id << endl;
	//Then go to the right child recursively
	Print_PreOrder1(temp->rch);
}


//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

actor_movie_avl am;
void traverse_Actorstart(movie_actor_node* temp, MovieNode* movie)
{
	if (temp == NULL)
		return;

	temp->points_to_actor->data.moviestart = am.insertnode(temp->points_to_actor->data.name_id, temp->points_to_actor->data.moviestart, movie);
	/*create_avl(temp->points_to_actor, movie);*///removed
	traverse_Actorstart(temp->lch, movie);
	traverse_Actorstart(temp->rch, movie);
}

void traverse_movie(MovieNode* traverser)
{
	if (traverser == NULL)
		return;

	traverse_Actorstart(traverser->data.actor_Start, traverser);
	//traversing movie avl
	traverse_movie(traverser->lchild);
	traverse_movie(traverser->rchild);
}


//------------------------------------------------------------------
//------------------------printing functions------------------------

void print_coactors_of_an_actor(string, NameNode*, Movie_AVL, Name_AVL);

void traverse_actor_Start1(movie_actor_node* temp, string name, int choice, Movie_AVL ml, NameNode* n1, Name_AVL n11)
{
	if (temp == NULL)
		return;
	if (temp->points_to_actor->data.name != name)
	{
		print_coactors_of_an_actor(temp->points_to_actor->data.name, n11.root, ml, n11);
	}
	traverse_actor_Start1(temp->lch, name, choice, ml, n1, n11);
	traverse_actor_Start1(temp->rch, name, choice, ml, n1, n11);
}

void traverse_actor_Start(movie_actor_node* temp, string name, int choice, Movie_AVL ml, NameNode* n1)
{
	if (temp == NULL)
		return;
	if (temp->points_to_actor->data.name != name)
	{
		cout << temp->points_to_actor->data.name << endl;
	}
	traverse_actor_Start(temp->lch, name, choice, ml, n1);
	traverse_actor_Start(temp->rch, name, choice, ml, n1);
}
void print_preorder_order2(MovieNode* actor_ki_movie, string name, int choice, Movie_AVL ml, NameNode* n1, Name_AVL n11)
{
	movie_actor_node* temp = actor_ki_movie->data.actor_Start;
	(choice == 0) ?
		cout << "The co-actors of actor " << name << " are\n" : cout << "The co-actors of coactors of " << name << " are\n\n";
	(choice == 0) ?
		traverse_actor_Start(temp, name, choice, ml, n1) : traverse_actor_Start1(temp, name, choice, ml, n1, n11);
}
void traverse_moviestart(actor_movie_node* actor_ki_movies, string name, int choice, Movie_AVL ml, NameNode* n1, Name_AVL n11)
{
	/*cout << "uffffffs\n";*/
	if (actor_ki_movies == NULL)
		return;
	print_preorder_order2(actor_ki_movies->points_to_movie, name, choice, ml, n1, n11);
	traverse_moviestart(actor_ki_movies->lch, name, choice, ml, n1, n11);
	traverse_moviestart(actor_ki_movies->rch, name, choice, ml, n1, n11);
}
void print_preorder_order1(NameNode* n1, string name, int choice, Movie_AVL ml, Name_AVL n11)
{

	actor_movie_node* actor_ki_movies = n1->data.moviestart;

	traverse_moviestart(actor_ki_movies, name, choice, ml, n1, n11);
}
void print_coactors_of_an_actor(string name, NameNode* n1, Movie_AVL ml, Name_AVL n11)
{
	if (n1 == NULL) {
		return;
	}

	/*cout << "passes\n";*/
	if (name == n1->data.name)
	{

		print_preorder_order1(n1, name, 0, ml, n11);
		/*return;*/
	}

	print_coactors_of_an_actor(name, n1->lchild, ml, n11);
	print_coactors_of_an_actor(name, n1->rchild, ml, n11);
}
void print_coactors_of_coactors_of_an_actor(string name, NameNode* n1, Movie_AVL ml, Name_AVL n11)
{
	if (n1 == NULL) {
		return;
	}

	/*cout << "passes\n";*/
	if (name == n1->data.name)
	{
		print_preorder_order1(n1, name, 1, ml, n11);
		/*return;*/// escape sequemce when name found
	}

	print_coactors_of_coactors_of_an_actor(name, n1->lchild, ml, n11);
	print_coactors_of_coactors_of_an_actor(name, n1->rchild, ml, n11);
}

void main() {
	Movie_AVL ml;
	Ratings_AVL rl;
	title_principles_AVL t1;
	Name_AVL n1;
	read(&ml, &rl, &t1, &n1);


	MovieNode* traverser = ml.root;
	traverse_movie(traverser);
	print_coactors_of_coactors_of_an_actor("Blanche Bayliss", n1.root, ml, n1);




	getchar();
	getchar();
}
