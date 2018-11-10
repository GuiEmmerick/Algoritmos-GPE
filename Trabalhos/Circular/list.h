#ifndef List_h
#define List_h

using namespace std;
class List{
	public:
		List();
		~List();
		bool IsEmpty(); //ver se a lista está vazia
		void AddNodeNext(int i); //adicionar nó depois
		void AddNodePrevious(int i); //adicionar nó antes
		int GetValue(); // pegar o valor do nó onde position aponta
		int GetValueNext(); // pegar o valor do próximo nó onde position aponta
		int GetValuePrevious(); // pegar o valor do nó anterior onde position aponta
		void ApagaPositionPositionNext(); // apaga position atual e aponta para o próximo
		void ApagaPositionPositionPrevious(); // apaga position atual e aponta par ao anterior
		void ApontaNextNode(); // muda position para o próximo nó
		void ApontaPreviousNode(); // muda position para o nó anterior
		bool BuscaValor(int i); // busca valor na lista
		Node *position;
};

List::List(){
	position=NULL;
}
List::~List(){
	while(!IsEmpty()){
		ApagaPositionPositionNext();
	}
}

bool List::IsEmpty(){
	if(position==NULL){
		return true;
	}
	else{
		return false;
	}
}

void List::AddNodeNext(int i){
	if(IsEmpty()){
		position = new Node(i);
		position->next = position;
		position->previous = position;

	}
	else{
		Node *aux = new Node(i,position->next,position);
		position->next->previous = aux;
		position->next =aux;

	}
}

void List::AddNodePrevious(int i){
	if(IsEmpty()){
		position = new Node(i);
		position->next = position;
		position->previous = position;

	}
	else{
		Node *aux = new Node(i, position, position->previous);
		position->previous->next =aux;
		position->previous = aux;

	}
}

int List::GetValue(){
	if(IsEmpty()){
		throw invalid_argument("Lista vazia");
	}
	else{
		return position->info;
	}
}

int List::GetValueNext(){
	if(IsEmpty()){
		throw invalid_argument("Lista vazia");
	}
	else{
		return position->next->info;
	}
}

int List::GetValuePrevious(){
	if(IsEmpty()){
		throw invalid_argument("Lista vazia");
	}
	else{
		return position->previous->info;
	}
}

void List::ApagaPositionPositionNext(){ //apaga position e aponta para o próximo
	if (IsEmpty()){
		throw invalid_argument("Lista vazia");
	}
	else if(position==position->next){
		position = NULL;
	}
	else{
		Node *aux;
		aux = position;
		position->previous->next = position->next;
		position->next->previous = position->previous;
		position = aux->next;
		delete aux;
	}
}

void List::ApagaPositionPositionPrevious(){ //apaga position e aponta para o anterior
	if (IsEmpty()){
		throw invalid_argument("Lista vazia");
	}
	else if(position==position->next){
		position = NULL;
	}
	else{
		Node *aux;
		aux = position;
		position->previous->next = position->next;
		position->next->previous = position->previous;
		position = aux->previous;
		delete aux;
	}
}

void List::ApontaNextNode(){ //faz position mudar para a proxima posição

	if (IsEmpty()){
		throw invalid_argument("lista vazia");
	}
	Node *aux;
	aux = position;
	position->next->previous = aux;
	position->previous->next = aux;
	position = position->next;

}

void List::ApontaPreviousNode(){ //faz position mudar para a posição anterior
	if(IsEmpty()){
		throw invalid_argument("lista vazia");
	}
	Node *aux;
	aux = position;
	position->next->previous = aux;
	position->previous->next = aux;
	position = position->previous;

}

bool List::BuscaValor(int i){
	Node *aux = position;
	if (aux->info == i){
		return true;
	}else{
		aux = aux->next;
		while(aux != position){
			if (aux->info == i){
				return true;
			}
			aux = aux->next;
		}
   	}
	return false;
}
#endif
