#include <iostream>
#include <list>
#include <cstdlib>
 
using namespace std;


	//Pokemon rooster works usign a Circularly linked list to store data
	//This represent an element of the linked list
	//It's your job to determine what need to go in there
	typedef struct ListNode{
	    int level;
	    string *name;
		string *type;
        struct ListNode *pNext;
        struct ListNode *pPrev;
	}ListElem;
	//---------------------------------------------------------

    //pfirst points to the first item of the list
    ListElem *pfirst;
    //plast points to the last item of the list
    ListElem *plast;
    static int size = 0;

	// Insert pokemonName at position pos in linked list
	// First arg is pokemon name, second is pokemon level
	// Third is pokemon Type and last one is the position in the list
	void Insert (std::string& name, int level, std::string& type, int pos) {
        int i = 0;
        if (pfirst == NULL) {
            ListElem *node = (ListElem*) malloc(sizeof(ListElem));
            node->level = level;
            node->name = &name;
            node->type = &type;
            node->pNext = node;
            node->pPrev = node;
            pfirst = node;
            plast = node;
            return;
        }
        ListElem *elem = pfirst;
        while (i != pos) {
            i++;
            elem = elem->pNext;
        }
        ListElem *node = (ListElem*) malloc(sizeof(ListElem));
        node->level = level;
        node->name = &name;
        node->type = &type;
        node->pNext = elem;
        node->pPrev = elem->pPrev;
        elem->pPrev = node;

        if (elem == pfirst) {
            pfirst = node;
        }
        if (elem == plast) {
            plast = node;
        }
        size++;
    }
	
	//delete pokemon at position i from the Circularly Linked List
	void Delete(int pos) {
        size--;
        int i = 0;
        ListElem* elem = pfirst;
        while (i != pos) {
            i++;
            elem = elem->pNext;
        }
        elem->pPrev->pNext = elem->pNext;
        elem->pNext->pPrev = elem->pPrev;
        if (elem == pfirst) {
            pfirst = elem->pNext;
        }
        if (elem == plast) {
            plast = elem->pPrev;
        }
        free(elem);
    }

	//Print out all pokemon on the screen
	void printall(ListElem *L)
	{

        if (pfirst == NULL) return;
        ListElem* elem = pfirst;
        while (elem != plast) {
            cout << "Name: " << *(elem->name) << " -- Level: " << elem->level << " -- Type: " << *(elem->type) << endl;
            elem = elem->pNext;
        }

	}

	//count the number of pokemon in the Circularly Linked List
	int countitem(ListElem *L)
	{
        int size = 0;
        ListElem* elem = pfirst;
        while (elem != plast) {
            size++;
            elem = elem->pNext;
        }
        size++;
	    return size;
	}

	//Find pokemon with lowest level
	ListElem *findmin(ListElem *L)
	{
	    ListElem *min = L;
	    ListElem *elem = L->pNext;
	    while(elem != L)
	    {
	        if(elem->level < min->level)
	        {
	            min = elem;
	        }
	        elem = elem->pNext;
	    }
	    return min;
	}

	//Find pokemon with highest level
	ListElem *findmax(ListElem *L)
	{
	    ListElem *max = L;
	    ListElem *elem = L->pNext;
	    while(elem != L)
	    {
	        if(elem->level < max->level)
	        {
	            max = elem;
	        }
	        elem = elem->pNext;
	    }
	    return max;
	}

	//Find pokemon with corresponding name
	ListElem *find(std::string comp)
	{
	    ListElem *elem = pfirst;
	    while(elem != plast)
	    {
	        if(elem->name->compare(comp) == 0)
	        {
	            return elem;
	        }
	        elem = elem->pNext;
	    }
        if (elem->name->compare(comp) == 0) {
            return elem;
        }
	    return NULL;
	}

	//Empty the Circularly linked List
	void makeEmpty(){
        ListElem* elem = pfirst;
        while (elem != plast) {
            ListElem* work_elem = elem;
            elem = work_elem->pNext;
            free(work_elem);
        }
		pfirst=plast=NULL;
	}
	
	
	void showmenu(){
		cout<<"=================================\n";
		cout<<"Pokemon Rooster Menu\n";
		cout<<"=================================\n";
		cout<<"1.Add a Pokemon\n";
		cout<<"2.Delete a Pokemon\n";
		cout<<"3.Show number of Pokemons in rooster\n";
		cout<<"4.Find Pokemon with lowest level\n";
		cout<<"5.Find Pokemon with highest level\n";
		cout<<"6.Find Pokemon\n";
		cout<<"7.Print all Pokemons\n";
		cout<<"8.Exit\n";
	}
	
	void select(){
		std::string name, type;
		int pos, ch, level;
		ListElem *temp;
		char yes='y';
		makeEmpty();
		//Make the list empty

		while(yes=='y'){ 
			cout<<"Enter your choice:";
			cin>>ch;
			switch(ch){
				// Add a new pokemon
				case 1: cout<<"Pokemon name :";
					cin>>name;
					cout<<"Pokemon level :";
					cin>>level;
					cout<<"Pokemon type :";
					cin>>type;
					cout<<"Position into the rooster:";
					cin>>pos;
					Insert(name, level, type, pos);
					break;

				// Delete a pokemon	
				case 2: 
					cout<<"Position in rooster:";
					cin>>pos;
					Delete(pos);
					break;

				// Show number of Pokemons in rooster	
				case 3: 
				    
					cout<<"Number of Pokemons:"<< countitem(NULL) << endl;
					break;

				// Find Pokemon with lowest level	
				case 4: 
					//if you found a pokemon
					{
					    ListElem * shit = findmin(pfirst);
						cout<<"The pokemon with the lowest level is:"<< *(shit->name) <<
						" who is level " << shit->level <<endl;
					//else you should return cout<<"Not found\n";
					}
					break;
				
				// Find Pokemon with highest level
				case 5: 
					//if you found a pokemon
					{
					    ListElem * top = findmax(pfirst);  
						cout<<"The pokemon with the highest level is :"<< *(top->name) << 
						" who is level " << top->level <<endl;
					}
					//else you should return cout<<"Not found\n";
					break;

				// Find Pokemon by name and show his informations	
				case 6: 
				    {
					cout<<"Find what:";
					cin>>name;
					//if you found a pokemon :
					ListElem * node = find(name);
						cout<<"Pokemon found : "<< *(node->name) << " Level : "
						<< node->level << " Type : " << *(node->type) << endl;
					}
					//else you should return cout<<"Not found\n";
						
					
					break;

				// Show all Pokemon in rooster	
				case 7: 
				    {
					cout<<"All Pokemons in rooster:\n";
					printall(pfirst);
					}
					break;

				// Quit Pokemon Rooster	
				case 8: 
					exit(0);
				default: cout<<"Invalid choice\n";
			}
			cout<<"Continue?y/n:";
			cin>>yes;
		}
	}

int main(){
	showmenu();
	select();
	return 0;
}
