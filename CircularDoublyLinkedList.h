 #pragma once
template <class T>

class CircularDoublyLinkedList {

private:

	//Using a struct as you need Node members to be public
	struct Node
	{
		Node *next;
		Node *prev;
		T data;
		Node(T item, Node *n = nullptr, Node *p = nullptr) : next(n), prev(p), data(item) {}
	};

	//Unsigned integer to keep track of the size of the CDLL
	unsigned int CDLLsize;

	//Head and tail pointers for CDLL
	Node *head;
	Node *tail;

public:

	//Iterator class with public access, overloaded operators ++,-- and !=
	class Iterator {
	private:
		Node *ptr;
	public:
		Iterator()
		{
			ptr = nullptr;
		}

		Iterator(const Iterator &other)
		{
			ptr = other.ptr;
		}

		Iterator(Node *m_ptr) {
			ptr = m_ptr;
		}
		//Overloaded pre-increment and post-increment operators
		Iterator &operator++ () {
			ptr = ptr->next;
			return *this;
		}
		Iterator operator-- () {
			ptr = ptr->prev;
			return *this;
		}
		bool operator!= (const Iterator &b)
		{
			return ptr != b.ptr;
		}
		T getValue() const
		{
			return ptr->data;
		}
		void setValue(T val)
		{
			ptr->data = val;
		}
		//Overloaded the = operator, returns the this pointer
		Iterator &operator=(const Iterator &other)
		{
			ptr = other.ptr;
			return *this;
		}
	};

	//Member functions of CDLL 
	//CDLL Constructor and Destructor
	CircularDoublyLinkedList();
	~CircularDoublyLinkedList();

	//Returns size of the CDLL
	unsigned int size() const;

	//Retrieves head node data 
	T retrieveHead();

	//Retrieves tail node data 
	T retrieveTail();

	//Adds head/node
	void addNode(T value);

	//adds head
	void addHead(T value);

	//adds tail
	void addTail(T value);

	//Clears elements of the CDLL
	void clear();

	//IsEmpty function of the CDLL
	bool isEmpty() const;

	//Member functions of Iterators
	//Start of the CDLL

	Iterator begin()
	{
		return Iterator(head);
	}
	//End of the CDLL

	Iterator end()
	{
		return Iterator(tail);
	}
};

//Function to return size of the CDLL

template <class T>
unsigned int CircularDoublyLinkedList<T>::size() const {
	return CDLLsize;
}

//Constructor for the CDLL

template <class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
	CDLLsize = 0;
}

//To retrieve data in head

template <class T>
T CircularDoublyLinkedList<T>::retrieveHead()
{
	T returnValue = head->data;
	return(returnValue);
}

//To retrieve data in tail

template <class T>
T CircularDoublyLinkedList<T>::retrieveTail() {
	T returnValue = tail->data;
	return(returnValue);
}

//Destructor for the CDLL, deletes every node.

template <class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
	Node *here = head;
	while (here->next != head) {
		Node *temp;
		temp = here;
		here = here->next;
		delete temp;
		--CDLLsize;
	}
}


//Add a newNode to the CDLL

template <class T>
void CircularDoublyLinkedList<T>::addNode(T value) {

	//if no nodes exist
	if (CDLLsize == 0)
	{
		Node *newNode = new Node(value, head, tail);
		head = newNode;
		tail = head;
		head->next = nullptr;
		head->prev = nullptr;
		CDLLsize++;
	}
	else
	{
		Node *newNode = new Node(value, head, tail);
		tail->next = newNode;
		head->prev = newNode;
		tail = newNode;
		CDLLsize++;
	}
}

//templated addHead function for the CDLL

template <class T>
void CircularDoublyLinkedList<T>::addHead(T value) {
	//if no nodes exist

	if (CDLLsize == 0) 
	{
		Node *newNode = new Node(value, head, tail);
		head = newNode;
		tail = head;
		head->next = nullptr;
		head->prev = nullptr;
		CDLLsize++;
	}
	else
	{
		Node *newNode = new Node(value, head, tail);
		head->prev = newNode;
		tail->next = newNode;
		head = newNode;
		CDLLsize++;
	}
}

//templated addTail function for the CDLL

template <class T>
void CircularDoublyLinkedList<T>::addTail(T value) {
	//if no nodes exist

	if (CDLLsize == 0) 
	{
		Node *newNode = new Node(value, head, tail);
		head = newNode;
		tail = head;
		head->next = nullptr;
		head->prev = nullptr;
		CDLLsize++;
	}
	else 
	{
		Node *newNode = new Node(value, head, tail);
		head->prev = newNode;
		tail->next = newNode;
		tail = newNode;
		CDLLsize++;
	}
}

//Clear function for the CDLL

template <class T>
void CircularDoublyLinkedList<T>::clear() 
{
	Node *here = head;
	while (here->next != head) {
		Node *temp;
		temp = here;
		here = here->next;
		delete temp;
		--CDLLsize;
	}
	CDLLsize = 0;
}

//checks if the CDLL is empty

template <class T>
bool CircularDoublyLinkedList<T>::isEmpty() const
{
	if (CDLLsize == 0) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}