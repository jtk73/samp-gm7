#pragma once

class PlayerManager : public CInit<PlayerManager> {
  CPlayer *pool[1000] = {nullptr};
  int cache = 0;
  std::vector<std::function<bool(CPlayer *)>> connect;
  std::vector<std::function<bool(CPlayer *)>> entry;
  std::vector<std::function<bool(CPlayer *, int)>> disconnect;

public:
  bool Connect(int playerId);
  bool OnConnect(std::function<bool(CPlayer *)> callback);
  bool Spawn(int playerId);
  bool OnSpawn(std::function<bool(CPlayer *)> callback);
  bool Disconnect(int playerId, int reason);
  bool OnDisconnect(std::function<bool(CPlayer *, int)> callback);

  CPlayer *operator[](int playerId) {
    return this->pool[playerId];
  }

  bool ConnectedState(int playerId) {
    return this->pool[playerId] != nullptr;
  }

  int GetCache() {
    return this->cache;
  }
};