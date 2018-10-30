class Node{
	public:
		Node(int inf, Node* next=NULL, Node* previous=NULL);
		int info;
		Node* next;
		Node* previous;	
		

};

Node::Node(int inf, Node* n, Node* p){
	info = inf;
	next = n;
	previous = p;
}

