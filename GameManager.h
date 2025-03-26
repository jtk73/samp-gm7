#pragma once

class GameManager : public CInit<GameManager> {
  std::vector<std::function<bool()>> init;
  std::vector<std::function<bool()>> exit;

public:
  bool Init();
  bool OnInit(std::function<bool()> callback);
  bool Exit();
  bool OnExit(std::function<bool()> callback);
};