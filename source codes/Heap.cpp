#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<sstream>
using namespace std;//heap

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
	string actors;
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
	MovieNode(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actors, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics);
	MovieData data;
	MovieNode* lchild;
	MovieNode* rchild;
	int height1;
};

MovieNode::MovieNode(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actors, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics) {
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

	data.actors = actors;

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
	MovieNode* create_node(string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actors, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
	{
		MovieNode* newnode = new MovieNode(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actors, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
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

	MovieNode* insert(MovieNode* n, string title_id, string title, string original_title, string year, string date, string genre, string duration, string country, string language, string director, string writer, string production_company, string actors, string description, string age_vote, string votes, string budget, string usa_gross_income, string worldwide_gross_income, string meta_score, string reviews_from_user, string reviews_from_critics)
	{
		if (n == NULL)
		{
			return create_node(title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actors, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		}
		if (title_id < n->data.title_id)
		{
			n->lchild = insert(n->lchild, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actors, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
		}
		else if (title_id > n->data.title_id)
		{
			n->rchild = insert(n->rchild, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actors, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
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

class rating_movie_node {
public:
	string IMDB_title_ID;
	MovieNode* movie_ptr;
	double mean_vote;
	void insert(string, MovieNode*, string);
};

void rating_movie_node::insert(string IMDB_title_ID, MovieNode* movie_ptr, string s_mean_vote) {
	this->IMDB_title_ID = IMDB_title_ID;
	this->movie_ptr = movie_ptr;
	double temp;
	stringstream geek(s_mean_vote);
	geek >> temp;
	this->mean_vote = temp;
}

void swap(rating_movie_node** x, rating_movie_node** y);

class MaxHeap{
	rating_movie_node** harr;
	int capacity;
	int heap_size;
public:
	MaxHeap(int capacity);
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }
	void insertKey(rating_movie_node* k);
	void display();
};

MaxHeap::MaxHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new rating_movie_node*[cap];
}

void MaxHeap::insertKey(rating_movie_node* k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while (i != 0 && harr[parent(i)]->mean_vote < harr[i]->mean_vote)
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void MaxHeap::display() {
	for (size_t i = 0; i < heap_size; i++) {
		cout << harr[i]->movie_ptr->data.title_id << endl;
	}
}

void swap(rating_movie_node** x, rating_movie_node** y)
{
	rating_movie_node* temp = *x;
	*x = *y;
	*y = temp;
}

void read(Movie_AVL* ml, MaxHeap* h) {

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
				ml->root = ml->insert(ml->root, title_id, title, original_title, year, date, genre, duration, country, language, director, writer, production_company, actors, description, age_vote, votes, budget, usa_gross_income, worldwide_gross_income, meta_score, reviews_from_user, reviews_from_critics);
			}
		}
	}
	else {
		cout << "Give Error\n" << endl;
	}


    count = 0;
	string imdb_title_id;
	MovieNode* movie_ptr;
	string mean_vote;

	ifstream File1("ratings.csv");

	while (!File1.eof()) {
		string temp;
		if (count == 0) {
			getline(File1, temp);
			count = 1;
		}
		else {
			getline(File1, imdb_title_id, ',');
			getline(File1, temp, ',');
			getline(File1, temp, ',');
			getline(File1, mean_vote, ',');
			getline(File1, temp, '\n');
			MovieNode* traverver = ml->root;
			while (traverver != NULL && traverver->data.title_id!=imdb_title_id) {
				if (imdb_title_id < traverver->data.title_id) {
					traverver = traverver->lchild;
				}
				else {
					traverver = traverver->rchild;
				}
			}
			if (traverver != NULL) {
				movie_ptr = traverver;
				rating_movie_node* newnode = new rating_movie_node();
				newnode->insert(imdb_title_id, movie_ptr, mean_vote);
				h->insertKey(newnode);
			}
		}
	}
	File.close();
}

int main()
{
	Movie_AVL ml;
	MaxHeap h(11);
	read(&ml,&h);
	cout<<"Movies according to their heighest mean votes are : "<<endl;
	h.display();
	getchar();
	return 0;
}
