//-------------btree class functions-------------//

template <typename T>
btree<T>::btree(size_t maxNodeElems): maxElem_{maxNodeElems}{
    std::cout << "Created default btree\n";
}

template <typename T>
bool btree<T>::insert(const T& elem){
    if (root_ == nullptr){
        root_ = std::make_shared<Node>(Node(nullptr,maxElem_));
        (*root_).add_value(elem);
    } else {
        (*root_).add_value(elem);
    }
    return true;
}

template <typename T>
void btree<T>::printRoot(){
    (*root_).printNode();
}

//-------------Node struct functions-------------//

// constructor
template <typename T>
btree<T>::Node::Node(const std::shared_ptr<Node> &parent, const size_t &maxNode):
    parent_{parent}, maxNode_{maxNode} 
{
    std::cout << "Node created!\n";
}

//Add value into node
template <typename T>
void btree<T>::Node::add_value(const T& value){
    if (nodes_.size() < maxNode_){
        nodes_.insert(value);
    } else {
        std::cout << "TODO\n";
    }
}