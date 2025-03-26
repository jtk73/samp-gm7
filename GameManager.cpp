#include "gm.h"

bool GameManager::Init() {
  for (auto it = this->init.begin(); it < this->init.end(); ++it) {
    if ((*it)()) {
      return true;
    }
  }
  return false;
}

bool GameManager::OnInit(std::function<bool()> callback) {
  this->init.push_back(callback);
  return true;
}

bool GameManager::Exit() {
  for (auto it = this->exit.begin(); it < this->exit.end(); ++it) {
    if ((*it)()) {
      return true;
    }
  }
  return false;
}

bool GameManager::OnExit(std::function<bool()> callback) {
  this->exit.push_back(callback);
  return true;
}