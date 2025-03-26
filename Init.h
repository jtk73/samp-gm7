#pragma once

template <typename T>

class CInit {
protected:
  CInit() noexcept = default;
  CInit(const CInit &) = delete;
  CInit &operator=(const CInit &) = delete;
  virtual ~CInit() = default;

public:
  static T &get() noexcept(std::is_nothrow_constructible<T>::value) {
    static T s;
    return s;
  }
};