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
        root_->add_value(elem);
    } else {
        if ((*root_).add_value(elem) == false){
            std::cout << "TODO\n";
        }
    }
}

//REMOVE WHEN DONE
template <typename T>
void btree<T>::printRoot(){
    root_->printNode();
}

template <typename T>
void btree<T>::tester(){
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
        if (find_value(value) == -1){
            std::cout << "value inserted!\n";
            nodes_.insert(value);
        } else {
            std::cout << "Value exist!\n";
        }
        return true;
    } else {
        for (auto i : nodes_){
            std::cout << "checking key!\n";
            if (check_key(i, i) != true){
            } else {
                std::cout << "key exist in: " << i << "\n";
            }
        }

    }
    return true;
}

template <typename T>
bool btree<T>::Node::check_key(const T& a, const T& b){
    if (children_.find(a) != children_.end()){
        if(children_[a].find(b) != children_[a].end()){
            return true;
        } else {
            return false;
        }
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

template <typename T>
void btree<T>::Node::printNode(){
    std::cout << "| ";
    for(auto i : nodes_){
        std::cout<< i << " | ";
    }
    std::cout << "\n";
}