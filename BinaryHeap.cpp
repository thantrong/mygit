//
// Created by Thân Vĩnh Trọng on 19/7/24.
//

#include "BinaryHeap.h"
#include "iostream"


using namespace std;

void BinaryHeap::display() {
    for(int h : this->heap){
        cout<<h<<" ";
    }
    cout<<endl;
}

int BinaryHeap::get_max() {
    if(this->heap.empty()){

        cout<<"Heap emty !!! "<<endl;
        return -1;
    }
    return this->heap[0];
}

int BinaryHeap::parten(int index) {
    return (index)>>1;
}

int BinaryHeap::left_child(int index) {
    return index<<1;
}

int BinaryHeap::right_child(int index) {
    return (index<<1)+1;
}

void BinaryHeap::heap_up(int index) {

    if(this->heap[parten(index)]<this->heap[index]){

        swap(this->heap[parten(index)],this->heap[index]);

        heap_up(parten(index));
    }
}

void BinaryHeap::heap_dow(int index) {
    int l_child = left_child(index);
    int r_child = right_child(index);
    int head = index;

    if(this->heap.size()>= l_child && this->heap[l_child]> this->heap[head]){
        head = l_child;
    }
    if(this->heap.size()>=r_child && this->heap[r_child]>this->heap[head]){
        head = r_child;
    }
    if(head != index){

        swap(this->heap[index],this->heap[head]);

        heap_dow(head);
    }
}

void BinaryHeap::insert(int element) {

    this->heap.push_back(element);

    heap_up(this->heap.size()-1);
}
void BinaryHeap::remove_max() {
    if(this->heap.empty()){
    cout<<"Heap Emty !!!";
        return;
    }
    this->heap[0]= this->heap.back();
    this->heap.pop_back();
    heap_dow(0);
}