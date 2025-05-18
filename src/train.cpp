// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
    if (first == nullptr) {
      first = newCar;
      first->next = first;
      first->prev = first;
    } else {
      newCar->next = first;
      newCar->prev = first->prev;
      first->prev->next = newCar;
      first->prev = newCar;
    }
}

int Train::getLength() {
  if (first == nullptr) {
    return 0;
  }
  int lenght = 0;
  Car* current = first;
  do {
    lenght++;
    current = current->next;
  } while (current != first);
  return lenght;
}

int Train::getOpCount() {
  if (first == nullptr) {
    return 0;
  }
  countOp = 0;
  int len = 0;
  Car* current = first;
  int flag = 0;
  for (int i = 0; i < getLength()-1; i++) {
    if (current->light == false) {
      countOp += 2;
      len += 1;
    } else if (current->light == true) {
      len += 1;
      countOp += 2;
      countOp += len * 2;
      flag = 1;
    }
    current = current->next;
  }
  if (flag == 1) {
    countOp += 2;
  }
  return countOp;
}
