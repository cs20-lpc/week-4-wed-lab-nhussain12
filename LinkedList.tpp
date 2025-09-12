template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) : head(nullptr) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // TODO
    clear();
    this->length = 0;
    if (copyObj.isEmpty()) {
        return;
    } else {
        head = new Node(copyObj.head->value);
        this->length++;

        Node* curr = head;
        Node* copy = copyObj.head->next;
        
        while(copy != nullptr) {
            curr->next = new Node(copy->value);
            copy = copy->next;
            curr = curr->next;
            this->length++;
        }
    }
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    // TODO
    // Exception Handling
    if (position < 0 || position >= this->length) {
        throw string("insert: error, position out of bounds");
    }

    // Function Implementation
    Node* new_node = new Node(elem);
    Node* curr = head;

    if(head == nullptr) {
        new_node->next = head;
        head = new_node;
    } else {
        for(int i = 0; i < position-1; i++) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
    this->length++;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    // TODO
    // Exception Handling
    if(position < 0 || position >= this->length) {
        throw string("remove: error, position out of bounds");
    }

    // Function Implementation
    Node* mustDelete;
    if(position == 0) {
        mustDelete = head;
        head = head->next;
    } else {
        Node* prev = head;
        for(int i = 0; i < position-1; i++) {
            prev = prev->next;
        }
        mustDelete = prev->next;
        prev->next = mustDelete->next;
    }
    delete mustDelete;
    this->length--;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
