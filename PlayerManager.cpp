#include "gm.h"

bool PlayerManager::Connect(int playerId) {
  if (playerId > cache)
  cache = playerId;

  this->pool[playerId] = new CPlayer(playerId);
  for (auto it = this->connect.begin(); it < this->connect.end(); ++it) {
    if ((*it)(this->pool[playerId])) {
      return true;
    }
  }
  return false;
}

bool PlayerManager::OnConnect(std::function<bool(CPlayer *)> callback) {
  this->connect.push_back(callback);
  return true;
}

bool PlayerManager::Spawn(int playerId) {
  for (auto it = this->entry.begin(); it < this->entry.end(); ++it) {
    if ((*it)(this->pool[playerId])) {
      return true;
    }
  }
  return true;
}

bool PlayerManager::OnSpawn(std::function<bool(CPlayer *)> callback) {
  this->entry.push_back(callback);
  return true;
}

bool PlayerManager::Disconnect(int playerId, int reason) {
  if (playerId == cache) {
    for (int i = cache - 1; i >= 0; --i) {
      if (this->ConnectedState(i)) {
        cache = i;
        break;
      }
    }
    if (playerId == cache)
    cache = 0;
  }
  for (auto it = this->disconnect.begin(); it < this->disconnect.end(); ++it) {
    if ((*it)(this->pool[playerId], reason)) {
      return true;
    }
  }
  delete this->pool[playerId];
  this->pool[playerId] = nullptr;
  return true;
}

bool PlayerManager::OnDisconnect(std::function<bool(CPlayer *, int reason)> callback) {
  this->disconnect.push_back(callback);
  return true;
}