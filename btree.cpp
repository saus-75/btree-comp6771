//-------------btree class functions-------------//

template <typename T>
btree<T>::btree(size_t maxNodeElems): maxElem_{maxNodeElems}{
    std::cout << "Created default btree\n";
}

//Need to change to the correct type
template <typename T>
void btree<T>::insert(const T& elem){
    
    if (root_ == nullptr){
        root_ = std::make_shared<Node>(Node(maxElem_));
        (*root_).add_value(elem);
    } else {
        if ((*root_).add_value(elem) == false){
            std::cout << "TODO\n";
        }
    }
}

//REMOVE WHEN DONE
template <typename T>
void btree<T>::printRoot(){
    (*root_).printNode();
}

template <typename T>
void btree<T>::tester(){
    auto i = (*root_).find_value(10);
    std::cout << i << "\n";
}

//-------------Node struct functions-------------//

template <typename T>
btree<T>::Node::Node(const size_t &maxNode):
    maxNode_{maxNode} 
{
    std::cout << "Node created!\n";
}

template <typename T>
bool btree<T>::Node::add_value(const T& value){
    if (nodes_.size() < maxNode_){
        nodes_.insert(value);
        return true;
    } else {
        return false;
    }
}

// template <typename T>
// std::shared_ptr<Node> btree<T>::Node::search()

template <typename T>
int btree<T>::Node::find_value(const T& value){
    auto find = nodes_.find(value);
    if (find != nodes_.end()){
        return std::distance(nodes_.begin(), find);
    } else {
        return -1;
    }
}