// Copyright 2021 NNTU-CS
#include "train.h"
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
  current->light = true;
  Car* nextCar = current->next;
  int flag = 0;
  while (current->light) {
    if (flag == 1) {
      nextCar->prev->light = true;
      flag = 0;
    }
    if (nextCar->light == true) {
      flag = 1;
    }
    nextCar->light = false;
    nextCar = nextCar->next;
    lenght++;
  }
  return lenght;
}

int Train::getOpCount() {
  if (first == nullptr) {
    return 0;
  }
  countOp = 0;
  int len = 0;
  Car* current = first;
  current->light = true;
  Car* nextCar = current->next;
  for (int i = 0; i < getLength(); i++) {
    if (nextCar->light == false) {
      countOp += 2;
      len += 1;
    } else if (nextCar->light == true) {
      len += 1;
      countOp += 2;
      countOp += len * 2;
    }
    nextCar = nextCar->next;
  }
  return countOp;
}
