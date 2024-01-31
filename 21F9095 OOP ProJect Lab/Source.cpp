#include<iostream>
#include<fstream>
#include<iomanip>
#include<stack>
#include<windows.h>
using namespace std;
class book
{
public:
	string title;
	string author;
	int ISBN;// 4 digit international standard book number
	int num;// number of copies
	book()
	{
		title = "";
		author = "";
		ISBN = 0;
		num = 0;
	}
};
class node
{
public:
	book data;
	node* next;
	node()
	{
		next = NULL;
	}
};
class library
{
	node* head;
public:
	library()
	{
		head = NULL;
		
		ifstream fin("Text.txt");
		node* temp = new node;
		while (!fin.eof())
		{
			if (!fin.eof())
			{
				temp = new node;
				fin >> temp->data.title;
				fin >> temp->data.author;
				fin >> temp->data.ISBN;
				fin >> temp->data.num;
				temp->next = NULL;
				if (head == NULL && !fin.eof())
				{
					head = temp;
				}
				else if(!fin.eof())
				{
					node* move = new node;
					move =head;
					while (move->next != NULL)
					{
						move = move->next;
					}
					move->next = temp;
				}
			}
		}
		fin.close();
	}
	void insert(book &obj)
	{
		node* temp = new node;
		temp->data.author = obj.author;
		temp->data.title = obj.title;
		temp->data.ISBN = obj.ISBN;
		temp->data.num = obj.num;
		temp->next = NULL;

		node* move = head;
		while (move->next != NULL)
		{
			move = move->next;
		}
		
		move->next = temp;
		cout << "Inserted Succesfully" << endl;
	}
	void  search()
	{
		char x=' ';
		int  y = 0;
		cout << "Are you from management? [Y/N]" << endl;
		cin >> x;
		if (x == 'Y')
		{
			cout << "Enter the password " << endl;
			cin >> y;
			if (y == 1234)
			{
				cout << "Authorized" << endl;
			}
			else
			{
				cout << "Wrong Access" << endl;
			}
		}
		string z = "";
		cout << "Enter the Search" << endl;
		cin >> z;
		int count = 0;
		node* search = head;
		bool flag = 0;
		stack<book> st;
		while(search) 
		{
			count = 0;
			string str1 = search->data.author;
			string str2 = search->data.title;
			int    str3 = search->data.ISBN;
			for (int i = 0; i < z.length(); i++)
			{
				flag = 0;
				for (int j = 0; j < str1.length(); j++)
				{
					if (str1[j] == z[i])
					{
						count++;
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					for (int j = 0; j < str2.length(); j++)
					{
						if (str2[j] == z[i])
						{
							count++;
							flag = 1;
							break;
						}
					}

				}
				if (flag == 0)
				{
					int temp = 0;
					int cpy = str3;
					while (cpy != 0)
					{
						
						temp = cpy % 10;
						cpy /= 10;
						if (z[i] - 48 == temp)
						{
							count++;
							flag = 1;
							break;

						}
					}
				}

			}
			if (count >= z.length())
			{
				st.push(search->data);
			}
			search = search->next;
		}
		if (st.empty())
		{
			cout << "No Related Book Available" << endl;
		}
		else if (y != 1234)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n" << endl;
			cout << setw(70) << "Library Management System" << endl;
			cout << setw(70) << "-------------------------" << endl;
			cout << "\n\n\n" << endl;
			cout << "|------------------------------|" << endl;
			cout << "|" << setw(10) << "Title" << setw(6) << "|" << setw(10) << "Author" << setw(5) << "|"<< endl;
			while (!st.empty())
			{
				book temp = st.top();
				st.pop();
				cout << "|" << setw(12) << temp.title << setw(4) << "|" << setw(12) << temp.author << setw(3) << "|" << endl;

			}
			cout << "|------------------------------|" << endl;
			
			
		}
		else if(y==1234)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n" << endl;
			cout << setw(70) << "Library Management System" << endl;
			cout << setw(70) << "-------------------------" << endl;
			cout << "\n\n\n" << endl;
			cout << "|---------------------------------------------------------------------|" << endl;
			cout << "|" << setw(10) << "Title" << setw(6) << "|" << setw(10) << "Author" << setw(5) << "|" << setw(10) << "ISBN" << setw(8) << "|" << setw(10) << "Copies" << setw(11) << "|"<<endl;
			while (!st.empty())
			{
				book temp = st.top();
				st.pop();
				cout << "|" << setw(12) << temp.title << setw(4) << "|" << setw(12) << temp.author << setw(3) << "|" << setw(10) << temp.ISBN << setw(8) << "|" << setw(11) << temp.num << setw(10) << "|" << endl;

			}
			cout << "|---------------------------------------------------------------------|" << endl;
			cout<<"\n\n" << endl;
			
			
			
		}
		int f = 0;
		cout << "Press any integer  to continue...." << endl;
		while (!(cin >> f))
		{
			cout << "Enter number" << endl;
			cin.clear();
			cin.ignore(123, '\n');
		}
		
	}
	void modify()
	{
		cout << "The title of the books are" << endl;
		node* temp = head;
		int check = 1;
		while (temp != NULL)
		{
			cout <<check<<". " <<temp->data.title << endl;
			check++;
			temp = temp->next;
		}
		int a = 0;
		cout << "Which book you want to update" << endl;
		cin >> a;
		temp = head;
		for (int i = 0; i < a-1; i++)
		{
			temp = temp->next;
		}
		cout<<"The book selected is :"<<temp->data.title << endl;
		char x = ' ';
		int  y = 0;
		cout << "Are you from management? [Y/N]" << endl;
		cin >> x;
		if (x == 'Y')
		{
			cout << "Enter the password " << endl;
			cin >> y;
			if (y == 1234)
			{
				cout << "Authorized" << endl;
			}
			else
			{
				cout << "Wrong Access not able to modify" << endl;
				cout << "Please Wait" << endl;
			}
		}
		else if (x == 'N')
		{
			cout << "Not able to Modify Thankyou" << endl;
			cout << "Please Wait" << endl;
		}
		if (y == 1234)
		{
			int s = 0;
			cout << "Press 1 to change title" << endl;
			cout << "Press 2 to change author name " << endl;
			cout << "Press 3 to change ISBN number" << endl;
			cout << "Press 4 to change number of books available in library " << endl;
			cin >> s;
			if (s == 1)
			{
				cout << "Enter the new title" << endl;
				cin >> temp->data.title;
				cout << "Please Wait" << endl;
			}
			else if (s == 2)
			{
				cout << "Enter the new author's name" << endl;
				cin >> temp->data.author;
				cout << "Please Wait" << endl;
			}
			else if (s == 3)
			{
				cout << "Enter new 4 digit ISBN number " << endl;
				cin >> temp->data.ISBN;
				cout << "Please Wait" << endl;
			}
			else if (s == 4)
			{
				cout << "Enter the copies available of this book in libraray" << endl;
				cin >> temp->data.num;
				cout << "Please Wait" << endl;
			}
		}

		Sleep(3000);
	}
	void remove()
	{
		char x = ' ';
		int  y = 0;
		cout << "Are you from management? [Y/N]" << endl;
		cin >> x;
		if (x == 'Y')
		{
			cout << "Enter the password " << endl;
			cin >> y;
			if (y == 1234)
			{
				cout << "Authorized" << endl;
			}
			else
			{
				cout << "Wrong Access not able to DEL" << endl;
			}
		}
		else if (x == 'N')
		{
			cout << "Not able to Modify Thankyou" << endl;
		}
		if (y == 1234)
		{
			cout << "The title of the books are" << endl;
			node* temp = head;
			int check = 1;
			while (temp != NULL)
			{
				cout << check << ". " << temp->data.title << endl;
				check++;
				temp = temp->next;
			}
			int a = 0;
			cout << "Which book you want to delete" << endl;
			cin >> a;
			temp = head;
			for (int i = 0; i < a-2; i++)
			{
				temp = temp->next;
			}
			char ent;
			node* del = temp->next;
			cout << "The book selected is :" << del->data.title << endl;
			cout << "Are you sure to delete[Y/N]" << endl;
			cin >>ent;
			if (ent == 'Y')
			{
				temp->next = del->next;
				delete del;
				del = NULL;
				cout << "Deleted" << endl;
			}


		}
		Sleep(3000);
	}
	~library()
	{
		ofstream fout("Text.txt");
		node* temp = head;
		while (temp != NULL)
		{
			fout << temp->data.title << " " << temp->data.author << " " << temp->data.ISBN << " " << temp->data.num<<endl;
			temp = temp->next;
		}
		fout.close();
		
	}
		


};
int main()
{

	
	cout << "\n\n\n\n\n\n\n\n" << endl;
	cout << setw(70) << "Mini Library Management System" << endl;
	cout << setw(70) << "------------------------------" << endl;
	Sleep(3000);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n" << endl;
	cout << setw(70)<< "Loading Data From File" << endl;
	cout << setw(70) << "----------------------"<< endl;
	Sleep(3000);
	system("cls");
	library l1;
	int a=1;
	while (a != 0)
	{
		system("cls");
		cout << "Press 1 to add a new book " << endl;
		cout << "Press 2 to search a  book " << endl;
		cout << "Press 3 to modify a  book " << endl;
		cout << "Press 4 to delete a  book " << endl;
		cout << "Press 0 to exit" << endl;
		
		while(!(cin >> a))
		{
			cout << "Enter number" << endl;
			cin.clear();
			cin.ignore(123, '\n');
		}
		if (a == 1)
		{
			book o;
			cout << "Enter the data required for book :" << endl;
			cout << " Title : ";
			cin >> o.title;
			cout << endl;
			cout << " Author Name : ";
			cin >> o.author;
			cout << endl;
			cout << " ISBN(4 Digit Longer) : ";
			cin >> o.ISBN;
			cout << endl;
			cout << " Number of Copies : ";
			cin >> o.num;
			cout << endl;
			l1.insert(o);
			cout << "Added Successfully" << endl;
			
		}
		else if (a == 2)
		{
			l1.search();
		}
		else if (a == 3)
		{
			l1.modify();

		}
		else if (a == 4)
		{
			l1.remove();
		}
		else if(a>4)
		{
			cout << "Wrong Selection" << endl;
		}

		
	}
	cout << "Program Ends Thankyou" << endl;
}