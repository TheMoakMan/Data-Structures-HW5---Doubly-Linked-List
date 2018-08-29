/*~~~~~MyList Functions~~~~~*/
template <typename T>
MyList<T>::MyList()
{
  m_head = new Node<T>(T(), NULL, NULL); 
  m_tail = m_head->m_next = new Node<T>(T(), m_head, NULL);  
  m_size = 0;
}

template <typename T>
MyList<T>::~MyList()
{
  Node<T> *temp;
  
  while(m_head)
    {
	  temp = m_head;
	  m_head = m_head->m_next;
	  delete temp;
    }		
}

template <typename T>
MyList<T> & MyList<T>::operator=(const MyList<T> &source)
{
  //Clear the current list
  clear();
  
  m_size = source.m_size;
  
  //Create an iterator to go through source list
  Node<T> *s_iter = source.m_head;
  Node<T> *this_iter = m_head;
  
  //Copy source list into new list
  for(int i = 0; i < m_size; i++){

	//Move the source iter over  
	s_iter = s_iter->m_next;
	
	//Create a new Node after this_iter and adjust pointers
	this_iter->m_next = new Node<T>(s_iter->m_element, this_iter, m_tail);
	m_tail->m_prev = this_iter->m_next;
	
	//Move this_iter over
	this_iter = this_iter->m_next;
  }
  
  return *this;	
}

template <typename T>
MyList<T>::MyList(const MyList<T> &source)
{   
  m_head = new Node<T>(T(), NULL, NULL);
  m_tail = m_head->m_next = new Node<T>(T(), m_head, NULL);
  m_size = source.m_size;
  
  Node<T> *s_iter = source.m_head;
  Node<T> *this_iter = m_head;
  
  for(int i = 0; i < m_size; i++){
	s_iter = s_iter->m_next;
	
	this_iter->m_next = new Node<T>(s_iter->m_element, this_iter, m_tail);
	m_tail->m_prev = this_iter->m_next;
	
	this_iter = this_iter->m_next;
  }
}

template <typename T>
T & MyList<T>::front()
{
  return m_head->m_next->m_element;	
}

template <typename T>
 T & MyList<T>::back()
 { 
   return m_tail->m_prev->m_element;
 }
 
 template <typename T>
 void MyList<T>::assign(int count, const T &value)
 {
    clear();
	m_size = count;
    
	Node<T> *iter = m_head;
	
    for(int i = 0; i < m_size; i++){
	  iter->m_next = new Node<T>(value, iter, m_tail);
	  m_tail->m_prev = iter->m_next; 
    
	  iter = iter->m_next;
	}		 
 }
 
 template <typename T>
 void MyList<T>::clear()
 {
   Node<T> *temp;
   //Delete the list elements
   while(m_head)
   {
	 temp = m_head;
	 m_head = m_head->m_next;
	 delete temp;
   }
	 
   //Initialize a new list.	
   m_head = new Node<T>(T(), NULL, NULL);
   m_tail = m_head->m_next = new Node<T>(T(), m_head, NULL);   
   m_size = 0;   
 }
 
 template <typename T>
 void MyList<T>::push_front(const T &x)
 {
	Node<T> *temp = new Node<T>(x, m_head, m_head->m_next);
	m_head->m_next->m_prev = temp;
	m_head->m_next = temp;    	 
 
    m_size++;
 }
 
 template <typename T>
 void MyList<T>::push_back(const T &x)
 {	
	Node<T> *temp = new Node<T>(x, m_tail->m_prev, m_tail);
	m_tail->m_prev->m_next = temp;
	m_tail->m_prev = temp;
	
	m_size++;
 }
 
 template <typename T>
 void MyList<T>::pop_back()
 {
	Node<T> *temp = m_tail->m_prev;
    temp->m_prev->m_next = m_tail;
	m_tail->m_prev = temp->m_prev;
	
    delete temp;

    m_size--;	
 }
 
 //i = pos before the element to be inserted,
 //indexing starts at 0;
 template <typename T>
 void MyList<T>::insert(int i, const T &x)
 { 
    if(i > m_size)
	  return;
  
	Node<T> *iter = m_head;
	
	for(int count = 0; count < i; count++){
	  iter = iter->m_next;
	}
		
	Node<T> *temp = new Node<T>(x, iter, iter->m_next);
    iter->m_next->m_prev = temp;
    iter->m_next = temp;

    m_size++;
 }
 
 //Removes all elements that are equal to the value of i
 template <typename T>
 void MyList<T>::remove(T i)
 {
	Node<T> *iter = m_head; 
	 
	//Search through the whole list for each element that is equal
	//to i and remove that Node.
    while(iter->m_next){
	  //Set a temp at current position
	  Node<T> *temp = iter;
	  
	  //Advance Iterator
	  iter = iter->m_next;
		
	  //If element is equal to target, delete element	
	  if(temp->m_element == i){
		temp->m_prev->m_next = temp->m_next;
        temp->m_next->m_prev = temp->m_prev;
		
        delete temp;
        m_size--;
      }		  
	}	
 }
 

 template <typename T>
 void MyList<T>::erase(int i)
 {
	if(i > m_size)
      return;
  
	Node<T> *iter = m_head;
	for(int count = 1; count <= i; count++){
      iter = iter->m_next;
	} 
	
	iter->m_prev->m_next = iter->m_next;
	iter->m_next->m_prev = iter->m_prev;
	
	delete iter;
	
	m_size--;
 }
 
 //Reverses all the elements in the list
template <typename T>
 void MyList<T>::reverse()
 {
   //Make a new list to hold the reverse of the original
   Node<T> *new_head = new Node<T>(T(), NULL, NULL);
   Node<T> *new_tail = new_head->m_next = new Node<T>(T(), new_head, NULL);
   
   Node<T> *this_iter = m_tail;
   Node<T> *new_iter = new_head;
   
   //Iterate through the list and copy the elements in reverse order.
   for(int i = 0; i < m_size; i++){
     new_iter->m_next = new Node<T>(this_iter->m_prev->m_element, new_iter, new_tail);

	 new_tail->m_prev = new_iter->m_next;
     new_iter = new_iter->m_next;
     this_iter = this_iter->m_prev;    	 
   }
   
   Node<T> *temp;
   
   //Delete the current list;
   while(m_head)
   {
	 temp = m_head;
	 m_head = m_head->m_next;
	 delete temp;
   }
	 
   //Assign head and tail to the new list;
   m_head = new_head;
   m_tail = new_tail;   
 	 
 }
 
 template <typename T>
 void MyList<T>::resize(int count)
 {
	//If m_size > count reduce the size of the list
	//Need to make sure it starts right before the tail;
	if(m_size > count){
	  for(int i = m_size; i > count; i--){
        erase(i);		
	  }
	 
	  m_size = count;
	}
    
	//If m_size < count, append more Nodes	
	if(m_size < count){
	  for(int i = m_size; i < count; i++){
	    push_back(T());
	  }
      
	  m_size = count;
    }
    	  
 }
 
 template <typename T>
 bool MyList<T>::empty()
 {
   return (!m_size);
 }
 
 template <typename T>
int MyList<T>::size()
{
  return m_size;	
}
