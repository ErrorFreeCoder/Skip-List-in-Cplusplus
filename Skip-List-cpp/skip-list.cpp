// #include <bits/stdc++.h>
#include <iostream>
#define MaxLevel_of_skipList 7
using namespace std;

class Node {
public:
	int value;
	Node** forward;

	Node(int value, int level)
	{
		setValue(value);
		forward = new Node * [level + 1];
		memset(forward, NULL, sizeof(Node*) * (level + 1));
	}
	void setValue(int value) { this->value = value; }
	int getValue() { return value; }
};
class SkipList {
private:
	float probablility = 0.5;
	int level;
	Node* head;
	void setHead(Node* head) { this->head = head; }
	Node* getHead() { return head; }
	bool Empty() 
	{ 
		return level == NULL && getHead()->forward[0] ==NULL;
	}
	int RandomLevel_Genrator()
	{
		float randomValue = (float)rand() / RAND_MAX;
		int level = 0;
		while (randomValue < probablility && level < MaxLevel_of_skipList)
		{
			level++;
			randomValue = (float)rand() / RAND_MAX;
		}
		return level;
	};
	Node* createNode(int key, int level)
	{
		Node* newNode = new Node(key, level);
		return newNode;
	};
public:
	SkipList()
	{
		level = 0;
		setHead(new Node(NULL, MaxLevel_of_skipList));
	}

	void InsertData(int value)
	{
		Node* current = getHead();
		Node* update[MaxLevel_of_skipList + 1];
		memset(update, NULL, sizeof(Node*) * (MaxLevel_of_skipList + 1));
		for (int i = level; i >= 0; i--)
		{
			while (current->forward[i] != NULL && current->forward[i]->getValue() < value)
			{
				current = current->forward[i];
			}
			update[i] = current;
		}
		current = current->forward[0];
		if (current == NULL || current->getValue() != value)
		{
			int randomlevel = RandomLevel_Genrator();
			if (randomlevel > level)
			{
				for (int i = level + 1; i < randomlevel + 1; i++)
				{
					update[i] = getHead();
				}
				level = randomlevel;
			}
			Node* newNode = createNode(value, randomlevel);
			for (int i = 0; i <= randomlevel; i++)
			{
				newNode->forward[i] = update[i]->forward[i];
				update[i]->forward[i] = newNode;
			}
			cout << "Successfully Inserted value: " << value << "\n";
		}
	}
	Node* SearchData(int SearchData)
	{
		if (Empty())
		{
			cout << "\n---Skip list is Empty, Kindly Insert Data to Search---" << endl;
			return NULL;
		}
		else
		{
			Node* current = getHead();
			for (int i = level; i >= 0; i--)
			{
				while (current->forward[i] && current->forward[i]->getValue() < SearchData)
				{
					current = current->forward[i];
				}
			}
			current = current->forward[0];
			if (current->getValue() == SearchData)
			{
				cout << "\nFound key: " << current->getValue() << "\n";
				return current;
			}
			else
			{
				cout << "\n---This Value [" << SearchData << "] Does Not Exist in the Skip List---" << endl;
				return NULL;
			}
		}
	}
	void RemoveData(int DeleteData)
	{
		if (Empty())
		{
			cout << "\n---Skip list is Empty, Kindly Insert Data to Delete---" << endl;
		}
		else
		{
			Node* current = getHead();
			Node* update[MaxLevel_of_skipList + 1];
			memset(update, NULL, sizeof(Node*) * (MaxLevel_of_skipList + 1));
			for (int i = level; i >= 0; i--)
			{
				while (current->forward[i] != NULL && current->forward[i]->value < DeleteData)
				{
					current = current->forward[i];
				}
				update[i] = current;
			}
			current = current->forward[0];
			if (current != NULL && current->getValue() == DeleteData)
			{
				for (int i = 0; i <= level; i++)
				{
					if (update[i]->forward[i] != current)
					{
						break;
					}
					update[i]->forward[i] = current->forward[i];
				}
				cout << "\nKey Deleted: " << current->getValue() << endl;
				delete current;
				while (level > 0 && getHead()->forward[level] == NULL)
				{
					cout << "\n--Empty Level ["<<level<<"] Vanished--" << endl;
					level--;
				}
			}
			else
			{
				cout << "\n---This Value [" << DeleteData << "] Does Not Exist in the Skip List---" << endl;
				DisplayData();
			}
		}
	}
	void DisplayData()
	{
		if (Empty())
		{
			cout << "\n---Skip list is Empty, Kindly Insert Data to Display---" << endl;
		}
		else {
			cout << "\n<-----Displaying Whole Skip List----->" << endl;
			for (int i = 0; i <= level; i++)
			{
				Node* node = getHead()->forward[i];
				cout << "\nLevel " << i << ": ";
				while (node != NULL)
				{
					cout << node->getValue() << "\t";
					node = node->forward[i];
				}
				cout << "\n";
			}
		}
	}
};
int main()
{
	SkipList FirstobjectofSkiplist;
	int options, value;
	bool quit = true;
	cout << "\n----------Skip List Program----------\n" << endl;
	do
	{
		cout << "\n==============================" << endl;
		cout << "----Functions of Skip List----" << endl;
		cout << "==============================" << endl;
		cout << "\n1-> Insert Data ";
		cout << "\n2-> Delete Data ";
		cout << "\n3-> Search Data ";
		cout << "\n4-> Display List ";
		cout << "\n5-> Exit " << endl;

		cout << "\nEnter Option: ";
		cin >> options;
		switch (options)
		{
		case 1:
			cout << "\nEnter Value: ";
			cin >> value;
			FirstobjectofSkiplist.InsertData(value);
			break;
		case 2:
			cout << "\nEnter Value To Delete: ";
			cin >> value;
			FirstobjectofSkiplist.RemoveData(value);
			break;
		case 3:
			cout << "\nEnter Value to be Searched: ";
			cin >> value;
			FirstobjectofSkiplist.SearchData(value);
			break;
		case 4:
			srand((unsigned)time(NULL));
			FirstobjectofSkiplist.DisplayData();
			break;
		case 5:
			cout << "\n--Thank You,You can Leave---" << endl;
			quit = false;
			break;
		default:
			cout << "\n---Invalid Option---" << endl;
			break;
		}
	} while (quit);
	return 0;
}